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

int main(void) {
    test_profit_accounting();
    test_close_period_accumulates();
    puts("branch operations reconstruction: OK");
    return 0;
}
