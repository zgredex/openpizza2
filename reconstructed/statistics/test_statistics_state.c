#include "statistics_state.h"

#include <assert.h>
#include <stdio.h>

static void test_company_overview(void) {
    StatisticsState state;
    statistics_state_init(&state);
    assert(state.page == STATISTICS_PAGE_OVERVIEW);
    statistics_set_page(&state, STATISTICS_PAGE_BALANCE);
    assert(state.page == STATISTICS_PAGE_BALANCE);
    statistics_set_page(&state, STATISTICS_PAGE_BRANCH_BALANCE);
    assert(state.page == STATISTICS_PAGE_BRANCH_BALANCE);

    const StatisticsBuilding buildings[] = {
        {0, false, true},
        {1, true, true},
        {2, true, true},
        {1, true, false},
    };
    const StatisticsWarehouse warehouses[] = {
        {3, true},
        {1, false},
    };
    const CompanyInput companies[] = {
        {0, 3, 40, 1000, true},
        {1, 5, 30, 600, true},
        {2, 3, 30, 400, true},
        {3, 0, 0, 0, false},
    };

    statistics_fill_company_overview(&state, buildings, 4, warehouses, 2, companies, 4, 0);
    const CompanyOverview *overview = &state.overview;
    assert(overview->owned_buildings == 2);
    assert(overview->rented_buildings == 1);
    assert(overview->owned_value ==
           (2 + 1) * 0x5dc + (3 + 1) * 0x5dc + (1 + 1) * 0x5dc);
    assert(overview->rented_value == (0 + 1) * 600 + (1 + 1) * 600);
    assert(overview->warehouses == 2);
    assert(overview->company_value == 1000);
    assert(overview->player_c20 == 3);
    assert(overview->player_field60 == 40);
    assert(overview->share_x100 == 5000);
    assert(overview->rank_x1000 == 10000);
}

static void test_branch_balance(void) {
    StatisticsState state;
    statistics_state_init(&state);
    statistics_add_branch_balance(&state, 13694, 100, 60);
    statistics_add_branch_balance(&state, 13695, 40, 50);
    assert(state.branch_count == 2);
    assert(state.branches[0].profit == 40);
    assert(state.branches[1].profit == -10);
    assert(statistics_total_branch_profit(&state) == 30);
}

static void test_player_aggregate(void) {
    const StatisticsBranchAggregate branches[2] = {
        {.customers = 100, .profit = 60, .ratio = 2},
        {.customers = 50, .profit = 40, .ratio = 1},
    };
    StatisticsPlayerAggregate aggregate;
    statistics_compute_player_aggregate(branches, 2, true, true, true,
                                        &aggregate);
    assert(aggregate.customer_total == 150);
    assert(aggregate.customer_max == 100);
    assert(aggregate.customer_score == 5001);
    assert(aggregate.profit_total == 100);
    assert(aggregate.profit_max == 60);
    assert(aggregate.profit_score == 5010);
    assert(aggregate.ratio_total == 3);
    assert(aggregate.ratio_max == 2);
    assert(aggregate.ratio_score == 6500);

    statistics_compute_player_aggregate(branches, 2, false, false, false,
                                        &aggregate);
    assert(aggregate.customer_score == 1);
    assert(aggregate.profit_score == 10);
    assert(aggregate.ratio_score == 1500);

    const StatisticsBranchAggregate empty[1] = {{0, 0, 0}};
    statistics_compute_player_aggregate(empty, 1, true, true, true, &aggregate);
    assert(aggregate.customer_score == 0);
    assert(aggregate.profit_score == 0);
    assert(aggregate.ratio_score == 0);
}

int main(void) {
    test_company_overview();
    test_branch_balance();
    test_player_aggregate();
    puts("statistics state reconstruction: OK");
    return 0;
}
