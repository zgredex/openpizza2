#include "city_state.h"

#include <string.h>

static void city_state_evaluate(CityState *city) {
    mission_evaluate_goals(&city->mission,
                           (MissionGoalInputs){
                               .player_field_c20 = (int32_t)city->hq_level,
                               .flag16f4_count = (int32_t)city->branch_count,
                               .force_complete = false,
                           });
}

void city_state_init(CityState *city, const char *city_name, const char *map_name,
                     uint32_t width, uint32_t height, uint32_t population,
                     double starting_cash, uint32_t game_length) {
    if (city == NULL) {
        return;
    }
    memset(city, 0, sizeof(*city));
    if (city_name != NULL) {
        strncpy(city->city_name, city_name, sizeof(city->city_name) - 1);
    }
    if (map_name != NULL) {
        strncpy(city->map_name, map_name, sizeof(city->map_name) - 1);
    }
    city->width = width;
    city->height = height;
    city->population = population;
    city->game_length = game_length;

    CityMissionData mission_data;
    memset(&mission_data, 0, sizeof(mission_data));
    mission_data.field_33c = 1;
    mission_data.game_length = (int32_t)game_length;
    mission_data.goals[0] = 0;
    mission_data.goals[1] = 1;
    mission_data.goals[2] = 2;
    game_init_date_state(&city->mission, &mission_data);

    branch_economy_init(&city->economy);
    branch_set_starting_cash(&city->economy, starting_cash);
}

CityLeaseResult city_state_lease(CityState *city, uint32_t tile_index, uint32_t rent) {
    if (city == NULL) {
        return CITY_LEASE_NO_FUNDS;
    }
    if (city->has_leased_tile) {
        return CITY_LEASE_ALREADY_LEASED;
    }
    if (city->branch_count >= CITY_MAX_BRANCHES) {
        return CITY_LEASE_FULL;
    }
    if (city->economy.cash < (double)rent) {
        return CITY_LEASE_NO_FUNDS;
    }

    city->economy.cash -= (double)rent;
    city->has_leased_tile = true;
    city->leased_tile = tile_index;
    city->branches[city->branch_count] = (PlayerBranch){
        .tile_index = tile_index,
        .owner_slot = 0,
        .size = 0,
        .style = 0,
        .owned = false,
        .player_controlled = true,
        .rent = rent,
        .sales = 0,
        .revenue = 0.0,
    };
    city->branch_count += 1;
    city_state_evaluate(city);
    return CITY_LEASE_OK;
}

bool city_state_build_hq(CityState *city) {
    if (city == NULL || city->hq_level >= 3) {
        return false;
    }
    city->hq_level += 1;
    city_state_evaluate(city);
    return true;
}

bool city_state_place_rat(CityState *city) {
    if (city == NULL || city->branch_count == 0) {
        return false;
    }
    city->rats_placed += 1;
    mission_array_set_slot(&city->mission, 1, 1);
    city_state_evaluate(city);
    return true;
}

BranchStepOutcome city_state_sale(CityState *city, uint32_t clock_minutes) {
    if (city == NULL) {
        return BRANCH_CLOSED;
    }
    BranchStepOutcome outcome = branch_settle_sale_at(&city->economy, clock_minutes);
    if (outcome == BRANCH_SALE && city->branch_count > 0) {
        PlayerBranch *branch = &city->branches[0];
        branch->sales += city->economy.last_sale.servings;
        branch->revenue += city->economy.last_sale.revenue;
    }
    city_state_evaluate(city);
    return outcome;
}

bool city_state_mission_complete(const CityState *city) {
    return city != NULL && mission_all_goals_complete(&city->mission);
}
