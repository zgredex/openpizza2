#ifndef PC2_RECONSTRUCTED_RATING_STATE_H
#define PC2_RECONSTRUCTED_RATING_STATE_H

#include <stdbool.h>
#include <stdint.h>

#include <stdbool.h>
#include <stdint.h>

/*
 * Customer-group rating composition recovered from
 * Branch_GetCustomerGroupRating (0x47A3B0), Branch_GetMenuRating (0x478320)
 * and the branch-score table rule in Rating_ComputeBranchScores (0x478F60).
 */
int32_t rating_city_adjust(int32_t rating, int32_t city_field_5c,
                           int32_t city_field_44);
int32_t rating_branch_score(int32_t value, int32_t baseline);
int32_t branch_customer_group_rating(int32_t stats_average8,
                                     int32_t building_rating,
                                     int32_t menu_rating, int32_t price_rating,
                                     bool has_price, int32_t building_score);

#endif
