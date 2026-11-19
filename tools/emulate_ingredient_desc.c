/*
 * Bounded Unicorn probe for Game_SetBuildingDesc (0x4e4860).
 *
 * Calls the original __thiscall with the Olives descriptor and reads the
 * ingredient object back: +0x88 name buffer and the numeric fields.
 */

#include <unicorn/unicorn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SPAN 0x200000
#define STACK_BASE 0x00200000
#define STACK_SIZE 0x10000
#define SCRATCH 0x30000000
#define SCRATCH_SIZE 0x3000
#define SENTINEL 0x005ff000
#define MAX_INSTRUCTIONS 50000
#define SET_BUILDING_DESC 0x4e4860

typedef struct { int instructions; int reached; } run_state;

static uint32_t rd32(const uint8_t *data, size_t offset) {
    uint32_t value; memcpy(&value, data + offset, 4); return value;
}
static uint16_t rd16(const uint8_t *data, size_t offset) {
    uint16_t value; memcpy(&value, data + offset, 2); return value;
}
static int read_file(const char *path, uint8_t **out, size_t *size) {
    FILE *file = fopen(path, "rb"); long length;
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return 0; }
    length = ftell(file);
    if (length <= 0 || fseek(file, 0, SEEK_SET) != 0) { fclose(file); return 0; }
    *out = malloc((size_t)length);
    if (!*out) { fclose(file); return 0; }
    if (fread(*out, 1, (size_t)length, file) != (size_t)length) {
        free(*out); fclose(file); return 0;
    }
    fclose(file); *size = (size_t)length; return 1;
}
static void hook(uc_engine *uc, uint64_t address, uint32_t size, void *user) {
    run_state *state = user; (void)size; state->instructions += 1;
    if (address == SENTINEL) { state->reached = 1; uc_emu_stop(uc); }
}

int main(int argc, char **argv) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uint32_t pe, sections, optional, base;
    uc_engine *uc = NULL;
    uc_hook handle;
    run_state state;
    uint32_t args[14] = {
        SCRATCH + 0x1000, 1, 7, 4, 2, 1, 0, 0x402e0000u,
        0, 0xff, 1, 0, 0, 0,
    };
    uint32_t esp, ret = SENTINEL, object = SCRATCH;
    char name[32] = {0};
    uint32_t fields[9] = {0};
    if (argc != 2) { fprintf(stderr, "usage: %s <fastfood2.exe>\n", argv[0]); return 2; }
    if (!read_file(argv[1], &image, &image_size)) return 2;
    pe = rd32(image, 0x3c); sections = rd16(image, pe + 6);
    optional = rd16(image, pe + 20); base = rd32(image, pe + 24 + 28);
    if (base != 0x400000 || sections > 16) return 2;
    if (uc_open(UC_ARCH_X86, UC_MODE_32, &uc) != UC_ERR_OK) return 2;
    if (uc_mem_map(uc, base, IMAGE_SPAN, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_write(uc, base, image, image_size) != UC_ERR_OK) return 2;
    for (uint32_t index = 0; index < sections; index++) {
        size_t offset = pe + 24 + optional + index * 40;
        uint32_t vsize = rd32(image, offset + 8), rva = rd32(image, offset + 12);
        uint32_t raw_size = rd32(image, offset + 16), raw_ptr = rd32(image, offset + 20);
        uint32_t copy = vsize < raw_size ? vsize : raw_size;
        if (uc_mem_write(uc, base + rva, image + raw_ptr, copy) != UC_ERR_OK) return 2;
    }
    free(image);
    if (uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_map(uc, SCRATCH, SCRATCH_SIZE, UC_PROT_ALL) != UC_ERR_OK) return 2;
    if (uc_mem_write(uc, args[0], "Olives", 7) != UC_ERR_OK) return 2;
    memset(&state, 0, sizeof(state));
    if (uc_hook_add(uc, &handle, UC_HOOK_CODE, hook, &state, 1, 0) != UC_ERR_OK) return 2;
    esp = STACK_BASE + STACK_SIZE - 0x80;
    for (int index = 13; index >= 0; index--) {
        esp -= 4;
        if (uc_mem_write(uc, esp, &args[index], 4) != UC_ERR_OK) return 2;
    }
    esp -= 4;
    if (uc_mem_write(uc, esp, &ret, 4) != UC_ERR_OK) return 2;
    uc_reg_write(uc, UC_X86_REG_ESP, &esp);
    uc_reg_write(uc, UC_X86_REG_ECX, &object);
    {
        uint32_t zero = 0;
        uc_reg_write(uc, UC_X86_REG_EAX, &zero);
        uc_reg_write(uc, UC_X86_REG_EDX, &zero);
    }
    if (uc_emu_start(uc, SET_BUILDING_DESC, 0, 0, MAX_INSTRUCTIONS) != UC_ERR_OK) return 2;
    if (!state.reached) { fprintf(stderr, "no sentinel\n"); return 3; }
    uc_mem_read(uc, object + 0x88, name, sizeof(name) - 1);
    for (int index = 0; index < 9; index++) {
        uc_mem_read(uc, object + 0xa8 + index * 4, &fields[index], 4);
    }
    printf("{\"mode\":\"ingredient_desc\",\"name\":\"%s\","
           "\"field_a8\":%u,\"field_ac\":%u,\"field_b0\":%u,\"field_b4\":%u,"
           "\"field_b8\":%u,\"field_c0\":%u,\"field_c4\":%u,\"field_c8\":%u,"
           "\"instructions\":%d,\"evidence\":\"emulated\"}\n",
           name, fields[0], fields[1], fields[2], fields[3], fields[4], fields[6],
           fields[7], fields[8], state.instructions);
    uc_close(uc);
    return 0;
}
