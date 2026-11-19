#include "value_state.h"

#include <math.h>
#include <stddef.h>

void value_state_init(ValueApproachState *state, double value) {
    if (state == NULL) {
        return;
    }
    state->value = value;
    state->dirty = 0;
}

bool value_approach(ValueApproachState *state, double step, double target) {
    if (state == NULL) {
        return false;
    }
    if (target > 0.0) {
        if (state->value >= target) {
            return false;
        }
        double next = state->value + step;
        if (target < next) {
            state->value = target;
        } else {
            state->value = next;
        }
        state->dirty = 1;
        return true;
    }
    if (target < 0.0) {
        if (state->value <= target) {
            return false;
        }
        double next = state->value + step;
        if (next < target) {
            state->value = target;
        } else {
            state->value = next;
        }
        state->dirty = 1;
        return true;
    }
    return false;
}

void value_state_decay_hour(ValueApproachState *state) {
    if (state == NULL) {
        return;
    }
    if (state->dirty == 0) {
        if (state->value > 0.0) {
            state->value -= 4.0;
            if (state->value < 0.0) {
                state->value = 0.0;
            }
        } else if (state->value < 0.0) {
            state->value += 2.0;
            if (state->value > 0.0) {
                state->value = 0.0;
            }
        }
    }
    state->dirty = 0;
}

int32_t game_adjusted_value(int32_t base_value, int32_t animated_value,
                            int32_t city_event_bonus, bool human_player,
                            uint8_t mission_field_c4, bool mission_field_1ac,
                            int32_t owner_slot, int32_t owner_coverage,
                            int32_t city_field_64, int32_t city_field_4c) {
    int32_t value = animated_value + city_event_bonus + base_value;
    if (human_player) {
        if (mission_field_c4 == 0 && mission_field_1ac) {
            value = 120;
        } else if (mission_field_c4 != 0) {
            value = value * 15 / 10;
        }
    }
    if (owner_slot != -1) {
        int32_t factor = 100 - (100 - owner_coverage) / 3;
        if (factor < 0) {
            factor = 0;
        }
        value = (int32_t)((double)value * sqrt((double)factor * 0.01));
        value = value * (100 + 3 * (city_field_64 + city_field_4c)) / 100;
    }
    if (base_value > 0 && value < 60) {
        value = 60;
    }
    if (value > 500) {
        value = 500;
    }
    return value;
}

int32_t company_get_percent_modifier(int32_t plan_type, int32_t budget) {
    if (plan_type == 1) {
        return budget * 100 / 10000;
    }
    if (plan_type == 2) {
        return budget * 100 / 5000;
    }
    return 100;
}

int32_t gameplan_effect_from_bar(int32_t plan_type, int32_t budget, int32_t bar,
                                 int32_t city_field_64, int32_t city_field_4c) {
    int32_t percent = company_get_percent_modifier(plan_type, budget);
    int32_t value = percent * (bar - 40) / 100 + 40;
    value = (100 - 3 * (city_field_64 + city_field_4c)) * value / 100;
    if (value < 0) {
        return 0;
    }
    if (value > 100) {
        return 100;
    }
    return value;
}

int32_t gameplan_average_effect(const int32_t bars[8], int32_t plan_type,
                                int32_t budget, int32_t city_field_64,
                                int32_t city_field_4c) {
    int32_t total = 0;
    for (int index = 0; index < 8; index++) {
        total += gameplan_effect_from_bar(plan_type, budget, bars[index],
                                          city_field_64, city_field_4c);
    }
    return total >> 3;
}

static const int8_t kPlanEffectTable[12][8] = {
    {6, 1, -2, -4, 2, -2, -6, -2},
    {5, 0, 3, 5, -5, -6, 6, -4},
    {4, 2, 0, 1, -2, -5, 0, 2},
    {-6, -2, 6, -6, 6, 2, 2, -3},
    {2, 4, -6, -3, 5, 1, -5, 0},
    {3, 5, -4, -2, 0, -3, -4, 5},
    {0, -4, 5, 2, -3, 4, 4, -6},
    {-3, -5, -5, 4, -6, 6, 5, 3},
    {1, 3, 2, 0, 4, 0, -2, -5},
    {-2, -3, 1, 3, 1, 3, 3, 1},
    {-5, -6, 4, -5, 3, 5, 1, 6},
    {-4, 6, -3, 6, -4, -4, -3, 4},
};

int32_t gameplan_company_category_metric(uint32_t flag, int32_t price,
                                         int32_t menu, int32_t building,
                                         int32_t stats) {
    switch (flag) {
    case 1:
        return price;
    case 2:
        return menu;
    case 4:
        return building;
    case 8:
        return stats;
    default:
        return 0;
    }
}

int32_t gameplan_category_effect(int32_t branch_count, int32_t media_type,
                                 uint32_t flags, int32_t category,
                                 int32_t percent, int32_t city_field_64,
                                 int32_t city_field_4c, bool competitor_present,
                                 const int32_t competitor_avg[4],
                                 const int32_t own_metrics[4]) {
    if (branch_count == 0) {
        return 0;
    }
    if (category < 0) {
        category = 0;
    }
    if (category > 7) {
        category = 7;
    }
    int32_t base = 40;
    if (media_type != 0) {
        int32_t media = media_type;
        if (media < 1) {
            media = 1;
        }
        if (media > 12) {
            media = 12;
        }
        base = (kPlanEffectTable[media - 1][category] + 8) * 5;
    }
    static const uint32_t kFlagBits[4] = {1, 2, 4, 8};
    for (int index = 0; index < 4; index++) {
        if ((flags & kFlagBits[index]) == 0) {
            continue;
        }
        int32_t lower = 45;
        int32_t upper = 55;
        if (competitor_present) {
            lower = competitor_avg[index] - 5;
            upper = competitor_avg[index] + 5;
        }
        int32_t own = own_metrics[index];
        if (own < lower) {
            base -= (lower - own) >> 2;
        }
        if (upper < own) {
            base += (own - upper) >> 1;
        }
    }
    int32_t value = percent * (base - 40) / 100 + 40;
    value = (100 - 3 * (city_field_64 + city_field_4c)) * value / 100;
    if (value < 0) {
        return 0;
    }
    if (value > 100) {
        return 100;
    }
    return value;
}
