#ifndef PC2_RECONSTRUCTED_SAVE_STATE_H
#define PC2_RECONSTRUCTED_SAVE_STATE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../mission/mission_state.h"
#include "../settings/settings.h"

#define SAVE_STATE_MAGIC 0x53324350u /* "PC2S" in little-endian bytes */
#define SAVE_STATE_VERSION 1u
#define SAVE_STATE_HEADER_SIZE 8u
#define SAVE_STATE_MISSION_SIZE 0xD0u
#define SAVE_STATE_TOTAL_SIZE (SAVE_STATE_HEADER_SIZE + 0x164u + SAVE_STATE_MISSION_SIZE)

typedef struct SaveState {
    Settings settings;
    MissionState mission;
} SaveState;

size_t save_state_encoded_size(void);

/*
 * Encode a host save blob:
 *   +0x00  magic "PC2S"
 *   +0x04  version u32
 *   +0x08  Settings (0x164 bytes, the 0x57B8A8 global block)
 *   +0x16C mission state in Player_MissionState_Save order:
 *          goals 0xC, progress 0xB0, deadline 4, completed 3,
 *          field C8 4, field CC 1, field D0 4, field D4 4
 *          (0xD0 packed bytes; the save stream skips the +0xC7 and
 *          +0xCD..+0xCF alignment gaps)
 */
size_t save_state_encode(const SaveState *state, uint8_t *buffer, size_t capacity);
bool save_state_decode(SaveState *state, const uint8_t *buffer, size_t length);

#endif
