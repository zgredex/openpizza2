#ifndef PC2_RECONSTRUCTED_AI_STATE_H
#define PC2_RECONSTRUCTED_AI_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define CUSTOMER_QUEUE_CAPACITY 40
#define CUSTOMER_WALK_TICKS 260
#define CUSTOMER_PRODUCTION_TICKS 180
#define CUSTOMER_SERVICE_TICKS 80

typedef enum CustomerPhase {
    CUSTOMER_IDLE = 0,
    CUSTOMER_WAITING = 1,
    CUSTOMER_PRODUCING = 2,
    CUSTOMER_DEPARTING = 3,
} CustomerPhase;

typedef struct Customer {
    uint32_t id;
    uint32_t party_size;
    CustomerPhase phase;
    uint32_t timer_ticks;
    bool active;
} Customer;

typedef struct CustomerAIState {
    Customer customers[CUSTOMER_QUEUE_CAPACITY];
    int count;
    int active_index;
    uint32_t next_id;
    uint32_t queued_party;
    uint32_t sales;
    uint32_t departures;
    uint32_t rejected;
} CustomerAIState;

typedef struct CustomerAIEvents {
    uint32_t production_starts;
    uint32_t sales;
    uint32_t departures;
    uint32_t rejected;
} CustomerAIEvents;

typedef enum CompetitorAction {
    AI_ACTION_NONE = 0,
    AI_ACTION_BUY_BRANCH = 1,
    AI_ACTION_BUILD_BRANCH = 2,
    AI_ACTION_HIRE_STAFF = 3,
    AI_ACTION_ADVERTISE = 4,
    AI_ACTION_ANNOY_RIVAL = 5,
} CompetitorAction;

typedef struct CompetitorAIState {
    uint32_t company_slot;
    double cash;
    uint32_t branch_count;
    uint32_t staff_count;
    uint32_t market_share_x100;
    uint32_t plan_steps;
    CompetitorAction last_action;
} CompetitorAIState;

/*
 * Customer state machine from Object_UpdateCustomerQueue (0x409D80) and the
 * 10 ms worker timers: walk 260, production 180, service 80. Competitor state
 * mirrors the AI plan fields used by AI_InitActionPlan (0x502CE0),
 * AI_GetMaxPlanSteps (0x4E2C40) and AI_SumPlanSteps (0x4E2CA0).
 */
void customer_ai_init(CustomerAIState *state);
bool customer_ai_enqueue(CustomerAIState *state, uint32_t party_size);
CustomerPhase customer_ai_visit_state(const CustomerAIState *state);
CustomerAIEvents customer_ai_advance_ticks(CustomerAIState *state, uint32_t ticks);

void competitor_ai_init(CompetitorAIState *state, uint32_t company_slot);
void competitor_ai_update(CompetitorAIState *state, double cash, uint32_t branches,
                          uint32_t staff, uint32_t market_share_x100,
                          uint32_t plan_steps);
void competitor_ai_record_action(CompetitorAIState *state, CompetitorAction action);

#endif
