#include "save_state.h"

#include <string.h>

static void write_u32(uint8_t *buffer, size_t offset, uint32_t value) {
    buffer[offset + 0] = (uint8_t)(value & 0xffu);
    buffer[offset + 1] = (uint8_t)((value >> 8) & 0xffu);
    buffer[offset + 2] = (uint8_t)((value >> 16) & 0xffu);
    buffer[offset + 3] = (uint8_t)((value >> 24) & 0xffu);
}

static uint32_t read_u32(const uint8_t *buffer, size_t offset) {
    return (uint32_t)buffer[offset + 0] | ((uint32_t)buffer[offset + 1] << 8) |
           ((uint32_t)buffer[offset + 2] << 16) | ((uint32_t)buffer[offset + 3] << 24);
}

size_t save_state_encoded_size(void) {
    return SAVE_STATE_HEADER_SIZE + sizeof(Settings) + SAVE_STATE_MISSION_SIZE;
}

size_t save_state_encode(const SaveState *state, uint8_t *buffer, size_t capacity) {
    if (state == NULL || buffer == NULL) {
        return 0;
    }
    const size_t required = save_state_encoded_size();
    if (capacity < required) {
        return 0;
    }
    memset(buffer, 0, required);
    write_u32(buffer, 0, SAVE_STATE_MAGIC);
    write_u32(buffer, 4, SAVE_STATE_VERSION);
    memcpy(buffer + SAVE_STATE_HEADER_SIZE, &state->settings, sizeof(Settings));

    size_t offset = SAVE_STATE_HEADER_SIZE + sizeof(Settings);
    memcpy(buffer + offset, state->mission.goals, 0x0C);
    offset += 0x0C;
    memcpy(buffer + offset, state->mission.goal_progress, 0xB0);
    offset += 0xB0;
    write_u32(buffer, offset, (uint32_t)state->mission.deadline);
    offset += 4;
    memcpy(buffer + offset, state->mission.completed, 3);
    offset += 3;
    write_u32(buffer, offset, (uint32_t)state->mission.field_c8);
    offset += 4;
    buffer[offset] = state->mission.field_cc;
    offset += 1;
    write_u32(buffer, offset, (uint32_t)state->mission.field_d0);
    offset += 4;
    write_u32(buffer, offset, (uint32_t)state->mission.field_d4);
    offset += 4;
    return offset == required ? required : 0;
}

bool save_state_decode(SaveState *state, const uint8_t *buffer, size_t length) {
    if (state == NULL || buffer == NULL || length < save_state_encoded_size()) {
        return false;
    }
    if (read_u32(buffer, 0) != SAVE_STATE_MAGIC || read_u32(buffer, 4) != SAVE_STATE_VERSION) {
        return false;
    }

    memcpy(&state->settings, buffer + SAVE_STATE_HEADER_SIZE, sizeof(Settings));
    memset(&state->mission, 0, sizeof(state->mission));

    size_t offset = SAVE_STATE_HEADER_SIZE + sizeof(Settings);
    memcpy(state->mission.goals, buffer + offset, 0x0C);
    offset += 0x0C;
    memcpy(state->mission.goal_progress, buffer + offset, 0xB0);
    offset += 0xB0;
    state->mission.deadline = (int32_t)read_u32(buffer, offset);
    offset += 4;
    memcpy(state->mission.completed, buffer + offset, 3);
    offset += 3;
    state->mission.field_c8 = (int32_t)read_u32(buffer, offset);
    offset += 4;
    state->mission.field_cc = buffer[offset];
    offset += 1;
    state->mission.field_d0 = (int32_t)read_u32(buffer, offset);
    offset += 4;
    state->mission.field_d4 = (int32_t)read_u32(buffer, offset);
    return true;
}
