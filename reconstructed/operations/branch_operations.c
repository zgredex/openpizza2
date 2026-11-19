#include "branch_operations.h"

#include <string.h>

void branch_operations_init(BranchOperations *operations, double monthly_rent) {
    if (operations == NULL) {
        return;
    }
    memset(operations, 0, sizeof(*operations));
    operations->rent = monthly_rent;
}

void branch_operations_record_sale(BranchOperations *operations, double revenue,
                                   double ingredient_cost) {
    if (operations == NULL) {
        return;
    }
    operations->revenue += revenue;
    operations->ingredient_cost += ingredient_cost;
    operations->sales += 1;
}

void branch_operations_set_payroll(BranchOperations *operations,
                                   uint32_t staff_count, double wage_scale) {
    if (operations == NULL) {
        return;
    }
    operations->staff_count = staff_count;
    operations->wages = (double)staff_count * 12.0 * wage_scale;
}

void branch_operations_set_advertising(BranchOperations *operations,
                                       double amount) {
    if (operations != NULL) {
        operations->advertising = amount;
    }
}

double branch_operations_compute_profit(BranchOperations *operations) {
    if (operations == NULL) {
        return 0.0;
    }
    operations->profit = operations->revenue - operations->ingredient_cost -
                         operations->wages - operations->rent -
                         operations->advertising;
    return operations->profit;
}

double branch_operations_close_period(BranchOperations *operations) {
    if (operations == NULL) {
        return 0.0;
    }
    double profit = branch_operations_compute_profit(operations);
    operations->accumulated_profit += profit;
    operations->revenue = 0.0;
    operations->ingredient_cost = 0.0;
    operations->wages = 0.0;
    operations->advertising = 0.0;
    operations->sales = 0;
    operations->staff_count = 0;
    return operations->accumulated_profit;
}
