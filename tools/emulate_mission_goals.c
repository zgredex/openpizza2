/*
 * Bounded Unicorn probe for the campaign mission-goal evaluator.
 *
 * Usage:
 *   emulate_mission_goals <fastfood2.exe> array <progress>
 *   emulate_mission_goals <fastfood2.exe> evaluate <goal0> <goal1> <goal2> <progress1> <c20> <flag_count>
 *
 * The PE is mapped at 0x400000.  A synthetic player-mission state is placed at
 * 0x30000000.  Game_GetPlayerFieldC20 (0x4e2280) and
 * Game_CountRecordsWithFlag16F4 (0x4de710) are patched to return the supplied
 * values so case 0 and case 2 can be evaluated without constructing a city.
 *
 * This observes the shipped evaluator's writes; it does not claim the whole
 * game runs in Unicorn.
 */

#include <unicorn/unicorn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SPAN 0x200000
#define STACK_BASE 0x00200000
#define STACK_SIZE 0x10000
#define MISSION_BASE 0x30000000
#define MISSION_SIZE 0x1000
#define GAME_SCRATCH 0x30001000
#define CITY_SCRATCH 0x30002000
#define ARRAY_SET_SLOT 0x4f5f70
#define EVALUATE_GOALS 0x4f5fd0
#define GET_PLAYER_C20 0x4e2280
#define COUNT_FLAG_16F4 0x4de710
#define IS_FREE_PLAY 0x57bb20
#define SENTINEL 0x005ff000
#define MAX_INSTRUCTIONS 200000

static uint64_t g_stop_at = SENTINEL;

typedef struct {
    int instructions;
    int reached_sentinel;
    uint64_t stop_address;
    uint64_t recent[128];
    uint64_t stop_at;
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
    state->recent[state->instructions & 127] = address;
    state->stop_address = address;
    if (address == state->stop_at || address == SENTINEL) {
        state->reached_sentinel = 1;
        state->stop_address = address;
        uc_emu_stop(uc);
    }
    if (state->instructions > MAX_INSTRUCTIONS) {
        uc_emu_stop(uc);
    }
}

static int map_image(uc_engine *uc, const uint8_t *image, size_t image_size,
                     uint32_t *section_count, uint32_t *optional_size,
                     uint32_t *pe_offset) {
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
    *section_count = sections;
    *optional_size = opt_size;
    *pe_offset = pe;
    return 1;
}

static int patch_call_return(uc_engine *uc, uint32_t address, uint32_t eax) {
    uint8_t code[6] = {0xB8, 0, 0, 0, 0, 0xC3};
    memcpy(code + 1, &eax, 4);
    return uc_mem_write(uc, address, code, sizeof(code)) == UC_ERR_OK;
}

