/*
 * Bounded Unicorn checks for the named MSVC CRT helpers.
 *
 * Usage: emulate_crt_helpers <fastfood2.exe> <mode> [args...]
 *   control <flags>
 *   control_inv <word>
 *   strcspn <string> <set>
 *   strpbrk <string> <set>
 *   strnlen <string> <max>
 *   addcarry <a> <b>
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
#define MAX_INSTRUCTIONS 20000

#define CONTROL_WORD_FROM_FLAGS 0x555650
#define FP_FLAGS_FROM_CONTROL 0x5556e2
#define STRCSPN 0x555ff0
#define STRPBRK 0x556030
#define STRNLEN 0x5577aa
#define ADD_U32_CARRY 0x556bdd

typedef struct {
    int instructions;
    int reached;
} run_state;

static uint32_t rd32(const uint8_t *data, size_t offset) {
    uint32_t value;
    memcpy(&value, data + offset, 4);
    return value;
}

static uint16_t rd16(const uint8_t *data, size_t offset) {
    uint16_t value;
    memcpy(&value, data + offset, 2);
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

static void hook(uc_engine *uc, uint64_t address, uint32_t size, void *user) {
    run_state *state = user;
    (void)size;
    state->instructions += 1;
    if (address == SENTINEL) {
        state->reached = 1;
        uc_emu_stop(uc);
    }
}

static int call_cdecl(uc_engine *uc, uint32_t entry, const uint32_t *args, int count,
                      run_state *state) {
    uc_hook handle;
    uint32_t esp = STACK_BASE + STACK_SIZE - 0x80;
    uint32_t ret = SENTINEL;
    memset(state, 0, sizeof(*state));
    if (uc_hook_add(uc, &handle, UC_HOOK_CODE, hook, state, 1, 0) != UC_ERR_OK) return 0;
    for (int index = count - 1; index >= 0; index--) {
        esp -= 4;
        if (uc_mem_write(uc, esp, &args[index], 4) != UC_ERR_OK) return 0;
    }
    esp -= 4;
    if (uc_mem_write(uc, esp, &ret, 4) != UC_ERR_OK) return 0;
    uc_reg_write(uc, UC_X86_REG_ESP, &esp);
    {
        uint32_t zero = 0;
        uc_reg_write(uc, UC_X86_REG_EAX, &zero);
        uc_reg_write(uc, UC_X86_REG_ECX, &zero);
        uc_reg_write(uc, UC_X86_REG_EDX, &zero);
    }
    if (uc_emu_start(uc, entry, 0, 0, MAX_INSTRUCTIONS) != UC_ERR_OK) {
        uc_hook_del(uc, handle);
        return 0;
    }
    uc_hook_del(uc, handle);
    return state->reached;
}

static int setup(uc_engine **out, const char *exe) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uint32_t pe, sections, optional, base;
    uc_engine *uc = NULL;
    if (!read_file(exe, &image, &image_size)) { fprintf(stderr, "read failed\n"); return 0; }
    pe = rd32(image, 0x3c);
    sections = rd16(image, pe + 6);
    optional = rd16(image, pe + 20);
    base = rd32(image, pe + 24 + 28);
    if (base != 0x400000 || sections > 16) { fprintf(stderr, "pe base/sections %x %u\n", base, sections); free(image); return 0; }
    if (uc_open(UC_ARCH_X86, UC_MODE_32, &uc) != UC_ERR_OK) { fprintf(stderr, "uc_open failed\n"); free(image); return 0; }
    if (uc_mem_map(uc, base, IMAGE_SPAN, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_write(uc, base, image, image_size) != UC_ERR_OK) {
        fprintf(stderr, "image map failed\n"); free(image); uc_close(uc); return 0;
    }
    for (uint32_t index = 0; index < sections; index++) {
        size_t offset = pe + 24 + optional + index * 40;
        uint32_t vsize = rd32(image, offset + 8);
        uint32_t rva = rd32(image, offset + 12);
        uint32_t raw_size = rd32(image, offset + 16);
        uint32_t raw_ptr = rd32(image, offset + 20);
        uint32_t copy = vsize < raw_size ? vsize : raw_size;
        if (raw_ptr + copy > image_size ||
            uc_mem_write(uc, base + rva, image + raw_ptr, copy) != UC_ERR_OK) {
            fprintf(stderr, "section %u copy failed\n", index); free(image); uc_close(uc); return 0;
        }
    }
    free(image);
    if (uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_map(uc, SCRATCH, SCRATCH_SIZE, UC_PROT_ALL) != UC_ERR_OK) {
        fprintf(stderr, "scratch map failed\n"); uc_close(uc); return 0;
    }
    *out = uc;
    return 1;
}

static uint32_t result(uc_engine *uc, int *ok) {
    uint32_t eax = 0;
    *ok = uc_reg_read(uc, UC_X86_REG_EAX, &eax) == UC_ERR_OK;
    return eax;
}

int main(int argc, char **argv) {
    uc_engine *uc = NULL;
    run_state state;
    uint32_t args[3];
    int ok = 0;
    uint32_t eax;
    if (argc < 3 || !setup(&uc, argv[1])) return 2;
    if (strcmp(argv[2], "control") == 0 && argc == 4) {
        args[0] = (uint32_t)strtoul(argv[3], NULL, 0);
        if (!call_cdecl(uc, CONTROL_WORD_FROM_FLAGS, args, 1, &state)) return 2;
        eax = result(uc, &ok);
        printf("{\"mode\":\"control\",\"input\":%u,\"eax\":%u,\"ok\":%d}\n", args[0], eax, ok);
    } else if (strcmp(argv[2], "control_inv") == 0 && argc == 4) {
        args[0] = (uint32_t)strtoul(argv[3], NULL, 0);
        if (!call_cdecl(uc, FP_FLAGS_FROM_CONTROL, args, 1, &state)) return 2;
        eax = result(uc, &ok);
        printf("{\"mode\":\"control_inv\",\"input\":%u,\"eax\":%u,\"ok\":%d}\n", args[0], eax, ok);
    } else if (strcmp(argv[2], "strcspn") == 0 && argc == 5) {
        uint32_t a = SCRATCH + 0x100, b = SCRATCH + 0x200;
        uc_mem_write(uc, a, argv[3], strlen(argv[3]) + 1);
        uc_mem_write(uc, b, argv[4], strlen(argv[4]) + 1);
        args[0] = a; args[1] = b;
        if (!call_cdecl(uc, STRCSPN, args, 2, &state)) return 2;
        eax = result(uc, &ok);
        printf("{\"mode\":\"strcspn\",\"eax\":%u,\"ok\":%d}\n", eax, ok);
    } else if (strcmp(argv[2], "strpbrk") == 0 && argc == 5) {
        uint32_t a = SCRATCH + 0x100, b = SCRATCH + 0x200;
        uc_mem_write(uc, a, argv[3], strlen(argv[3]) + 1);
        uc_mem_write(uc, b, argv[4], strlen(argv[4]) + 1);
        args[0] = a; args[1] = b;
        if (!call_cdecl(uc, STRPBRK, args, 2, &state)) return 2;
        eax = result(uc, &ok);
        printf("{\"mode\":\"strpbrk\",\"offset\":%d,\"ok\":%d}\n",
               ok && eax ? (int)(eax - a) : -1, ok);
    } else if (strcmp(argv[2], "strnlen") == 0 && argc == 5) {
        uint32_t a = SCRATCH + 0x100;
        uc_mem_write(uc, a, argv[3], strlen(argv[3]) + 1);
        args[0] = a; args[1] = (uint32_t)strtoul(argv[4], NULL, 0);
        if (!call_cdecl(uc, STRNLEN, args, 2, &state)) return 2;
        eax = result(uc, &ok);
        printf("{\"mode\":\"strnlen\",\"eax\":%u,\"ok\":%d}\n", eax, ok);
    } else if (strcmp(argv[2], "addcarry") == 0 && argc == 5) {
        uint32_t out = SCRATCH + 0x300;
        args[0] = (uint32_t)strtoul(argv[3], NULL, 0);
        args[1] = (uint32_t)strtoul(argv[4], NULL, 0);
        args[2] = out;
        if (!call_cdecl(uc, ADD_U32_CARRY, args, 3, &state)) return 2;
        eax = result(uc, &ok);
        {
            uint32_t sum = 0;
            uc_mem_read(uc, out, &sum, 4);
            printf("{\"mode\":\"addcarry\",\"eax\":%u,\"sum\":%u,\"ok\":%d}\n", eax, sum, ok);
        }
    } else {
        uc_close(uc);
        return 2;
    }
    uc_close(uc);
    return ok ? 0 : 3;
}
