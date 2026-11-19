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
    test_briefing_composition();
    puts("screen render reconstruction: OK");
    return 0;
}
