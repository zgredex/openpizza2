#include "branch/branch_economy.h"
#include "city/city_state.h"
#include "construction/construction_state.h"
#include "ingredient/ingredient.h"
#include "menu/menu_state.h"
#include "mission/mission_goals.h"
#include "settings/settings.h"
#include "save/save_state.h"
#include "piz/piz_container.h"
#include "personnel/personnel_state.h"
#include "recipes/recipe_state.h"
#include "ai/ai_state.h"
#include "render/render_state.h"
#include "operations/branch_operations.h"
#include "assets/assets.h"
#include "ui_render/ui_render.h"
#include "screen/screen_render.h"
#include "map/map_render.h"
#include "statistics/statistics_state.h"
#include "options/options_state.h"
#include "ui_screen/ui_screen.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
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

    OptionsState options;
    options_state_init(&options, &settings);
    options_open(&options, OPTIONS_PAGE_AUTOSAVE);
    options_set_autosave_interval_index(&options, 8);
    options_set_language(&options, 2);
    options_toggle_autosave(&options);
    options_apply(&options, &settings);
    assert(settings.autosave_interval == 45);
    assert(settings.language_index == 2);
    assert(settings.autosave_enabled == 1);

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

    ScreenState screen;
    ui_screen_init(&screen);
    ui_screen_from_menu_action(&screen, MENU_START_NEW_GAME);
    assert(screen.active == SCREEN_CHARACTER_SELECT);
    ui_screen_character_select_start(&screen);
    assert(screen.active == SCREEN_MISSION_BRIEFING);
    ui_screen_mission_start(&screen);
    assert(screen.active == SCREEN_GAME_SESSION);

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

    size_t iso_length = 0;
    uint8_t *iso_data = NULL;
    FILE *iso_file = fopen("../game/Isokarten/Lon.iso", "rb");
    if (iso_file != NULL) {
        fseek(iso_file, 0, SEEK_END);
        long iso_size = ftell(iso_file);
        fseek(iso_file, 0, SEEK_SET);
        if (iso_size > 0) {
            iso_data = malloc((size_t)iso_size);
            if (iso_data != NULL) {
                iso_length = fread(iso_data, 1, (size_t)iso_size, iso_file);
            }
        }
        fclose(iso_file);
    }
    static IsoTile london_tiles[ISO_MAX_TILES];
    IsoMap london_map;
    if (iso_data != NULL &&
        iso_map_parse(iso_data, iso_length, &london_map, london_tiles,
                      ISO_MAX_TILES)) {
        size_t lon_length = 0;
        uint8_t *lon_data = NULL;
        FILE *lon_file = fopen("../extracted/backgrounds/lon.tga", "rb");
        if (lon_file != NULL) {
            fseek(lon_file, 0, SEEK_END);
            long lon_size = ftell(lon_file);
            fseek(lon_file, 0, SEEK_SET);
            if (lon_size > 0) {
                lon_data = malloc((size_t)lon_size);
                if (lon_data != NULL) {
                    lon_length = fread(lon_data, 1, (size_t)lon_size, lon_file);
                }
            }
            fclose(lon_file);
        }
        if (lon_data != NULL) {
            size_t city_capacity = (size_t)4096 * 2048 * 4;
            uint8_t *city_pixels = malloc(city_capacity);
            uint32_t city_width = 0;
            uint32_t city_height = 0;
            if (city_pixels != NULL &&
                tga_decode_rgba(lon_data, lon_length, city_pixels, city_capacity,
                                &city_width, &city_height)) {
                RgbaSprite city_background = {city_width, city_height, city_pixels};
                uint8_t *city_frame = malloc(800 * 600 * 4);
                assert(city_frame != NULL);
                RenderSurface city_surface;
                assert(render_surface_init(&city_surface, city_frame,
                                           800 * 600 * 4, 800, 600));
                const MapMarker city_marker = {82, 83, {20, 230, 90, 255}, 5};
                assert(map_render_city_view(
                    &city_surface, &city_background,
                    (int32_t)london_map.header.origin_x,
                    (int32_t)london_map.header.origin_y, &london_map, 13694,
                    &city_marker, 1));
                size_t city_center = ((size_t)300 * 800 + 400) * 4;
                assert(city_frame[city_center + 1] == 230);
                assert(city_frame[city_center + 2] == 90);
                free(city_frame);
            }
            free(city_pixels);
            free(lon_data);
        }
    }
    free(iso_data);

    assert_close(city.economy.cash, 494283.420524712365806, 1e-9);
    assert(city.branches[0].sales == 1);
    assert_close(city.branches[0].revenue, 13.80, 1e-12);

    ConstructionSite site;
    construction_site_begin(&site, 7, 0, 13694, 10, 20, 164, 1);
    assert(!site.complete);
    assert(construction_site_tick(&site, 10));
    assert(site.object.owned);
    assert(site.object.player_controlled);
    assert(site.order.cell_index == 3290);

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
    assert(memcmp(&loaded.settings, &settings, sizeof(Settings)) == 0);
    assert(mission_all_goals_complete(&loaded.mission));

    FntInfo font_info;
    uint8_t font_data[32768] = {0};
    size_t font_size = 0;
    FILE *font_file = fopen("../extracted/fonts/timesfont.fnt", "rb");
    if (font_file != NULL) {
        font_size = fread(font_data, 1, sizeof(font_data), font_file);
        fclose(font_file);
        assert(fnt_read_info(font_data, font_size, &font_info));
        assert(font_info.line_height == 23);
        assert(font_info.max_width == 18);
    }

    uint8_t text_frame[64 * 64 * 4];
    RenderSurface text_surface;
    assert(render_surface_init(&text_surface, text_frame, sizeof(text_frame), 64, 64));
    const uint8_t white_bg[4] = {255, 255, 255, 255};
    const uint8_t black_text[4] = {0, 0, 0, 255};
    render_clear(&text_surface, white_bg);
    if (font_file != NULL) {
        assert(ui_draw_text(&text_surface, font_data, font_size, &font_info, 2, 2,
                            "A", black_text));
        bool text_ink = false;
        for (size_t index = 0; index < sizeof(text_frame); index += 4) {
            if (text_frame[index] < 255) {
                text_ink = true;
                break;
            }
        }
        assert(text_ink);
    }

    size_t tga_size = 0;
    uint8_t *tga_data = NULL;
    FILE *tga_file = fopen("../extracted/pictures/pe_startscreen.tga", "rb");
    if (tga_file != NULL) {
        fseek(tga_file, 0, SEEK_END);
        long tga_length = ftell(tga_file);
        fseek(tga_file, 0, SEEK_SET);
        if (tga_length > 0) {
            tga_data = malloc((size_t)tga_length);
            if (tga_data != NULL) {
                tga_size = fread(tga_data, 1, (size_t)tga_length, tga_file);
            }
        }
        fclose(tga_file);
    }
    if (tga_data != NULL && font_size > 0) {
        size_t screen_frame_size = 800 * 600 * 4;
        uint8_t *screen_frame = malloc(screen_frame_size);
        uint8_t *screen_decoded = malloc(screen_frame_size);
        assert(screen_frame != NULL);
        assert(screen_decoded != NULL);
        RenderSurface screen_surface;
        assert(render_surface_init(&screen_surface, screen_frame, screen_frame_size,
                                   800, 600));
        menu_set_hover(&menu, 0);
        assert(screen_render_menu(&screen_surface, tga_data, tga_size, font_data,
                                  font_size, &font_info, &menu, screen_decoded,
                                  screen_frame_size));
        assert(memcmp(screen_frame, screen_decoded, screen_frame_size) != 0);
        free(screen_decoded);
        free(screen_frame);
        free(tga_data);
    }

    tga_data = NULL;
    tga_size = 0;
    tga_file = fopen("../extracted/pictures/pe_charakterauswahl.tga", "rb");
    if (tga_file != NULL) {
        fseek(tga_file, 0, SEEK_END);
        long character_length = ftell(tga_file);
        fseek(tga_file, 0, SEEK_SET);
        if (character_length > 0) {
            tga_data = malloc((size_t)character_length);
            if (tga_data != NULL) {
                tga_size = fread(tga_data, 1, (size_t)character_length, tga_file);
            }
        }
        fclose(tga_file);
    }
    if (tga_data != NULL && font_size > 0) {
        size_t character_frame_size = 800 * 600 * 4;
        uint8_t *character_frame = malloc(character_frame_size);
        uint8_t *character_decoded = malloc(character_frame_size);
        assert(character_frame != NULL);
        assert(character_decoded != NULL);
        RenderSurface character_surface;
        assert(render_surface_init(&character_surface, character_frame,
                                   character_frame_size, 800, 600));
        CharacterScreenData character_screen = {
            .player_name = "Ada",
            .enterprise_name = "Ada Pizza",
            .attributes = {5, 3, 4, 2, 5, 4},
            .difficulty = 9,
            .selected_button = 1,
        };
        assert(screen_render_character_select(
            &character_surface, tga_data, tga_size, font_data, font_size,
            &font_info, &character_screen, character_decoded,
            character_frame_size));
        assert(memcmp(character_frame, character_decoded,
                      character_frame_size) != 0);
        free(character_decoded);
        free(character_frame);
        free(tga_data);
    }

    tga_data = NULL;
    tga_size = 0;
    tga_file = fopen("../extracted/pictures/pe_missionsbriefing_lon.tga", "rb");
    if (tga_file != NULL) {
        fseek(tga_file, 0, SEEK_END);
        long briefing_length = ftell(tga_file);
        fseek(tga_file, 0, SEEK_SET);
        if (briefing_length > 0) {
            tga_data = malloc((size_t)briefing_length);
            if (tga_data != NULL) {
                tga_size = fread(tga_data, 1, (size_t)briefing_length, tga_file);
            }
        }
        fclose(tga_file);
    }
    if (tga_data != NULL && font_size > 0) {
        size_t briefing_frame_size = 800 * 600 * 4;
        uint8_t *briefing_frame = malloc(briefing_frame_size);
        uint8_t *briefing_decoded = malloc(briefing_frame_size);
        assert(briefing_frame != NULL);
        assert(briefing_decoded != NULL);
        RenderSurface briefing_surface;
        assert(render_surface_init(&briefing_surface, briefing_frame,
                                   briefing_frame_size, 800, 600));
        int briefing_lines = screen_render_briefing(
            &briefing_surface, tga_data, tga_size, font_data, font_size,
            &font_info, "London",
            "You begin your life as - hopefully - a successful pizza chef. Your "
            "boss sits in New York and has selected you from the many "
            "applications to be his new regional manager. Since the English are "
            "infamous for having no taste where food is concerned, you shouldn't "
            "have too much of a problem conquering the city with your tasty "
            "pizzas.",
            "Press any key to continue", briefing_decoded, briefing_frame_size);
        assert(briefing_lines >= 4);
        assert(memcmp(briefing_frame, briefing_decoded, briefing_frame_size) != 0);
        free(briefing_decoded);
        free(briefing_frame);
        free(tga_data);
    }

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

    puts("unified game reconstruction: OK");
    return 0;
}
