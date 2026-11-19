#ifndef PC2_RECONSTRUCTED_BRANCH_OPERATIONS_H
#define PC2_RECONSTRUCTED_BRANCH_OPERATIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define BRANCH_OPEN_HOURS 24u

typedef struct BranchOperationProfit {
    uint32_t branch_id;
    int32_t profit;
} BranchOperationProfit;

typedef struct BranchOperations {
    double revenue;
    double ingredient_cost;
    double wages;
    double rent;
    double advertising;
    double profit;
    double accumulated_profit;
    uint32_t sales;
    uint32_t staff_count;
    uint8_t open_hours[BRANCH_OPEN_HOURS];
} BranchOperations;

/*
 * Period accounting layer that connects the branch sale model, personnel wages
 * and statistics screens. Wage scaling follows the existing simulator model:
 * total_staff * 12 * wage_scale.
 */
void branch_operations_init(BranchOperations *operations, double monthly_rent);
void branch_operations_record_sale(BranchOperations *operations, double revenue,
                                   double ingredient_cost);
void branch_operations_set_payroll(BranchOperations *operations,
                                   uint32_t staff_count, double wage_scale);
void branch_operations_set_advertising(BranchOperations *operations,
                                       double amount);
double branch_operations_compute_profit(BranchOperations *operations);
double branch_operations_close_period(BranchOperations *operations);

/* Hourly path from Branch_ProcessHour (0x4773A0) and
 * Company_ProcessHourlyTick (0x4E0200): monthly wages and advertising are
 * paid as 1/24 shares, negative cash accrues 0.4% interest per hour, and sales
 * only accrue while the branch is open. */
void branch_operations_set_open_hours(BranchOperations *operations,
                                      const uint8_t hours[BRANCH_OPEN_HOURS]);
bool branch_operations_is_open(const BranchOperations *operations, uint32_t hour);
double branch_operations_hourly_wages(const BranchOperations *operations);
double branch_operations_hourly_advertising(const BranchOperations *operations);
double branch_operations_negative_cash_interest(double cash);
double branch_operations_process_hour(BranchOperations *operations, uint32_t hour,
                                      double sale_revenue, double ingredient_cost,
                                      double *cash);

/* Game_ComputePlayerSalary (0x4E3820) for player class 1/2. */
int32_t game_compute_player_salary(int32_t player_class, int32_t field_c20,
                                   int32_t city_field_58, int32_t city_field_40);

/* Company_CollectUnprofitableBranches (0x4E1BC0): sort by profit, then keep
 * branches below half the company average when that average is positive. */
size_t branch_collect_unprofitable(const BranchOperationProfit *branches,
                                   size_t branch_count,
                                   BranchOperationProfit *result,
                                   size_t capacity);

#endif
