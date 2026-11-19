/*
 * Bounded Unicorn probe for Settings_InitDefaults (0x406a90).
 *
 * Usage: emulate_settings_defaults <fastfood2.exe>
 *
 * Settings_LoadFromRegistry (0x406bb0) is patched to return false so the
 * default branch runs; Random_RangeFast (0x4034d0) is patched to return 0.
 * The original initializer then writes the defaults into 0x57b8a8..0x57ba0c.
 */

#include <unicorn/unicorn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SPAN 0x200000
#define STACK_BASE 0x00200000
#define STACK_SIZE 0x10000
#define SENTINEL 0x005ff000
#define MAX_INSTRUCTIONS 100000
#define INIT_DEFAULTS 0x406a90
#define LOAD_REGISTRY 0x406bb0
#define RANDOM_RANGE_FAST 0x4034d0

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
static int patch_ret_zero(uc_engine *uc, uint32_t address) {
    const uint8_t code[3] = {0x31, 0xC0, 0xC3};
    return uc_mem_write(uc, address, code, sizeof(code)) == UC_ERR_OK;
}

int main(int argc, char **argv) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uint32_t pe, sections, optional, base;
    uc_engine *uc = NULL;
    uc_hook handle;
    run_state state;
    uint32_t esp, ret = SENTINEL, zero = 0;
    static const uint32_t addresses[] = {
        0x57b8a8, 0x57b9dc, 0x57b9c8, 0x57b9cc, 0x57b9d0, 0x57b9d4,
        0x57b9d8, 0x57b9f0, 0x57b9f4, 0x57b9f8, 0x57b9fc, 0x57b964,
        0x57b968, 0x57b96c, 0x57b970, 0x57b978, 0x57ba08,
    };
    if (argc != 2) { fprintf(stderr, "usage: %s <fastfood2.exe>\n", argv[0]); return 2; }
    if (!read_file(argv[1], &image, &image_size)) return 2;
    pe = rd32(image, 0x3c);
    sections = rd16(image, pe + 6);
    optional = rd16(image, pe + 20);
    base = rd32(image, pe + 24 + 28);
    if (base != 0x400000 || sections > 16) return 2;
    if (uc_open(UC_ARCH_X86, UC_MODE_32, &uc) != UC_ERR_OK) return 2;
    if (uc_mem_map(uc, base, IMAGE_SPAN, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_write(uc, base, image, image_size) != UC_ERR_OK) return 2;
    for (uint32_t index = 0; index < sections; index++) {
        size_t offset = pe + 24 + optional + index * 40;
        uint32_t vsize = rd32(image, offset + 8);
        uint32_t rva = rd32(image, offset + 12);
        uint32_t raw_size = rd32(image, offset + 16);
        uint32_t raw_ptr = rd32(image, offset + 20);
        uint32_t copy = vsize < raw_size ? vsize : raw_size;
        if (uc_mem_write(uc, base + rva, image + raw_ptr, copy) != UC_ERR_OK) return 2;
    }
    free(image);
    if (uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL) != UC_ERR_OK) return 2;
    if (!patch_ret_zero(uc, LOAD_REGISTRY) || !patch_ret_zero(uc, RANDOM_RANGE_FAST)) {
        fprintf(stderr, "cannot patch stubs\n"); return 2;
    }
    memset(&state, 0, sizeof(state));
    if (uc_hook_add(uc, &handle, UC_HOOK_CODE, hook, &state, 1, 0) != UC_ERR_OK) return 2;
    esp = STACK_BASE + STACK_SIZE - 0x40;
    if (uc_mem_write(uc, esp, &ret, 4) != UC_ERR_OK) return 2;
    uc_reg_write(uc, UC_X86_REG_ESP, &esp);
    uc_reg_write(uc, UC_X86_REG_EAX, &zero);
    uc_reg_write(uc, UC_X86_REG_ECX, &zero);
    uc_reg_write(uc, UC_X86_REG_EDX, &zero);
    if (uc_emu_start(uc, INIT_DEFAULTS, 0, 0, MAX_INSTRUCTIONS) != UC_ERR_OK) {
        fprintf(stderr, "emulation failed at instruction %d\n", state.instructions);
        return 2;
    }
    if (!state.reached) {
        fprintf(stderr, "did not reach sentinel (%d instructions)\n", state.instructions);
        return 3;
    }
    printf("{\"mode\":\"settings_defaults\",\"instructions\":%d,\"globals\":{", state.instructions);
    for (size_t index = 0; index < sizeof(addresses) / sizeof(addresses[0]); index++) {
        uint32_t value = 0;
        uc_mem_read(uc, addresses[index], &value, 4);
        printf("%s\"0x%08x\":%u", index ? "," : "", addresses[index], value);
    }
    printf("},\"evidence\":\"emulated\"}\n");
    uc_close(uc);
    return 0;
}