static int setup(uc_engine **out, const char *exe, uint32_t *pe_offset,
                 uint32_t *section_count) {
    uint8_t *image = NULL;
    size_t image_size = 0;
    uint32_t optional_size;
    uc_engine *uc = NULL;
    uc_err err;
    if (!read_file(exe, &image, &image_size)) {
        fprintf(stderr, "cannot read %s\n", exe);
        return 0;
    }
    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);
    if (err != UC_ERR_OK) {
        fprintf(stderr, "uc_open: %s\n", uc_strerror(err));
        free(image); return 0;
    }
    if (!map_image(uc, image, image_size, section_count, &optional_size, pe_offset)) {
        fprintf(stderr, "cannot map PE (size=%zu)\n", image_size); free(image); uc_close(uc); return 0;
    }
    free(image);
    err = uc_mem_map(uc, STACK_BASE, STACK_SIZE, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map stack: %s\n", uc_strerror(err)); uc_close(uc); return 0; }
    err = uc_mem_map(uc, MISSION_BASE, MISSION_SIZE, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map mission: %s\n", uc_strerror(err)); uc_close(uc); return 0; }
    err = uc_mem_map(uc, 0xdeadb000, 0x1000, UC_PROT_ALL);
    if (err != UC_ERR_OK && err != UC_ERR_MAP) { fprintf(stderr, "map sentinel: %s\n", uc_strerror(err)); uc_close(uc); return 0; }
    err = uc_mem_map(uc, GAME_SCRATCH, 0x1000, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map game scratch: %s\n", uc_strerror(err)); uc_close(uc); return 0; }
    err = uc_mem_map(uc, CITY_SCRATCH, 0x1000, UC_PROT_ALL);
    if (err != UC_ERR_OK) { fprintf(stderr, "map city scratch: %s\n", uc_strerror(err)); uc_close(uc); return 0; }
    {
        uint8_t zero = 0;
        uint32_t value = 0;
        uint32_t game_ptr = GAME_SCRATCH;
        if (uc_mem_write(uc, IS_FREE_PLAY, &zero, 1) != UC_ERR_OK ||
            uc_mem_write(uc, 0xdeadb000, &value, 4) != UC_ERR_OK ||
            uc_mem_write(uc, 0x57c670, &game_ptr, 4) != UC_ERR_OK) {
            fprintf(stderr, "cannot seed globals\n"); uc_close(uc); return 0;
        }
    }
    *out = uc;
    return 1;
}

static int call_thiscall(uc_engine *uc, uint32_t entry, uint32_t this_ptr,
                         uint32_t param1, uint32_t param2, run_state *state) {
    uc_hook hook;
    uint32_t esp = STACK_BASE + STACK_SIZE - 0x40;
    uint32_t ret = SENTINEL;
    memset(state, 0, sizeof(*state));
    state->stop_at = g_stop_at;
    if (uc_hook_add(uc, &hook, UC_HOOK_CODE, (void *)hook_code, state, 1, 0) != UC_ERR_OK)
        return 0;
    if (uc_mem_write(uc, esp, &ret, 4) != UC_ERR_OK ||
        uc_mem_write(uc, esp + 4, &param1, 4) != UC_ERR_OK ||
        uc_mem_write(uc, esp + 8, &param2, 4) != UC_ERR_OK)
        return 0;
    uc_reg_write(uc, UC_X86_REG_ESP, &esp);
    uc_reg_write(uc, UC_X86_REG_ECX, &this_ptr);
    {
        uint32_t zero = 0;
        uc_reg_write(uc, UC_X86_REG_EAX, &zero);
        uc_reg_write(uc, UC_X86_REG_EBX, &zero);
        uc_reg_write(uc, UC_X86_REG_EDX, &zero);
        uc_reg_write(uc, UC_X86_REG_ESI, &zero);
        uc_reg_write(uc, UC_X86_REG_EDI, &zero);
        uc_reg_write(uc, UC_X86_REG_EBP, &zero);
    }
    {
        uc_err err = uc_emu_start(uc, entry, 0, 0, MAX_INSTRUCTIONS);
        if (err != UC_ERR_OK) {
            uint32_t eip = 0, esp_now = 0, ecx_now = 0;
            uc_reg_read(uc, UC_X86_REG_EIP, &eip);
            uc_reg_read(uc, UC_X86_REG_ESP, &esp_now);
            uc_reg_read(uc, UC_X86_REG_ECX, &ecx_now);
            fprintf(stderr, "emu_start 0x%x: %s (instructions=%d last=0x%llx eip=0x%x esp=0x%x ecx=0x%x)\n",
                    entry, uc_strerror(err), state->instructions,
                    (unsigned long long)state->stop_address, eip, esp_now, ecx_now);
            fprintf(stderr, "recent:");
            for (int k = state->instructions - 40; k <= state->instructions; k++) {
                if (k >= 0) fprintf(stderr, " 0x%llx", (unsigned long long)state->recent[k & 127]);
            }
            fprintf(stderr, "\n");
            uc_hook_del(uc, hook);
            return 0;
        }
    }
    uc_hook_del(uc, hook);
    return state->reached_sentinel;
}

static int run_array(const char *exe, uint32_t progress) {
    uc_engine *uc = NULL;
    uint32_t pe_offset, section_count;
    run_state state;
    uint32_t goals[3] = {1, 0xffffffff, 0xffffffff};
    uint8_t slots[0xd8];
    uint32_t value = 0;
    if (!setup(&uc, exe, &pe_offset, &section_count)) return 2;
    memset(slots, 0, sizeof(slots));
    memcpy(slots + 4, goals, sizeof(goals));
    memcpy(slots + 0x14, &progress, 4);
    if (uc_mem_write(uc, MISSION_BASE, slots, sizeof(slots)) != UC_ERR_OK) {
        uc_close(uc); return 2;
    }
    if (!call_thiscall(uc, ARRAY_SET_SLOT, MISSION_BASE, 1, 1, &state)) {
        fprintf(stderr, "array probe did not return (instructions=%d)\n", state.instructions);
        uc_close(uc); return 3;
    }
    uc_mem_read(uc, MISSION_BASE + 0x14, &value, 4);
    printf("{\"mode\":\"array\",\"input_progress\":%u,\"slot_14\":%u,"
           "\"instructions\":%d,\"evidence\":\"emulated\"}\n",
           progress, value, state.instructions);
    uc_close(uc);
    return 0;
}

static int run_evaluate(const char *exe, uint32_t goal0, uint32_t goal1,
                        uint32_t goal2, uint32_t progress1, uint32_t c20,
                        uint32_t flag_count) {
    uc_engine *uc = NULL;
    uint32_t pe_offset, section_count;
    run_state state;
    uint8_t slots[0xd8];
    uint8_t completed[3];
    uint32_t goals[3] = {goal0, goal1, goal2};
    if (!setup(&uc, exe, &pe_offset, &section_count)) return 2;
    g_stop_at = 0x4f6a74;
    if (!patch_call_return(uc, GET_PLAYER_C20, c20) ||
        !patch_call_return(uc, COUNT_FLAG_16F4, flag_count) ||
        !patch_call_return(uc, 0x4ddcc0, CITY_SCRATCH)) {
        fprintf(stderr, "cannot patch stubs\n"); uc_close(uc); return 2;
    }
    memset(slots, 0, sizeof(slots));
    memcpy(slots + 4, goals, sizeof(goals));
    memcpy(slots + 0x14, &progress1, 4);
    if (uc_mem_write(uc, MISSION_BASE, slots, sizeof(slots)) != UC_ERR_OK) {
        uc_close(uc); return 2;
    }
    if (!call_thiscall(uc, EVALUATE_GOALS, MISSION_BASE, 0, 0, &state)) {
        fprintf(stderr, "evaluator did not return (instructions=%d)\n", state.instructions);
        uc_close(uc); return 3;
    }
    uc_mem_read(uc, MISSION_BASE + 0xc4, completed, sizeof(completed));
    printf("{\"mode\":\"evaluate\",\"goals\":[%u,%u,%u],\"progress1\":%u,"
           "\"c20\":%u,\"flag_count\":%u,\"completed\":[%u,%u,%u],"
           "\"instructions\":%d,\"evidence\":\"emulated\"}\n",
           goal0, goal1, goal2, progress1, c20, flag_count,
           completed[0], completed[1], completed[2], state.instructions);
    uc_close(uc);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <fastfood2.exe> array <progress> | "
                        "evaluate <g0> <g1> <g2> <progress1> <c20> <flags>\n", argv[0]);
        return 2;
    }
    if (strcmp(argv[2], "array") == 0 && argc == 4) {
        g_stop_at = SENTINEL;
        return run_array(argv[1], (uint32_t)strtoul(argv[3], NULL, 0));
    }
    if (strcmp(argv[2], "evaluate") == 0 && argc == 9) {
        return run_evaluate(argv[1],
                            (uint32_t)strtoul(argv[3], NULL, 0),
                            (uint32_t)strtoul(argv[4], NULL, 0),
                            (uint32_t)strtoul(argv[5], NULL, 0),
                            (uint32_t)strtoul(argv[6], NULL, 0),
                            (uint32_t)strtoul(argv[7], NULL, 0),
                            (uint32_t)strtoul(argv[8], NULL, 0));
    }
    fprintf(stderr, "invalid arguments\n");
    return 2;
}
