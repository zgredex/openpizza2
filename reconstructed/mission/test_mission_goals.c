#include "mission_goals.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef struct GoalCase {
    const char *name;
    int32_t c20;
    int32_t progress1;
    int32_t flag_count;
    uint8_t expected[3];
} GoalCase;

static void init_london(MissionState *state) {
    memset(state, 0, sizeof(*state));
    state->goals[0] = 0;
    state->goals[1] = 1;
    state->goals[2] = 2;
}

static void assert_completed(const MissionState *state, const uint8_t expected[3]) {
    for (int index = 0; index < 3; index++) {
        assert(state->completed[index] == expected[index]);
    }
}

static void test_unicorn_cases(void) {
    static const GoalCase cases[] = {
        {"no_goals_complete", 0, 0, 0, {0, 0, 0}},
        {"goal0_needs_more_than_2", 2, 0, 0, {0, 0, 0}},
        {"goal0_level3", 3, 0, 0, {1, 0, 0}},
        {"goal1_needs_progress", 0, 0, 0, {0, 0, 0}},
        {"goal1_progress", 0, 1, 0, {0, 1, 0}},
        {"goal2_needs_flagged_record", 0, 0, 0, {0, 0, 0}},
        {"goal2_flagged_record", 0, 0, 1, {0, 0, 1}},
        {"all_goals_complete", 3, 1, 1, {1, 1, 1}},
    };
    for (size_t index = 0; index < sizeof(cases) / sizeof(cases[0]); index++) {
        MissionState state;
        init_london(&state);
        state.goal_progress[1] = cases[index].progress1;
        mission_evaluate_goals(&state,
                               (MissionGoalInputs){
                                   .player_field_c20 = cases[index].c20,
                                   .flag16f4_count = cases[index].flag_count,
                                   .force_complete = false,
                               });
        assert_completed(&state, cases[index].expected);
        assert(mission_all_goals_complete(&state) ==
               (cases[index].expected[0] && cases[index].expected[1] &&
                cases[index].expected[2]));
    }
}

static void test_array_set_slot_unicorn_case(void) {
    MissionState state;
    memset(&state, 0, sizeof(state));
    state.goals[0] = 1;
    state.goals[1] = 0;
    state.goals[2] = 0;

    mission_array_set_slot(&state, 1, 1);
    assert(state.goal_progress[1] == 1);

    mission_evaluate_goals(&state,
                           (MissionGoalInputs){
                               .player_field_c20 = 0,
                               .flag16f4_count = 0,
                               .force_complete = false,
                           });
    assert(state.completed[0] == 1);
    assert(state.completed[1] == 0);
    assert(state.completed[2] == 0);
}

static void test_completed_flags_stick_and_force_complete(void) {
    MissionState state;
    init_london(&state);
    state.goal_progress[1] = 1;
    mission_evaluate_goals(&state,
                           (MissionGoalInputs){
                               .player_field_c20 = 0,
                               .flag16f4_count = 0,
                               .force_complete = false,
                           });
    assert(state.completed[1] == 1);

    state.goal_progress[1] = 0;
    mission_evaluate_goals(&state,
                           (MissionGoalInputs){
                               .player_field_c20 = 0,
                               .flag16f4_count = 0,
                               .force_complete = false,
                           });
    assert(state.completed[1] == 1);

    mission_evaluate_goals(&state,
                           (MissionGoalInputs){
                               .player_field_c20 = 0,
                               .flag16f4_count = 0,
                               .force_complete = true,
                           });
    assert(mission_all_goals_complete(&state));
}

int main(void) {
    test_unicorn_cases();
    test_array_set_slot_unicorn_case();
    test_completed_flags_stick_and_force_complete();
    puts("mission goals reconstruction: OK");
    return 0;
}
