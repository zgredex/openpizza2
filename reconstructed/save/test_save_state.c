#include "save_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool load_fails(Settings *settings) {
    (void)settings;
    return false;
}

static uint32_t random_low(uint32_t low, uint32_t high) {
    (void)high;
    return low;
}

static SaveState make_state(void) {
    SaveState state;
    memset(&state, 0, sizeof(state));
    settings_init_defaults(&state.settings, load_fails, random_low);
    state.settings.language_index = 3;
    state.settings.autosave_interval = 7;
    state.mission.goals[0] = 0;
    state.mission.goals[1] = 1;
    state.mission.goals[2] = 2;
    state.mission.goal_progress[1] = 1;
    state.mission.deadline = 120;
    state.mission.completed[0] = 1;
    state.mission.completed[1] = 1;
    state.mission.completed[2] = 1;
    state.mission.field_c8 = 1;
    state.mission.field_cc = 0;
    state.mission.field_d0 = 0;
    state.mission.field_d4 = 0;
    return state;
}

static void test_round_trip(void) {
    SaveState original = make_state();
    assert(save_state_encoded_size() == SAVE_STATE_TOTAL_SIZE);
    uint8_t buffer[SAVE_STATE_TOTAL_SIZE];
    memset(buffer, 0xaa, sizeof(buffer));
    size_t written = save_state_encode(&original, buffer, sizeof(buffer));
    assert(written == SAVE_STATE_TOTAL_SIZE);
    assert(memcmp(buffer, "PC2S", 4) == 0);
    assert(buffer[4] == 1 && buffer[5] == 0 && buffer[6] == 0 && buffer[7] == 0);

    SaveState restored;
    memset(&restored, 0x55, sizeof(restored));
    assert(save_state_decode(&restored, buffer, written));
    assert(memcmp(&restored.settings, &original.settings, sizeof(Settings)) == 0);
    assert(memcmp(restored.mission.goals, original.mission.goals, sizeof(original.mission.goals)) == 0);
    assert(memcmp(restored.mission.goal_progress, original.mission.goal_progress,
                  sizeof(original.mission.goal_progress)) == 0);
    assert(restored.mission.deadline == 120);
    assert(restored.mission.completed[0] == 1);
    assert(restored.mission.completed[1] == 1);
    assert(restored.mission.completed[2] == 1);
    assert(restored.mission.field_c8 == 1);
    assert(restored.mission.field_cc == 0);
    assert(restored.mission.field_d0 == 0);
    assert(restored.mission.field_d4 == 0);
}

static void test_rejects_short_and_bad_magic(void) {
    SaveState original = make_state();
    uint8_t buffer[SAVE_STATE_TOTAL_SIZE];
    size_t written = save_state_encode(&original, buffer, sizeof(buffer));
    assert(written == SAVE_STATE_TOTAL_SIZE);

    SaveState restored;
    assert(!save_state_decode(&restored, buffer, written - 1));
    buffer[0] = 'X';
    assert(!save_state_decode(&restored, buffer, written));

    assert(save_state_encode(&original, buffer, written - 1) == 0);
}

int main(void) {
    test_round_trip();
    test_rejects_short_and_bad_magic();
    puts("save state reconstruction: OK");
    return 0;
}
