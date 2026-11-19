#include "branch_economy.h"

#include <stddef.h>

void branch_economy_init(BranchEconomy *branch) {
    if (branch == NULL) {
        return;
    }
    *branch = (BranchEconomy){
        .open = false,
        .price = 12.0,
        .cash = BRANCH_START_CASH,
        .starting_cash = BRANCH_START_CASH,
        .stock = BRANCH_START_STOCK,
        .clock_minutes = 10 * 60,
        .servings_sold = 0,
        .customers_served = 0,
        .customers_lost = 0,
        .sales = 0,
        .steps = 0,
        .has_last_sale = false,
        .last_sale = {0},
    };
}

void branch_set_open(BranchEconomy *branch, bool open) {
    if (branch != NULL) {
        branch->open = open;
    }
}

void branch_set_price(BranchEconomy *branch, double price) {
    if (branch == NULL) {
        return;
    }
    if (price < 0.01) {
        price = 0.01;
    } else if (price > 999.99) {
        price = 999.99;
    }
    branch->price = price;
}

void branch_set_starting_cash(BranchEconomy *branch, double cash) {
    if (branch != NULL) {
        branch->starting_cash = cash;
        branch->cash = cash;
    }
}

void branch_record_lost_customer(BranchEconomy *branch) {
    if (branch != NULL) {
        branch->customers_lost += 1;
    }
}

double branch_recipe_price(double base_price, double price_percent,
                           double building_value, double price_offset) {
    return base_price * (price_percent * 0.01 * building_value) + price_offset;
}

BranchStepOutcome branch_settle_sale_at(BranchEconomy *branch,
                                        uint32_t clock_minutes) {
    if (branch == NULL) {
        return BRANCH_CLOSED;
    }
    if (!branch->open) {
        return BRANCH_CLOSED;
    }
    if (branch->stock < 1.0) {
        branch->customers_lost += 1;
        return BRANCH_STOCK_OUT;
    }

    const uint32_t servings = 1;
    const double tip = (BRANCH_RATING - 20) / 2.0;
    const double revenue = (100.0 + tip) * servings * branch->price * 0.01;
    const double stock_cost = BRANCH_UNIT_COST * servings;
    const double market_cost = stock_cost * BRANCH_MARKET_PRICE_FACTOR;
    const double cash_delta = revenue - market_cost;

    branch->stock -= servings;
    branch->servings_sold += servings;
    branch->customers_served += 1;
    branch->sales += 1;
    branch->cash += cash_delta;
    branch->has_last_sale = true;
    branch->last_sale = (BranchSale){
        .clock_minutes = clock_minutes,
        .price = branch->price,
        .servings = servings,
        .revenue = revenue,
        .stock_cost = stock_cost,
        .market_cost = market_cost,
        .cash_delta = cash_delta,
    };
    return BRANCH_SALE;
}

BranchStepOutcome branch_step(BranchEconomy *branch) {
    if (branch == NULL) {
        return BRANCH_CLOSED;
    }
    branch->steps += 1;
    branch->clock_minutes += BRANCH_STEP_MINUTES;
    return branch_settle_sale_at(branch, branch->clock_minutes);
}
