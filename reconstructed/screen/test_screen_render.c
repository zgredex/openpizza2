#include "screen_render.h"

#include "../assets/ani.h"

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

static bool load_spr(const char *path, uint8_t **pixels, RgbaSprite *sprite);

static void test_character_select_composition(void) {
    size_t tga_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/pe_charakterauswahl.tga", &tga_size);
    assert(tga != NULL);
    static const char *const sprite_paths[CHARACTER_SELECT_ASSET_COUNT] = {
        "../extracted/sprites/pb22_00.spr",
        "../extracted/sprites/pb24_00.spr",
        "../extracted/sprites/pb26_00.spr",
        "../extracted/sprites/pb27_00.spr",
        "../extracted/sprites/sl02_00.spr",
        "../extracted/sprites/fotorahmen00.spr",
        "../extracted/sprites/fotodummy00.spr",
        "../extracted/sprites/textpbtranspgelb_00.spr",
        "../extracted/sprites/textpbtranspgruen_00.spr",
        "../extracted/sprites/geschlecht_m_00.spr",
        "../extracted/sprites/geschlecht_w_00.spr",
        "../extracted/sprites/playlog_2_01_00.spr",
        "../extracted/sprites/logofenster.spr",
        "../extracted/sprites/leuchtfeld_00_00.spr",
    };
    static const char *const font_paths[CHARACTER_SELECT_FONT_COUNT] = {
        "../extracted/fonts/timesfont.fnt",
        "../extracted/fonts/verdana10.fnt",
        "../extracted/fonts/verdana8.fnt",
        "../extracted/fonts/times14.fnt",
    };
    uint8_t *sprite_pixels[CHARACTER_SELECT_ASSET_COUNT] = {NULL};
    RgbaSprite sprites[CHARACTER_SELECT_ASSET_COUNT];
    for (int index = 0; index < CHARACTER_SELECT_ASSET_COUNT; index++) {
        assert(load_spr(sprite_paths[index], &sprite_pixels[index],
                        &sprites[index]));
    }
    uint8_t *font_data[CHARACTER_SELECT_FONT_COUNT] = {NULL};
    size_t font_sizes[CHARACTER_SELECT_FONT_COUNT] = {0};
    FntInfo font_infos[CHARACTER_SELECT_FONT_COUNT];
    for (int index = 0; index < CHARACTER_SELECT_FONT_COUNT; index++) {
        font_data[index] = load_file(font_paths[index], &font_sizes[index]);
        assert(font_data[index] != NULL);
        assert(fnt_read_info(font_data[index], font_sizes[index],
                             &font_infos[index]));
    }
    CharacterSelectAssets assets = {0};
    for (int index = 0; index < CHARACTER_SELECT_ASSET_COUNT; index++) {
        assets.sprites[index] = &sprites[index];
    }
    for (int index = 0; index < CHARACTER_SELECT_FONT_COUNT; index++) {
        assets.fonts[index] = (CharacterSelectFont){
            font_data[index], font_sizes[index], &font_infos[index]};
    }
    assert(kCharacterSelectControlCount == 66);
    const CharacterSelectControl *control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1056) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 13 && control->y == 5);
    assert(control->font == 0 && control->align == 2 && control->width == 560);
    assert(strcmp(control->text, "Select player character") == 0);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1033) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 609 && control->y == 304);
    assert(control->align == 2 && control->width == 180);
    assert(strcmp(control->text, "Enterprise name:") == 0);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1031) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 617 && control->y == 461);
    assert(control->kind == CHARACTER_SELECT_KIND_SLIDER);
    assert(control->asset == CHARACTER_SELECT_ASSET_SLIDER);
    assert(control->width == 175);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1034) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->kind == CHARACTER_SELECT_KIND_INPUT);
    assert(control->x == 616 && control->y == 347);
    assert(control->font == 3 && control->width == 170);
    assert(strcmp(control->text, "#Unternehmensname") == 0);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1076) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->kind == CHARACTER_SELECT_KIND_BUTTON);
    assert(control->x == 595 && control->y == 509);
    assert(control->asset == CHARACTER_SELECT_ASSET_BUTTON_YELLOW);
    assert(control->width == 204);
    assert(strcmp(control->text, "To main menu") == 0);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1086) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 626 && control->y == 54);
    assert(control->asset == CHARACTER_SELECT_ASSET_LOGO);
    control = NULL;
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        if (kCharacterSelectControls[index].id == 1087) {
            control = &kCharacterSelectControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 42 && control->y == 343);
    assert(control->asset == CHARACTER_SELECT_ASSET_LIGHT);

    CharacterScreenData data = {
        .player_name = "Ada",
        .enterprise_name = "Ada Pizza",
        .attributes = {5, 3, 4, 2, 5, 4},
        .difficulty = 2,
        .selected_button = 1,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_character_select(&surface, tga, tga_size, &assets,
                                          &data, decoded, frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);

    bool title_ink = false;
    for (int y = 4; y < 28; y++) {
        for (int x = 10; x < 300; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    bool name_ink = false;
    for (int y = 347; y < 365; y++) {
        for (int x = 51; x < 210; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                name_ink = true;
            }
        }
    }
    assert(name_ink);
    bool start_text_ink = false;
    for (int y = 551; y < 590; y++) {
        for (int x = 595; x < 799; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 80 && frame[offset + 1] < 80 &&
                frame[offset + 2] < 80) {
                start_text_ink = true;
            }
        }
    }
    assert(start_text_ink);
    bool slider_ink = false;
    for (int y = 458; y < 472; y++) {
        for (int x = 680; x < 730; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                slider_ink = true;
            }
        }
    }
    assert(slider_ink);
    assert(!screen_render_character_select(&surface, tga, tga_size, NULL,
                                           &data, decoded, frame_size));

    for (int index = 0; index < CHARACTER_SELECT_FONT_COUNT; index++) {
        free(font_data[index]);
    }
    for (int index = 0; index < CHARACTER_SELECT_ASSET_COUNT; index++) {
        free(sprite_pixels[index]);
    }
    free(tga);
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
    uint8_t *button_pixels = NULL;
    uint8_t *help_pixels = NULL;
    uint8_t *frame_pixels = NULL;
    uint8_t *dummy_pixels = NULL;
    uint8_t *light_pixels = NULL;
    uint8_t *slider_pixels = NULL;
    uint8_t *left_pixels = NULL;
    uint8_t *right_pixels = NULL;
    uint8_t *on_off_pixels[4] = {NULL, NULL, NULL, NULL};
    uint8_t *lower_slider_pixels[4] = {NULL, NULL, NULL, NULL};
    uint8_t *slider_bar_pixels[4] = {NULL, NULL, NULL, NULL};
    uint8_t *tab_pixels[4] = {NULL, NULL, NULL, NULL};
    RgbaSprite panel;
    RgbaSprite separator;
    RgbaSprite rating;
    RgbaSprite button;
    RgbaSprite help;
    RgbaSprite photo_frame;
    RgbaSprite photo_dummy;
    RgbaSprite plan_light;
    RgbaSprite slider;
    RgbaSprite arrow_left;
    RgbaSprite arrow_right;
    RgbaSprite tabs[4];
    RgbaSprite on_off[4];
    RgbaSprite lower_sliders[4];
    RgbaSprite slider_bars[4];
    assert(load_spr("../extracted/sprites/submenue.spr", &panel_pixels, &panel));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/bewertung__08.spr", &rating_pixels,
                    &rating));
    assert(load_spr("../extracted/sprites/textpb01__00.spr", &button_pixels,
                    &button));
    assert(load_spr("../extracted/sprites/hilfebuttonsnip_00.spr",
                    &help_pixels, &help));
    assert(load_spr("../extracted/sprites/fotorahmen00.spr", &frame_pixels,
                    &photo_frame));
    assert(load_spr("../extracted/sprites/fotodummy00.spr", &dummy_pixels,
                    &photo_dummy));
    assert(load_spr("../extracted/sprites/persoplanlight.spr", &light_pixels,
                    &plan_light));
    assert(load_spr("../extracted/sprites/sc_00.spr", &slider_pixels, &slider));
    assert(load_spr("../extracted/sprites/pb22_00.spr", &left_pixels, &arrow_left));
    assert(load_spr("../extracted/sprites/pb24_00.spr", &right_pixels, &arrow_right));
    assert(load_spr("../extracted/sprites/persoueber_00.spr", &tab_pixels[0],
                    &tabs[0]));
    assert(load_spr("../extracted/sprites/persoueber_01.spr", &tab_pixels[1],
                    &tabs[1]));
    assert(load_spr("../extracted/sprites/persoueber_02.spr", &tab_pixels[2],
                    &tabs[2]));
    assert(load_spr("../extracted/sprites/persoueber_03.spr", &tab_pixels[3],
                    &tabs[3]));
    const char *on_off_paths[4] = {
        "../extracted/sprites/pb16_onoff_00.spr",
        "../extracted/sprites/pb18_onoff_00.spr",
        "../extracted/sprites/pb23_onoff_00.spr",
        "../extracted/sprites/pb21_onoff_00.spr",
    };
    const char *lower_paths[4] = {
        "../extracted/sprites/persosliderblue_00.spr",
        "../extracted/sprites/persoslidergreen_00.spr",
        "../extracted/sprites/persosliderred_00.spr",
        "../extracted/sprites/persoslideryellow_00.spr",
    };
    const char *bar_paths[4] = {
        "../extracted/sprites/persosliderblau_00.spr",
        "../extracted/sprites/persosliderblau_01.spr",
        "../extracted/sprites/persoslidergelb_00.spr",
        "../extracted/sprites/persoslidergelb_01.spr",
    };
    for (int index = 0; index < 4; index++) {
        assert(load_spr(on_off_paths[index], &on_off_pixels[index],
                        &on_off[index]));
        assert(load_spr(lower_paths[index], &lower_slider_pixels[index],
                        &lower_sliders[index]));
        assert(load_spr(bar_paths[index], &slider_bar_pixels[index],
                        &slider_bars[index]));
    }

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    PersonnelOverviewSprites sprites = {
        .panel = &panel,
        .tabs = tabs,
        .separator = &separator,
        .button_background = &button,
        .help_button = &help,
        .arrow_left = &arrow_left,
        .arrow_right = &arrow_right,
        .photo_frame = &photo_frame,
        .photo_dummy = &photo_dummy,
        .plan_light = &plan_light,
        .slider = &slider,
    };
    for (int index = 0; index < 4; index++) {
        sprites.on_off[index] = &on_off[index];
        sprites.lower_sliders[index] = &lower_sliders[index];
        sprites.slider_bars[index] = &slider_bars[index];
    }
    for (int index = 0; index < 8; index++) {
        sprites.ratings[index] = &rating;
    }
    const PersonnelOverviewData data = {
        .candidate_name = "Carlos Estarda",
        .profession = "Koch",
        .age = 45,
        .health = 90,
        .motivation = 75,
        .cooking = 70,
        .speed = 60,
        .performance = 56,
        .salary = 5656,
        .selected_tab = 0,
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_personnel_overview(&surface, &sprites, font_data,
                                             font_size, &font, &data));
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
    assert(!screen_render_personnel_overview(&surface, &sprites, font_data,
                                             font_size, &font, NULL));
    free(font_data);
    free(frame);
    free(panel_pixels);
    free(separator_pixels);
    free(rating_pixels);
    free(button_pixels);
    free(help_pixels);
    free(frame_pixels);
    free(dummy_pixels);
    free(light_pixels);
    free(slider_pixels);
    free(left_pixels);
    free(right_pixels);
    for (int index = 0; index < 4; index++) {
        free(tab_pixels[index]);
        free(on_off_pixels[index]);
        free(lower_slider_pixels[index]);
        free(slider_bar_pixels[index]);
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
    static const char *const sprite_paths[BALANCE_ASSET_COUNT] = {
        "../extracted/sprites/tab09.spr",
        "../extracted/sprites/tabpb01__00.spr",
        "../extracted/sprites/sl01_00.spr",
        "../extracted/sprites/trennzeile.spr",
        "../extracted/sprites/pb33_00.spr",
        "../extracted/sprites/pb22_00.spr",
        "../extracted/sprites/pb24_00.spr",
        "../extracted/sprites/textpb05__00.spr",
        "../extracted/sprites/hilfebuttonsnip_00.spr",
        "../extracted/sprites/statistikbilanzback.spr",
    };
    static const char *const font_paths[6] = {
        "../extracted/fonts/timesfont.fnt",
        "../extracted/fonts/verdana7.fnt",
        "../extracted/fonts/verdana8.fnt",
        "../extracted/fonts/vedana11.fnt",
        "../extracted/fonts/verdana10.fnt",
        "../extracted/fonts/verdana14.fnt",
    };
    uint8_t *sprite_pixels[BALANCE_ASSET_COUNT] = {NULL};
    RgbaSprite sprites[BALANCE_ASSET_COUNT];
    for (int index = 0; index < BALANCE_ASSET_COUNT; index++) {
        assert(load_spr(sprite_paths[index], &sprite_pixels[index],
                        &sprites[index]));
    }
    uint8_t *font_data[6] = {NULL};
    size_t font_sizes[6] = {0};
    FntInfo font_infos[6];
    for (int index = 0; index < 6; index++) {
        font_data[index] = load_file(font_paths[index], &font_sizes[index]);
        assert(font_data[index] != NULL);
        assert(fnt_read_info(font_data[index], font_sizes[index],
                             &font_infos[index]));
    }
    StatisticsBalanceAssets assets = {0};
    for (int index = 0; index < BALANCE_ASSET_COUNT; index++) {
        assets.sprites[index] = &sprites[index];
    }
    for (int index = 0; index < 6; index++) {
        assets.fonts[index] = (StatisticsBalanceFont){
            font_data[index], font_sizes[index], &font_infos[index]};
    }
    assert(kBalanceControlCount == 162);
    const BalanceControl *control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1000) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 605 && control->y == 223);
    assert(control->kind == BALANCE_KIND_TEXT);
    assert(control->font == 0 && control->align == 2 && control->width == 190);
    assert(strcmp(control->text, "Balance") == 0);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1016) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 614 && control->y == 282);
    assert(control->font == 1 && control->align == 0 && control->width == 60);
    assert(strcmp(control->text, "Total:") == 0);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1043) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 46 && control->y == 90);
    assert(control->font == 2 && control->width == 160);
    assert(strcmp(control->text, "Warehouse rent") == 0);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1041) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 456 && control->y == 66);
    assert(control->font == 3 && control->width == 100);
    assert(strcmp(control->text, "Income") == 0);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1223) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 612 && control->y == 279);
    assert(control->kind == BALANCE_KIND_SPRITE);
    assert(control->asset == BALANCE_ASSET_TAB09);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1010) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 782 && control->y == 316);
    assert(control->kind == BALANCE_KIND_SLIDER);
    assert(control->asset == BALANCE_ASSET_SLIDER && control->width == 160);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 1204) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 626 && control->y == 520);
    assert(control->kind == BALANCE_KIND_BUTTON);
    assert(control->asset == BALANCE_ASSET_BUTTON && control->width == 147);
    assert(strcmp(control->text, "#Alle Quartale") == 0);
    control = NULL;
    for (size_t index = 0; index < kBalanceControlCount; index++) {
        if (kBalanceControls[index].id == 8000) {
            control = &kBalanceControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 572 && control->y == 217);
    assert(control->kind == BALANCE_KIND_IMAGE);
    assert(control->asset == BALANCE_ASSET_HELP);

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
    assert(screen_render_statistics_balance(&surface, &assets, &data));
    assert(memcmp(frame, sprites[BALANCE_ASSET_BACKGROUND].pixels, 4) == 0);

    bool row_ink = false;
    for (int y = 278; y < 299; y++) {
        for (int x = 611; x < 771; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset + 3] == 255 &&
                (frame[offset] != sprites[BALANCE_ASSET_BACKGROUND].pixels[offset] ||
                 frame[offset + 1] !=
                     sprites[BALANCE_ASSET_BACKGROUND].pixels[offset + 1] ||
                 frame[offset + 2] !=
                     sprites[BALANCE_ASSET_BACKGROUND].pixels[offset + 2])) {
                row_ink = true;
            }
        }
    }
    assert(row_ink);

    bool title_ink = false;
    for (int y = 223; y < 247; y++) {
        for (int x = 605; x < 700; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    bool label_ink = false;
    for (int y = 90; y < 104; y++) {
        for (int x = 46; x < 170; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                label_ink = true;
            }
        }
    }
    assert(label_ink);
    bool income_ink = false;
    for (int y = 66; y < 86; y++) {
        for (int x = 456; x < 540; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                income_ink = true;
            }
        }
    }
    assert(income_ink);
    bool button_ink = false;
    for (int y = 520; y < 541; y++) {
        for (int x = 626; x < 773; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 200 && frame[offset + 1] < 200) {
                button_ink = true;
            }
        }
    }
    assert(button_ink);
    size_t slider_offset = ((size_t)316 * 800 + 782) * 4;
    assert(frame[slider_offset] != 22 || frame[slider_offset + 1] != 26 ||
           frame[slider_offset + 2] != 34);
    assert(!screen_render_statistics_balance(&surface, &assets, NULL));

    for (int index = 0; index < 6; index++) {
        free(font_data[index]);
    }
    free(frame);
    for (int index = 0; index < BALANCE_ASSET_COUNT; index++) {
        free(sprite_pixels[index]);
    }
}

