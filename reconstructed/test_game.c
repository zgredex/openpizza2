#include "branch/branch_economy.h"
#include "city/city_state.h"
#include "ingredient/ingredient.h"
#include "menu/menu_state.h"
#include "mission/mission_goals.h"
#include "settings/settings.h"
#include "save/save_state.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static bool load_fails(Settings *settings) {
    (void)settings;
    return false;
}

static uint32_t random_low(uint32_t low, uint32_t high) {
    (void)high;
    return low;
}

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

int main(void) {
    Settings settings;
    settings_init_defaults(&settings, load_fails, random_low);
    assert(settings.language_index == 3);
    assert(settings.autosave_interval == 5);

    Ingredient ingredient;
    memset(&ingredient, 0, sizeof(ingredient));
    game_set_building_desc(&ingredient, "Olives", 1, 7, 4, 2, 1, 0, 0x402e0000u,
                           0, 0xff, 1, 0, 0, 0);
    assert(strcmp(ingredient.name, "Olives") == 0);
    assert(ingredient.kind == 1);

    MenuState menu;
    menu_state_init(&menu);
    assert(menu_button_at(&menu, 650, 12) == 0);
    assert(menu_button_at(&menu, 650, 566) == 5);
    menu_set_selected(&menu, 2);
    assert(menu_activate(&menu) == MENU_CONTINUE_GAME);
    assert(strcmp(menu.status, "No saved games found.") == 0);

    CityState city;
    city_state_init(&city, "London", "lon.iso", 4096, 2048, 280, 500000.0, 2);
    assert(city_state_lease(&city, 13694, 5730) == CITY_LEASE_OK);
    assert(city_state_build_hq(&city));
    assert(city_state_build_hq(&city));
    assert(city_state_build_hq(&city));
    branch_set_open(&city.economy, true);
    assert(city_state_sale(&city, 600) == BRANCH_SALE);
    assert(city_state_place_rat(&city));
    assert(city_state_mission_complete(&city));
    assert_close(city.economy.cash, 494283.420524712365806, 1e-9);
    assert(city.branches[0].sales == 1);
    assert_close(city.branches[0].revenue, 13.80, 1e-12);

    SaveState save;
    memset(&save, 0, sizeof(save));
    save.settings = settings;
    save.mission = city.mission;
    uint8_t buffer[SAVE_STATE_TOTAL_SIZE];
    size_t written = save_state_encode(&save, buffer, sizeof(buffer));
    assert(written == SAVE_STATE_TOTAL_SIZE);
    SaveState loaded;
    assert(save_state_decode(&loaded, buffer, written));
    assert(memcmp(&loaded.settings, &settings, sizeof(Settings)) == 0);
    assert(mission_all_goals_complete(&loaded.mission));

    puts("unified game reconstruction: OK");
    return 0;
}
