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
#include "advertising/value_state.h"
#include "rating/rating_state.h"
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

static bool load_spr_asset(const char *path, uint8_t **pixels,
                           RgbaSprite *sprite) {
    size_t length = 0;
    uint8_t *data = NULL;
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return false;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (size > 0) {
        data = malloc((size_t)size);
        if (data != NULL) {
            length = fread(data, 1, (size_t)size, file);
        }
    }
    fclose(file);
    if (data == NULL || length < 0x21) {
        free(data);
        return false;
    }
    uint16_t width = (uint16_t)(data[7] | (data[8] << 8));
    uint16_t height = (uint16_t)(data[9] | (data[10] << 8));
    size_t capacity = (size_t)width * height * 4;
    uint8_t *decoded = malloc(capacity);
    if (decoded == NULL) {
        free(data);
        return false;
    }
    SpriteAsset asset;
    bool ok = spr_decode(data, length, &asset, decoded, capacity);
    free(data);
    if (!ok) {
        free(decoded);
        return false;
    }
    sprite->width = asset.width;
    sprite->height = asset.height;
    sprite->pixels = decoded;
    *pixels = decoded;
    return true;
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

    uint8_t *bl_panel_pixels = NULL;
    uint8_t *bl_table_pixels = NULL;
    uint8_t *bl_separator_pixels = NULL;
    uint8_t *bl_branch_pixels = NULL;
    uint8_t *bl_warehouse_pixels = NULL;
    RgbaSprite bl_panel;
    RgbaSprite bl_table;
    RgbaSprite bl_separator;
    RgbaSprite bl_branch_icon;
    RgbaSprite bl_warehouse_icon;
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &bl_panel_pixels,
                          &bl_panel));
    assert(load_spr_asset("../extracted/sprites/tab01xxx.spr", &bl_table_pixels,
                          &bl_table));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &bl_separator_pixels, &bl_separator));
    assert(load_spr_asset("../extracted/sprites/skfiliale_00.spr",
                          &bl_branch_pixels, &bl_branch_icon));
    assert(load_spr_asset("../extracted/sprites/sklager_00.spr",
                          &bl_warehouse_pixels, &bl_warehouse_icon));
    const BranchListEntry bl_entries[2] = {
        {city.branches[0].tile_index, city.branches[0].rent, false},
        {7, 0, true},
    };
    const BranchListData bl_data = {
        .city = "London",
        .entries = bl_entries,
        .entry_count = 2,
        .selected = 0,
    };
    uint8_t *bl_frame = malloc(800 * 600 * 4);
    assert(bl_frame != NULL);
    RenderSurface bl_surface;
    assert(render_surface_init(&bl_surface, bl_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_branch_list(&bl_surface, &bl_panel, &bl_table,
                                     &bl_separator, &bl_branch_icon,
                                     &bl_warehouse_icon, font_data, font_size,
                                     &font_info, &bl_data));
    size_t bl_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(bl_frame + bl_panel_offset, bl_panel.pixels, 4) == 0);
    free(bl_frame);
    free(bl_panel_pixels);
    free(bl_table_pixels);
    free(bl_separator_pixels);
    free(bl_branch_pixels);
    free(bl_warehouse_pixels);

    size_t stats_tga_length = 0;
    uint8_t *stats_tga = NULL;
    FILE *stats_tga_file = fopen("../extracted/pictures/bg003.tga", "rb");
    if (stats_tga_file != NULL) {
        fseek(stats_tga_file, 0, SEEK_END);
        long stats_tga_size = ftell(stats_tga_file);
        fseek(stats_tga_file, 0, SEEK_SET);
        if (stats_tga_size > 0) {
            stats_tga = malloc((size_t)stats_tga_size);
            if (stats_tga != NULL) {
                stats_tga_length = fread(stats_tga, 1, (size_t)stats_tga_size,
                                         stats_tga_file);
            }
        }
        fclose(stats_tga_file);
    }
    if (stats_tga != NULL && font_size > 0) {
        size_t stats_frame_size = 800 * 600 * 4;
        uint8_t *stats_frame = malloc(stats_frame_size);
        uint8_t *stats_decoded = malloc(stats_frame_size);
        assert(stats_frame != NULL);
        assert(stats_decoded != NULL);
        RenderSurface stats_surface;
        assert(render_surface_init(&stats_surface, stats_frame, stats_frame_size,
                                   800, 600));
        assert(screen_render_statistics(&stats_surface, stats_tga,
                                        stats_tga_length, font_data, font_size,
                                        &font_info, &stats, "London",
                                        "17.32.2003", stats_decoded,
                                        stats_frame_size));
        assert(memcmp(stats_frame, stats_decoded, stats_frame_size) != 0);
        free(stats_decoded);
        free(stats_frame);
        free(stats_tga);
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
    tga_file = fopen("../extracted/pictures/pe_freies_spiel.tga", "rb");
    if (tga_file != NULL) {
        fseek(tga_file, 0, SEEK_END);
        long freeplay_length = ftell(tga_file);
        fseek(tga_file, 0, SEEK_SET);
        if (freeplay_length > 0) {
            tga_data = malloc((size_t)freeplay_length);
            if (tga_data != NULL) {
                tga_size = fread(tga_data, 1, (size_t)freeplay_length, tga_file);
            }
        }
        fclose(tga_file);
    }
    if (tga_data != NULL && font_size > 0) {
        size_t freeplay_frame_size = 800 * 600 * 4;
        uint8_t *freeplay_frame = malloc(freeplay_frame_size);
        uint8_t *freeplay_decoded = malloc(freeplay_frame_size);
        assert(freeplay_frame != NULL);
        assert(freeplay_decoded != NULL);
        RenderSurface freeplay_surface;
        assert(render_surface_init(&freeplay_surface, freeplay_frame,
                                   freeplay_frame_size, 800, 600));
        FreePlayScenario freeplay = {
            .city = "Berlin",
            .map = "Ber.iso",
            .player_name = "Ada",
            .enterprise_name = "Ada Pizza",
            .population = 250,
            .game_length = 11,
            .difficulty = 9,
            .starting_capital = 22000,
            .opponents = {-1, -1, -1},
            .selected_button = 1,
        };
        assert(screen_render_free_play(
            &freeplay_surface, tga_data, tga_size, font_data, font_size,
            &font_info, &freeplay, freeplay_decoded, freeplay_frame_size));
        assert(memcmp(freeplay_frame, freeplay_decoded, freeplay_frame_size) != 0);
        free(freeplay_decoded);
        free(freeplay_frame);
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
    branch_operations_set_advertising(&operations, 240.0);
    uint8_t open_hours[BRANCH_OPEN_HOURS] = {0};
    for (uint32_t hour = 10; hour <= 20; hour++) {
        open_hours[hour] = 1;
    }
    branch_operations_set_open_hours(&operations, open_hours);
    assert(branch_operations_is_open(&operations, 12));
    assert(branch_operations_hourly_wages(&operations) == 1.5);
    double hourly_cash = 1000.0;
    assert(branch_operations_process_hour(&operations, 12, 50.0, 20.0,
                                          &hourly_cash) == 1018.5);
    assert(game_compute_player_salary(1, 5, 3, 2) == 10000);
    assert(game_compute_player_salary(2, 6, 3, 2) == 20000);
    assert(game_compute_player_salary(1, 4, 3, 2) == -1);
    const BranchOperationProfit unprofitable_input[] = {
        {1, 1000}, {2, 400}, {3, 100}, {4, 500},
    };
    BranchOperationProfit unprofitable_result[4];
    assert(branch_collect_unprofitable(unprofitable_input, 4,
                                       unprofitable_result, 4) == 1);
    assert(unprofitable_result[0].branch_id == 3);
    ValueApproachState advertising;
    value_state_init(&advertising, 50.0);
    assert(value_approach(&advertising, 10.0, 55.0));
    assert(advertising.value == 55.0);
    advertising.dirty = 0;
    value_state_decay_hour(&advertising);
    assert(advertising.value == 51.0);
    assert(game_adjusted_value(10, 50, 5, false, 0, false, -1, 100, 0, 0) ==
           65);
    assert(game_adjusted_value(10, 50, 5, true, 1, false, -1, 100, 0, 0) ==
           97);
    assert(rating_city_adjust(80, 5, 5) == 56);
    assert(rating_branch_score(10, 40) == 10);
    assert(branch_customer_group_rating(60, 70, 80, 90, true, 10) == 85);
    assert(branch_customer_group_rating(30, 30, 30, 0, false, 20) == 50);
    const int32_t rating_values[8] = {10, 40, 19, 41, 0, 100, 20, 30};
    const int32_t rating_baselines[8] = {40, 40, 20, 40, 30, 50, 60, 30};
    int32_t rating_scores[8] = {0};
    assert(rating_branch_scores(rating_values, rating_baselines,
                                rating_scores) == 8);
    assert(rating_scores[0] == 10 && rating_scores[6] == 0);
    assert(rating_market_bonus_factor(false, 0, 0) == 1.0);
    assert(rating_market_bonus_factor(true, 20, 0) == 1.1);
    const int32_t price_ratings[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    assert(rating_group_average8(price_ratings, -1) == 45);
    bool has_price = false;
    assert(branch_price_comparison_rating(80, 5, 5, false, &has_price) == 0);
    assert(!has_price);
    assert(branch_price_comparison_rating(80, 5, 5, true, &has_price) == 56);
    assert(has_price);


    assert(company_get_percent_modifier(1, 5000) == 50);
    assert(gameplan_effect_from_bar(1, 5000, 80, 0, 0) == 60);
    assert(gameplan_effect_from_bar(1, 5000, 80, 25, 0) == 15);
    const int32_t plan_bars[8] = {80, 80, 80, 80, 80, 80, 80, 80};
    assert(gameplan_average_effect(plan_bars, 1, 5000, 0, 0) == 60);
    assert(gameplan_company_category_metric(1, 11, 22, 33, 44) == 11);
    const int32_t plan_competitor_avg[4] = {50, 50, 50, 50};
    const int32_t plan_own_metrics[4] = {100, 100, 100, 100};
    assert(gameplan_category_effect(1, 0, 0, 0, 100, 0, 0, false,
                                    plan_competitor_avg,
                                    plan_own_metrics) == 40);
    assert(gameplan_category_effect(1, 1, 1, 0, 100, 0, 0, true,
                                    plan_competitor_avg,
                                    plan_own_metrics) == 92);
    PlanAllocation plan_allocations[3] = {
        {.type = 1, .effect = 60},
        {.type = 2, .effect = 50},
        {.type = 3, .effect = 0},
    };
    company_allocate_plan_budget(plan_allocations, 3, 1000, 2);
    assert(plan_allocations[0].share == 705);
    assert(plan_allocations[1].share == 295);
    assert(plan_allocations[2].fixed);







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
    const int32_t plan_income[3] = {100, 80, 60};
    const int32_t plan_expense[3] = {30, 20, 10};
    int32_t plan_scores[3] = {0};
    int32_t plan_total = 0;
    assert(ai_compute_plan_scores(plan_income, plan_expense, 3, plan_scores, 3,
                                  &plan_total) == 3);
    assert(plan_scores[0] == 70 && plan_scores[1] == 60 &&
           plan_scores[2] == 50);
    assert(plan_total == 180);


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

    uint8_t *bd_panel_pixels = NULL;
    uint8_t *bd_separator_pixels = NULL;
    uint8_t *bd_logo_pixels = NULL;
    uint8_t *bd_rating_pixels = NULL;
    RgbaSprite bd_panel;
    RgbaSprite bd_separator;
    RgbaSprite bd_logo;
    RgbaSprite bd_rating;
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &bd_panel_pixels,
                          &bd_panel));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &bd_separator_pixels, &bd_separator));
    assert(load_spr_asset("../extracted/sprites/logorahmen_00.spr",
                          &bd_logo_pixels, &bd_logo));
    assert(load_spr_asset("../extracted/sprites/bewertung__08.spr",
                          &bd_rating_pixels, &bd_rating));
    const BranchDetailsData bd_data = {
        .branch_name = "London branch",
        .employee_name = "Ada",
        .employee_role = "Cook",
        .owner_name = "Ada Pizza",
        .tile_index = city.branches[0].tile_index,
        .age = 30,
        .cooking = personnel.staff[0].skill,
        .speed = personnel.staff[0].speed,
        .motivation = personnel.staff[0].motivation,
        .health = personnel.staff[0].health,
        .performance = personnel_average_skill(&personnel),
        .salary = (uint32_t)personnel.staff[0].wage,
        .selected_button = 0,
    };
    uint8_t *bd_frame = malloc(800 * 600 * 4);
    assert(bd_frame != NULL);
    RenderSurface bd_surface;
    assert(render_surface_init(&bd_surface, bd_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_branch_details(&bd_surface, &bd_panel, &bd_separator,
                                        &bd_logo, &bd_rating, font_data,
                                        font_size, &font_info, &bd_data));
    size_t bd_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(bd_frame + bd_panel_offset, bd_panel.pixels, 4) == 0);
    free(bd_frame);
    free(bd_panel_pixels);
    free(bd_separator_pixels);
    free(bd_logo_pixels);
    free(bd_rating_pixels);

    uint8_t *bo_panel_pixels = NULL;
    uint8_t *bo_separator_pixels = NULL;
    uint8_t *bo_rating_pixels = NULL;
    RgbaSprite bo_panel;
    RgbaSprite bo_separator;
    RgbaSprite bo_rating;
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &bo_panel_pixels,
                          &bo_panel));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &bo_separator_pixels, &bo_separator));
    assert(load_spr_asset("../extracted/sprites/bewertung__08.spr",
                          &bo_rating_pixels, &bo_rating));
    BranchOfferData bo_data = {
        .branch_name = "London branch",
        .expand_days = 3,
        .cost = 3422,
        .capacity = 100,
        .new_capacity = 150,
        .selected_button = 0,
    };
    for (int index = 0; index < 8; index++) {
        bo_data.ratings[index] = &bo_rating;
    }
    uint8_t *bo_frame = malloc(800 * 600 * 4);
    assert(bo_frame != NULL);
    RenderSurface bo_surface;
    assert(render_surface_init(&bo_surface, bo_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_branch_offer(&bo_surface, &bo_panel, &bo_separator,
                                      font_data, font_size, &font_info,
                                      &bo_data));
    size_t bo_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(bo_frame + bo_panel_offset, bo_panel.pixels, 4) == 0);
    free(bo_frame);
    free(bo_panel_pixels);
    free(bo_separator_pixels);
    free(bo_rating_pixels);

    uint8_t *po_panel_pixels = NULL;
    uint8_t *po_separator_pixels = NULL;
    uint8_t *po_rating_pixels = NULL;
    uint8_t *po_tab_pixels[4] = {NULL, NULL, NULL, NULL};
    RgbaSprite po_panel;
    RgbaSprite po_separator;
    RgbaSprite po_rating;
    RgbaSprite po_tabs[4];
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &po_panel_pixels,
                          &po_panel));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &po_separator_pixels, &po_separator));
    assert(load_spr_asset("../extracted/sprites/bewertung__08.spr",
                          &po_rating_pixels, &po_rating));
    assert(load_spr_asset("../extracted/sprites/persoueber_00.spr",
                          &po_tab_pixels[0], &po_tabs[0]));
    assert(load_spr_asset("../extracted/sprites/persoueber_01.spr",
                          &po_tab_pixels[1], &po_tabs[1]));
    assert(load_spr_asset("../extracted/sprites/persoueber_02.spr",
                          &po_tab_pixels[2], &po_tabs[2]));
    assert(load_spr_asset("../extracted/sprites/persoueber_03.spr",
                          &po_tab_pixels[3], &po_tabs[3]));
    PersonnelOverviewData po_data = {
        .candidate_name = "Ada",
        .profession = "Cook",
        .age = 30,
        .health = personnel.staff[0].health,
        .motivation = personnel.staff[0].motivation,
        .cooking = personnel.staff[0].skill,
        .speed = personnel.staff[0].speed,
        .selected_tab = 0,
        .selected_button = 0,
    };
    for (int index = 0; index < 4; index++) {
        po_data.ratings[index] = &po_rating;
    }
    uint8_t *po_frame = malloc(800 * 600 * 4);
    assert(po_frame != NULL);
    RenderSurface po_surface;
    assert(render_surface_init(&po_surface, po_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_personnel_overview(&po_surface, &po_panel, po_tabs,
                                             &po_separator, font_data,
                                             font_size, &font_info, &po_data));
    size_t po_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(po_frame + po_panel_offset, po_panel.pixels, 4) == 0);
    free(po_frame);
    free(po_panel_pixels);
    free(po_separator_pixels);
    free(po_rating_pixels);
    for (int index = 0; index < 4; index++) {
        free(po_tab_pixels[index]);
    }

    uint8_t *pr_panel_pixels = NULL;
    uint8_t *pr_plan_pixels = NULL;
    uint8_t *pr_light_pixels = NULL;
    uint8_t *pr_separator_pixels = NULL;
    uint8_t *pr_rating_pixels = NULL;
    RgbaSprite pr_panel;
    RgbaSprite pr_plan;
    RgbaSprite pr_light;
    RgbaSprite pr_separator;
    RgbaSprite pr_rating;
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &pr_panel_pixels,
                          &pr_panel));
    assert(load_spr_asset("../extracted/sprites/persoplan.spr", &pr_plan_pixels,
                          &pr_plan));
    assert(load_spr_asset("../extracted/sprites/persoplanlight.spr",
                          &pr_light_pixels, &pr_light));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &pr_separator_pixels, &pr_separator));
    assert(load_spr_asset("../extracted/sprites/bewertung__08.spr",
                          &pr_rating_pixels, &pr_rating));
    PersonnelRecordData pr_data = {
        .employee_name = "Ada",
        .profession = "Cook",
        .age = 30,
        .cooking = personnel.staff[0].skill,
        .speed = personnel.staff[0].speed,
        .motivation = personnel.staff[0].motivation,
        .health = personnel.staff[0].health,
    };
    for (int index = 0; index < 8; index++) {
        pr_data.ratings[index] = &pr_rating;
    }
    uint8_t *pr_frame = malloc(800 * 600 * 4);
    assert(pr_frame != NULL);
    RenderSurface pr_surface;
    assert(render_surface_init(&pr_surface, pr_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_personnel_record(&pr_surface, &pr_panel, &pr_plan,
                                           &pr_light, &pr_separator, font_data,
                                           font_size, &font_info, &pr_data));
    size_t pr_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(pr_frame + pr_panel_offset, pr_panel.pixels, 4) == 0);
    free(pr_frame);
    free(pr_panel_pixels);
    free(pr_plan_pixels);
    free(pr_light_pixels);
    free(pr_separator_pixels);
    free(pr_rating_pixels);

    uint8_t *sb_background_pixels = NULL;
    uint8_t *sb_row_pixels = NULL;
    RgbaSprite sb_background;
    RgbaSprite sb_row_plate;
    assert(load_spr_asset("../extracted/sprites/statistikbilanzback.spr",
                          &sb_background_pixels, &sb_background));
    assert(load_spr_asset("../extracted/sprites/tab09.spr", &sb_row_pixels,
                          &sb_row_plate));
    const StatisticsBalanceRow sb_expenses[3] = {
        {"Stocks", operations.ingredient_cost},
        {"Rent", operations.rent},
        {"Wages", operations.wages},
    };
    const StatisticsBalanceRow sb_incomes[1] = {
        {"Sales", operations.revenue},
    };
    const StatisticsBalanceData sb_data = {
        .branch_name = "London branch",
        .period = "Quarter 1",
        .validity = city.city_name,
        .expenses = sb_expenses,
        .expense_count = 3,
        .incomes = sb_incomes,
        .income_count = 1,
    };
    uint8_t *sb_frame = malloc(800 * 600 * 4);
    assert(sb_frame != NULL);
    RenderSurface sb_surface;
    assert(render_surface_init(&sb_surface, sb_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_statistics_balance(&sb_surface, &sb_background,
                                             &sb_row_plate, font_data,
                                             font_size, &font_info, &sb_data));
    assert(memcmp(sb_frame, sb_background.pixels, 4) == 0);
    free(sb_frame);
    free(sb_background_pixels);
    free(sb_row_pixels);

    uint8_t *sbb_background_pixels = NULL;
    uint8_t *sbb_row_pixels = NULL;
    uint8_t *sbb_rating_pixels = NULL;
    uint8_t *sbb_personal_pixels = NULL;
    uint8_t *sbb_money_pixels = NULL;
    uint8_t *sbb_load_pixels = NULL;
    uint8_t *sbb_balance_pixels = NULL;
    RgbaSprite sbb_background;
    RgbaSprite sbb_row_plate;
    RgbaSprite sbb_rating;
    RgbaSprite sbb_personal;
    RgbaSprite sbb_money;
    RgbaSprite sbb_load;
    RgbaSprite sbb_balance;
    assert(load_spr_asset("../extracted/sprites/statistikfilialbilanz.spr",
                          &sbb_background_pixels, &sbb_background));
    assert(load_spr_asset("../extracted/sprites/tabpb01__00.spr",
                          &sbb_row_pixels, &sbb_row_plate));
    assert(load_spr_asset("../extracted/sprites/bewertung__08.spr",
                          &sbb_rating_pixels, &sbb_rating));
    assert(load_spr_asset("../extracted/sprites/skfilialpersonal_00.spr",
                          &sbb_personal_pixels, &sbb_personal));
    assert(load_spr_asset("../extracted/sprites/skfilialmoney_00.spr",
                          &sbb_money_pixels, &sbb_money));
    assert(load_spr_asset("../extracted/sprites/skfilialauslastung_00.spr",
                          &sbb_load_pixels, &sbb_load));
    assert(load_spr_asset("../extracted/sprites/skbilanz_00.spr",
                          &sbb_balance_pixels, &sbb_balance));
    const StatisticsBalanceRow sbb_rows[3] = {
        {"Revenue", operations.revenue},
        {"Ingredients", operations.ingredient_cost},
        {"Wages", operations.wages},
    };
    const StatisticsBranchBalanceData sbb_data = {
        .branch_name = "London branch",
        .period = "Quarter 1",
        .validity = city.city_name,
        .total = operations.revenue - operations.ingredient_cost - operations.wages,
        .rows = sbb_rows,
        .row_count = 3,
        .rating = &sbb_rating,
    };
    uint8_t *sbb_frame = malloc(800 * 600 * 4);
    assert(sbb_frame != NULL);
    RenderSurface sbb_surface;
    assert(render_surface_init(&sbb_surface, sbb_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_statistics_branch_balance(
        &sbb_surface, &sbb_background, &sbb_row_plate, &sbb_rating,
        &sbb_personal, &sbb_money, &sbb_load, &sbb_balance, font_data,
        font_size, &font_info, &sbb_data));
    assert(memcmp(sbb_frame, sbb_background.pixels, 4) == 0);
    free(sbb_frame);
    free(sbb_background_pixels);
    free(sbb_row_pixels);
    free(sbb_rating_pixels);
    free(sbb_personal_pixels);
    free(sbb_money_pixels);
    free(sbb_load_pixels);
    free(sbb_balance_pixels);

    uint8_t *mg_panel_pixels = NULL;
    uint8_t *mg_separator_pixels = NULL;
    RgbaSprite mg_panel;
    RgbaSprite mg_separator;
    assert(load_spr_asset("../extracted/sprites/submenue.spr", &mg_panel_pixels,
                          &mg_panel));
    assert(load_spr_asset("../extracted/sprites/trennzeile.spr",
                          &mg_separator_pixels, &mg_separator));
    const MissionGoalsData mg_data = {
        .title = "Town aims",
        .goal_labels = {"C20 > 2", "+0x14 > 0", "flag 0x16f4"},
        .completed = {(uint8_t)city.mission.completed[0],
                      (uint8_t)city.mission.completed[1],
                      (uint8_t)city.mission.completed[2]},
        .progress = {city.mission.goal_progress[0],
                     city.mission.goal_progress[1],
                     city.mission.goal_progress[2]},
        .years = city.game_length,
        .capital = (uint32_t)city.economy.cash,
        .selected_button = 0,
    };
    uint8_t *mg_frame = malloc(800 * 600 * 4);
    assert(mg_frame != NULL);
    RenderSurface mg_surface;
    assert(render_surface_init(&mg_surface, mg_frame, 800 * 600 * 4, 800, 600));
    assert(screen_render_mission_goals(&mg_surface, &mg_panel, &mg_separator,
                                       font_data, font_size, &font_info,
                                       &mg_data));
    size_t mg_panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(mg_frame + mg_panel_offset, mg_panel.pixels, 4) == 0);
    free(mg_frame);
    free(mg_panel_pixels);
    free(mg_separator_pixels);







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
    piz.companies[0].slot = 0;
    strcpy(piz.companies[0].name, "Ada Pizza");
    piz.companies[0].cash = city.economy.cash;
    piz.companies[0].plan_count = 1;
    piz.companies[0].plans[0] = (PizPlanRecord){
        .active = 1,
        .type = 2,
        .media_type = 1,
        .flags = 1,
        .ingredient_index = 487,
        .target_company = 0xffffffffu,
        .budget = 5000,
        .target_billboard = 0xffffffffu,
        .branch_id = 13694,
        .effect = 60,
    };
    piz.companies[0].recipe_count = 1;
    piz.companies[0].recipes[0].id = 42;
    strcpy(piz.companies[0].recipes[0].name, "Margherita");
    piz.companies[0].recipes[0].topping_count = 1;
    piz.companies[0].recipes[0].toppings[0] = (PizRecipeTopping){
        .ingredient = 5,
        .category = 1,
        .tier = 2,
        .x = 10,
        .y = 20,
        .variant = 1,
        .flag = 1,
    };
    piz.companies[0].branch_count = 1;
    piz.companies[0].branches[0].id = city.branches[0].tile_index;
    strcpy(piz.companies[0].branches[0].name, "London branch");
    piz.companies[0].branches[0].style = 2;
    piz.companies[0].branches[0].flags = 0x24;
    piz.companies[0].branches[0].company_slot = 0;
    piz.companies[0].report_count = 1;
    piz.companies[0].reports[0].income[0] = 100.5f;
    piz.companies[0].reports[0].income[4] = 50.25f;
    piz.companies[0].reports[0].expense[12] = 30.75f;
    piz.companies[0].storage_count = 1;
    piz.companies[0].storage[0].id = 7;
    strcpy(piz.companies[0].storage[0].name, "London storage");
    piz.companies[0].pair_count = 1;
    piz.companies[0].pairs[0].id = 9;
    piz.companies[0].pairs[0].type = 0x17;
    piz.companies[0].pairs[0].state = 1;
    piz.companies[0].big_count = 1;
    piz.companies[0].big[0] = (PizBigRecord){
        .total_customers = 120,
        .max_customers = 40,
        .total_profit = 100,
        .max_profit = 50,
        .total_ratio = 2,
        .max_ratio = 1,
        .value_78 = 7,
        .value_7c = 3,
        .score_customers = 5001,
        .score_profit = 5010,
        .score_ratio = 6000,
        .score_value = 700,
    };
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
    assert(piz_loaded.companies[0].present == 1);
    assert(piz_loaded.companies[0].slot == 0);
    assert(strcmp(piz_loaded.companies[0].name, "Ada Pizza") == 0);
    assert(piz_loaded.companies[0].cash == city.economy.cash);
    assert(piz_loaded.companies[0].plan_count == 1);
    assert(piz_loaded.companies[0].plans[0].active == 1);
    assert(piz_loaded.companies[0].plans[0].type == 2);
    assert(piz_loaded.companies[0].plans[0].media_type == 1);
    assert(piz_loaded.companies[0].plans[0].budget == 5000);
    assert(piz_loaded.companies[0].plans[0].branch_id == 13694);
    assert(piz_loaded.companies[0].plans[0].effect == 60);
    assert(piz_loaded.companies[0].recipe_count == 1);
    assert(piz_loaded.companies[0].recipes[0].id == 42);
    assert(strcmp(piz_loaded.companies[0].recipes[0].name, "Margherita") == 0);
    assert(piz_loaded.companies[0].recipes[0].topping_count == 1);
    assert(piz_loaded.companies[0].recipes[0].toppings[0].ingredient == 5);
    assert(piz_loaded.companies[0].recipes[0].toppings[0].x == 10);
    assert(piz_loaded.companies[0].recipes[0].toppings[0].y == 20);
    assert(piz_loaded.companies[0].branch_count == 1);
    assert(piz_loaded.companies[0].branches[0].id == city.branches[0].tile_index);
    assert(strcmp(piz_loaded.companies[0].branches[0].name, "London branch") == 0);
    assert(piz_loaded.companies[0].branches[0].style == 2);
    assert(piz_loaded.companies[0].branches[0].flags == 0x24);
    assert(piz_loaded.companies[0].report_count == 1);
    assert(piz_loaded.companies[0].reports[0].income[0] == 100.5f);
    assert(piz_loaded.companies[0].reports[0].income[4] == 50.25f);
    assert(piz_loaded.companies[0].reports[0].expense[12] == 30.75f);
    assert(piz_loaded.companies[0].storage_count == 1);
    assert(piz_loaded.companies[0].storage[0].id == 7);
    assert(strcmp(piz_loaded.companies[0].storage[0].name, "London storage") == 0);
    assert(piz_loaded.companies[0].pair_count == 1);
    assert(piz_loaded.companies[0].pairs[0].id == 9);
    assert(piz_loaded.companies[0].pairs[0].type == 0x17);
    assert(piz_loaded.companies[0].pairs[0].state == 1);
    assert(piz_loaded.companies[0].big_count == 1);
    assert(piz_loaded.companies[0].big[0].total_customers == 120);
    assert(piz_loaded.companies[0].big[0].total_profit == 100);
    assert(piz_loaded.companies[0].big[0].score_customers == 5001);
    assert(piz_loaded.companies[0].big[0].score_value == 700);

    puts("unified game reconstruction: OK");
    return 0;
}