static const OfficeDeskControl *find_office_control(int32_t id) {
    for (size_t index = 0; index < kOfficeDeskControlCount; index++) {
        if (kOfficeDeskControls[index].id == id) {
            return &kOfficeDeskControls[index];
        }
    }
    return NULL;
}

static void test_office_desk_composition(void) {
    static const char *const sprite_paths[OFFICE_ASSET_COUNT] = {
        "../extracted/sprites/mauerbogen.spr",
        "../extracted/sprites/pb22_00.spr",
        "../extracted/sprites/pb24_00.spr",
        "../extracted/sprites/hpb__00.spr",
        "../extracted/sprites/hpb__01.spr",
        "../extracted/sprites/hpb__02.spr",
        "../extracted/sprites/hpb__03.spr",
        "../extracted/sprites/hpb__04.spr",
        "../extracted/sprites/rb01_00.spr",
        "../extracted/sprites/rb02_00.spr",
        "../extracted/sprites/rb03_00.spr",
        "../extracted/sprites/rb04_00.spr",
        "../extracted/sprites/rb05_00.spr",
        "../extracted/sprites/citybut01_00.spr",
        "../extracted/sprites/piloesch01_00.spr",
        "../extracted/sprites/redo01_00.spr",
        "../extracted/sprites/undo01_00.spr",
        "../extracted/sprites/ring.spr",
        "../extracted/sprites/uhr.spr",
        "../extracted/sprites/loch_00.spr",
        "../extracted/sprites/hilfebuttonsnip_00.spr",
        "../extracted/sprites/playlog_8_01_02.spr",
        "../extracted/sprites/star_01.spr",
    };
    static const char *const font_paths[OFFICE_FONT_COUNT] = {
        "../extracted/fonts/timesfont.fnt",
        "../extracted/fonts/times14.fnt",
        "../extracted/fonts/verdana7.fnt",
        "../extracted/fonts/verdana8.fnt",
        "../extracted/fonts/verdana10.fnt",
    };
    uint8_t *sprite_pixels[OFFICE_ASSET_COUNT] = {NULL};
    RgbaSprite sprites[OFFICE_ASSET_COUNT];
    for (int index = 0; index < OFFICE_ASSET_COUNT; index++) {
        assert(load_spr(sprite_paths[index], &sprite_pixels[index],
                        &sprites[index]));
    }
    uint8_t *font_data[OFFICE_FONT_COUNT] = {NULL};
    size_t font_sizes[OFFICE_FONT_COUNT] = {0};
    FntInfo font_infos[OFFICE_FONT_COUNT];
    for (int index = 0; index < OFFICE_FONT_COUNT; index++) {
        font_data[index] = load_file(font_paths[index], &font_sizes[index]);
        assert(font_data[index] != NULL);
        assert(fnt_read_info(font_data[index], font_sizes[index],
                             &font_infos[index]));
    }
    OfficeDeskAssets assets = {0};
    for (int index = 0; index < OFFICE_ASSET_COUNT; index++) {
        assets.sprites[index] = &sprites[index];
    }
    for (int index = 0; index < OFFICE_FONT_COUNT; index++) {
        assets.fonts[index] = (OfficeDeskFont){
            font_data[index], font_sizes[index], &font_infos[index]};
    }
    static const struct {
        const char *path;
        size_t chunk;
    } ani_cases[6] = {
        {"../extracted/sprites/haecksler.ani", 1},
        {"../extracted/sprites/spideranim.ani", 34},
        {"../extracted/sprites/kakanim2.ani", 12},
        {"../extracted/sprites/kakanim.ani", 3},
        {"../extracted/sprites/kakanim1.ani", 3},
        {"../extracted/sprites/tomatenanim.ani", 0},
    };
    uint8_t *ani_data[6] = {NULL};
    uint8_t *ani_pixels[6] = {NULL};
    RgbaSprite ani_sprites[6];
    for (int index = 0; index < 6; index++) {
        size_t ani_size = 0;
        ani_data[index] = load_file(ani_cases[index].path, &ani_size);
        assert(ani_data[index] != NULL);
        ani_pixels[index] = malloc(800 * 600 * 4);
        assert(ani_pixels[index] != NULL);
        assert(ani_decode_chunk(ani_data[index], ani_size,
                                ani_cases[index].chunk, ani_pixels[index],
                                800 * 600 * 4, &ani_sprites[index]));
        assets.animations[index] = &ani_sprites[index];
    }
    assert(kOfficeDeskControlCount == 42);
    const OfficeDeskControl *control = find_office_control(8012);
    assert(control != NULL);
    assert(control->x == 534 && control->y == -2);
    assert(control->kind == OFFICE_KIND_SPRITE);
    assert(control->asset == OFFICE_ASSET_MAUERBOGEN);
    control = find_office_control(1039);
    assert(control != NULL);
    assert(control->x == 640 && control->y == 4);
    assert(control->kind == OFFICE_KIND_TEXT && control->font == 0);
    assert(control->align == 2 && control->width == 120);
    assert(strcmp(control->text, "Paris") == 0);
    control = find_office_control(1040);
    assert(control != NULL);
    assert(control->x == 10 && control->y == 568);
    assert(control->font == 1 && control->align == 2 && control->width == 50);
    assert(strcmp(control->text, "17:32") == 0);
    control = find_office_control(1023);
    assert(control != NULL);
    assert(control->x == 600 && control->y == 178);
    assert(control->asset == OFFICE_ASSET_HPB00);
    control = find_office_control(1022);
    assert(control != NULL);
    assert(control->x == 759 && control->y == 177);
    assert(control->asset == OFFICE_ASSET_RB05);
    control = find_office_control(1075);
    assert(control != NULL);
    assert(control->x == 454 && control->y == 9);
    assert(control->asset == OFFICE_ASSET_RING);
    control = find_office_control(1079);
    assert(control != NULL);
    assert(control->x == 538 && control->y == 178);
    assert(control->font == 2 && control->align == 0 && control->width == 52);
    assert(strcmp(control->text, "Time left") == 0);
    control = find_office_control(8005);
    assert(control != NULL);
    assert(control->x == 202 && control->y == 576);
    assert(control->font == 4 && control->align == 2 && control->width == 0);
    control = find_office_control(8001);
    assert(control != NULL);
    assert(control->x == 104 && control->y == 560);
    assert(control->font == 3 && control->align == 2 && control->width == 91);
    assert(strcmp(control->text, "#32.11.2003") == 0);
    control = find_office_control(1080);
    assert(control != NULL);
    assert(control->x == 446 && control->y == 1);
    assert(control->kind == OFFICE_KIND_ANIMATION);
    assert(strcmp(control->text, "haecksler.ani") == 0);
    control = find_office_control(1086);
    assert(control != NULL);
    assert(control->x == 237 && control->y == 562);
    assert(control->kind == OFFICE_KIND_BITMAP);
    assert(control->width == 44 && control->height == 29);
    control = find_office_control(8007);
    assert(control != NULL);
    assert(control->x == 767 && control->y == 53);
    assert(control->asset == OFFICE_ASSET_STAR);

    size_t tga_size = 0;
    uint8_t *tga = load_file("../extracted/pictures/bg002.tga", &tga_size);
    assert(tga != NULL);
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_office_desk(&surface, tga, tga_size, &assets, NULL,
                                     decoded, frame_size));
    uint8_t *frame_without_animations = malloc(frame_size);
    assert(frame_without_animations != NULL);
    RenderSurface surface_without_animations;
    assert(render_surface_init(&surface_without_animations,
                               frame_without_animations, frame_size, 800, 600));
    OfficeDeskAssets no_animations = assets;
    memset(no_animations.animations, 0, sizeof(no_animations.animations));
    assert(screen_render_office_desk(&surface_without_animations, tga, tga_size,
                                     &no_animations, NULL, decoded, frame_size));
    assert(memcmp(frame, frame_without_animations, frame_size) != 0);

    bool mauer_ink = false;
    for (size_t index = 0;
         index + 3 < (size_t)sprites[OFFICE_ASSET_MAUERBOGEN].width *
                         sprites[OFFICE_ASSET_MAUERBOGEN].height * 4;
         index += 4) {
        if (sprites[OFFICE_ASSET_MAUERBOGEN].pixels[index + 3] == 255) {
            size_t px = (index / 4) % sprites[OFFICE_ASSET_MAUERBOGEN].width;
            size_t py = (index / 4) / sprites[OFFICE_ASSET_MAUERBOGEN].width;
            if (py < 2) {
                continue;
            }
            size_t target = ((size_t)(-2 + (int)py) * 800 + 534 + px) * 4;
            assert(memcmp(frame_without_animations + target,
                          sprites[OFFICE_ASSET_MAUERBOGEN].pixels + index,
                          4) == 0);
            mauer_ink = true;
            break;
        }
    }
    assert(mauer_ink);
    bool city_ink = false;
    for (int y = 4; y < 24; y++) {
        for (int x = 600; x < 780; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                city_ink = true;
            }
        }
    }
    assert(city_ink);
    bool date_ink = false;
    for (int y = 560; y < 576; y++) {
        for (int x = 104; x < 210; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                date_ink = true;
            }
        }
    }
    assert(date_ink);
    size_t help_offset = ((size_t)217 * 800 + 572) * 4;
    assert(frame[help_offset] != 22 || frame[help_offset + 1] != 26 ||
           frame[help_offset + 2] != 34);
    const OfficeDeskData data = {
        .city = "Berlin",
        .clock = "18:45",
        .time_left_clock = "#01:20",
        .time_left_label = "Time left",
        .guid = "Guid",
        .date = "#01.01.2004",
    };
    assert(screen_render_office_desk(&surface, tga, tga_size, &assets, &data,
                                     decoded, frame_size));
    assert(!screen_render_office_desk(&surface, tga, tga_size, NULL, NULL,
                                      decoded, frame_size));

    for (int index = 0; index < OFFICE_FONT_COUNT; index++) {
        free(font_data[index]);
    }
    for (int index = 0; index < OFFICE_ASSET_COUNT; index++) {
        free(sprite_pixels[index]);
    }
    for (int index = 0; index < 6; index++) {
        free(ani_data[index]);
        free(ani_pixels[index]);
    }
    free(frame_without_animations);
    free(tga);
    free(decoded);
    free(frame);
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

