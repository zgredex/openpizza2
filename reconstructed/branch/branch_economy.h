#ifndef PC2_RECONSTRUCTED_BRANCH_ECONOMY_H
#define PC2_RECONSTRUCTED_BRANCH_ECONOMY_H

#include <stdbool.h>
#include <stdint.h>

/*
 * Values shared with the Rust simulator and the REA-backed notes:
 * - Branch_ComputeRecipePrice (0x513BF0) for the menu price formula;
 * - Object_UpdateCustomerQueue (0x409D80) for the lost-customer counter;
 * - the one-serving sale arithmetic used by the playable branch view.
 */
#define BRANCH_START_CASH 10000.0
#define BRANCH_START_STOCK 400.0
#define BRANCH_STOCK_CAPACITY 400.0
#define BRANCH_UNIT_COST 4.0
#define BRANCH_MARKET_PRICE_FACTOR 0.09486882190854848
#define BRANCH_RATING 50
#define BRANCH_STEP_MINUTES 15

typedef enum BranchStepOutcome {
    BRANCH_CLOSED = 0,
    BRANCH_STOCK_OUT = 1,
    BRANCH_SALE = 2,
} BranchStepOutcome;

typedef struct BranchSale {
    uint32_t clock_minutes;
    double price;
    uint32_t servings;
    double revenue;
    double stock_cost;
    double market_cost;
    double cash_delta;
} BranchSale;

typedef struct BranchEconomy {
    bool open;
    double price;
    double cash;
    double starting_cash;
    double stock;
    uint32_t clock_minutes;
    uint32_t servings_sold;
    uint32_t customers_served;
    uint32_t customers_lost;
    uint32_t sales;
    uint32_t steps;
    bool has_last_sale;
    BranchSale last_sale;
} BranchEconomy;

void branch_economy_init(BranchEconomy *branch);
void branch_set_open(BranchEconomy *branch, bool open);
void branch_set_price(BranchEconomy *branch, double price);
void branch_set_starting_cash(BranchEconomy *branch, double cash);
void branch_record_lost_customer(BranchEconomy *branch);

double branch_recipe_price(double base_price, double price_percent,
                           double building_value, double price_offset);

BranchStepOutcome branch_settle_sale_at(BranchEconomy *branch,
                                        uint32_t clock_minutes);
BranchStepOutcome branch_step(BranchEconomy *branch);

#endif
