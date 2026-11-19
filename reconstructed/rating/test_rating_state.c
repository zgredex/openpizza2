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

int main(void) {
    test_city_adjust();
    test_branch_score();
    test_group_rating();
    puts("rating state reconstruction: OK");
    return 0;
}
