#include "branch/branch_economy.h"
#include "city/city_state.h"
#include "construction/construction_state.h"
#include "ingredient/ingredient.h"
#include "menu/menu_state.h"
#include "options/options_state.h"
#include "mission/mission_goals.h"
#include "save/save_state.h"
#include "piz/piz_container.h"
#include "personnel/personnel_state.h"
#include "recipes/recipe_state.h"
#include "ai/ai_state.h"
#include "render/render_state.h"
#include "operations/branch_operations.h"
#include "statistics/statistics_state.h"
#include "settings/settings.h"
#include "ui_screen/ui_screen.h"

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

int main(void) {
    MenuState menu;
    menu_state_init(&menu);
    menu_set_selected(&menu, MENU_START_NEW_GAME);
    MenuAction action = menu_activate(&menu);
    assert(action == MENU_START_NEW_GAME);

    ScreenState screen;
    ui_screen_init(&screen);
    ui_screen_from_menu_action(&screen, action);
    assert(screen.active == SCREEN_CHARACTER_SELECT);
    ui_screen_character_select_start(&screen);
    assert(screen.active == SCREEN_MISSION_BRIEFING);
    ui_screen_mission_start(&screen);
    assert(screen.active == SCREEN_GAME_SESSION);

    Settings settings;
    settings_init_defaults(&settings, load_fails, random_low);
    assert(settings.language_index == 3);

    OptionsState options;
    options_state_init(&options, &settings);
    options_open(&options, OPTIONS_PAGE_AUTOSAVE);
    options_set_autosave_interval_index(&options, 8);
    options_set_language(&options, 2);
    options_toggle_autosave(&options);
    options_apply(&options, &settings);
    assert(settings.autosave_interval == 45);
    assert(settings.autosave_enabled == 1);

    Ingredient ingredient;
    memset(&ingredient, 0, sizeof(ingredient));
    game_set_building_desc(&ingredient, "Olives", 1, 7, 4, 2, 1, 0, 0x402e0000u,
                           0, 0xff, 1, 0, 0, 0);
    assert(strcmp(ingredient.name, "Olives") == 0);

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

    ConstructionSite site;
    construction_site_begin(&site, 7, 0, 13694, 10, 20, 164, 1);
    assert(construction_site_tick(&site, 10));
    assert(site.object.owned && site.object.player_controlled);

    StatisticsState stats;
    statistics_state_init(&stats);
    const StatisticsBuilding buildings[] = {{1, true, true}, {1, false, true}};
    const StatisticsWarehouse warehouses[] = {{2, true}};
    const CompanyInput companies[] = {
        {0, 3, 40, 1000, true},
        {1, 5, 30, 600, true},
    };
    statistics_fill_company_overview(&stats, buildings, 2, warehouses, 1,
                                     companies, 2, 0);
    statistics_add_branch_balance(&stats, 13694, 100, 60);
    assert(stats.overview.player_c20 == 3);
    assert(stats.overview.share_x100 == 6200);
    assert(statistics_total_branch_profit(&stats) == 40);

    SaveState save;
    memset(&save, 0, sizeof(save));
    save.settings = settings;
    save.mission = city.mission;
    uint8_t buffer[SAVE_STATE_TOTAL_SIZE];
    size_t written = save_state_encode(&save, buffer, sizeof(buffer));
    assert(written == SAVE_STATE_TOTAL_SIZE);
    SaveState loaded;
    assert(save_state_decode(&loaded, buffer, written));
    assert(mission_all_goals_complete(&loaded.mission));

    BranchOperations operations;
    branch_operations_init(&operations, 5730.0);
    branch_operations_record_sale(&operations, 13.80, 0.3794752876341939);
    branch_operations_set_payroll(&operations, 3, 1.0);
    branch_operations_set_advertising(&operations, 50.0);
    double branch_profit = branch_operations_compute_profit(&operations);
    assert(branch_profit < 0.0);
    assert(operations.sales == 1);
    assert(operations.staff_count == 3);

    uint8_t frame[4 * 4 * 4];
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, sizeof(frame), 4, 4));
    const uint8_t black[4] = {0, 0, 0, 255};
    const uint8_t red[4] = {255, 0, 0, 255};
    render_clear(&surface, black);
    render_fill_rect(&surface, 1, 1, 2, 2, red);
    assert(frame[(1 * 4 + 1) * 4] == 255);
    RgbaSprite sprite = {1, 1, red};
    assert(render_blit(&surface, &sprite, 3, 3));
    assert(frame[(3 * 4 + 3) * 4] == 255);

    CustomerAIState customer_ai;
    customer_ai_init(&customer_ai);
    assert(customer_ai_enqueue(&customer_ai, 1));
    CustomerAIEvents ai_events = customer_ai_advance_ticks(
        &customer_ai, CUSTOMER_WALK_TICKS + CUSTOMER_PRODUCTION_TICKS +
                          CUSTOMER_SERVICE_TICKS);
    assert(ai_events.sales == 1);
    assert(ai_events.departures == 1);
    CompetitorAIState rival_ai;
    competitor_ai_init(&rival_ai, 1);
    competitor_ai_update(&rival_ai, 250000.0, 4, 12, 3250, 7);
    assert(rival_ai.branch_count == 4);
    assert(rival_ai.plan_steps == 7);

    BranchMenu menu_state;
    branch_menu_init(&menu_state, 1);
    Recipe recipe;
    recipe_init(&recipe, 42, "Margherita", 12.0, 1);
    recipe_add_topping(&recipe, 487, 2, 0, 0);
    assert(branch_menu_add(&menu_state, &recipe));
    assert(menu_state.count == 1);
    assert(fabs(recipe_compute_price(&recipe, 100.0, 1.0, 0.0) - 12.0) < 1e-12);

    PersonnelState personnel;
    personnel_state_init(&personnel);
    personnel_add(&personnel, 1, STAFF_COOK, 70, 60, 80, 90, 100, 13694);
    personnel_add(&personnel, 2, STAFF_SERVER, 60, 70, 75, 85, 80, 13694);
    personnel_add(&personnel, 3, STAFF_ERRAND_BOY, 50, 90, 65, 95, 60, 13694);
    assert(personnel.count == 3);
    assert(personnel_total_wage(&personnel) == 240);
    assert(personnel_average_skill(&personnel) == 60);
    personnel_set_branch(&personnel, 2, 13694);
    assert(personnel_find(&personnel, 2)->branch_id == 13694);

    PizContainer piz;
    piz_container_init(&piz, "My Save", "Ada Pizza", "London");
    piz.save = save;
    piz.briefing_count = 1;
    piz.briefings[0].id = 1;
    strcpy(piz.briefings[0].text, "Welcome to London");
    piz_container_set_tile_name(&piz, 0, "tile-zero");
    piz.character_count = 1;
    piz.characters[0].id = 99;
    strcpy(piz.characters[0].name, "Ada");
    piz.players[0].present = 1;
    strcpy(piz.players[0].name, "Ada");
    piz.players[0].cash = city.economy.cash;
    piz.companies[0].present = 1;
    strcpy(piz.companies[0].name, "Ada Pizza");
    piz.companies[0].branches = 1;
    uint8_t piz_buffer[PIZ_MAX_CONTAINER_SIZE];
    size_t piz_written = piz_container_encode(&piz, piz_buffer, sizeof(piz_buffer));
    assert(piz_written == piz_container_size(&piz));
    PizContainer piz_loaded;
    assert(piz_container_decode(&piz_loaded, piz_buffer, piz_written));
    assert(strcmp(piz_loaded.header.title, "My Save") == 0);
    assert(strcmp(piz_loaded.header.city, "London") == 0);
    assert(mission_all_goals_complete(&piz_loaded.save.mission));
    assert(piz_loaded.character_count == 1);
    assert(strcmp(piz_loaded.tile_names[0], "tile-zero") == 0);

    printf("pc2 reconstructed full game: OK\n");
    printf("screen=%d goals=%u/%u hq=%u rats=%u branches=%u cash=%.6f\n",
           (int)screen.active, city.mission.completed[0] + city.mission.completed[1] +
                                   city.mission.completed[2],
           3u, city.hq_level, city.rats_placed, city.branch_count, city.economy.cash);
    return 0;
}
