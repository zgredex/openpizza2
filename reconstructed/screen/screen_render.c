#include "screen_render.h"

#include <stdio.h>
#include <string.h>

#include "../ui_render/ui_render.h"

static void blend_rect(RenderSurface *surface, int32_t x, int32_t y, int32_t w,
                       int32_t h, const uint8_t rgba[4]) {
    if (surface == NULL) {
        return;
    }
    int32_t x0 = x < 0 ? 0 : x;
    int32_t y0 = y < 0 ? 0 : y;
    int32_t x1 = x + w;
    int32_t y1 = y + h;
    if (x1 > (int32_t)surface->width) {
        x1 = (int32_t)surface->width;
    }
    if (y1 > (int32_t)surface->height) {
        y1 = (int32_t)surface->height;
    }
    uint32_t alpha = rgba[3];
    for (int32_t py = y0; py < y1; py++) {
        for (int32_t px = x0; px < x1; px++) {
            size_t offset = ((size_t)py * surface->width + (size_t)px) * 4;
            for (int channel = 0; channel < 3; channel++) {
                surface->pixels[offset + channel] = (uint8_t)(
                    (rgba[channel] * alpha +
                     surface->pixels[offset + channel] * (255 - alpha) + 127) /
                    255);
            }
            surface->pixels[offset + 3] = 255;
        }
    }
}

bool screen_render_background(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, uint8_t *decode_buffer,
                              size_t decode_capacity) {
    if (surface == NULL || tga_data == NULL || decode_buffer == NULL) {
        return false;
    }
    uint32_t width = 0;
    uint32_t height = 0;
    if (!tga_decode_rgba(tga_data, tga_size, decode_buffer, decode_capacity,
                         &width, &height)) {
        return false;
    }
    if (width != surface->width || height != surface->height) {
        return false;
    }
    memcpy(surface->pixels, decode_buffer, (size_t)width * height * 4);
    return true;
}

static int draw_wrapped_text(RenderSurface *surface, const uint8_t *font_data,
                             size_t font_size, const FntInfo *font, int32_t x,
                             int32_t y, uint32_t max_width, const char *text,
                             const uint8_t rgba[4]) {
    if (surface == NULL || font == NULL || text == NULL) {
        return -1;
    }
    char line[256];
    size_t line_length = 0;
    int lines = 0;
    const char *cursor = text;
    while (*cursor != 0) {
        while (*cursor == ' ') {
            cursor += 1;
        }
        if (*cursor == 0) {
            break;
        }
        size_t word_length = 0;
        while (cursor[word_length] != 0 && cursor[word_length] != ' ') {
            word_length += 1;
        }
        char candidate[256];
        size_t copy = line_length;
        if (copy > sizeof(candidate) - 1) {
            copy = sizeof(candidate) - 1;
        }
        memcpy(candidate, line, copy);
        if (copy > 0 && copy < sizeof(candidate) - 1) {
            candidate[copy++] = ' ';
        }
        size_t take = word_length;
        if (copy + take > sizeof(candidate) - 1) {
            take = sizeof(candidate) - 1 - copy;
        }
        memcpy(candidate + copy, cursor, take);
        copy += take;
        candidate[copy] = 0;
        if (line_length > 0 && ui_measure_text(font, candidate) > max_width) {
            if (!ui_draw_text(surface, font_data, font_size, font, x, y, line, rgba)) {
                return -1;
            }
            lines += 1;
            y += font->line_height;
            line_length = 0;
            copy = 0;
            if (take > sizeof(candidate) - 1) {
                take = sizeof(candidate) - 1;
            }
            memcpy(candidate, cursor, take);
            copy = take;
            candidate[copy] = 0;
        }
        memcpy(line, candidate, copy + 1);
        line_length = copy;
        cursor += word_length;
    }
    if (line_length > 0) {
        if (!ui_draw_text(surface, font_data, font_size, font, x, y, line, rgba)) {
            return -1;
        }
        lines += 1;
    }
    return lines;
}

