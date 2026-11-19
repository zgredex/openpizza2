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
    uint8_t *left_pixels = NULL;
    uint8_t *right_pixels = NULL;
    uint8_t *help_pixels = NULL;
    uint8_t *button_pixels = NULL;
    uint8_t *storage_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite table;
    RgbaSprite separator;
    RgbaSprite branch_icon;
    RgbaSprite warehouse_icon;
    RgbaSprite arrow_left;
    RgbaSprite arrow_right;
    RgbaSprite help_button;
    RgbaSprite button_background;
    RgbaSprite storage_icon;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/tab01xxx.spr", &table_pixels, &table));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels, &separator));
    assert(load_spr("../extracted/sprites/skfiliale_00.spr", &branch_pixels, &branch_icon));
    assert(load_spr("../extracted/sprites/sklager_00.spr", &warehouse_pixels, &warehouse_icon));
    assert(load_spr("../extracted/sprites/pb26_00.spr", &left_pixels, &arrow_left));
    assert(load_spr("../extracted/sprites/pb27_00.spr", &right_pixels, &arrow_right));
    assert(load_spr("../extracted/sprites/hilfebuttonsnip_00.spr", &help_pixels,
                    &help_button));
    assert(load_spr("../extracted/sprites/textpb01__00.spr", &button_pixels,
                    &button_background));
    assert(load_spr("../extracted/sprites/mg_h_lager_c7.spr", &storage_pixels,
                    &storage_icon));

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
    const BranchListSprites sprites = {
        .panel = &panel,
        .table = &table,
        .separator = &separator,
        .branch_icon = &branch_icon,
        .warehouse_icon = &warehouse_icon,
        .arrow_left = &arrow_left,
        .arrow_right = &arrow_right,
        .help_button = &help_button,
        .button_background = &button_background,
        .storage_icon = &storage_icon,
    };

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_list(&surface, &sprites, font_data,
                                     font_size, &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    size_t branch_offset = ((size_t)(218 + 126) * 800 + (561 + 99)) * 4;
    bool branch_ink = false;
    for (size_t index = 0; index + 3 < (size_t)branch_icon.width * branch_icon.height * 4;
         index += 4) {
        if (branch_icon.pixels[index + 3] == 255) {
            size_t px = (index / 4) % branch_icon.width;
            size_t py = (index / 4) / branch_icon.width;
            size_t target = ((size_t)(218 + 126 + (int)py) * 800 +
                             (561 + 99 + (int)px)) * 4;
            assert(memcmp(frame + target, branch_icon.pixels + index, 4) == 0);
            branch_ink = true;
            break;
        }
    }
    assert(branch_ink);
    (void)branch_offset;

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
    size_t lease_offset = ((size_t)(218 + 278) * 800 + (561 + 220)) * 4;
    assert(frame[lease_offset] != 22 || frame[lease_offset + 1] != 26 ||
           frame[lease_offset + 2] != 34);
    assert(!screen_render_branch_list(&surface, &sprites, font_data,
                                      font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(table_pixels);
    free(separator_pixels);
    free(branch_pixels);
    free(warehouse_pixels);
    free(left_pixels);
    free(right_pixels);
    free(help_pixels);
    free(button_pixels);
    free(storage_pixels);
}

static void test_branch_details_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *logo_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    uint8_t *help_pixels = NULL;
    uint8_t *button_pixels = NULL;
    uint8_t *slider_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite logo;
    RgbaSprite rating;
    RgbaSprite help;
    RgbaSprite button;
    RgbaSprite slider;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/logorahmen_00.spr", &logo_pixels, &logo));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));
    assert(load_spr("../extracted/sprites/hilfebuttonsnip_00.spr",
                    &help_pixels, &help));
    assert(load_spr("../extracted/sprites/textpb01__00.spr", &button_pixels,
                    &button));
    assert(load_spr("../extracted/sprites/sc_00.spr", &slider_pixels, &slider));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    BranchDetailsSprites sprites = {
        .panel = &panel,
        .separator = &separator,
        .logo_frame = &logo,
        .help_button = &help,
        .button_background = &button,
        .slider = &slider,
    };
    for (int index = 0; index < 8; index++) {
        sprites.ratings[index] = &rating;
    }
    const BranchDetailsData data = {
        .employee_name = "Carlos Estarda",
        .employee_role = "Koch",
        .owner_name = "Pizza Tingeltangel",
        .working_location = "Pizzeria",
        .tile_index = 13694,
        .age = 45,
        .cooking = 70,
        .speed = 60,
        .motivation = 80,
        .health = 90,
        .performance = 56,
        .salary = 5656,
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_details(&surface, &sprites, font_data,
                                        font_size, &font, &data));
    size_t panel_offset = ((size_t)218 * 800 + 561) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    size_t logo_offset = ((size_t)(218 + 260) * 800 + (561 + 181)) * 4;
    assert(frame[logo_offset] != 22 || frame[logo_offset + 1] != 26 ||
           frame[logo_offset + 2] != 34);
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
    assert(!screen_render_branch_details(&surface, &sprites, font_data,
                                         font_size, &font, NULL));
    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(logo_pixels);
    free(rating_pixels);
    free(help_pixels);
    free(button_pixels);
    free(slider_pixels);
}

static void test_branch_offer_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    uint8_t *help_pixels = NULL;
    uint8_t *button_pixels = NULL;
    uint8_t *storage_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite rating;
    RgbaSprite help;
    RgbaSprite button;
    RgbaSprite storage;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));
    assert(load_spr("../extracted/sprites/hilfebuttonsnip_00.spr",
                    &help_pixels, &help));
    assert(load_spr("../extracted/sprites/textpb01__00.spr", &button_pixels,
                    &button));
    assert(load_spr("../extracted/sprites/mg_h_lager_b4.spr", &storage_pixels,
                    &storage));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    BranchOfferSprites sprites = {
        .panel = &panel,
        .separator = &separator,
        .button_background = &button,
        .help_button = &help,
        .storage_icon = &storage,
    };
    for (int index = 0; index < 8; index++) {
        sprites.ratings[index] = &rating;
    }
    const BranchOfferData data = {
        .expand_days = 3,
        .cost = 3422,
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_branch_offer(&surface, &sprites, font_data,
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
    size_t button_offset = ((size_t)(218 + 276) * 800 + (561 + 220)) * 4;
    assert(frame[button_offset] != 22 || frame[button_offset + 1] != 26 ||
           frame[button_offset + 2] != 34);
    assert(!screen_render_branch_offer(&surface, &sprites, font_data,
                                       font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(rating_pixels);
    free(help_pixels);
    free(button_pixels);
    free(storage_pixels);
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

static void test_statistics_balance_composition(void) {
    uint8_t *background_pixels = NULL;
    uint8_t *row_pixels = NULL;
    RgbaSprite background;
    RgbaSprite row_plate;
    assert(load_spr("../extracted/sprites/statistikbilanzback.spr",
                    &background_pixels, &background));
    assert(load_spr("../extracted/sprites/tab09.spr", &row_pixels, &row_plate));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    const StatisticsBalanceRow expenses[] = {
        {"Stocks", 30.75},
        {"Rent", 20.0},
        {"Wages", 60.0},
    };
    const StatisticsBalanceRow incomes[] = {
        {"Sales", 100.5},
        {"Other", 50.25},
    };
    const StatisticsBalanceData data = {
        .branch_name = "London branch",
        .period = "Quarter 1",
        .validity = "London",
        .expenses = expenses,
        .expense_count = 3,
        .incomes = incomes,
        .income_count = 2,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_statistics_balance(&surface, &background, &row_plate,
                                             font_data, font_size, &font,
                                             &data));
    assert(memcmp(frame, background.pixels, 4) == 0);

    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)row_plate.width * row_plate.height * 4;
         index += 4) {
        if (row_plate.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t row_x = (opaque_index / 4) % row_plate.width;
    size_t row_y = (opaque_index / 4) / row_plate.width;
    size_t row_offset = ((size_t)(279 + (int)row_y) * 800 +
                         (612 + (int)row_x)) * 4;
    assert(memcmp(frame + row_offset, row_plate.pixels + opaque_index, 4) == 0);

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
    assert(!screen_render_statistics_balance(&surface, &background, &row_plate,
                                              font_data, font_size, &font,
                                              NULL));

    free(font_data);
    free(frame);
    free(background_pixels);
    free(row_pixels);
}

static void test_statistics_branch_balance_composition(void) {
    uint8_t *background_pixels = NULL;
    uint8_t *row_pixels = NULL;
    uint8_t *rating_pixels = NULL;
    uint8_t *personal_pixels = NULL;
    uint8_t *money_pixels = NULL;
    uint8_t *load_pixels = NULL;
    uint8_t *balance_pixels = NULL;
    RgbaSprite background;
    RgbaSprite row_plate;
    RgbaSprite rating;
    RgbaSprite personal;
    RgbaSprite money;
    RgbaSprite load;
    RgbaSprite balance;
    assert(load_spr("../extracted/sprites/statistikfilialbilanz.spr",
                    &background_pixels, &background));
    assert(load_spr("../extracted/sprites/tabpb01__00.spr", &row_pixels,
                    &row_plate));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));
    assert(load_spr("../extracted/sprites/skfilialpersonal_00.spr",
                    &personal_pixels, &personal));
    assert(load_spr("../extracted/sprites/skfilialmoney_00.spr", &money_pixels,
                    &money));
    assert(load_spr("../extracted/sprites/skfilialauslastung_00.spr",
                    &load_pixels, &load));
    assert(load_spr("../extracted/sprites/skbilanz_00.spr", &balance_pixels,
                    &balance));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    const StatisticsBalanceRow rows[] = {
        {"Customers", 120.0},
        {"Revenue", 100.5},
        {"Costs", 30.75},
    };
    const StatisticsBranchBalanceData data = {
        .branch_name = "London branch",
        .period = "Quarter 1",
        .validity = "London",
        .total = 69.75,
        .rows = rows,
        .row_count = 3,
        .rating = &rating,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_statistics_branch_balance(
        &surface, &background, &row_plate, &rating, &personal, &money, &load,
        &balance, font_data, font_size, &font, &data));
    assert(memcmp(frame, background.pixels, 4) == 0);

    bool opaque = false;
    size_t opaque_index = 0;
    for (size_t index = 0; index + 3 < (size_t)row_plate.width * row_plate.height * 4;
         index += 4) {
        if (row_plate.pixels[index + 3] == 255) {
            opaque = true;
            opaque_index = index;
            break;
        }
    }
    assert(opaque);
    size_t row_x = (opaque_index / 4) % row_plate.width;
    size_t row_y = (opaque_index / 4) / row_plate.width;
    size_t row_offset = ((size_t)(279 + (int)row_y) * 800 +
                         (611 + (int)row_x)) * 4;
    assert(memcmp(frame + row_offset, row_plate.pixels + opaque_index, 4) == 0);

    bool rating_opaque = false;
    size_t rating_index = 0;
    for (size_t index = 0; index + 3 < (size_t)rating.width * rating.height * 4;
         index += 4) {
        if (rating.pixels[index + 3] == 255) {
            rating_opaque = true;
            rating_index = index;
            break;
        }
    }
    assert(rating_opaque);
    size_t rating_x = (rating_index / 4) % rating.width;
    size_t rating_y = (rating_index / 4) / rating.width;
    size_t rating_offset = ((size_t)(79 + (int)rating_y) * 800 +
                            (245 + (int)rating_x)) * 4;
    assert(memcmp(frame + rating_offset, rating.pixels + rating_index, 4) == 0);

    bool title_ink = false;
    for (int y = 220; y < 245; y++) {
        for (int x = 600; x < 780; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    assert(!screen_render_statistics_branch_balance(
        &surface, &background, &row_plate, &rating, &personal, &money, &load,
        &balance, font_data, font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(background_pixels);
    free(row_pixels);
    free(rating_pixels);
    free(personal_pixels);
    free(money_pixels);
    free(load_pixels);
    free(balance_pixels);
}

static void test_mission_goals_composition(void) {
    uint8_t *panel_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    RgbaSprite panel;
    RgbaSprite separator;
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    const MissionGoalsData data = {
        .title = "Town aims",
        .help_text = "#Hier steht, welches Szenario f\u00fcr diese Stadt vorgesehen ist.",
        .goal_labels = {"#Retten Sie die Welt.",
                        "#Verdienen Sie dabei so viel Geld wie m\u00f6glich.",
                        "#Achten Sie auf eine gesunde Umwelt."},
        .completed = {1, 1, 1},
        .progress = {3, 1, 1},
        .years = 2,
        .capital = 500000,
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_mission_goals(&surface, &panel, &separator, font_data,
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
    bool goal_ink = false;
    for (int y = 430; y < 452; y++) {
        for (int x = 630; x < 760; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 140) {
                goal_ink = true;
            }
        }
    }
    assert(goal_ink);
    size_t button_offset = ((size_t)(218 + 350) * 800 + (561 + 215)) * 4;
    assert(frame[button_offset + 1] > frame[button_offset]);
    assert(!screen_render_mission_goals(&surface, &panel, &separator, font_data,
                                        font_size, &font, NULL));

    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
}

static void test_recipe_info_panel_composition(void) {
    uint8_t *panel_pixels = NULL;
    RgbaSprite panel;
    assert(load_spr("../extracted/sprites/dummysprite.spr", &panel_pixels, &panel));
    const char *paths[9] = {
        "../extracted/sprites/r_info__00.spr",
        "../extracted/sprites/r_neurezept__00.spr",
        "../extracted/sprites/r_zutaten__00.spr",
        "../extracted/sprites/r_speisekarte__00.spr",
        "../extracted/sprites/r_rezautomatik__00.spr",
        "../extracted/sprites/r_lupe__00.spr",
        "../extracted/sprites/r_infowett__00.spr",
        "../extracted/sprites/r_neurezeptwett__00.spr",
        "../extracted/sprites/r_zutatenwett__00.spr",
    };
    uint8_t *pixels[9] = {NULL};
    RgbaSprite buttons[9];
    for (int index = 0; index < 9; index++) {
        assert(load_spr(paths[index], &pixels[index], &buttons[index]));
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_recipe_info_panel(&surface, &panel, buttons, 0));
    size_t panel_offset = ((size_t)248 * 800 + 567) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    bool first_ink = false;
    for (int y = 251; y < 282; y++) {
        for (int x = 568; x < 605; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                first_ink = true;
            }
        }
    }
    assert(first_ink);
    assert(!screen_render_recipe_info_panel(&surface, &panel, NULL, 0));
    free(frame);
    free(panel_pixels);
    for (int index = 0; index < 9; index++) {
        free(pixels[index]);
    }
}

static void test_game_sidebar_composition(void) {
    uint8_t *panel_pixels = NULL;
    RgbaSprite panel;
    assert(load_spr("../extracted/sprites/dummysprite.spr", &panel_pixels, &panel));
    const char *paths[10] = {
        "../extracted/sprites/r_info__00.spr",
        "../extracted/sprites/r_personal__00.spr",
        "../extracted/sprites/r_einrichtung__00.spr",
        "../extracted/sprites/r_speisekarte__00.spr",
        "../extracted/sprites/r_bilanz__00.spr",
        "../extracted/sprites/r_werbung__00.spr",
        "../extracted/sprites/r_inarchi__00.spr",
        "../extracted/sprites/r_manager__00.spr",
        "../extracted/sprites/r_lupe__00.spr",
        "../extracted/sprites/r_bauen__00.spr",
    };
    uint8_t *pixels[10] = {NULL};
    RgbaSprite buttons[10];
    for (int index = 0; index < 10; index++) {
        assert(load_spr(paths[index], &pixels[index], &buttons[index]));
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_game_sidebar(&surface, &panel, buttons, 0));
    size_t panel_offset = ((size_t)248 * 800 + 567) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    bool ink = false;
    for (int y = 251; y < 282; y++) {
        for (int x = 568; x < 605; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                ink = true;
            }
        }
    }
    assert(ink);
    assert(!screen_render_game_sidebar(&surface, &panel, NULL, 0));
    free(frame);
    free(panel_pixels);
    for (int index = 0; index < 10; index++) {
        free(pixels[index]);
    }
}

static void test_options_sidebar_composition(void) {
    uint8_t *panel_pixels = NULL;
    RgbaSprite panel;
    assert(load_spr("../extracted/sprites/dummysprite.spr", &panel_pixels, &panel));
    const char *paths[5] = {
        "../extracted/sprites/r_grafik__00.spr",
        "../extracted/sprites/r_laden__00.spr",
        "../extracted/sprites/r_sound__00.spr",
        "../extracted/sprites/r_speichern__00.spr",
        "../extracted/sprites/r_help__00.spr",
    };
    uint8_t *pixels[5] = {NULL};
    RgbaSprite buttons[5];
    for (int index = 0; index < 5; index++) {
        assert(load_spr(paths[index], &pixels[index], &buttons[index]));
    }
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_options_sidebar(&surface, &panel, buttons, 0));
    size_t panel_offset = ((size_t)248 * 800 + 567) * 4;
    assert(memcmp(frame + panel_offset, panel.pixels, 4) == 0);
    bool ink = false;
    for (int y = 251; y < 282; y++) {
        for (int x = 568; x < 605; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                ink = true;
            }
        }
    }
    assert(ink);
    assert(!screen_render_options_sidebar(&surface, &panel, NULL, 0));
    free(frame);
    free(panel_pixels);
    for (int index = 0; index < 5; index++) {
        free(pixels[index]);
    }
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
    uint8_t *button_pixels = NULL;
    RgbaSprite button_sprite;
    assert(load_spr("../extracted/sprites/textpbtranspgelb_00.spr",
                    &button_pixels, &button_sprite));

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
    assert(screen_render_menu(&surface, tga, tga_size, font_data, font_size,
                              &font, &button_sprite, &menu, decoded,
                              frame_size));

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
    assert(screen_render_menu(&surface, tga, tga_size, font_data, font_size,
                              &font, &button_sprite, &menu, decoded,
                              frame_size));
    assert(menu.has_status);

    free(tga);
    free(font_data);
    free(button_pixels);
    free(decoded);
    free(frame);
    test_character_select_composition();
    test_branch_list_composition();
    test_branch_details_composition();
    test_branch_offer_composition();
    test_personnel_overview_composition();
    test_personnel_record_composition();
    test_statistics_balance_composition();
    test_statistics_branch_balance_composition();
    test_mission_goals_composition();
    test_recipe_info_panel_composition();
    test_options_sidebar_composition();
    test_game_sidebar_composition();
    test_statistics_composition();
    test_free_play_composition();
    test_briefing_composition();
    puts("screen render reconstruction: OK");
    return 0;
}
