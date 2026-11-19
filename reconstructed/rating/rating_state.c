#include "rating_state.h"

#include <stddef.h>

static int32_t clamp_0_100(int32_t value) {
    if (value < 0) {
        return 0;
    }
    if (value > 100) {
        return 100;
    }
    return value;
}

int32_t rating_city_adjust(int32_t rating, int32_t city_field_5c,
                           int32_t city_field_44) {
    int32_t adjusted = ((100 - 3 * (city_field_5c + city_field_44)) * rating) / 100;
    return clamp_0_100(adjusted);
}

int32_t rating_branch_score(int32_t value, int32_t baseline) {
    int32_t score = value < baseline ? (value - baseline) * 3 + 100 : 100;
    return clamp_0_100(score);
}

int32_t branch_customer_group_rating(int32_t stats_average8,
                                     int32_t building_rating,
                                     int32_t menu_rating, int32_t price_rating,
                                     bool has_price, int32_t building_score) {
    int32_t score = stats_average8 + building_rating + menu_rating;
    int32_t divisor = 3;
    if (has_price) {
        score += price_rating;
        divisor = 4;
    }
    int32_t result = building_score + score / divisor;
    return clamp_0_100(result);
}

int32_t rating_branch_scores(const int32_t values[8],
                             const int32_t baselines[8], int32_t scores[8]) {
    if (values == NULL || baselines == NULL || scores == NULL) {
        return 0;
    }
    for (int index = 0; index < 8; index++) {
        scores[index] = rating_branch_score(values[index], baselines[index]);
    }
    return 8;
}

double rating_market_bonus_factor(bool has_market, int32_t market_value,
                                  int32_t composite) {
    if (!has_market) {
        return 1.0;
    }
    int32_t value = market_value >> 1;
    if (value < 0) {
        int32_t adjustment = composite / 20;
        if (adjustment < 1) {
            value += adjustment;
        }
    }
    return (double)(value + 100) * 0.01;
}

int32_t rating_group_average8(const int32_t ratings[8], int32_t group) {
    if (ratings == NULL) {
        return 0;
    }
    int32_t value;
    if (group == -1) {
        int32_t total = 0;
        for (int index = 0; index < 8; index++) {
            total += ratings[index];
        }
        value = total / 8;
    } else if (group >= 0 && group < 8) {
        value = ratings[group];
    } else {
        return 0;
    }
    return clamp_0_100(value);
}

int32_t branch_price_comparison_rating(int32_t effect, int32_t city_field_5c,
                                       int32_t city_field_44, bool has_plan,
                                       bool *has_price) {
    if (has_price != NULL) {
        *has_price = has_plan;
    }
    if (!has_plan) {
        return 0;
    }
    return rating_city_adjust(effect, city_field_5c, city_field_44);
}

int32_t rating_stats_average8(const int32_t ratings[8], int32_t group,
                              int32_t city_field_5c, int32_t city_field_44) {
    return rating_city_adjust(rating_group_average8(ratings, group),
                              city_field_5c, city_field_44);
}

int32_t rating_menu_rating(const int32_t ratings[8], int32_t group,
                           int32_t city_field_5c, int32_t city_field_44) {
    return rating_stats_average8(ratings, group, city_field_5c, city_field_44);
}