bool screen_render_menu(RenderSurface *surface, const uint8_t *tga_data,
                        size_t tga_size, const uint8_t *font_data,
                        size_t font_size, const FntInfo *font,
                        const MenuState *menu, uint8_t *decode_buffer,
                        size_t decode_capacity) {
    if (menu == NULL || font == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t active[4] = {255, 225, 120, 150};
    const uint8_t idle[4] = {30, 30, 30, 80};
    const uint8_t text_color[4] = {0, 0, 0, 255};
    for (int index = 0; index < MENU_ITEM_COUNT; index++) {
        const MenuItem *item = &menu->items[index];
        bool highlighted = menu->hover >= 0 ? index == menu->hover
                                             : (menu->interacted && index == menu->selected);
        blend_rect(surface, item->x, item->y, (int32_t)item->width,
                   (int32_t)item->height, highlighted ? active : idle);
        uint32_t text_width = ui_measure_text(font, item->label);
        int32_t text_x = item->x + ((int32_t)item->width - (int32_t)text_width) / 2;
        int32_t text_y = item->y + 9;
        if (!ui_draw_text(surface, font_data, font_size, font, text_x, text_y,
                          item->label, text_color)) {
            return false;
        }
    }
    if (menu->has_status) {
        const uint8_t status_color[4] = {255, 255, 255, 255};
        ui_draw_text(surface, font_data, font_size, font, 20,
                     (int32_t)surface->height - 30, menu->status, status_color);
    }
    return true;
}

int screen_render_briefing(RenderSurface *surface, const uint8_t *tga_data,
                           size_t tga_size, const uint8_t *font_data,
                           size_t font_size, const FntInfo *font,
                           const char *title, const char *body,
                           const char *prompt, uint8_t *decode_buffer,
                           size_t decode_capacity) {
    if (font == NULL || title == NULL || body == NULL) {
        return -1;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return -1;
    }
    const uint8_t panel[4] = {10, 12, 24, 190};
    const uint8_t title_color[4] = {255, 225, 120, 255};
    const uint8_t body_color[4] = {245, 245, 245, 255};
    const uint8_t prompt_color[4] = {180, 200, 255, 255};
    int32_t panel_x = 60;
    int32_t panel_y = 70;
    int32_t panel_w = (int32_t)surface->width - 120;
    int32_t panel_h = (int32_t)surface->height - 180;
    blend_rect(surface, panel_x, panel_y, panel_w, panel_h, panel);

    if (!ui_draw_text(surface, font_data, font_size, font, panel_x + 24,
                      panel_y + 18, title, title_color)) {
        return -1;
    }
    int lines = draw_wrapped_text(surface, font_data, font_size, font,
                                  panel_x + 24, panel_y + 60,
                                  (uint32_t)panel_w - 48, body, body_color);
    if (lines < 0) {
        return -1;
    }
    if (prompt != NULL) {
        ui_draw_text(surface, font_data, font_size, font, panel_x + 24,
                     panel_y + panel_h - 38, prompt, prompt_color);
    }
    return lines;
}

static void draw_label(RenderSurface *surface, const uint8_t *font_data,
                       size_t font_size, const FntInfo *font, int32_t x, int32_t y,
                       const char *text, const uint8_t rgba[4]) {
    ui_draw_text(surface, font_data, font_size, font, x, y, text, rgba);
}

bool screen_render_character_select(RenderSurface *surface,
                                    const uint8_t *tga_data, size_t tga_size,
                                    const uint8_t *font_data, size_t font_size,
                                    const FntInfo *font, const CharacterScreenData *data,
                                    uint8_t *decode_buffer,
                                    size_t decode_capacity) {
    if (data == NULL || font == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    draw_label(surface, font_data, font_size, font, 13, 5,
               "Select player character", title_color);
    draw_label(surface, font_data, font_size, font, 608, 5, "Enterprises:",
               title_color);
    draw_label(surface, font_data, font_size, font, 259, 77, "Characteristics:",
               title_color);
    draw_label(surface, font_data, font_size, font, 44, 304, "Player's name:",
               label_color);
    draw_label(surface, font_data, font_size, font, 609, 304, "Enterprise name:",
               label_color);

    static const char *const attribute_labels[CHARACTER_ATTRIBUTE_COUNT] = {
        "Buyer", "Gangsters", "Specialist", "Politicians", "Seller", "Guard",
    };
    static const int32_t attribute_y[CHARACTER_ATTRIBUTE_COUNT] = {
        140, 173, 207, 239, 273, 305,
    };
    char value_text[16];
    for (int index = 0; index < CHARACTER_ATTRIBUTE_COUNT; index++) {
        draw_label(surface, font_data, font_size, font, 323, attribute_y[index],
                   attribute_labels[index], label_color);
        snprintf(value_text, sizeof(value_text), "%d", data->attributes[index]);
        draw_label(surface, font_data, font_size, font, 501, attribute_y[index],
                   value_text, value_color);
    }

    if (data->player_name != NULL) {
        draw_label(surface, font_data, font_size, font, 44, 332, data->player_name,
                   value_color);
    }
    if (data->enterprise_name != NULL) {
        draw_label(surface, font_data, font_size, font, 609, 332,
                   data->enterprise_name, value_color);
    }

    draw_label(surface, font_data, font_size, font, 609, 425,
               "Level of difficulty", label_color);
    snprintf(value_text, sizeof(value_text), "%u", data->difficulty);
    draw_label(surface, font_data, font_size, font, 609, 478, "Very easy",
               value_color);
    draw_label(surface, font_data, font_size, font, 690, 478, value_text,
               value_color);

    const uint8_t back_idle[4] = {180, 170, 150, 210};
    const uint8_t back_active[4] = {255, 215, 110, 230};
    const uint8_t start_idle[4] = {140, 180, 140, 210};
    const uint8_t start_active[4] = {130, 230, 130, 235};
    blend_rect(surface, 595, 509, 204, 38,
               data->selected_button == 0 ? back_active : back_idle);
    blend_rect(surface, 595, 551, 204, 38,
               data->selected_button == 1 ? start_active : start_idle);
    draw_label(surface, font_data, font_size, font, 640, 517, "To main menu",
               label_color);
    draw_label(surface, font_data, font_size, font, 650, 559, "Start game",
               label_color);
    return true;
}

bool screen_render_free_play(RenderSurface *surface, const uint8_t *tga_data,
                             size_t tga_size, const uint8_t *font_data,
                             size_t font_size, const FntInfo *font,
                             const FreePlayScenario *scenario,
                             uint8_t *decode_buffer, size_t decode_capacity) {
    if (scenario == NULL || font == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, 13, 5,
               "Select player character", title_color);
    draw_label(surface, font_data, font_size, font, 608, 5, "Enterprises:",
               title_color);
    if (scenario->city != NULL) {
        draw_label(surface, font_data, font_size, font, 608, 30, scenario->city,
                   value_color);
    }
    if (scenario->map != NULL) {
        draw_label(surface, font_data, font_size, font, 608, 52, scenario->map,
                   value_color);
    }

    draw_label(surface, font_data, font_size, font, 124, 44, "Player's name:",
               label_color);
    if (scenario->player_name != NULL) {
        draw_label(surface, font_data, font_size, font, 240, 44,
                   scenario->player_name, value_color);
    }
    draw_label(surface, font_data, font_size, font, 124, 72, "Enterprise name:",
               label_color);
    if (scenario->enterprise_name != NULL) {
        draw_label(surface, font_data, font_size, font, 240, 72,
                   scenario->enterprise_name, value_color);
    }

    draw_label(surface, font_data, font_size, font, 195, 425, "Population",
               label_color);
    snprintf(value_text, sizeof(value_text), "%u", scenario->population);
    draw_label(surface, font_data, font_size, font, 195, 478,
               "100 town inhabitants", value_color);
    draw_label(surface, font_data, font_size, font, 330, 478, value_text,
               value_color);

    draw_label(surface, font_data, font_size, font, 385, 425, "Time limit",
               label_color);
    snprintf(value_text, sizeof(value_text), "%u", scenario->game_length);
    draw_label(surface, font_data, font_size, font, 385, 478, "Endless",
               value_color);
    draw_label(surface, font_data, font_size, font, 465, 478, value_text,
               value_color);

    draw_label(surface, font_data, font_size, font, 609, 425,
               "Level of difficulty", label_color);
    snprintf(value_text, sizeof(value_text), "%u", scenario->difficulty);
    draw_label(surface, font_data, font_size, font, 609, 478, "Very easy",
               value_color);
    draw_label(surface, font_data, font_size, font, 700, 478, value_text,
               value_color);

    draw_label(surface, font_data, font_size, font, 366, 47, "Initial capital",
               label_color);
    snprintf(value_text, sizeof(value_text), "%u", scenario->starting_capital);
    draw_label(surface, font_data, font_size, font, 498, 47, value_text,
               value_color);
    draw_label(surface, font_data, font_size, font, 366, 67, "Characteristics",
               label_color);

    static const int32_t opponent_y[3] = {104, 164, 224};
    for (int index = 0; index < 3; index++) {
        snprintf(value_text, sizeof(value_text), "Opponent %d", index + 1);
        draw_label(surface, font_data, font_size, font, 124, opponent_y[index],
                   value_text, label_color);
        draw_label(surface, font_data, font_size, font,
                   scenario->opponents[index] < 0 ? 498 : 240,
                   opponent_y[index],
                   scenario->opponents[index] < 0 ? "None" : "Active",
                   value_color);
    }

    const uint8_t back_idle[4] = {180, 170, 150, 210};
    const uint8_t back_active[4] = {255, 215, 110, 230};
    const uint8_t start_idle[4] = {140, 180, 140, 210};
    const uint8_t start_active[4] = {130, 230, 130, 235};
    blend_rect(surface, 595, 509, 204, 38,
               scenario->selected_button == 0 ? back_active : back_idle);
    blend_rect(surface, 595, 550, 204, 38,
               scenario->selected_button == 1 ? start_active : start_idle);
    draw_label(surface, font_data, font_size, font, 640, 517, "To main menu",
               label_color);
    draw_label(surface, font_data, font_size, font, 650, 558, "Start game",
               label_color);
    return true;
}

bool screen_render_statistics(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, const uint8_t *font_data,
                              size_t font_size, const FntInfo *font,
                              const StatisticsState *state, const char *city,
                              const char *date, uint8_t *decode_buffer,
                              size_t decode_capacity) {
    if (state == NULL || font == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[96];

    if (city != NULL) {
        draw_label(surface, font_data, font_size, font, 640, 4, city,
                   title_color);
    }
    if (date != NULL) {
        draw_label(surface, font_data, font_size, font, 10, 568, date,
                   label_color);
    }
    draw_label(surface, font_data, font_size, font, 30, 22, "Statistics",
               title_color);
    draw_label(surface, font_data, font_size, font, 30, 56, "Company overview",
               title_color);

    const CompanyOverview *overview = &state->overview;
    snprintf(value_text, sizeof(value_text), "Owned buildings: %d  value %d",
             overview->owned_buildings, overview->owned_value);
    draw_label(surface, font_data, font_size, font, 50, 92, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Rented buildings: %d  value %d",
             overview->rented_buildings, overview->rented_value);
    draw_label(surface, font_data, font_size, font, 50, 120, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Warehouses: %d", overview->warehouses);
    draw_label(surface, font_data, font_size, font, 50, 148, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Company value: %d",
             overview->company_value);
    draw_label(surface, font_data, font_size, font, 50, 176, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Market share: %d.%02d%%",
             overview->share_x100 / 100, overview->share_x100 % 100);
    draw_label(surface, font_data, font_size, font, 50, 204, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Rank: %d.%03d",
             overview->rank_x1000 / 1000, overview->rank_x1000 % 1000);
    draw_label(surface, font_data, font_size, font, 50, 232, value_text,
               value_color);
    snprintf(value_text, sizeof(value_text), "Player C20: %d  field 60: %d",
             overview->player_c20, overview->player_field60);
    draw_label(surface, font_data, font_size, font, 50, 260, value_text,
               label_color);
    snprintf(value_text, sizeof(value_text), "HQ: %d  total branch profit: %d",
             overview->hq_count, statistics_total_branch_profit(state));
    draw_label(surface, font_data, font_size, font, 50, 288, value_text,
               value_color);

    draw_label(surface, font_data, font_size, font, 30, 332, "Branches",
               title_color);
    int32_t y = 364;
    for (int index = 0; index < state->branch_count; index++) {
        const BranchBalanceEntry *entry = &state->branches[index];
        snprintf(value_text, sizeof(value_text),
                 "Branch %u  revenue %d  costs %d  profit %d", entry->branch_id,
                 entry->revenue, entry->costs, entry->profit);
        draw_label(surface, font_data, font_size, font, 50, y, value_text,
                   value_color);
        y += 28;
    }
    snprintf(value_text, sizeof(value_text), "Total profit: %d",
             statistics_total_branch_profit(state));
    draw_label(surface, font_data, font_size, font, 50, y + 12, value_text,
               title_color);
    return true;
}

bool screen_render_branch_list(RenderSurface *surface, const RgbaSprite *panel,
                               const RgbaSprite *table,
                               const RgbaSprite *separator,
                               const RgbaSprite *branch_icon,
                               const RgbaSprite *warehouse_icon,
                               const uint8_t *font_data, size_t font_size,
                               const FntInfo *font,
                               const BranchListData *data) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (panel != NULL && !render_blit(surface, panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Rent buildings", title_color);
    if (data->city != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 44,
                   window_y + 24, data->city, value_color);
    }

    if (branch_icon != NULL) {
        render_blit(surface, branch_icon, window_x + 99, window_y + 126);
    }
    if (warehouse_icon != NULL) {
        render_blit(surface, warehouse_icon, window_x + 141, window_y + 126);
    }
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 126, "Branch", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 180,
               window_y + 126, "Stocks", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 149, "Mittel", value_color);
    draw_label(surface, font_data, font_size, font, window_x + 180,
               window_y + 149, "Mittel", value_color);
    draw_label(surface, font_data, font_size, font, window_x + 51,
               window_y + 169, "Lease a branch to extend your chain.",
               label_color);

    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 253, "Rent per quarter", label_color);
    char value_text[64];
    uint32_t rent = data->entry_count > 0 ? data->entries[0].rent : 0;
    snprintf(value_text, sizeof(value_text), "%u", rent);
    draw_label(surface, font_data, font_size, font, window_x + 167,
               window_y + 253, value_text, value_color);

    draw_label(surface, font_data, font_size, font, window_x + 44,
               window_y + 274, "Choose branch", label_color);
    const uint8_t lease_idle[4] = {140, 180, 140, 220};
    const uint8_t lease_active[4] = {130, 230, 130, 235};
    blend_rect(surface, window_x + 142, window_y + 272, 84, 26,
               data->selected >= 0 ? lease_active : lease_idle);
    draw_label(surface, font_data, font_size, font, window_x + 158,
               window_y + 276, "Lease", label_color);

    if (table != NULL) {
        render_blit(surface, table, window_x + 47, window_y + 314);
    }
    const int32_t row_y[2] = {window_y + 316, window_y + 340};
    for (size_t index = 0; index < data->entry_count && index < 2; index++) {
        if ((int)index == data->selected) {
            blend_rect(surface, window_x + 48, row_y[index] - 1, 179, 20,
                       (const uint8_t[4]){255, 225, 120, 150});
        }
        snprintf(value_text, sizeof(value_text), "%s %u",
                 data->entries[index].warehouse ? "Warehouse" : "Branch",
                 data->entries[index].tile_index);
        draw_label(surface, font_data, font_size, font, window_x + 52,
                   row_y[index], value_text, value_color);
        snprintf(value_text, sizeof(value_text), "%u",
                 data->entries[index].rent);
        draw_label(surface, font_data, font_size, font, window_x + 160,
                   row_y[index], value_text, value_color);
    }
    draw_label(surface, font_data, font_size, font, window_x + 44,
               window_y + 303, "Persons in area of influence", label_color);
    return true;
}

bool screen_render_branch_details(RenderSurface *surface, const RgbaSprite *panel,
                                  const RgbaSprite *separator,
                                  const RgbaSprite *logo_frame,
                                  const RgbaSprite *rating_sprite,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const BranchDetailsData *data) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (panel != NULL && !render_blit(surface, panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Other staff", title_color);
    if (data->branch_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 44,
                   window_y + 24, data->branch_name, value_color);
    }
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 117, "Cooking", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 140, "Speed", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 163, "Motivation", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 186, "Health", label_color);
    const int32_t stat_rows[4] = {117, 140, 163, 186};
    const int32_t stat_values[4] = {data->cooking, data->speed,
                                    data->motivation, data->health};
    for (int index = 0; index < 4; index++) {
        snprintf(value_text, sizeof(value_text), "%d", stat_values[index]);
        draw_label(surface, font_data, font_size, font, window_x + 100,
                   window_y + stat_rows[index], value_text, value_color);
    }

    static const char *const button_labels[5] = {
        "Headhunt", "Bribe", "Bribe", "Bribe", "Edit",
    };
    static const int32_t button_y[5] = {98, 123, 146, 169, 192};
    const uint8_t button_idle[4] = {180, 170, 150, 220};
    const uint8_t button_active[4] = {255, 215, 110, 235};
    for (int index = 0; index < 5; index++) {
        blend_rect(surface, window_x + 142, window_y + button_y[index], 84, 20,
                   index == data->selected_button ? button_active : button_idle);
        draw_label(surface, font_data, font_size, font, window_x + 150,
                   window_y + button_y[index] + 2, button_labels[index],
                   label_color);
    }

    if (data->employee_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 126,
                   window_y + 37, data->employee_name, value_color);
    }
    if (data->employee_role != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 126,
                   window_y + 60, data->employee_role, label_color);
    }
    snprintf(value_text, sizeof(value_text), "%u", data->age);
    draw_label(surface, font_data, font_size, font, window_x + 183,
               window_y + 49, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 49, "Age", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 71, "Performance", label_color);
    snprintf(value_text, sizeof(value_text), "%d%%", data->performance);
    draw_label(surface, font_data, font_size, font, window_x + 183,
               window_y + 71, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 83, "Salary", label_color);
    snprintf(value_text, sizeof(value_text), "%u", data->salary);
    draw_label(surface, font_data, font_size, font, window_x + 169,
               window_y + 83, value_text, value_color);

    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 242);
        render_blit(surface, separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 45,
               window_y + 253, "Owners", label_color);
    if (data->owner_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 45,
                   window_y + 278, data->owner_name, value_color);
    }
    if (logo_frame != NULL) {
        render_blit(surface, logo_frame, window_x + 181, window_y + 260);
    }
    if (rating_sprite != NULL) {
        render_blit(surface, rating_sprite, window_x + 199, window_y + 315);
        render_blit(surface, rating_sprite, window_x + 99, window_y + 315);
        render_blit(surface, rating_sprite, window_x + 49, window_y + 350);
    }
    snprintf(value_text, sizeof(value_text), "Branch %u", data->tile_index);
    draw_label(surface, font_data, font_size, font, window_x + 45,
               window_y + 358, value_text, label_color);
    return true;
}

