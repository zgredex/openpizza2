#include "mission_state.h"

#include <string.h>

_Static_assert(sizeof(MissionState) == 0xd8, "mission state must stay 0xD8 bytes");
_Static_assert(offsetof(MissionState, goals) == 0x04, "goals offset");
_Static_assert(offsetof(MissionState, goal_progress) == 0x10, "progress offset");
_Static_assert(offsetof(MissionState, goal_progress[1]) == 0x14, "goal 1 progress offset");
_Static_assert(offsetof(MissionState, deadline) == 0xc0, "deadline offset");
_Static_assert(offsetof(MissionState, completed) == 0xc4, "completed offset");
_Static_assert(offsetof(MissionState, field_c8) == 0xc8, "field c8 offset");
_Static_assert(offsetof(MissionState, field_cc) == 0xcc, "field cc offset");
_Static_assert(offsetof(MissionState, field_d0) == 0xd0, "field d0 offset");
_Static_assert(offsetof(MissionState, field_d4) == 0xd4, "field d4 offset");

_Static_assert(sizeof(CityMissionData) == 0x358, "city prefix must stay 0x358 bytes");
_Static_assert(offsetof(CityMissionData, field_33c) == 0x33c, "city field 33c offset");
_Static_assert(offsetof(CityMissionData, game_length) == 0x348, "city game length offset");
_Static_assert(offsetof(CityMissionData, goals) == 0x34c, "city goals offset");

void game_init_date_state(MissionState *state, const CityMissionData *city) {
    if (state == NULL || city == NULL) {
        return;
    }

    state->deadline = city->game_length * 60;
    for (size_t index = 0; index < 3; index++) {
        state->goals[index] = city->goals[index];
        state->completed[index] = 0;
    }

    memset(state->goal_progress, 0, 0xb0);

    state->field_c8 = city->field_33c;
    state->field_d0 = city->field_33c - 1;
    if (state->field_d0 == 0) {
        state->field_d4 = 0;
        state->field_cc = 0;
    } else {
        state->field_d4 = 0x0c;
        state->field_cc = 0;
    }
}
