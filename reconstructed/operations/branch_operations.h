#ifndef PC2_RECONSTRUCTED_BRANCH_OPERATIONS_H
#define PC2_RECONSTRUCTED_BRANCH_OPERATIONS_H

#include <stdint.h>

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

#endif
