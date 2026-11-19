#include "rating_state.h"

#include <assert.h>
#include <stdio.h>

static void test_city_adjust(void) {
    assert(rating_city_adjust(80, 0, 0) == 80);
    assert(rating_city_adjust(80, 5, 5) == 56);
    assert(rating_city_adjust(120, 0, 0) == 100);
    assert(rating_city_adjust(-5, 0, 0) == 0);
    assert(rating_city_adjust(100, 20, 20) == 0);
}

static void test_branch_score(void) {
    assert(rating_branch_score(50, 40) == 100);
    assert(rating_branch_score(10, 40) == 10);
    assert(rating_branch_score(20, 40) == 40);
    assert(rating_branch_score(0, 0) == 100);
    assert(rating_branch_score(-100, 40) == 0);
}

static void test_group_rating(void) {
    assert(branch_customer_group_rating(60, 70, 80, 0, false, 10) == 80);
    assert(branch_customer_group_rating(60, 70, 80, 90, true, 10) == 85);
    assert(branch_customer_group_rating(100, 100, 100, 100, true, 100) == 100);
    assert(branch_customer_group_rating(0, 0, 0, 0, false, 0) == 0);
    assert(branch_customer_group_rating(30, 30, 30, 0, false, 20) == 50);
}

static void test_branch_scores(void) {
    const int32_t values[8] = {10, 40, 19, 41, 0, 100, 20, 30};
    const int32_t baselines[8] = {40, 40, 20, 40, 30, 50, 60, 30};
    int32_t scores[8] = {0};
    assert(rating_branch_scores(values, baselines, scores) == 8);
    assert(scores[0] == 10);
    assert(scores[1] == 100);
    assert(scores[2] == 97);
    assert(scores[3] == 100);
    assert(scores[4] == 10);
    assert(scores[5] == 100);
    assert(scores[6] == 0);
    assert(scores[7] == 100);
    assert(rating_branch_scores(NULL, baselines, scores) == 0);
}

static void test_price_rating(void) {
    const int32_t ratings[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    assert(rating_group_average8(ratings, -1) == 45);
    assert(rating_group_average8(ratings, 3) == 40);
    assert(rating_group_average8(ratings, 0) == 10);
    assert(rating_group_average8(NULL, -1) == 0);
    bool has_price = false;
    assert(branch_price_comparison_rating(80, 5, 5, false, &has_price) == 0);
    assert(!has_price);
    assert(branch_price_comparison_rating(80, 5, 5, true, &has_price) == 56);
    assert(has_price);
}

static void test_group_mean_city_adjust(void) {
    const int32_t ratings[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    assert(rating_stats_average8(ratings, -1, 0, 0) == 45);
    assert(rating_stats_average8(ratings, 3, 0, 0) == 40);
    assert(rating_stats_average8(ratings, -1, 5, 5) == 31);
    assert(rating_menu_rating(ratings, 3, 5, 5) == 28);
    assert(rating_stats_average8(NULL, -1, 0, 0) == 0);
}

static void test_market_bonus(void) {
    assert(rating_market_bonus_factor(false, 0, 0) == 1.0);
    assert(rating_market_bonus_factor(true, 20, 0) == 1.1);
    assert(rating_market_bonus_factor(true, -40, 10) == 0.8);
    assert(rating_market_bonus_factor(true, -40, 20) == 0.8);
    assert(rating_market_bonus_factor(true, 0, 20) == 1.0);
}

int main(void) {
    test_city_adjust();
    test_branch_score();
    test_group_rating();
    test_branch_scores();
    test_market_bonus();
    test_group_mean_city_adjust();
    test_price_rating();
    puts("rating state reconstruction: OK");
    return 0;
}
