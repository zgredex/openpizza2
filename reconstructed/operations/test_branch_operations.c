#include "branch_operations.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

static void test_profit_accounting(void) {
    BranchOperations operations;
    branch_operations_init(&operations, 5730.0);
    assert(operations.rent == 5730.0);
    assert(operations.sales == 0);

    branch_operations_record_sale(&operations, 13.80, 0.3794752876341939);
    branch_operations_set_payroll(&operations, 3, 1.0);
    branch_operations_set_advertising(&operations, 50.0);
    double profit = branch_operations_compute_profit(&operations);
    assert_close(operations.wages, 36.0, 1e-12);
    assert_close(profit, 13.80 - 0.3794752876341939 - 36.0 - 5730.0 - 50.0, 1e-9);
    assert(operations.sales == 1);
    assert(operations.staff_count == 3);
}

static void test_close_period_accumulates(void) {
    BranchOperations operations;
    branch_operations_init(&operations, 0.0);
    branch_operations_record_sale(&operations, 1000.0, 100.0);
    branch_operations_set_payroll(&operations, 10, 2.5);
    branch_operations_set_advertising(&operations, 50.0);
    assert_close(operations.wages, 300.0, 1e-12);
    double accumulated = branch_operations_close_period(&operations);
    assert_close(accumulated, 1000.0 - 100.0 - 300.0 - 50.0, 1e-9);
    assert(operations.revenue == 0.0);
    assert(operations.sales == 0);
    assert(operations.staff_count == 0);
    assert(operations.rent == 0.0);

    branch_operations_record_sale(&operations, 200.0, 20.0);
    branch_operations_set_payroll(&operations, 1, 1.0);
    accumulated = branch_operations_close_period(&operations);
    assert_close(accumulated, 550.0 + 168.0, 1e-9);
}

static void test_hourly_economy(void) {
    BranchOperations operations;
    branch_operations_init(&operations, 0.0);
    branch_operations_set_payroll(&operations, 3, 1.0);
    branch_operations_set_advertising(&operations, 240.0);
    assert_close(branch_operations_hourly_wages(&operations), 1.5, 1e-12);
    assert_close(branch_operations_hourly_advertising(&operations), 10.0, 1e-12);

    uint8_t hours[BRANCH_OPEN_HOURS] = {0};
    for (uint32_t hour = 10; hour <= 20; hour++) {
        hours[hour] = 1;
    }
    branch_operations_set_open_hours(&operations, hours);
    assert(branch_operations_is_open(&operations, 12));
    assert(!branch_operations_is_open(&operations, 3));
    assert(!branch_operations_is_open(&operations, 24));

    double cash = 1000.0;
    assert_close(branch_operations_process_hour(&operations, 12, 50.0, 20.0, &cash),
                 1018.5, 1e-12);
    assert(operations.sales == 1);
    assert_close(operations.revenue, 50.0, 1e-12);
    assert_close(branch_operations_process_hour(&operations, 3, 50.0, 20.0, &cash),
                 1007.0, 1e-12);
    assert(operations.sales == 1);

    double negative = -1000.0;
    assert_close(branch_operations_process_hour(&operations, 3, 0.0, 0.0,
                                                &negative),
                 -1015.546, 1e-9);
    assert_close(branch_operations_negative_cash_interest(500.0), 500.0, 1e-12);
}

static void test_player_salary(void) {
    assert(game_compute_player_salary(1, 5, 3, 2) == 10000);
    assert(game_compute_player_salary(2, 6, 3, 2) == 20000);
    assert(game_compute_player_salary(1, 4, 3, 2) == -1);
    assert(game_compute_player_salary(2, 5, 3, 2) == -1);
    assert(game_compute_player_salary(3, 9, 3, 2) == -1);
    assert(game_compute_player_salary(1, 9, 4, 4) == 4000);
}

static void test_unprofitable_branches(void) {
    const BranchOperationProfit branches[] = {
        {1, 1000}, {2, 400}, {3, 100}, {4, 500},
    };
    BranchOperationProfit result[4];
    size_t count = branch_collect_unprofitable(branches, 4, result, 4);
    assert(count == 1);
    assert(result[0].branch_id == 3);
    assert(result[0].profit == 100);

    const BranchOperationProfit weak[] = {{5, 50}, {6, -10}, {7, 20}};
    count = branch_collect_unprofitable(weak, 3, result, 4);
    assert(count == 1);
    assert(result[0].branch_id == 6);

    const BranchOperationProfit healthy[] = {{8, 100}, {9, 200}};
    assert(branch_collect_unprofitable(healthy, 2, result, 4) == 0);
    assert(branch_collect_unprofitable(branches, 4, result, 1) == 1);
}

int main(void) {
    test_profit_accounting();
    test_hourly_economy();
    test_player_salary();
    test_unprofitable_branches();
    test_close_period_accumulates();
    puts("branch operations reconstruction: OK");
    return 0;
}