bool screen_render_branch_offer(RenderSurface *surface, const RgbaSprite *panel,
                                const RgbaSprite *separator,
                                const uint8_t *font_data, size_t font_size,
                                const FntInfo *font, const BranchOfferData *data) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (panel != NULL && !render_blit(surface, panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Expand stocks", title_color);
    if (data->branch_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 44,
                   window_y + 24, data->branch_name, value_color);
    }
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 134, "Advantages", title_color);

    static const char *const group_names[8] = {
        "Kids", "Teens", "Students", "Louts",
        "Yuppies", "Big shots", "Gothics", "Tourist",
    };
    static const int32_t group_x[4] = {39, 88, 138, 188};
    static const int32_t group_y[2] = {304, 340};
    static const int32_t rating_x[4] = {49, 99, 149, 199};
    static const int32_t rating_y[2] = {315, 350};
    for (int group = 0; group < 8; group++) {
        int column = group % 4;
        int row = group / 4;
        draw_label(surface, font_data, font_size, font, window_x + group_x[column],
                   window_y + group_y[row], group_names[group], label_color);
        if (data->ratings[group] != NULL) {
            render_blit(surface, data->ratings[group],
                        window_x + rating_x[column], window_y + rating_y[row]);
        }
    }

    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 242);
        render_blit(surface, separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 258, "Costs", label_color);
    snprintf(value_text, sizeof(value_text), "%u", data->cost);
    draw_label(surface, font_data, font_size, font, window_x + 102,
               window_y + 258, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 279, "Length", label_color);
    snprintf(value_text, sizeof(value_text), "%u days", data->expand_days);
    draw_label(surface, font_data, font_size, font, window_x + 87,
               window_y + 279, value_text, value_color);
    snprintf(value_text, sizeof(value_text), "Capacity %u -> %u", data->capacity,
             data->new_capacity);
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 158, value_text, value_color);

    const uint8_t button_idle[4] = {140, 180, 140, 220};
    const uint8_t button_active[4] = {130, 230, 130, 235};
    blend_rect(surface, window_x + 142, window_y + 272, 84, 24,
               data->selected_button == 0 ? button_active : button_idle);
    draw_label(surface, font_data, font_size, font, window_x + 158,
               window_y + 276, "Expand", label_color);
    return true;
}

