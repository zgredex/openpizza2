#ifndef PC2_RECONSTRUCTED_STATISTICS_STATE_H
#define PC2_RECONSTRUCTED_STATISTICS_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define STATISTICS_MAX_BRANCHES 8

typedef enum StatisticsPage {
    STATISTICS_PAGE_OVERVIEW = 0,
    STATISTICS_PAGE_BALANCE = 1,
    STATISTICS_PAGE_BRANCH_BALANCE = 2,
} StatisticsPage;

typedef struct StatisticsBuilding {
    uint32_t size;
    bool owned;
    bool player_controlled;
} StatisticsBuilding;

typedef struct StatisticsWarehouse {
    int32_t field_2c;
    bool owned;
} StatisticsWarehouse;

typedef struct CompanyInput {
    int32_t slot;
    int32_t c20;
    int32_t field_60;
    int32_t statistic; /* g_game + 0xcb0 + slot*4 */
    bool active;
} CompanyInput;

typedef struct CompanyOverview {
    int32_t owned_buildings;
    int32_t rented_buildings;
    int32_t owned_value;
    int32_t rented_value;
    int32_t warehouses;
    int32_t hq_count;
    int32_t company_value;
    int32_t player_c20;
    int32_t player_field60;
    int32_t share_x100;
    int32_t rank_x1000;
} CompanyOverview;

typedef struct BranchBalanceEntry {
    uint32_t branch_id;
    int32_t revenue;
    int32_t costs;
    int32_t profit;
} BranchBalanceEntry;

typedef struct StatisticsState {
    StatisticsPage page;
    int32_t selected_company;
    int32_t quarter;
    CompanyOverview overview;
    int32_t branch_count;
    BranchBalanceEntry branches[STATISTICS_MAX_BRANCHES];
} StatisticsState;

/*
 * Reconstructed from Stats_Report_FillCompanyOverview (0x4DECF0),
 * Screen_StatisticsBalance (0x430FD0) and
 * Window_BuildStatisticsBranchBalancePage (0x433790).
 */
void statistics_state_init(StatisticsState *state);
void statistics_set_page(StatisticsState *state, StatisticsPage page);
void statistics_set_selected_company(StatisticsState *state, int32_t slot);
void statistics_fill_company_overview(StatisticsState *state,
                                      const StatisticsBuilding *buildings,
                                      int building_count,
                                      const StatisticsWarehouse *warehouses,
                                      int warehouse_count,
                                      const CompanyInput *companies,
                                      int company_count,
                                      int32_t player_slot);
void statistics_add_branch_balance(StatisticsState *state, uint32_t branch_id,
                                   int32_t revenue, int32_t costs);
int32_t statistics_total_branch_profit(const StatisticsState *state);

#endif
