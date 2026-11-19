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

static void test_plan_effect(void) {
    assert(company_get_percent_modifier(1, 5000) == 50);
    assert(company_get_percent_modifier(2, 2500) == 50);
    assert(company_get_percent_modifier(3, 3500) == 100);
    assert(gameplan_effect_from_bar(1, 5000, 80, 0, 0) == 60);
    assert(gameplan_effect_from_bar(1, 5000, 80, 25, 0) == 15);
    assert(gameplan_effect_from_bar(1, 5000, 40, 25, 0) == 10);
    assert(gameplan_effect_from_bar(2, 5000, 200, 0, 0) == 100);
    assert(gameplan_effect_from_bar(1, 0, 0, 100, 0) == 0);
    const int32_t bars[8] = {80, 80, 80, 80, 80, 80, 80, 80};
    assert(gameplan_average_effect(bars, 1, 5000, 0, 0) == 60);
}

static void test_category_effect(void) {
    assert(gameplan_company_category_metric(1, 11, 22, 33, 44) == 11);
    assert(gameplan_company_category_metric(2, 11, 22, 33, 44) == 22);
    assert(gameplan_company_category_metric(4, 11, 22, 33, 44) == 33);
    assert(gameplan_company_category_metric(8, 11, 22, 33, 44) == 44);
    assert(gameplan_company_category_metric(16, 11, 22, 33, 44) == 0);

    const int32_t competitor_avg[4] = {50, 50, 50, 50};
    const int32_t own_metrics[4] = {100, 100, 100, 100};
    assert(gameplan_category_effect(0, 0, 0, 0, 100, 0, 0, false,
                                    competitor_avg, own_metrics) == 0);
    assert(gameplan_category_effect(1, 0, 0, 0, 100, 0, 0, false,
                                    competitor_avg, own_metrics) == 40);
    assert(gameplan_category_effect(1, 1, 0, 0, 100, 0, 0, false,
                                    competitor_avg, own_metrics) == 70);
    assert(gameplan_category_effect(1, 1, 1, 0, 100, 0, 0, true,
                                    competitor_avg, own_metrics) == 92);
    assert(gameplan_category_effect(1, 1, 1, 0, 100, 5, 5, true,
                                    competitor_avg, own_metrics) == 64);
    const int32_t low_metrics[4] = {30, 30, 30, 30};
    assert(gameplan_category_effect(1, 1, 1, 0, 100, 0, 0, true,
                                    competitor_avg, low_metrics) == 67);
}

static void test_plan_allocation(void) {
    PlanAllocation plans[3] = {
        {.type = 1, .effect = 60},
        {.type = 2, .effect = 50},
        {.type = 3, .effect = 0},
    };
    company_allocate_plan_budget(plans, 3, 1000, 2);
    assert(plans[0].score == 120);
    assert(plans[0].share == 705);
    assert(plans[0].active);
    assert(plans[1].share == 295);
    assert(plans[1].active);
    assert(plans[2].fixed);
    assert(plans[2].active);

    PlanAllocation weak[2] = {
        {.type = 1, .effect = 40},
        {.type = 2, .effect = 80},
    };
    company_allocate_plan_budget(weak, 2, 500, 1);
    assert(weak[0].fixed);
    assert(!weak[0].active);
    assert(weak[1].share == 500);

    PlanAllocation duplicate[3] = {
        {.type = 1, .effect = 60},
        {.type = 1, .effect = 40},
        {.type = 2, .effect = 50},
    };
    company_allocate_plan_budget(duplicate, 3, 1000, 2);
    assert(duplicate[0].share == 705);
    assert(duplicate[1].fixed);
    assert(duplicate[1].share == 0);
    assert(duplicate[2].share == 295);
}

int main(void) {
    test_positive_approach_and_decay();
    test_negative_and_zero_targets();
    test_adjusted_value();
    test_plan_effect();
    test_category_effect();
    test_plan_allocation();
    puts("advertising value reconstruction: OK");
    return 0;
}