bool screen_render_personnel_overview(
    RenderSurface *surface, const RgbaSprite *panel,
    const RgbaSprite *tabs, const RgbaSprite *separator,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const PersonnelOverviewData *data) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (panel != NULL && !render_blit(surface, panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Hire staff", title_color);
    static const int32_t tab_x[4] = {53, 97, 141, 185};
    for (int index = 0; index < 4; index++) {
        if (tabs != NULL && tabs[index].pixels != NULL) {
            render_blit(surface, &tabs[index], window_x + tab_x[index],
                        window_y + 242);
        }
    }
    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 53,
               window_y + 163, "Cooking", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 136,
               window_y + 163, "Speed", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 53,
               window_y + 185, "Health", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 152,
               window_y + 185, "Motivation", label_color);

    const int32_t gauge_x[4] = {52, 151, 52, 151};
    const int32_t gauge_y[4] = {180, 180, 202, 202};
    const int32_t gauge_values[4] = {data->cooking, data->speed, data->health,
                                     data->motivation};
    const uint8_t gauge_color[4] = {70, 150, 70, 230};
    for (int index = 0; index < 4; index++) {
        int32_t value = gauge_values[index];
        if (value < 0) {
            value = 0;
        }
        if (value > 100) {
            value = 100;
        }
        blend_rect(surface, window_x + gauge_x[index], window_y + gauge_y[index],
                   80, 12, (const uint8_t[4]){80, 70, 60, 180});
        blend_rect(surface, window_x + gauge_x[index], window_y + gauge_y[index],
                   value * 80 / 100, 12, gauge_color);
    }

    if (data->candidate_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 53,
                   window_y + 62, data->candidate_name, value_color);
    }
    if (data->profession != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 53,
                   window_y + 84, data->profession, label_color);
    }
    snprintf(value_text, sizeof(value_text), "Age %u", data->age);
    draw_label(surface, font_data, font_size, font, window_x + 160,
               window_y + 84, value_text, value_color);

    const uint8_t button_idle[4] = {140, 180, 140, 220};
    const uint8_t button_active[4] = {130, 230, 130, 235};
    blend_rect(surface, window_x + 143, window_y + 98, 84, 24,
               data->selected_button == 0 ? button_active : button_idle);
    draw_label(surface, font_data, font_size, font, window_x + 155,
               window_y + 102, "Employ", label_color);

    static const int32_t rating_x[4] = {49, 99, 149, 199};
    for (int index = 0; index < 4; index++) {
        if (data->ratings[index] != NULL) {
            render_blit(surface, data->ratings[index], window_x + rating_x[index],
                        window_y + 315);
        }
    }
    return true;
}

