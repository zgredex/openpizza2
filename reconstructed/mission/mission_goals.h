#ifndef PC2_RECONSTRUCTED_MISSION_GOALS_H
#define PC2_RECONSTRUCTED_MISSION_GOALS_H

#include <stdbool.h>
#include <stdint.h>

#include "mission_state.h"

/*
 * Injections for the external probes in Mission_EvaluateGoals.
 * player_field_c20 is Game_GetPlayerFieldC20 (0x4E2280).
 * flag16f4_count is Game_CountRecordsWithFlag16F4 (0x4DE710).
 * force_complete corresponds to the third parameter of Mission_EvaluateGoals
 * being nonzero; the normal tick path passes zero.
 */
typedef struct MissionGoalInputs {
    int32_t player_field_c20;
    int32_t flag16f4_count;
    bool force_complete;
} MissionGoalInputs;

/*
 * Reconstructed from Mission_EvaluateGoals (0x4F5FD0), limited to the London
 * goal ids 0/1/2. Other goal ids remain pending and are left to later batches.
 */
void mission_evaluate_goals(MissionState *state, MissionGoalInputs inputs);

bool mission_all_goals_complete(const MissionState *state);

/* Reconstructed from Array_SetSlot (0x4F5F70): write goal_progress[goal_id]. */
void mission_array_set_slot(MissionState *state, int goal_id, int32_t value);

#endif
