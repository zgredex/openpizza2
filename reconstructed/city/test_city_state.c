#include "city_state.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

static CityState make_london(void) {
    CityState city;
    city_state_init(&city, "London", "lon.iso", 4096, 2048, 280, 500000.0, 2);
    return city;
}

static void test_london_start(void) {
    CityState city = make_london();
    assert(strncmp(city.city_name, "London", 7) == 0);
    assert(city.width == 4096);
    assert(city.height == 2048);
    assert(city.population == 280);
    assert(city.branch_count == 0);
    assert(city.hq_level == 0);
    assert(city.mission.deadline == 120);
    assert(city.mission.goals[0] == 0);
    assert(city.mission.goals[1] == 1);
    assert(city.mission.goals[2] == 2);
    assert_close(city.economy.cash, 500000.0, 0.0);
}

static void test_full_mission_loop(void) {
    CityState city = make_london();
    assert(city_state_lease(&city, 13694, 5730) == CITY_LEASE_OK);
    assert(city.has_leased_tile);
    assert(city.leased_tile == 13694);
    assert(city.branch_count == 1);
    assert(city.branches[0].tile_index == 13694);
    assert(city.branches[0].owner_slot == 0);
    assert(!city.branches[0].owned);
    assert(city.branches[0].player_controlled);
    assert(city.branches[0].rent == 5730);
    assert_close(city.economy.cash, 494270.0, 0.0);
    assert(city.mission.completed[0] == 0);
    assert(city.mission.completed[1] == 0);
    assert(city.mission.completed[2] == 1);

    assert(city_state_lease(&city, 13694, 5730) == CITY_LEASE_ALREADY_LEASED);

    assert(city_state_build_hq(&city));
    assert(city_state_build_hq(&city));
    assert(city.mission.completed[0] == 0);
    assert(city_state_build_hq(&city));
    assert(city.mission.completed[0] == 1);
    assert(!city_state_build_hq(&city));

    branch_set_open(&city.economy, true);
    assert(city_state_sale(&city, 600) == BRANCH_SALE);
    assert(city.branches[0].sales == 1);
    assert_close(city.branches[0].revenue, 13.80, 1e-12);
    assert_close(city.economy.cash, 494283.420524712365806, 1e-9);
    assert_close(city.economy.stock, 399.0, 0.0);

    assert(city_state_place_rat(&city));
    assert(city.mission.completed[1] == 1);
    assert(city_state_mission_complete(&city));
    assert(city.mission.completed[0] == 1);
    assert(city.mission.completed[2] == 1);
}

static void test_insufficient_funds(void) {
    CityState city = make_london();
    branch_set_starting_cash(&city.economy, 100.0);
    assert(city_state_lease(&city, 13694, 5730) == CITY_LEASE_NO_FUNDS);
    assert(city.branch_count == 0);
    assert(!city.has_leased_tile);
}

int main(void) {
    test_london_start();
    test_full_mission_loop();
    test_insufficient_funds();
    puts("city branch state reconstruction: OK");
    return 0;
}