bool screen_render_personnel_record(
    RenderSurface *surface, const RgbaSprite *panel,
    const RgbaSprite *plan_sprite, const RgbaSprite *plan_light,
    const RgbaSprite *separator, const uint8_t *font_data, size_t font_size,
    const FntInfo *font, const PersonnelRecordData *data) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (panel != NULL && !render_blit(surface, panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Staff", title_color);
    if (plan_sprite != NULL) {
        render_blit(surface, plan_sprite, window_x + 48, window_y + 224);
    }
    if (plan_light != NULL) {
        for (int index = 0; index < 7; index++) {
            render_blit(surface, plan_light, window_x + 48,
                        window_y + 234 + index * 10);
        }
    }
    if (data->employee_name != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 126,
                   window_y + 37, data->employee_name, value_color);
    }
    if (data->profession != NULL) {
        draw_label(surface, font_data, font_size, font, window_x + 126,
                   window_y + 60, data->profession, label_color);
    }
    snprintf(value_text, sizeof(value_text), "Age %u", data->age);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 49, value_text, label_color);

    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 117, "Cooking", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 140, "Speed", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 163, "Motivation", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 186, "Health", label_color);
    const int32_t stat_rows[4] = {117, 140, 163, 186};
    const int32_t stat_values[4] = {data->cooking, data->speed,
                                    data->motivation, data->health};
    for (int index = 0; index < 4; index++) {
        snprintf(value_text, sizeof(value_text), "%d", stat_values[index]);
        draw_label(surface, font_data, font_size, font, window_x + 100,
                   window_y + stat_rows[index], value_text, value_color);
    }

    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 297);
    }
    static const char *const group_names[8] = {
        "Kids", "Teens", "Students", "Louts",
        "Yuppies", "Big shots", "Gothics", "Tourist",
    };
    static const int32_t group_x[4] = {39, 88, 138, 188};
    static const int32_t group_y[2] = {304, 340};
    static const int32_t rating_x[4] = {49, 99, 149, 199};
    static const int32_t rating_y[2] = {315, 350};
    for (int group = 0; group < 8; group++) {
        int column = group % 4;
        int row = group / 4;
        draw_label(surface, font_data, font_size, font, window_x + group_x[column],
                   window_y + group_y[row], group_names[group], label_color);
        if (data->ratings[group] != NULL) {
            render_blit(surface, data->ratings[group],
                        window_x + rating_x[column], window_y + rating_y[row]);
        }
    }
    return true;
}

