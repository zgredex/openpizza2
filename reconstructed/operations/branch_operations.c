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

void branch_operations_set_open_hours(BranchOperations *operations,
                                      const uint8_t hours[BRANCH_OPEN_HOURS]) {
    if (operations == NULL || hours == NULL) {
        return;
    }
    for (size_t index = 0; index < BRANCH_OPEN_HOURS; index++) {
        operations->open_hours[index] = hours[index] != 0 ? 1 : 0;
    }
}

bool branch_operations_is_open(const BranchOperations *operations, uint32_t hour) {
    if (operations == NULL || hour >= BRANCH_OPEN_HOURS) {
        return false;
    }
    return operations->open_hours[hour] != 0;
}

double branch_operations_hourly_wages(const BranchOperations *operations) {
    if (operations == NULL) {
        return 0.0;
    }
    return operations->wages / 24.0;
}

double branch_operations_hourly_advertising(const BranchOperations *operations) {
    if (operations == NULL) {
        return 0.0;
    }
    return operations->advertising / 24.0;
}

double branch_operations_negative_cash_interest(double cash) {
    if (cash >= 0.0) {
        return cash;
    }
    return cash * 1.004;
}

double branch_operations_process_hour(BranchOperations *operations, uint32_t hour,
                                      double sale_revenue, double ingredient_cost,
                                      double *cash) {
    if (operations == NULL || cash == NULL) {
        return 0.0;
    }
    double delta = -branch_operations_hourly_wages(operations) -
                   branch_operations_hourly_advertising(operations);
    if (branch_operations_is_open(operations, hour)) {
        double profit = sale_revenue - ingredient_cost;
        if (profit != 0.0) {
            operations->revenue += sale_revenue;
            operations->ingredient_cost += ingredient_cost;
            operations->sales += 1;
            delta += profit;
        }
    }
    *cash += delta;
    *cash = branch_operations_negative_cash_interest(*cash);
    return *cash;
}

int32_t game_compute_player_salary(int32_t player_class, int32_t field_c20,
                                   int32_t city_field_58, int32_t city_field_40) {
    int32_t base = 0;
    if (player_class == 1 && field_c20 > 4) {
        base = 20000;
    } else if (player_class == 2 && field_c20 > 5) {
        base = 40000;
    } else {
        return -1;
    }
    return ((10 - city_field_58 - city_field_40) * base * 10) / 100;
}

size_t branch_collect_unprofitable(const BranchOperationProfit *branches,
                                   size_t branch_count,
                                   BranchOperationProfit *result,
                                   size_t capacity) {
    if (branches == NULL || result == NULL || branch_count == 0 || capacity == 0) {
        return 0;
    }
    BranchOperationProfit sorted[64];
    if (branch_count > sizeof(sorted) / sizeof(sorted[0])) {
        branch_count = sizeof(sorted) / sizeof(sorted[0]);
    }
    for (size_t index = 0; index < branch_count; index++) {
        sorted[index] = branches[index];
    }
    for (size_t index = 1; index < branch_count; index++) {
        BranchOperationProfit value = sorted[index];
        size_t move = index;
        while (move > 0 && sorted[move - 1].profit > value.profit) {
            sorted[move] = sorted[move - 1];
            move -= 1;
        }
        sorted[move] = value;
    }
    int64_t total = 0;
    for (size_t index = 0; index < branch_count; index++) {
        total += sorted[index].profit;
    }
    int32_t average = (int32_t)(total / (int64_t)branch_count);
    if (average <= 0) {
        return 0;
    }
    int32_t threshold = average / 2;
    size_t collected = 0;
    for (size_t index = 0; index < branch_count && collected < capacity; index++) {
        if (sorted[index].profit < threshold) {
            result[collected++] = sorted[index];
        }
    }
    return collected;
}
