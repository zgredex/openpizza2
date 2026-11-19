#ifndef PC2_RECONSTRUCTED_VALUE_STATE_H
#define PC2_RECONSTRUCTED_VALUE_STATE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct ValueApproachState {
    double value;
    uint8_t dirty;
} ValueApproachState;

/*
 * Advertising value record recovered from Value_Approach (0x4E4670),
 * Game_DecayCityDateBonus (0x4E46F0) and Game_GetAdjustedValue (0x4E4490).
 * The animated value is the branch's customer-proximity radius component.
 */
void value_state_init(ValueApproachState *state, double value);
bool value_approach(ValueApproachState *state, double step, double target);
void value_state_decay_hour(ValueApproachState *state);

int32_t company_get_percent_modifier(int32_t plan_type, int32_t budget);
int32_t gameplan_effect_from_bar(int32_t plan_type, int32_t budget, int32_t bar,
                                 int32_t city_field_64, int32_t city_field_4c);
int32_t gameplan_company_category_metric(uint32_t flag, int32_t price,
                                         int32_t menu, int32_t building,
                                         int32_t stats);
int32_t gameplan_category_effect(int32_t branch_count, int32_t media_type,
                                 uint32_t flags, int32_t category,
                                 int32_t percent, int32_t city_field_64,
                                 int32_t city_field_4c, bool competitor_present,
                                 const int32_t competitor_avg[4],
                                 const int32_t own_metrics[4]);
#define ADVERTISING_MAX_PLANS 16
typedef struct PlanAllocation {
    int32_t type;
    int32_t effect;
    int32_t branch_count;
    bool fixed;
    int32_t score;
    int32_t cap;
    int32_t share;
    bool active;
} PlanAllocation;

void company_allocate_plan_budget(PlanAllocation *plans, size_t plan_count,
                                  int32_t pool, int32_t company_branch_count);

int32_t gameplan_average_effect(const int32_t bars[8], int32_t plan_type,
                                int32_t budget, int32_t city_field_64,
                                int32_t city_field_4c);

int32_t game_adjusted_value(int32_t base_value, int32_t animated_value,
                            int32_t city_event_bonus, bool human_player,
                            uint8_t mission_field_c4, bool mission_field_1ac,
                            int32_t owner_slot, int32_t owner_coverage,
                            int32_t city_field_64, int32_t city_field_4c);

#endif
