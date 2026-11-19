/*
 * Bounded Unicorn probes for the free-play cash-multiplier path.
 *
 * Usage:
 *   emulate_freeplay_profiles <fastfood2.exe> init
 *   emulate_freeplay_profiles <fastfood2.exe> copy
 *   emulate_freeplay_profiles <fastfood2.exe> cash <multiplier> <capital>
 *
 * The PE is mapped at 0x400000.  Each mode starts at an address inside the
 * shipped routine, seeds only the inputs used by that fragment, and stops
 * before the next unrelated instruction.  This observes the original bytes; it
 * does not claim the whole free-play setup runs in Unicorn.
 */

#include <unicorn/unicorn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SPAN 0x200000
#define STACK_BASE 0x00200000
#define STACK_SIZE 0x10000
#define SCRATCH_BASE 0x30000000
#define SCRATCH_SIZE 0x4000
#define SENTINEL 0x005ff000
#define MAX_INSTRUCTIONS 100000

#define INIT_START 0x406b7f
#define INIT_STOP 0x406ba7
#define COPY_START 0x4cbeb2
#define COPY_STOP 0x4cbed8
#define CASH_START 0x48203d
#define CASH_STOP 0x482063
#define APPEARANCE_START 0x4822df
#define APPEARANCE_STOP 0x48230f
#define LOGO_COLOR_START 0x48200c
#define LOGO_COLOR_STOP 0x482032
#define SETTINGS_MULTIPLIERS 0x57b97c
#define SETTINGS_SECOND 0x57b994
#define SETTINGS_ACTIVE 0x57b9ac
#define PROFILE_BASE 0x57bcd8

typedef struct {
    int instructions;
    uint64_t stop_at;
    uint64_t stop_address;
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
    state->stop_address = address;
    if (address == state->stop_at || address == SENTINEL) {
        uc_emu_stop(uc);
    }
    if (state->instructions > MAX_INSTRUCTIONS) {
        uc_emu_stop(uc);
    }
}

static int map_image(uc_engine *uc, const uint8_t *image, size_t image_size) {
    uint32_t pe, sections, opt_size, image_base;
    if (image_size < 0x1000 || memcmp(image, "MZ", 2) != 0) return 0;
    pe = read_u32(image, 0x3c);
    if (pe + 0x40 > image_size || memcmp(image + pe, "PE\0\0", 4) != 0) return 0;
    sections = read_u16(image, pe + 6);
    opt_size = read_u16(image, pe + 20);
    image_base = read_u32(image, pe + 24 + 28);
    if (image_base != 0x400000 || sections > 16) return 0;
    if (uc_mem_map(uc, image_base, IMAGE_SPAN, UC_PROT_ALL) != UC_ERR_OK) return 0;
    if (uc_mem_write(uc, image_base, image, image_size) != UC_ERR_OK) return 0;
    for (uint32_t index = 0; index < sections; index++) {
        size_t offset = pe + 24 + opt_size + index * 40;
        uint32_t virtual_size = read_u32(image, offset + 8);
        uint32_t virtual_address = read_u32(image, offset + 12);
        uint32_t raw_size = read_u32(image, offset + 16);
        uint32_t raw_pointer = read_u32(image, offset + 20);
        uint32_t copy_size = virtual_size < raw_size ? virtual_size : raw_size;
        if (raw_pointer + copy_size > image_size ||
            virtual_address + copy_size > IMAGE_SPAN) return 0;
        if (uc_mem_write(uc, image_base + virtual_address,
                         image + raw_pointer, copy_size) != UC_ERR_OK) return 0;
    }
    return 1;
}

static int setup(uc_engine **out, const char *exe) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uc_engine *uc = NULL;
    uc_err err;
    if (!read_file(exe, &image, &image_size)) {
        fprintf(stderr, "cannot read %s\n", exe);
        return 0;
    }
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
    if (err != UC_ERR_OK) {
        fprintf(stderr, "uc_open: %s\n", uc_strerror(err));
        free(image);
        return 0;
    }
    if (!map_image(uc, image, image_size)) {
        fprintf(stderr, "cannot map PE\n");
        free(image);
        uc_close(uc);
        return 0;
    }
    free(image);
    if (uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL) != UC_ERR_OK ||
        uc_mem_map(uc, SCRATCH_BASE, SCRATCH_SIZE, UC_PROT_ALL) != UC_ERR_OK) {
        fprintf(stderr, "cannot map scratch\n");
        uc_close(uc);
        return 0;
    }
    *out = uc;
    return 1;
}

