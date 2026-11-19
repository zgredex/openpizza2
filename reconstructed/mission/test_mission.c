#include "mission_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_london_initialisation(void) {
    CityMissionData city;
    MissionState state;
    memset(&city, 0, sizeof(city));
    memset(&state, 0xaa, sizeof(state));
    city.field_33c = 1;
    city.game_length = 2;
    city.goals[0] = 0;
    city.goals[1] = 1;
    city.goals[2] = 2;

    game_init_date_state(&state, &city);

    assert(state.deadline == 120);
    assert(state.goals[0] == 0);
    assert(state.goals[1] == 1);
    assert(state.goals[2] == 2);
    assert(state.completed[0] == 0);
    assert(state.completed[1] == 0);
    assert(state.completed[2] == 0);
    assert(state.goal_progress[0] == 0);
    assert(state.goal_progress[1] == 0); /* Unicorn reads +0x14 for goal 1 */
    assert(state.goal_progress[2] == 0);
    assert(state.field_c8 == 1);
    assert(state.field_d0 == 0);
    assert(state.field_d4 == 0);
    assert(state.field_cc == 0);
}

static void test_nonzero_stage_sets_twelve(void) {
    CityMissionData city;
    MissionState state;
    memset(&city, 0, sizeof(city));
    memset(&state, 0, sizeof(state));
    city.field_33c = 5;
    city.game_length = 3;
    city.goals[0] = 3;
    city.goals[1] = 4;
    city.goals[2] = 5;

    game_init_date_state(&state, &city);

    assert(state.deadline == 180);
    assert(state.goals[0] == 3);
    assert(state.goals[1] == 4);
    assert(state.goals[2] == 5);
    assert(state.field_c8 == 5);
    assert(state.field_d0 == 4);
    assert(state.field_d4 == 0x0c);
    assert(state.field_cc == 0);
}

int main(void) {
    test_london_initialisation();
    test_nonzero_stage_sets_twelve();
    puts("mission state reconstruction: OK");
    return 0;
}