static void test_options_page_composition(void) {
    uint8_t *background_pixels = NULL;
    uint8_t *slider_pixels = NULL;
    uint8_t *separator_pixels = NULL;
    uint8_t *marker_pixels = NULL;
    RgbaSprite background;
    RgbaSprite slider;
    RgbaSprite separator;
    RgbaSprite marker;
    assert(load_spr("../extracted/sprites/pe_sub_startscreen.spr",
                    &background_pixels, &background));
    assert(load_spr("../extracted/sprites/sl02_00.spr", &slider_pixels, &slider));
    assert(load_spr("../extracted/sprites/trennzeile.spr", &separator_pixels,
                    &separator));
    assert(load_spr("../extracted/sprites/pb14_00.spr", &marker_pixels, &marker));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    const OptionsPageData data = {
        .general_volume = 50,
        .music = 40,
        .language = 60,
        .graphic_detail = 80,
        .autosave = 70,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_options_page(&surface, &background, &slider,
                                      &separator, &marker, font_data, font_size,
                                      &font, &data));
    bool background_ink = false;
    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                background_ink = true;
            }
        }
    }
    assert(background_ink);
    bool ink = false;
    for (int y = 250; y < 280; y++) {
        for (int x = 600; x < 780; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                ink = true;
            }
        }
    }
    assert(ink);
    size_t slider_offset = ((size_t)297 * 800 + 700) * 4;
    assert(frame[slider_offset] != 80 || frame[slider_offset + 1] != 70 ||
           frame[slider_offset + 2] != 60);
    assert(!screen_render_options_page(&surface, &background, &slider,
                                       &separator, &marker, font_data,
                                       font_size, &font, NULL));
    free(font_data);
    free(frame);
    free(background_pixels);
    free(slider_pixels);
    free(separator_pixels);
    free(marker_pixels);
}