static int run_fragment(uc_engine *uc, uint32_t start, uint32_t stop,
                        uint32_t eax, uint32_t ecx, uint32_t edx,
                        uint32_t esi, uint32_t ebp, uint32_t esp,
                        run_state *state) {
    uc_hook hook;
    memset(state, 0, sizeof(*state));
    state->stop_at = stop;
    if (uc_reg_write(uc, UC_X86_REG_EAX, &eax) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_ECX, &ecx) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_EDX, &edx) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_ESI, &esi) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_EDI, &(uint32_t){0}) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_EBX, &(uint32_t){0}) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_EBP, &ebp) != UC_ERR_OK ||
        uc_reg_write(uc, UC_X86_REG_ESP, &esp) != UC_ERR_OK) {
        return 0;
    }
    if (uc_hook_add(uc, &hook, UC_HOOK_CODE, hook_code, state, 1, 0) !=
        UC_ERR_OK) {
        return 0;
    }
    uc_err err = uc_emu_start(uc, start, SENTINEL, 0, MAX_INSTRUCTIONS);
    uc_hook_del(uc, hook);
    if (err != UC_ERR_OK) {
        fprintf(stderr, "emu: %s at 0x%llx\n", uc_strerror(err),
                (unsigned long long)state->stop_address);
        return 0;
    }
    return state->stop_address == stop;
}

static int read_u32_mem(uc_engine *uc, uint32_t address, uint32_t *value) {
    return uc_mem_read(uc, address, value, sizeof(*value)) == UC_ERR_OK;
}

static int mode_init(uc_engine *uc) {
    uint8_t zero[0xd4];
    run_state state;
    memset(zero, 0, sizeof(zero));
    if (uc_mem_write(uc, 0x57b900, zero, sizeof(zero)) != UC_ERR_OK) return 0;
    if (!run_fragment(uc, INIT_START, INIT_STOP, 0, 0, 0, 0, 0,
                      STACK_BASE + STACK_SIZE - 0x40, &state)) return 0;
    for (int index = 0; index < 6; index++) {
        uint32_t multiplier, second, active;
        if (!read_u32_mem(uc, SETTINGS_MULTIPLIERS + index * 4, &multiplier) ||
            !read_u32_mem(uc, SETTINGS_SECOND + index * 4, &second) ||
            !read_u32_mem(uc, SETTINGS_ACTIVE + index * 4, &active)) return 0;
        printf("p%d_multiplier=%u\n", index, multiplier);
        printf("p%d_second=%u\n", index, second);
        printf("p%d_active=%u\n", index, active);
    }
    printf("instructions=%d\n", state.instructions);
    return 1;
}

static int mode_copy(uc_engine *uc) {
    run_state state;
    uint8_t zero[0x480];
    memset(zero, 0, sizeof(zero));
    if (uc_mem_write(uc, PROFILE_BASE, zero, sizeof(zero)) != UC_ERR_OK) return 0;
    for (int index = 0; index < 6; index++) {
        uint32_t multiplier = (uint32_t)(100 + index);
        uint32_t second = (uint32_t)(10 + index);
        uint32_t active = (uint32_t)(index % 2 == 0 ? 1 : 0);
        if (uc_mem_write(uc, SETTINGS_MULTIPLIERS + index * 4, &multiplier, 4) != UC_ERR_OK ||
            uc_mem_write(uc, SETTINGS_SECOND + index * 4, &second, 4) != UC_ERR_OK ||
            uc_mem_write(uc, SETTINGS_ACTIVE + index * 4, &active, 4) != UC_ERR_OK) return 0;
    }
    if (!run_fragment(uc, COPY_START, COPY_STOP, 0, 0x57bcdc, 0, 0, 0,
                      STACK_BASE + STACK_SIZE - 0x40, &state)) return 0;
    for (int index = 0; index < 6; index++) {
        uint32_t multiplier, second, active;
        uint32_t base = PROFILE_BASE + (uint32_t)index * 0xC0;
        if (!read_u32_mem(uc, base, &multiplier) ||
            !read_u32_mem(uc, base + 4, &second) ||
            !read_u32_mem(uc, base + 0x3C, &active)) return 0;
        printf("p%d_multiplier=%u\n", index, multiplier);
        printf("p%d_second=%u\n", index, second);
        printf("p%d_active=%u\n", index, active);
    }
    printf("instructions=%d\n", state.instructions);
    return 1;
}

static int mode_cash(uc_engine *uc, int32_t multiplier, int32_t capital) {
    run_state state;
    uint32_t esp = STACK_BASE + STACK_SIZE - 0x80;
    uint32_t ebp = SCRATCH_BASE;
    uint32_t multiplier_value = (uint32_t)multiplier;
    uint32_t capital_value = (uint32_t)capital;
    uint32_t edx = 0;
    if (uc_mem_write(uc, PROFILE_BASE, &multiplier_value, 4) != UC_ERR_OK ||
        uc_mem_write(uc, esp + 0x18, &capital_value, 4) != UC_ERR_OK) return 0;
    if (!run_fragment(uc, CASH_START, CASH_STOP, 0, 0, 0, 0, ebp, esp,
                      &state)) return 0;
    if (uc_reg_read(uc, UC_X86_REG_EDX, &edx) != UC_ERR_OK) return 0;
    printf("multiplier=%d\n", multiplier);
    printf("capital=%d\n", capital);
    printf("starting_cash=%d\n", (int32_t)edx);
    printf("instructions=%d\n", state.instructions);
    return 1;
}

