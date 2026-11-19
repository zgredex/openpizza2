#include "mission_goals.h"

#include <stddef.h>

_Static_assert(offsetof(MissionState, goal_progress[1]) == 0x14,
               "goal 1 reads state+0x14");

static bool evaluate_one(MissionState *state, int slot, MissionGoalInputs inputs) {
    if (state->completed[slot] != 0) {
        return true;
    }

    bool complete = false;
    switch (state->goals[slot]) {
    case 0:
        complete = inputs.player_field_c20 > 2;
        break;
    case 1:
        complete = state->goal_progress[1] > 0;
        break;
    case 2:
        complete = inputs.flag16f4_count != 0;
        break;
    default:
        break;
    }

    if (complete) {
        state->completed[slot] = 1;
    }
    return complete;
}

void mission_evaluate_goals(MissionState *state, MissionGoalInputs inputs) {
    if (state == NULL) {
        return;
    }
    for (int slot = 0; slot < 3; slot++) {
        (void)evaluate_one(state, slot, inputs);
    }
    if (inputs.force_complete) {
        for (int slot = 0; slot < 3; slot++) {
            state->completed[slot] = 1;
        }
    }
}

bool mission_all_goals_complete(const MissionState *state) {
    if (state == NULL) {
        return false;
    }
    return state->completed[0] != 0 && state->completed[1] != 0 &&
           state->completed[2] != 0;
}

void mission_array_set_slot(MissionState *state, int goal_id, int32_t value) {
    if (state == NULL || goal_id < 0 || goal_id > 2) {
        return;
    }
    for (int slot = 0; slot < 3; slot++) {
        if (state->goals[slot] == goal_id) {
            state->goal_progress[goal_id] = value;
        }
    }
}