static void test_load_save_page_composition(void) {
    uint8_t *background_pixels = NULL;
    uint8_t *row_pixels = NULL;
    uint8_t *scroll_pixels = NULL;
    RgbaSprite background;
    RgbaSprite row_plate;
    RgbaSprite scrollbar;
    assert(load_spr("../extracted/sprites/pe_sub_startscreen.spr",
                    &background_pixels, &background));
    assert(load_spr("../extracted/sprites/tabpb01__00.spr", &row_pixels,
                    &row_plate));
    assert(load_spr("../extracted/sprites/sl01_00.spr", &scroll_pixels,
                    &scrollbar));

    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    LoadSavePageData data = {
        .count = 3,
        .selected = 0,
    };
    data.names[0] = "London 1999";
    data.names[1] = "London 2000";
    data.names[2] = "Autosave";
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_load_save_page(&surface, &background, &row_plate,
                                        &scrollbar, font_data, font_size, &font,
                                        &data));
    bool background_ink = false;
    for (int y = 0; y < 600; y++) {
        for (int x = 0; x < 800; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                background_ink = true;
            }
        }
    }
    assert(background_ink);
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
    bool row_ink = false;
    for (size_t index = 0; index + 3 < (size_t)row_plate.width * row_plate.height * 4;
         index += 4) {
        if (row_plate.pixels[index + 3] == 255) {
            size_t px = (index / 4) % row_plate.width;
            size_t py = (index / 4) / row_plate.width;
            size_t target = ((size_t)(296 + (int)py) * 800 + (613 + (int)px)) * 4;
            assert(memcmp(frame + target, row_plate.pixels + index, 4) == 0);
            row_ink = true;
            break;
        }
    }
    assert(row_ink);
    assert(!screen_render_load_save_page(&surface, &background, &row_plate,
                                         &scrollbar, font_data, font_size,
                                         &font, NULL));
    free(font_data);
    free(frame);
    free(background_pixels);
    free(row_pixels);
    free(scroll_pixels);
}

