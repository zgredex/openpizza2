#ifndef PC2_RECONSTRUCTED_CITY_STATE_H
#define PC2_RECONSTRUCTED_CITY_STATE_H

#include <stdbool.h>
#include <stdint.h>

#include "../branch/branch_economy.h"
#include "../mission/mission_goals.h"

#define CITY_MAX_BRANCHES 4

typedef struct PlayerBranch {
    uint32_t tile_index;
    uint8_t owner_slot;
    uint8_t size;
    uint8_t style;
    bool owned;
    bool player_controlled;
    uint32_t rent;
    uint32_t sales;
    double revenue;
} PlayerBranch;

typedef enum CityLeaseResult {
    CITY_LEASE_OK = 0,
    CITY_LEASE_ALREADY_LEASED = 1,
    CITY_LEASE_NO_FUNDS = 2,
    CITY_LEASE_FULL = 3,
} CityLeaseResult;

/*
 * Host-side city/branch state used by the reconstructed modules. It carries
 * the London campaign fields seen in ScenarioSetup, PlayerBranch and the
 * playable branch economy, without claiming the original object layout.
 */
typedef struct CityState {
    char city_name[32];
    char map_name[32];
    uint32_t width;
    uint32_t height;
    uint32_t population;
    uint32_t game_length;
    uint32_t hq_level;
    uint32_t rats_placed;
    bool has_leased_tile;
    uint32_t leased_tile;
    uint32_t branch_count;
    PlayerBranch branches[CITY_MAX_BRANCHES];
    BranchEconomy economy;
    MissionState mission;
} CityState;

void city_state_init(CityState *city, const char *city_name, const char *map_name,
                     uint32_t width, uint32_t height, uint32_t population,
                     double starting_cash, uint32_t game_length);

CityLeaseResult city_state_lease(CityState *city, uint32_t tile_index, uint32_t rent);
bool city_state_build_hq(CityState *city);
bool city_state_place_rat(CityState *city);
BranchStepOutcome city_state_sale(CityState *city, uint32_t clock_minutes);

bool city_state_mission_complete(const CityState *city);

#endif
