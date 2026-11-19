#include "value_state.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

static void test_positive_approach_and_decay(void) {
    ValueApproachState state;
    value_state_init(&state, 50.0);
    assert(value_approach(&state, 10.0, 55.0));
    assert_close(state.value, 55.0, 1e-12);
    assert(state.dirty == 1);

    state.dirty = 0;
    assert(!value_approach(&state, 10.0, 55.0));
    assert(state.dirty == 0);
    value_state_decay_hour(&state);
    assert_close(state.value, 51.0, 1e-12);

    value_state_init(&state, 50.0);
    assert(value_approach(&state, 10.0, 54.0));
    assert_close(state.value, 54.0, 1e-12);
    assert(state.dirty == 1);
}

static void test_negative_and_zero_targets(void) {
    ValueApproachState state;
    value_state_init(&state, -10.0);
    assert(value_approach(&state, 3.0, -15.0));
    assert_close(state.value, -7.0, 1e-12);
    assert(state.dirty == 1);

    state.dirty = 0;
    value_state_decay_hour(&state);
    assert_close(state.value, -5.0, 1e-12);

    value_state_init(&state, 5.0);
    assert(!value_approach(&state, 10.0, 0.0));
    assert(state.dirty == 0);
    value_state_decay_hour(&state);
    assert_close(state.value, 1.0, 1e-12);
}

static void test_adjusted_value(void) {
    assert(game_adjusted_value(10, 50, 5, false, 0, false, -1, 100, 0, 0) ==
           65);
    assert(game_adjusted_value(10, 50, 5, true, 1, false, -1, 100, 0, 0) ==
           97);
    assert(game_adjusted_value(10, 50, 5, true, 0, true, -1, 100, 0, 0) ==
           120);
    assert(game_adjusted_value(10, 0, 0, false, 0, false, -1, 100, 0, 0) ==
           60);
    assert(game_adjusted_value(0, 0, 0, false, 0, false, -1, 100, 0, 0) == 0);
    assert(game_adjusted_value(10, 50, 5, false, 0, false, 0, 100, 25, 0) ==
           113);
    assert(game_adjusted_value(1000, 5000, 5, false, 0, false, 0, 100, 60, 60) ==
           500);
}

int main(void) {
    test_positive_approach_and_decay();
    test_negative_and_zero_targets();
    test_adjusted_value();
    puts("advertising value reconstruction: OK");
    return 0;
}