bool screen_render_statistics_balance(
    RenderSurface *surface, const RgbaSprite *background,
    const RgbaSprite *row_plate, const uint8_t *font_data, size_t font_size,
    const FntInfo *font, const StatisticsBalanceData *data) {
    if (surface == NULL || background == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background_color[4] = {22, 26, 34, 255};
    render_clear(surface, background_color);
    if (!render_blit(surface, background, 0, 0)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, 605, 223, "Balance",
               title_color);
    draw_label(surface, font_data, font_size, font, 43, 66, "Expenditures",
               title_color);
    draw_label(surface, font_data, font_size, font, 456, 66, "Income",
               title_color);
    if (data->validity != NULL) {
        draw_label(surface, font_data, font_size, font, 609, 258, data->validity,
                   label_color);
    }
    if (data->period != NULL) {
        draw_label(surface, font_data, font_size, font, 609, 498, data->period,
                   label_color);
    }

    for (size_t index = 0; index < data->expense_count && index < 8; index++) {
        int32_t y = 92 + (int32_t)index * 24;
        draw_label(surface, font_data, font_size, font, 43, y,
                   data->expenses[index].label, label_color);
        snprintf(value_text, sizeof(value_text), "%.2f",
                 data->expenses[index].amount);
        draw_label(surface, font_data, font_size, font, 210, y, value_text,
                   value_color);
    }
    for (size_t index = 0; index < data->income_count && index < 8; index++) {
        int32_t y = 92 + (int32_t)index * 24;
        draw_label(surface, font_data, font_size, font, 456, y,
                   data->incomes[index].label, label_color);
        snprintf(value_text, sizeof(value_text), "%.2f",
                 data->incomes[index].amount);
        draw_label(surface, font_data, font_size, font, 620, y, value_text,
                   value_color);
    }

    draw_label(surface, font_data, font_size, font, 614, 282, "Total",
               title_color);
    if (data->branch_name != NULL) {
        draw_label(surface, font_data, font_size, font, 614, 314,
                   data->branch_name, value_color);
    }
    for (int index = 0; index < 8; index++) {
        if (row_plate != NULL) {
            render_blit(surface, row_plate, 612, 279 + index * 21);
        }
    }
    double total = 0.0;
    for (size_t index = 0; index < data->income_count; index++) {
        total += data->incomes[index].amount;
    }
    for (size_t index = 0; index < data->expense_count; index++) {
        total -= data->expenses[index].amount;
    }
    snprintf(value_text, sizeof(value_text), "%.2f", total);
    draw_label(surface, font_data, font_size, font, 696, 282, value_text,
               value_color);
    return true;
}