static void test_statistics_backdrop_composition(void) {
    uint8_t *background_pixels = NULL;
    RgbaSprite background;
    assert(load_spr("../extracted/sprites/statistikbackspriteneutral.spr",
                    &background_pixels, &background));
    const char *icon_paths[8] = {
        "../extracted/sprites/skfiliale_00.spr",
        "../extracted/sprites/skstern_00.spr",
        "../extracted/sprites/skperso_00.spr",
        "../extracted/sprites/sksyndicate_00.spr",
        "../extracted/sprites/skwerbung_00.spr",
        "../extracted/sprites/skrezept_00.spr",
        "../extracted/sprites/skbilanz_00.spr",
        "../extracted/sprites/skbewertung_00.spr",
    };
    uint8_t *icon_pixels[8] = {NULL};
    RgbaSprite icons[8];
    for (int index = 0; index < 8; index++) {
        assert(load_spr(icon_paths[index], &icon_pixels[index], &icons[index]));
    }
    const char *logo_paths[6] = {
        "../extracted/sprites/logos__08.spr",
        "../extracted/sprites/logos__01.spr",
        "../extracted/sprites/logos__02.spr",
        "../extracted/sprites/logos__05.spr",
        "../extracted/sprites/logos__06.spr",
        "../extracted/sprites/logos__07.spr",
    };
    uint8_t *logo_pixels[6] = {NULL};
    RgbaSprite logos[6];
    for (int index = 0; index < 6; index++) {
        assert(load_spr(logo_paths[index], &logo_pixels[index], &logos[index]));
    }
    uint8_t *marker_pixels = NULL;
    uint8_t *help_pixels = NULL;
    uint8_t *button_pixels = NULL;
    RgbaSprite marker;
    RgbaSprite help;
    RgbaSprite button;
    assert(load_spr("../extracted/sprites/pb14_00.spr", &marker_pixels, &marker));
    assert(load_spr("../extracted/sprites/hilfebuttonsnip_00.spr",
                    &help_pixels, &help));
    assert(load_spr("../extracted/sprites/textpb01__00.spr", &button_pixels,
                    &button));
    size_t font_size = 0;
    uint8_t *font_data = load_file("../extracted/fonts/timesfont.fnt", &font_size);
    assert(font_data != NULL);
    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));

    StatisticsBackdropSprites sprites = {
        .background = &background,
        .row_marker = &marker,
        .help_button = &help,
        .button_background = &button,
    };
    for (int index = 0; index < 8; index++) {
        sprites.icons[index] = &icons[index];
    }
    for (int index = 0; index < 6; index++) {
        sprites.logos[index] = &logos[index];
    }
    const ComparisonRow rows[6] = {
        {"Ada Pizza", 16000000},
        {"Rival One", 12000000},
        {"Rival Two", 9000000},
        {"Rival Three", 7000000},
        {"Rival Four", 5000000},
        {"Rival Five", 3000000},
    };
    const StatisticsBackdropData data = {
        .rows = rows,
        .row_count = 6,
        .total_text = "23000$",
        .period_text = "Aktuelles Quartal",
        .selected_button = 0,
    };
    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    assert(frame != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_statistics_backdrop(&surface, &sprites, font_data,
                                             font_size, &font, &data));
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
    bool marker_ink = false;
    for (size_t index = 0; index + 3 < (size_t)marker.width * marker.height * 4;
         index += 4) {
        if (marker.pixels[index + 3] == 255) {
            size_t px = (index / 4) % marker.width;
            size_t py = (index / 4) / marker.width;
            size_t target = ((size_t)(386 + (int)py) * 800 + (608 + (int)px)) * 4;
            assert(memcmp(frame + target, marker.pixels + index, 4) == 0);
            marker_ink = true;
            break;
        }
    }
    assert(marker_ink);
    assert(!screen_render_statistics_backdrop(&surface, &sprites, font_data,
                                              font_size, &font, NULL));
    free(font_data);
    free(frame);
    free(background_pixels);
    for (int index = 0; index < 8; index++) {
        free(icon_pixels[index]);
    }
    for (int index = 0; index < 6; index++) {
        free(logo_pixels[index]);
    }
    free(marker_pixels);
    free(help_pixels);
    free(button_pixels);
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
    uint8_t *tga = load_file("../extracted/pictures/pe_freies_spiel.tga", &tga_size);
    assert(tga != NULL);
    static const char *const sprite_paths[FREE_PLAY_ASSET_COUNT] = {
        "../extracted/sprites/pb22_00.spr",
        "../extracted/sprites/pb24_00.spr",
        "../extracted/sprites/pb26_00.spr",
        "../extracted/sprites/pb27_00.spr",
        "../extracted/sprites/pb14_00.spr",
        "../extracted/sprites/sl02_00.spr",
        "../extracted/sprites/fotorahmen00.spr",
        "../extracted/sprites/fotodummy00.spr",
        "../extracted/sprites/logofenster.spr",
        "../extracted/sprites/playlog_2_01_00.spr",
        "../extracted/sprites/playlog_3_02_01.spr",
        "../extracted/sprites/playlog_3_03_01.spr",
        "../extracted/sprites/textpb05__00.spr",
        "../extracted/sprites/textpbtranspgelb_00.spr",
        "../extracted/sprites/textpbtranspgruen_00.spr",
    };
    static const char *const font_paths[FREE_PLAY_FONT_COUNT] = {
        "../extracted/fonts/timesfont.fnt",
        "../extracted/fonts/times14.fnt",
        "../extracted/fonts/verdana10.fnt",
        "../extracted/fonts/verdana7.fnt",
        "../extracted/fonts/verdana8.fnt",
    };
    uint8_t *sprite_pixels[FREE_PLAY_ASSET_COUNT] = {NULL};
    RgbaSprite sprites[FREE_PLAY_ASSET_COUNT];
    for (int index = 0; index < FREE_PLAY_ASSET_COUNT; index++) {
        assert(load_spr(sprite_paths[index], &sprite_pixels[index],
                        &sprites[index]));
    }
    uint8_t *font_data[FREE_PLAY_FONT_COUNT] = {NULL};
    size_t font_sizes[FREE_PLAY_FONT_COUNT] = {0};
    FntInfo font_infos[FREE_PLAY_FONT_COUNT];
    for (int index = 0; index < FREE_PLAY_FONT_COUNT; index++) {
        font_data[index] = load_file(font_paths[index], &font_sizes[index]);
        assert(font_data[index] != NULL);
        assert(fnt_read_info(font_data[index], font_sizes[index],
                             &font_infos[index]));
    }
    FreePlayAssets assets = {0};
    for (int index = 0; index < FREE_PLAY_ASSET_COUNT; index++) {
        assets.sprites[index] = &sprites[index];
    }
    for (int index = 0; index < FREE_PLAY_FONT_COUNT; index++) {
        assets.fonts[index] = (FreePlayFont){
            font_data[index], font_sizes[index], &font_infos[index]};
    }
    assert(kFreePlayControlCount == 157);
    const FreePlayControl *control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1056) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 13 && control->y == 5);
    assert(control->font == 0 && control->align == 2 && control->width == 560);
    assert(strcmp(control->text, "Select player character") == 0);
    control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1087) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 124 && control->y == 44);
    assert(strcmp(control->text, "#Spielername") == 0);
    control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1099) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 366 && control->y == 47);
    assert(strcmp(control->text, "Initial capital:") == 0);
    control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1031) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->kind == FREE_PLAY_KIND_SLIDER);
    assert(control->x == 617 && control->y == 461);
    assert(control->asset == FREE_PLAY_ASSET_SLIDER && control->width == 175);
    control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1250) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->kind == FREE_PLAY_KIND_BUTTON);
    assert(control->x == 595 && control->y == 509);
    assert(control->asset == FREE_PLAY_ASSET_BUTTON_YELLOW);
    assert(control->width == 204);
    assert(strcmp(control->text, "To main menu") == 0);
    control = NULL;
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        if (kFreePlayControls[index].id == 1251) {
            control = &kFreePlayControls[index];
        }
    }
    assert(control != NULL);
    assert(control->x == 595 && control->y == 550);
    assert(control->asset == FREE_PLAY_ASSET_BUTTON_GREEN);
    assert(strcmp(control->text, "Start game") == 0);

    FreePlayScenario scenario = {
        .city = "Berlin",
        .map = "Ber.iso",
        .player_name = "Ada",
        .enterprise_name = "Ada Pizza",
        .population = 2,
        .game_length = 1,
        .difficulty = 3,
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
    assert(screen_render_free_play(&surface, tga, tga_size, &assets,
                                   &scenario, decoded, frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);

    bool title_ink = false;
    for (int y = 4; y < 28; y++) {
        for (int x = 10; x < 300; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 180 && frame[offset + 1] < 120) {
                title_ink = true;
            }
        }
    }
    assert(title_ink);
    bool name_ink = false;
    for (int y = 44; y < 62; y++) {
        for (int x = 124; x < 280; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 120 && frame[offset + 1] < 120) {
                name_ink = true;
            }
        }
    }
    assert(name_ink);
    bool start_text_ink = false;
    for (int y = 550; y < 589; y++) {
        for (int x = 595; x < 799; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] < 80 && frame[offset + 1] < 80 &&
                frame[offset + 2] < 80) {
                start_text_ink = true;
            }
        }
    }
    assert(start_text_ink);
    bool slider_ink = false;
    for (int y = 458; y < 472; y++) {
        for (int x = 680; x < 730; x++) {
            size_t offset = ((size_t)y * 800 + (size_t)x) * 4;
            if (frame[offset] != 22 || frame[offset + 1] != 26 ||
                frame[offset + 2] != 34) {
                slider_ink = true;
            }
        }
    }
    assert(slider_ink);
    assert(!screen_render_free_play(&surface, tga, tga_size, NULL, &scenario,
                                    decoded, frame_size));

    for (int index = 0; index < FREE_PLAY_FONT_COUNT; index++) {
        free(font_data[index]);
    }
    for (int index = 0; index < FREE_PLAY_ASSET_COUNT; index++) {
        free(sprite_pixels[index]);
    }
    free(tga);
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
    uint8_t *logo_pixels = NULL;
    uint8_t *back_pixels = NULL;
    uint8_t *start_pixels = NULL;
    uint8_t *scroll_pixels = NULL;
    RgbaSprite logo;
    RgbaSprite back;
    RgbaSprite start;
    RgbaSprite scrollbar;
    assert(load_spr("../extracted/sprites/logofenster.spr", &logo_pixels, &logo));
    assert(load_spr("../extracted/sprites/textpbtranspgelb_00.spr",
                    &back_pixels, &back));
    assert(load_spr("../extracted/sprites/textpbtranspgruen_00.spr",
                    &start_pixels, &start));
    assert(load_spr("../extracted/sprites/sl01_00.spr", &scroll_pixels,
                    &scrollbar));

    FntInfo font;
    assert(fnt_read_info(font_data, font_size, &font));
    const char *body =
        "You begin your life as - hopefully - a successful pizza chef. Your boss "
        "sits in New York and has selected you from the many applications to be "
        "his new regional manager. Since the English are infamous for having no "
        "taste where food is concerned, you shouldn't have too much of a problem "
        "conquering the city with your tasty pizzas.";
    const MissionBriefingData data = {
        .city = "London",
        .description = body,
        .help_text = "Online-Hilfetext",
        .logo_window = &logo,
        .back_button = &back,
        .start_button = &start,
        .scrollbar = &scrollbar,
        .selected_button = 1,
    };

    size_t frame_size = 800 * 600 * 4;
    uint8_t *frame = malloc(frame_size);
    uint8_t *decoded = malloc(frame_size);
    assert(frame != NULL);
    assert(decoded != NULL);
    RenderSurface surface;
    assert(render_surface_init(&surface, frame, frame_size, 800, 600));
    assert(screen_render_briefing(&surface, tga, tga_size, font_data,
                                  font_size, &font, &data, decoded, frame_size));
    assert(memcmp(frame, decoded, frame_size) != 0);
    size_t logo_offset = ((size_t)54 * 800 + 626) * 4;
    assert(frame[logo_offset] != 0 || frame[logo_offset + 1] != 0 ||
           frame[logo_offset + 2] != 0);
    size_t start_offset = ((size_t)552 * 800 + 700) * 4;
    assert(frame[start_offset] != 0 || frame[start_offset + 1] != 0 ||
           frame[start_offset + 2] != 0);
    assert(!screen_render_briefing(&surface, tga, tga_size, font_data,
                                   font_size, &font, NULL, decoded,
                                   frame_size));

    free(tga);
    free(font_data);
    free(logo_pixels);
    free(back_pixels);
    free(start_pixels);
    free(scroll_pixels);
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
    test_office_desk_composition();
    test_statistics_branch_balance_composition();
    test_options_page_composition();
    test_load_save_page_composition();
    test_statistics_backdrop_composition();
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
