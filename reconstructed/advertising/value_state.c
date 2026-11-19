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