static int mode_logo_color(uc_engine *uc) {
    run_state state;
    uint32_t company_base = SCRATCH_BASE + 0x3000;
    uint32_t company_pointer = company_base;
    uint32_t logo = 5;
    uint32_t color = 3;
    uint8_t zero[0x40];
    memset(zero, 0, sizeof(zero));
    if (uc_mem_write(uc, company_base, zero, sizeof(zero)) != UC_ERR_OK ||
        uc_mem_write(uc, SCRATCH_BASE, &company_pointer, 4) != UC_ERR_OK ||
        uc_mem_write(uc, 0x57bd0c, &logo, 4) != UC_ERR_OK ||
        uc_mem_write(uc, 0x57bd10, &color, 4) != UC_ERR_OK) return 0;
    if (!run_fragment(uc, LOGO_COLOR_START, LOGO_COLOR_STOP, 0, 0, 0x57bd10,
                      0, SCRATCH_BASE - 0x200,
                      STACK_BASE + STACK_SIZE - 0x40, &state)) return 0;
    uint32_t company_color = 0;
    uint32_t company_logo = 0;
    if (!read_u32_mem(uc, company_base + 0x1dc, &company_color) ||
        !read_u32_mem(uc, company_base + 0x1e0, &company_logo)) return 0;
    printf("company_color=0x%x\n", company_color);
    printf("company_logo=%u\n", company_logo);
    printf("instructions=%d\n", state.instructions);
    return 1;
}

static int mode_appearance(uc_engine *uc) {
    run_state state;
    uint32_t character_base = SCRATCH_BASE + 0x2000;
    uint8_t initial[0x40];
    uint32_t values[5] = {1, 2, 3, 4, 5};
    memset(initial, 0xAA, sizeof(initial));
    if (uc_mem_write(uc, character_base, initial, sizeof(initial)) != UC_ERR_OK ||
        uc_mem_write(uc, 0x57bcf8, values, sizeof(values) * 4) != UC_ERR_OK) {
        /* Only five dwords exist, but keep the write explicit. */
        for (int index = 0; index < 5; index++) {
            if (uc_mem_write(uc, 0x57bcf8 + (uint32_t)index * 4,
                             &values[index], 4) != UC_ERR_OK) return 0;
        }
    }
    if (!run_fragment(uc, APPEARANCE_START, APPEARANCE_STOP, character_base,
                      0, 0x57bd10, 0, 0, STACK_BASE + STACK_SIZE - 0x40,
                      &state)) return 0;
    const char *names[5] = {"gender", "hair", "eyes", "mouth", "head"};
    for (int index = 0; index < 5; index++) {
        uint32_t value;
        if (!read_u32_mem(uc, character_base + 0x24 + (uint32_t)index * 4,
                          &value)) return 0;
        printf("%s=%u\n", names[index], value);
    }
    uint32_t untouched;
    if (!read_u32_mem(uc, character_base + 0x20, &untouched)) return 0;
    printf("sentinel=%u\n", untouched);
    printf("instructions=%d\n", state.instructions);
    return 1;
}

int main(int argc, char **argv) {
    uc_engine *uc = NULL;
    int status = 1;
    if (argc < 3) {
        fprintf(stderr, "usage: %s <fastfood2.exe> init|copy|cash [args]\n",
                argv[0]);
        return 2;
    }
    if (!setup(&uc, argv[1])) return 2;
    if (strcmp(argv[2], "init") == 0) {
        status = mode_init(uc) ? 0 : 1;
    } else if (strcmp(argv[2], "copy") == 0) {
        status = mode_copy(uc) ? 0 : 1;
    } else if (strcmp(argv[2], "cash") == 0 && argc == 5) {
        status = mode_cash(uc, (int32_t)strtol(argv[3], NULL, 0),
                           (int32_t)strtol(argv[4], NULL, 0)) ? 0 : 1;
    } else if (strcmp(argv[2], "appearance") == 0) {
        status = mode_appearance(uc) ? 0 : 1;
    } else if (strcmp(argv[2], "logo-color") == 0) {
        status = mode_logo_color(uc) ? 0 : 1;
    } else {
        fprintf(stderr, "unknown mode or arguments\n");
        status = 2;
    }
    uc_close(uc);
    return status;
}
