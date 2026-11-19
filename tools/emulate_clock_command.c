/*
 * Bounded Unicorn harness for the Game_WindowProc command mapping.
 *
 * Usage: emulate_clock_command <game/fastfood2.exe> <command>
 *
 * Execution starts at 0x4058f5 with EAX=command and stops at the consumer
 * entry (0x405aa9 for the hourly case or 0x405ae0 for the quarter-hour case).
 */

#include <unicorn/unicorn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SPAN 0x200000
#define STACK_BASE 0x00200000
#define STACK_SIZE 0x10000
#define ENTRY 0x4058f5
#define MAX_INSTRUCTIONS 200
#define TARGET_HOURLY 0x405aa9
#define TARGET_QUARTER 0x405ae0

typedef struct {
    int instructions;
    uint64_t stop_address;
    uint32_t eax;
    uint32_t ecx;
    int stopped;
} run_state;

static uint32_t read_u32(const uint8_t *data, size_t offset) {
    uint32_t value;
    memcpy(&value, data + offset, sizeof(value));
    return value;
}

static uint16_t read_u16(const uint8_t *data, size_t offset) {
    uint16_t value;
    memcpy(&value, data + offset, sizeof(value));
    return value;
}

static int read_file(const char *path, uint8_t **out, size_t *size) {
    FILE *file = fopen(path, "rb");
    long length;
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) != 0) { fclose(file); return 0; }
    length = ftell(file);
    if (length <= 0 || fseek(file, 0, SEEK_SET) != 0) { fclose(file); return 0; }
    *out = malloc((size_t)length);
    if (!*out) { fclose(file); return 0; }
    if (fread(*out, 1, (size_t)length, file) != (size_t)length) {
        free(*out); fclose(file); return 0;
    }
    fclose(file);
    *size = (size_t)length;
    return 1;
}

static void hook_code(uc_engine *uc, uint64_t address, uint32_t size, void *user) {
    run_state *state = (run_state *)user;
    (void)size;
    state->instructions += 1;
    if (address == TARGET_HOURLY || address == TARGET_QUARTER) {
        state->stop_address = address;
        state->stopped = 1;
        uc_reg_read(uc, UC_X86_REG_EAX, &state->eax);
        uc_reg_read(uc, UC_X86_REG_ECX, &state->ecx);
        uc_emu_stop(uc);
    }
}

int main(int argc, char **argv) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uint32_t pe_offset, image_base, section_count, optional_size, command;
    uc_engine *uc = NULL;
    uc_hook hook;
    run_state state;
    uc_err err;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <fastfood2.exe> <command>\n", argv[0]);
        return 2;
    }
    command = (uint32_t)strtoul(argv[2], NULL, 0);
    if (!read_file(argv[1], &image, &image_size)) {
        fprintf(stderr, "cannot read %s\n", argv[1]);
        return 2;
    }
    if (image_size < 0x1000 || memcmp(image, "MZ", 2) != 0) {
        fprintf(stderr, "not a PE image\n");
        return 2;
    }
    pe_offset = read_u32(image, 0x3c);
    if (pe_offset + 0x40 > image_size || memcmp(image + pe_offset, "PE\0\0", 4) != 0) {
        fprintf(stderr, "invalid PE header\n");
        return 2;
    }
    section_count = read_u16(image, pe_offset + 6);
    optional_size = read_u16(image, pe_offset + 20);
    image_base = read_u32(image, pe_offset + 24 + 28);
    if (image_base != 0x400000 || section_count > 16) {
        fprintf(stderr, "unexpected image base/section count\n");
        return 2;
    }
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
    if (err != UC_ERR_OK) { fprintf(stderr, "uc_open: %s\n", uc_strerror(err)); return 2; }
    err = uc_mem_map(uc, image_base, IMAGE_SPAN, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map image: %s\n", uc_strerror(err)); return 2; }
    err = uc_mem_write(uc, image_base, image, image_size);
    if (err != UC_ERR_OK) { fprintf(stderr, "copy image: %s\n", uc_strerror(err)); return 2; }
    for (uint32_t index = 0; index < section_count; index++) {
        size_t offset = pe_offset + 24 + optional_size + index * 40;
        uint32_t virtual_size = read_u32(image, offset + 8);
        uint32_t virtual_address = read_u32(image, offset + 12);
        uint32_t raw_size = read_u32(image, offset + 16);
        uint32_t raw_pointer = read_u32(image, offset + 20);
        uint32_t copy_size = virtual_size < raw_size ? virtual_size : raw_size;
        if (raw_pointer + copy_size > image_size || virtual_address + copy_size > IMAGE_SPAN) {
            fprintf(stderr, "invalid section %u\n", index);
            return 2;
        }
        err = uc_mem_write(uc, image_base + virtual_address, image + raw_pointer, copy_size);
        if (err != UC_ERR_OK) { fprintf(stderr, "copy section: %s\n", uc_strerror(err)); return 2; }
    }
    err = uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map stack: %s\n", uc_strerror(err)); return 2; }
    memset(&state, 0, sizeof(state));
    err = uc_hook_add(uc, &hook, UC_HOOK_CODE, (void *)hook_code, &state, 1, 0);
    if (err != UC_ERR_OK) { fprintf(stderr, "hook: %s\n", uc_strerror(err)); return 2; }
    {
        uint32_t esp = STACK_BASE + STACK_SIZE - 0x200;
        uint32_t sentinel = 0xdeadbeef;
        uc_reg_write(uc, UC_X86_REG_EAX, &command);
        uc_reg_write(uc, UC_X86_REG_ECX, &(uint32_t){0});
        uc_reg_write(uc, UC_X86_REG_EDX, &(uint32_t){0});
        uc_reg_write(uc, UC_X86_REG_EBX, &(uint32_t){0});
        uc_reg_write(uc, UC_X86_REG_ESP, &esp);
        uc_mem_write(uc, esp, &sentinel, sizeof(sentinel));
    }
    err = uc_emu_start(uc, ENTRY, 0, 0, MAX_INSTRUCTIONS);
    if (err != UC_ERR_OK) { fprintf(stderr, "emulation: %s\n", uc_strerror(err)); return 2; }
    if (!state.stopped) { fprintf(stderr, "consumer entry not reached\n"); return 3; }
    printf("{\"command\":\"0x%08x\",\"target\":\"0x%llx\",\"eax\":\"0x%08x\","
           "\"ecx\":\"0x%08x\",\"instructions\":%d,\"evidence\":\"emulated\"}\n",
           command, (unsigned long long)state.stop_address, state.eax, state.ecx,
           state.instructions);
    uc_close(uc);
    free(image);
    return 0;
}
