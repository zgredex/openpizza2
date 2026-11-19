#include "rating_state.h"

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
