#include "screen_render.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint8_t *load_file(const char *path, size_t *length) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    if (size <= 0) {
        fclose(file);
        return NULL;
    }
    uint8_t *data = malloc((size_t)size);
    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    if (fread(data, 1, (size_t)size, file) != (size_t)size) {
        free(data);
        fclose(file);
        return NULL;
    }
    fclose(file);
    *length = (size_t)size;
    return data;
}

static void test_character_select_composition(void) {
    size_t tga_size = 0;
    size_t font_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/pe_charakterauswahl.tga", &tga_size);
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(tga != NULL);
    assert(font_data != NULL);

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    CharacterScreenData data = {
        .player_name = "Ada",
        .enterprise_name = "Ada Pizza",
        .attributes = {5, 3, 4, 2, 5, 4},
        .difficulty = 9,
        .selected_button = 1,
    };

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_character_select(&surface, tga, tga_size, font_data,
                                          font_size, &font, &data, decoded,
                                          frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);

    bool title_ink = false;
    for (int y = 4; y < 30; y++) {
        for (int x = 10; x < 300; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t start_offset = ((size_t)560 * 800 + 700) * 4;
    assert(frame[start_offset + 1] > frame[start_offset]);
    assert(!screen_render_character_select(&surface, tga, tga_size, font_data,
                                           font_size, &font, NULL, decoded,
                                           frame_size));

    free(tga);
    free(font_data);
    free(decoded);
    free(frame);
}

static bool load_spr(const char *path, uint8_t **pixels, RgbaSprite *sprite) {
    size_t length = 0;
    uint8_t *data = load_file(path, &length);
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

static void test_branch_list_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *table_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *branch_pixels = NULL;
    uint8_t *warehouse_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite table;
    RgbaSprite separator;
    RgbaSprite branch_icon;
    RgbaSprite warehouse_icon;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/tab01xxx.spr", &table_pixels, &table));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels, &separator));
    assert(load_spr("../extracted/sprites/skfiliale_00.spr", &branch_pixels, &branch_icon));
    assert(load_spr("../extracted/sprites/sklager_00.spr", &warehouse_pixels, &warehouse_icon));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    const BranchListEntry entries[] = {
        {13694, 5730, false},
        {7, 0, true},
    };
    const BranchListData data = {
        .city = "London",
        .entries = entries,
        .entry_count = 2,
        .selected = 0,
    };

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_list(&surface, &panel, &table, &separator,
                                     &branch_icon, &warehouse_icon, font_data,
                                     font_size, &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t lease_offset = ((size_t)(220 + 276) * 800 + (561 + 160)) * 4;
    assert(frame[lease_offset + 1] > frame[lease_offset]);
    assert(!screen_render_branch_list(&surface, &panel, &table, &separator,
                                      &branch_icon, &warehouse_icon, font_data,
                                      font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(table_pixels);
    free(separator_pixels);
    free(branch_pixels);
    free(warehouse_pixels);
}

static void test_branch_details_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *logo_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite logo;
    RgbaSprite rating;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/logorahmen_00.spr", &logo_pixels, &logo));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    const BranchDetailsData data = {
        .branch_name = "London branch",
        .employee_name = "Carlos Estarda",
        .employee_role = "Cook",
        .owner_name = "Pizza Tingeltangel",
        .tile_index = 13694,
        .age = 45,
        .cooking = 5,
        .speed = 4,
        .motivation = 3,
        .health = 5,
        .performance = 56,
        .salary = 5656,
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_details(&surface, &panel, &separator, &logo,
                                        &rating, font_data, font_size, &font,
                                        &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)rating.width * rating.height * 4;
         index += 4) {
        if (rating.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t rating_x = (opaque_index / 4) % rating.width;
    size_t rating_y = (opaque_index / 4) / rating.width;
    size_t rating_offset = ((size_t)(218 + 315 + (int)rating_y) * 800 +
                            (561 + 199 + (int)rating_x)) * 4;
    assert(memcmp(frame + rating_offset, rating.pixels + opaque_index, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t button_offset = ((size_t)(218 + 100) * 800 + (561 + 215)) * 4;
    assert(frame[button_offset] > 200 && frame[button_offset + 1] > 180);
    assert(!screen_render_branch_details(&surface, &panel, &separator, &logo,
                                         &rating, font_data, font_size, &font,
                                         NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(logo_pixels);
    free(rating_pixels);
}

static void test_branch_offer_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite rating;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    BranchOfferData data = {
        .branch_name = "London branch",
        .expand_days = 3,
        .cost = 3422,
        .capacity = 100,
        .new_capacity = 150,
        .selected_button = 0,
    };
    for (int index = 0; index < 8; index++) {
        data.ratings[index] = &rating;
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_offer(&surface, &panel, &separator, font_data,
                                      font_size, &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);

    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)rating.width * rating.height * 4;
         index += 4) {
        if (rating.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t rating_x = (opaque_index / 4) % rating.width;
    size_t rating_y = (opaque_index / 4) / rating.width;
    size_t rating_offset = ((size_t)(218 + 315 + (int)rating_y) * 800 +
                            (561 + 49 + (int)rating_x)) * 4;
    assert(memcmp(frame + rating_offset, rating.pixels + opaque_index, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t button_offset = ((size_t)(218 + 274) * 800 + (561 + 215)) * 4;
    assert(frame[button_offset + 1] > frame[button_offset]);
    assert(!screen_render_branch_offer(&surface, &panel, &separator, font_data,
                                       font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(rating_pixels);
}

static void test_personnel_overview_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    uint8_t *tab_pixels[4] = {NULL, NULL, NULL, NULL};
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite rating;
    RgbaSprite tabs[4];
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));
    assert(load_spr("../extracted/sprites/persoueber_00.spr", &tab_pixels[0],
                    &tabs[0]));
    assert(load_spr("../extracted/sprites/persoueber_01.spr", &tab_pixels[1],
                    &tabs[1]));
    assert(load_spr("../extracted/sprites/persoueber_02.spr", &tab_pixels[2],
                    &tabs[2]));
    assert(load_spr("../extracted/sprites/persoueber_03.spr", &tab_pixels[3],
                    &tabs[3]));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    PersonnelOverviewData data = {
        .candidate_name = "Carlos Estarda",
        .profession = "Cook",
        .age = 45,
        .health = 90,
        .motivation = 75,
        .cooking = 70,
        .speed = 60,
        .selected_tab = 0,
        .selected_button = 0,
    };
    for (int index = 0; index < 4; index++) {
        data.ratings[index] = &rating;
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_personnel_overview(&surface, &panel, tabs, &separator,
                                            font_data, font_size, &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    size_t tab_offset = ((size_t)(218 + 242) * 800 + (561 + 53)) * 4;
    assert(memcmp(frame + tab_offset, tabs[0].pixels, 4) == 0);

    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)rating.width * rating.height * 4;
         index += 4) {
        if (rating.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t rating_x = (opaque_index / 4) % rating.width;
    size_t rating_y = (opaque_index / 4) / rating.width;
    size_t rating_offset = ((size_t)(218 + 315 + (int)rating_y) * 800 +
                            (561 + 49 + (int)rating_x)) * 4;
    assert(memcmp(frame + rating_offset, rating.pixels + opaque_index, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t button_offset = ((size_t)(218 + 100) * 800 + (561 + 215)) * 4;
    assert(frame[button_offset + 1] > frame[button_offset]);
    assert(!screen_render_personnel_overview(&surface, &panel, tabs, &separator,
                                             font_data, font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(rating_pixels);
    for (int index = 0; index < 4; index++) {
        free(tab_pixels[index]);
    }
}

static void test_personnel_record_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *plan_pixels = NULL;
    uint8_t *light_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite plan;
    RgbaSprite light;
    RgbaSprite separator;
    RgbaSprite rating;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/persoplan.spr", &plan_pixels, &plan));
    assert(load_spr("../extracted/sprites/persoplanlight.spr", &light_pixels,
                    &light));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    PersonnelRecordData data = {
        .employee_name = "Carlos Estarda",
        .profession = "Cook",
        .age = 45,
        .cooking = 70,
        .speed = 60,
        .motivation = 75,
        .health = 90,
    };
    for (int index = 0; index < 8; index++) {
        data.ratings[index] = &rating;
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_personnel_record(&surface, &panel, &plan, &light,
                                          &separator, font_data, font_size,
                                          &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    bool plan_opaque = false;
    for (size_t index = 0; index + 3 < (size_t)plan.width * plan.height * 4;
         index += 4) {
        if (plan.pixels[index + 3] == 255) {
            size_t px = (index / 4) % plan.width;
            size_t py = (index / 4) / plan.width;
            size_t target = ((size_t)(218 + 224 + (int)py) * 800 +
                             (561 + 48 + (int)px)) * 4;
            assert(memcmp(frame + target, plan.pixels + index, 4) == 0);
            plan_opaque = true;
            break;
        }
    }
    assert(plan_opaque);

    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)rating.width * rating.height * 4;
         index += 4) {
        if (rating.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t rating_x = (opaque_index / 4) % rating.width;
    size_t rating_y = (opaque_index / 4) / rating.width;
    size_t rating_offset = ((size_t)(218 + 315 + (int)rating_y) * 800 +
                            (561 + 49 + (int)rating_x)) * 4;
    assert(memcmp(frame + rating_offset, rating.pixels + opaque_index, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    assert(!screen_render_personnel_record(&surface, &panel, &plan, &light,
                                           &separator, font_data, font_size,
                                           &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(plan_pixels);
    free(light_pixels);
    free(separator_pixels);
    free(rating_pixels);
}

static void test_statistics_composition(void) {
    size_t tga_size = 0;
    size_t font_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/bg003.tga", &tga_size);
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(tga != NULL);
    assert(font_data != NULL);

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

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

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_statistics(&surface, tga, tga_size, font_data, font_size,
                                    &font, &stats, "London", "17.32.2003",
                                    decoded, frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);

    bool title_ink = false;
    for (int y = 18; y < 44; y++) {
        for (int x = 28; x < 200; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    assert(!screen_render_statistics(&surface, tga, tga_size, font_data, font_size,
                                     &font, NULL, "London", "17.32.2003",
                                     decoded, frame_size));

    free(tga);
    free(font_data);
    free(decoded);
    free(frame);
}

static void test_free_play_composition(void) {
    size_t tga_size = 0;
    size_t font_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/pe_freies_spiel.tga", &tga_size);
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(tga != NULL);
    assert(font_data != NULL);

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    FreePlayScenario scenario = {
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

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_free_play(&surface, tga, tga_size, font_data, font_size,
                                   &font, &scenario, decoded, frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);

    bool title_ink = false;
    for (int y = 4; y < 30; y++) {
        for (int x = 10; x < 300; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    size_t start_offset = ((size_t)560 * 800 + 700) * 4;
    assert(frame[start_offset + 1] > frame[start_offset]);
    assert(!screen_render_free_play(&surface, tga, tga_size, font_data, font_size,
                                    &font, NULL, decoded, frame_size));

    free(tga);
    free(font_data);
    free(decoded);
    free(frame);
}

static void test_briefing_composition(void) {
    size_t tga_size = 0;
    size_t font_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/pe_missionsbriefing_lon.tga",
                             &tga_size);
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(tga != NULL);
    assert(font_data != NULL);

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    const char *title = "London";
    const char *body =
        "You begin your life as - hopefully - a successful pizza chef. Your boss "
        "sits in New York and has selected you from the many applications to be "
        "his new regional manager. Since the English are infamous for having no "
        "taste where food is concerned, you shouldn't have too much of a problem "
        "conquering the city with your tasty pizzas.";
    const char *prompt = "Press any key to continue";

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));

    int lines = screen_render_briefing(&surface, tga, tga_size, font_data,
                                       font_size, &font, title, body, prompt,
                                       decoded, frame_size);
    assert(lines >= 4);
    assert(memcmp(frame, decoded, frame_size) != 0);
    uint32_t light = 0;
    for (int y = 130; y < 300; y++) {
        for (int x = 90; x < 700; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] > 200 && frame[offset + 1] > 200 &&
                frame[offset + 2] > 200) {
                light += 1;
            }
        }
    }
    assert(light > 500);

    assert(screen_render_briefing(&surface, tga, tga_size, font_data, font_size,
                                  &font, NULL, body, prompt, decoded,
                                  frame_size) == -1);

    free(tga);
    free(font_data);
    free(decoded);
    free(frame);
}

int main(void) {
    size_t tga_size = 0;
    size_t font_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/pe_startscreen.tga", &tga_size);
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(tga != NULL);
    assert(font_data != NULL);

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    assert(font.line_height == 23);

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));

    MenuState menu;
    menu_state_init(&menu);
    menu_set_hover(&menu, 0);
    assert(screen_render_menu(&surface, tga, tga_size, font_data, font_size, &font,
                              &menu, decoded, frame_size));

    bool highlight = false;
    bool text_ink = false;
    for (int y = 6; y < 44; y++) {
        for (int x = 595; x < 799; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] > 100 && frame[offset + 1] > 80) {
                highlight = true;
            }
            if (frame[offset] < 40 && frame[offset + 1] < 40 && frame[offset + 2] < 40) {
                text_ink = true;
            }
        }
    }
    assert(highlight);
    assert(text_ink);

    menu_set_selected(&menu, 2);
    menu_activate(&menu);
    assert(screen_render_menu(&surface, tga, tga_size, font_data, font_size, &font,
                              &menu, decoded, frame_size));
    assert(menu.has_status);

    free(tga);
    free(font_data);
    free(decoded);
    free(frame);
    test_character_select_composition();
    test_branch_list_composition();
    test_branch_details_composition();
    test_branch_offer_composition();
    test_personnel_overview_composition();
    test_personnel_record_composition();
    test_statistics_composition();
    test_free_play_composition();
    test_briefing_composition();
    puts("screen render reconstruction: OK");
    return 0;
}
