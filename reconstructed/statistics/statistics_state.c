#include "statistics_state.h"

#include <string.h>

#define OWNED_VALUE_MULTIPLIER 0x5dc
#define RENTED_VALUE_MULTIPLIER 600

void statistics_state_init(StatisticsState *state) {
    if (state == NULL) {
        return;
    }
    memset(state, 0, sizeof(*state));
    state->page = STATISTICS_PAGE_OVERVIEW;
    state->selected_company = 0;
}

void statistics_set_page(StatisticsState *state, StatisticsPage page) {
    if (state != NULL) {
        state->page = page;
    }
}

void statistics_set_selected_company(StatisticsState *state, int32_t slot) {
    if (state != NULL && slot >= 0) {
        state->selected_company = slot;
    }
}

void statistics_fill_company_overview(StatisticsState *state,
                                      const StatisticsBuilding *buildings,
                                      int building_count,
                                      const StatisticsWarehouse *warehouses,
                                      int warehouse_count,
                                      const CompanyInput *companies,
                                      int company_count,
                                      int32_t player_slot) {
    if (state == NULL) {
        return;
    }
    CompanyOverview *overview = &state->overview;
    memset(overview, 0, sizeof(*overview));

    for (int index = 0; index < building_count; index++) {
        const StatisticsBuilding *building = &buildings[index];
        if (!building->player_controlled) {
            continue;
        }
        if (building->owned) {
            overview->owned_buildings += 1;
            overview->owned_value +=
                ((int32_t)building->size + 1) * OWNED_VALUE_MULTIPLIER;
        } else {
            overview->rented_buildings += 1;
            overview->rented_value +=
                ((int32_t)building->size + 1) * RENTED_VALUE_MULTIPLIER;
        }
    }

    for (int index = 0; index < warehouse_count; index++) {
        const StatisticsWarehouse *warehouse = &warehouses[index];
        int32_t value = (warehouse->field_2c + 1) *
                        (warehouse->owned ? OWNED_VALUE_MULTIPLIER
                                          : RENTED_VALUE_MULTIPLIER);
        overview->warehouses += 1;
        if (warehouse->owned) {
            overview->owned_value += value;
        } else {
            overview->rented_value += value;
        }
    }

    const CompanyInput *player = NULL;
    int32_t total_statistic = 0;
    int32_t rank = 6;
    for (int index = 0; index < company_count; index++) {
        const CompanyInput *company = &companies[index];
        if (!company->active) {
            continue;
        }
        total_statistic += company->statistic;
        if (company->slot == player_slot) {
            player = company;
        }
    }
    if (player != NULL) {
        for (int index = 0; index < company_count; index++) {
            const CompanyInput *company = &companies[index];
            if (!company->active || company->slot == player_slot) {
                continue;
            }
            if (player->c20 < company->c20) {
                rank -= 1;
            } else if (player->c20 == company->c20 &&
                       company->field_60 < player->field_60) {
                rank -= 1;
            }
        }
        overview->company_value = player->statistic;
        overview->player_c20 = player->c20;
        overview->player_field60 = player->field_60;
        overview->share_x100 =
            total_statistic > 0 ? (player->statistic * 100 / total_statistic) * 100 : 0;
        overview->rank_x1000 = (rank + player->c20 * 2) * 1000;
    }
}

void statistics_add_branch_balance(StatisticsState *state, uint32_t branch_id,
                                   int32_t revenue, int32_t costs) {
    if (state == NULL || state->branch_count >= STATISTICS_MAX_BRANCHES) {
        return;
    }
    BranchBalanceEntry *entry = &state->branches[state->branch_count];
    entry->branch_id = branch_id;
    entry->revenue = revenue;
    entry->costs = costs;
    entry->profit = revenue - costs;
    state->branch_count += 1;
}

int32_t statistics_total_branch_profit(const StatisticsState *state) {
    if (state == NULL) {
        return 0;
    }
    int32_t total = 0;
    for (int index = 0; index < state->branch_count; index++) {
        total += state->branches[index].profit;
    }
    return total;
}

void statistics_compute_player_aggregate(
    const StatisticsBranchAggregate *branches, size_t branch_count,
    bool beats_customers, bool beats_profit, bool beats_ratio,
    StatisticsPlayerAggregate *aggregate) {
    if (aggregate == NULL) {
        return;
    }
    memset(aggregate, 0, sizeof(*aggregate));
    if (branches == NULL) {
        return;
    }
    for (size_t index = 0; index < branch_count; index++) {
        aggregate->customer_total += branches[index].customers;
        if (aggregate->customer_max < branches[index].customers) {
            aggregate->customer_max = branches[index].customers;
        }
        aggregate->profit_total += branches[index].profit;
        if (aggregate->profit_max < branches[index].profit) {
            aggregate->profit_max = branches[index].profit;
        }
        aggregate->ratio_total += branches[index].ratio;
        if (aggregate->ratio_max < branches[index].ratio) {
            aggregate->ratio_max = branches[index].ratio;
        }
    }
    int32_t customer_flag = aggregate->customer_total != 0 && beats_customers;
    int32_t profit_flag = aggregate->profit_total != 0 && beats_profit;
    int32_t ratio_flag = aggregate->ratio_total != 0 && beats_ratio;
    aggregate->customer_score = aggregate->customer_total / 100 + customer_flag * 5000;
    aggregate->profit_score = aggregate->profit_total / 10 + profit_flag * 5000;
    aggregate->ratio_score = (aggregate->ratio_total + ratio_flag * 10) * 500;
}
