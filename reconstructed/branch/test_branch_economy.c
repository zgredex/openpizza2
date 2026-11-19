#include "branch_economy.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

static void test_defaults_and_recipe_price(void) {
    BranchEconomy branch;
    branch_economy_init(&branch);
    assert(!branch.open);
    assert_close(branch.price, 12.0, 0.0);
    assert_close(branch.cash, 10000.0, 0.0);
    assert_close(branch.stock, 400.0, 0.0);
    assert(branch.clock_minutes == 600);
    assert(!branch.has_last_sale);

    assert_close(branch_recipe_price(12.0, 100.0, 1.0, 0.0), 12.0, 1e-12);
    assert_close(branch_recipe_price(10.0, 110.0, 1.2, 0.5), 13.7, 1e-12);
}

static void test_first_sale_matches_rust_model(void) {
    BranchEconomy branch;
    branch_economy_init(&branch);
    branch_set_open(&branch, true);

    BranchStepOutcome outcome = branch_settle_sale_at(&branch, 600);
    assert(outcome == BRANCH_SALE);
    assert(branch.has_last_sale);
    assert(branch.steps == 0);
    assert(branch.sales == 1);
    assert(branch.servings_sold == 1);
    assert(branch.customers_served == 1);
    assert(branch.customers_lost == 0);
    assert_close(branch.stock, 399.0, 0.0);
    assert_close(branch.last_sale.revenue, 13.80, 1e-12);
    assert_close(branch.last_sale.stock_cost, 4.0, 1e-12);
    assert_close(branch.last_sale.market_cost, 0.3794752876341939, 1e-12);
    assert_close(branch.last_sale.cash_delta, 13.420524712365806, 1e-12);
    assert_close(branch.cash, 10013.420524712365806, 1e-9);
    assert(branch.last_sale.clock_minutes == 600);
    assert(branch.last_sale.servings == 1);
}

static void test_closed_and_stock_out(void) {
    BranchEconomy branch;
    branch_economy_init(&branch);
    assert(branch_settle_sale_at(&branch, 600) == BRANCH_CLOSED);
    assert(branch.sales == 0);

    branch_set_open(&branch, true);
    branch.stock = 0.5;
    assert(branch_settle_sale_at(&branch, 600) == BRANCH_STOCK_OUT);
    assert(branch.customers_lost == 1);
    assert(branch.sales == 0);
    assert_close(branch.cash, 10000.0, 0.0);
}

static void test_step_advances_clock(void) {
    BranchEconomy branch;
    branch_economy_init(&branch);
    branch_set_open(&branch, true);
    BranchStepOutcome outcome = branch_step(&branch);
    assert(outcome == BRANCH_SALE);
    assert(branch.steps == 1);
    assert(branch.clock_minutes == 615);
    assert(branch.last_sale.clock_minutes == 615);
}

static void test_price_clamp(void) {
    BranchEconomy branch;
    branch_economy_init(&branch);
    branch_set_price(&branch, 0.0);
    assert_close(branch.price, 0.01, 0.0);
    branch_set_price(&branch, 5000.0);
    assert_close(branch.price, 999.99, 0.0);
}

int main(void) {
    test_defaults_and_recipe_price();
    test_first_sale_matches_rust_model();
    test_closed_and_stock_out();
    test_step_advances_clock();
    test_price_clamp();
    puts("branch economy reconstruction: OK");
    return 0;
}
