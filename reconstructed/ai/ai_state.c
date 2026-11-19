#include "ai_state.h"

#include <string.h>

static int active_index(const CustomerAIState *state) {
    if (state == NULL || state->active_index < 0 || state->active_index >= state->count) {
        return -1;
    }
    if (!state->customers[state->active_index].active) {
        return -1;
    }
    return state->active_index;
}

static void admit_next(CustomerAIState *state) {
    if (state == NULL) {
        return;
    }
    state->active_index = -1;
    if (state->count > 0) {
        state->customers[0].active = true;
        state->customers[0].phase = CUSTOMER_WAITING;
        state->customers[0].timer_ticks = CUSTOMER_WALK_TICKS;
        state->active_index = 0;
    }
}

void customer_ai_init(CustomerAIState *state) {
    if (state == NULL) {
        return;
    }
    memset(state, 0, sizeof(*state));
    state->active_index = -1;
    state->next_id = 1;
}

bool customer_ai_enqueue(CustomerAIState *state, uint32_t party_size) {
    if (state == NULL || party_size == 0) {
        return false;
    }
    if (state->count >= CUSTOMER_QUEUE_CAPACITY) {
        state->rejected += 1;
        return false;
    }
    state->customers[state->count] = (Customer){
        .id = state->next_id++,
        .party_size = party_size,
        .phase = CUSTOMER_IDLE,
        .timer_ticks = 0,
        .active = false,
    };
    state->count += 1;
    if (state->active_index < 0) {
        admit_next(state);
    }
    return true;
}

CustomerPhase customer_ai_visit_state(const CustomerAIState *state) {
    int index = active_index(state);
    return index < 0 ? CUSTOMER_IDLE : state->customers[index].phase;
}

CustomerAIEvents customer_ai_advance_ticks(CustomerAIState *state, uint32_t ticks) {
    CustomerAIEvents events = {0};
    if (state == NULL) {
        return events;
    }
    for (uint32_t tick = 0; tick < ticks; tick++) {
        int index = active_index(state);
        if (index < 0) {
            admit_next(state);
            index = active_index(state);
            if (index < 0) {
                break;
            }
        }
        Customer *customer = &state->customers[index];
        if (customer->timer_ticks > 0) {
            customer->timer_ticks -= 1;
        }
        if (customer->timer_ticks != 0) {
            continue;
        }
        switch (customer->phase) {
        case CUSTOMER_WAITING:
            customer->phase = CUSTOMER_PRODUCING;
            customer->timer_ticks = CUSTOMER_PRODUCTION_TICKS;
            events.production_starts += 1;
            break;
        case CUSTOMER_PRODUCING:
            customer->phase = CUSTOMER_DEPARTING;
            customer->timer_ticks = CUSTOMER_SERVICE_TICKS;
            state->sales += 1;
            events.sales += 1;
            break;
        case CUSTOMER_DEPARTING:
            for (int move = index; move + 1 < state->count; move++) {
                state->customers[move] = state->customers[move + 1];
            }
            state->count -= 1;
            state->active_index = -1;
            state->departures += 1;
            events.departures += 1;
            admit_next(state);
            break;
        case CUSTOMER_IDLE:
            break;
        }
    }
    return events;
}

void competitor_ai_init(CompetitorAIState *state, uint32_t company_slot) {
    if (state == NULL) {
        return;
    }
    *state = (CompetitorAIState){
        .company_slot = company_slot,
        .cash = 0.0,
        .branch_count = 0,
        .staff_count = 0,
        .market_share_x100 = 0,
        .plan_steps = 0,
        .last_action = AI_ACTION_NONE,
    };
}

void competitor_ai_update(CompetitorAIState *state, double cash, uint32_t branches,
                          uint32_t staff, uint32_t market_share_x100,
                          uint32_t plan_steps) {
    if (state == NULL) {
        return;
    }
    state->cash = cash;
    state->branch_count = branches;
    state->staff_count = staff;
    state->market_share_x100 = market_share_x100;
    state->plan_steps = plan_steps;
}

void competitor_ai_record_action(CompetitorAIState *state, CompetitorAction action) {
    if (state != NULL) {
        state->last_action = action;
    }
}

size_t ai_compute_plan_scores(const int32_t *period_income,
                              const int32_t *period_expense,
                              size_t period_count, int32_t *scores,
                              size_t max_scores, int32_t *total) {
    if (period_income == NULL || period_expense == NULL || scores == NULL) {
        return 0;
    }
    if (total != NULL) {
        *total = 0;
    }
    size_t produced = 0;
    for (size_t index = 0; index < period_count && produced < max_scores;
         index++) {
        int32_t score = period_income[index] - period_expense[index];
        scores[produced++] = score;
        if (total != NULL) {
            *total += score;
        }
    }
    return produced;
}
