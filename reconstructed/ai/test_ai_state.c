#include "ai_state.h"

#include <assert.h>
#include <stdio.h>

static void test_customer_visit(void) {
    CustomerAIState state;
    customer_ai_init(&state);
    assert(customer_ai_visit_state(&state) == CUSTOMER_IDLE);

    assert(customer_ai_enqueue(&state, 1));
    assert(state.count == 1);
    assert(customer_ai_visit_state(&state) == CUSTOMER_WAITING);
    assert(state.customers[0].timer_ticks == CUSTOMER_WALK_TICKS);

    CustomerAIEvents events = customer_ai_advance_ticks(&state, CUSTOMER_WALK_TICKS - 1);
    assert(state.customers[0].timer_ticks == 1);
    assert(customer_ai_visit_state(&state) == CUSTOMER_WAITING);
    assert(events.production_starts == 0);

    events = customer_ai_advance_ticks(&state, 1);
    assert(customer_ai_visit_state(&state) == CUSTOMER_PRODUCING);
    assert(state.customers[0].timer_ticks == CUSTOMER_PRODUCTION_TICKS);
    assert(events.production_starts == 1);

    events = customer_ai_advance_ticks(&state, CUSTOMER_PRODUCTION_TICKS);
    assert(customer_ai_visit_state(&state) == CUSTOMER_DEPARTING);
    assert(state.customers[0].timer_ticks == CUSTOMER_SERVICE_TICKS);
    assert(state.sales == 1);
    assert(events.sales == 1);

    events = customer_ai_advance_ticks(&state, CUSTOMER_SERVICE_TICKS);
    assert(customer_ai_visit_state(&state) == CUSTOMER_IDLE);
    assert(state.count == 0);
    assert(state.departures == 1);
    assert(events.departures == 1);
}

static void test_second_party_waits(void) {
    CustomerAIState state;
    customer_ai_init(&state);
    assert(customer_ai_enqueue(&state, 1));
    assert(customer_ai_enqueue(&state, 2));
    assert(state.count == 2);
    assert(state.customers[0].active);
    assert(!state.customers[1].active);

    assert(customer_ai_enqueue(&state, 3));
    customer_ai_advance_ticks(&state, CUSTOMER_WALK_TICKS + CUSTOMER_PRODUCTION_TICKS +
                                          CUSTOMER_SERVICE_TICKS);
    assert(state.count == 2);
    assert(state.departures == 1);
    assert(state.customers[0].party_size == 2);
    assert(customer_ai_visit_state(&state) == CUSTOMER_WAITING);
}

static void test_queue_capacity(void) {
    CustomerAIState state;
    customer_ai_init(&state);
    for (uint32_t index = 0; index < CUSTOMER_QUEUE_CAPACITY; index++) {
        assert(customer_ai_enqueue(&state, 1));
    }
    assert(state.count == CUSTOMER_QUEUE_CAPACITY);
    assert(!customer_ai_enqueue(&state, 1));
    assert(state.rejected == 1);
}

static void test_competitor_state(void) {
    CompetitorAIState rival;
    competitor_ai_init(&rival, 1);
    assert(rival.company_slot == 1);
    assert(rival.cash == 0.0);
    assert(rival.last_action == AI_ACTION_NONE);

    competitor_ai_update(&rival, 250000.0, 4, 12, 3250, 7);
    assert(rival.cash == 250000.0);
    assert(rival.branch_count == 4);
    assert(rival.staff_count == 12);
    assert(rival.market_share_x100 == 3250);
    assert(rival.plan_steps == 7);

    competitor_ai_record_action(&rival, AI_ACTION_BUILD_BRANCH);
    assert(rival.last_action == AI_ACTION_BUILD_BRANCH);
}

int main(void) {
    test_customer_visit();
    test_second_party_waits();
    test_queue_capacity();
    test_competitor_state();
    puts("AI state reconstruction: OK");
    return 0;
}
