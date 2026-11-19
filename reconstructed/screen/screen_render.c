#include "screen_render.h"

#include <stdio.h>
#include <string.h>

#include "../ui_render/ui_render.h"

static void draw_label(RenderSurface *surface, const uint8_t *font_data,
                       size_t font_size, const FntInfo *font, int32_t x,
                       int32_t y, const char *text, const uint8_t rgba[4]) {
    ui_draw_text(surface, font_data, font_size, font, x, y, text, rgba);
}

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
                        const RgbaSprite *button_sprite,
                        const MenuState *menu, uint8_t *decode_buffer,
                        size_t decode_capacity) {
    if (menu == NULL || font == NULL || button_sprite == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t highlight[4] = {255, 225, 120, 120};
    const uint8_t text_color[4] = {0, 0, 0, 255};
    for (int index = 0; index < MENU_ITEM_COUNT; index++) {
        const MenuItem *item = &menu->items[index];
        for (int32_t tile = 0; tile < (int32_t)item->width;
             tile += button_sprite->width) {
            render_blit(surface, button_sprite, item->x + tile, item->y);
        }
        bool highlighted = menu->hover >= 0 ? index == menu->hover
                                             : (menu->interacted && index == menu->selected);
        if (highlighted) {
            blend_rect(surface, item->x, item->y, (int32_t)item->width,
                       (int32_t)item->height, highlight);
        }
        uint32_t text_width = ui_measure_text(font, item->label);
        int32_t text_x = item->x + ((int32_t)item->width - (int32_t)text_width) / 2;
        int32_t text_y = item->y +
                         ((int32_t)item->height - (int32_t)font->line_height) / 2;
        if (!ui_draw_text(surface, font_data, font_size, font, text_x, text_y,
                          item->label, text_color)) {
            return false;
        }
    }
    return true;
}

bool screen_render_briefing(RenderSurface *surface, const uint8_t *tga_data,
                            size_t tga_size, const uint8_t *font_data,
                            size_t font_size, const FntInfo *font,
                            const MissionBriefingData *data,
                            uint8_t *decode_buffer, size_t decode_capacity) {
    if (surface == NULL || font == NULL || data == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};

    draw_label(surface, font_data, font_size, font, 608, 5, "Mission:",
               title_color);
    if (data->city != NULL) {
        draw_label(surface, font_data, font_size, font, 608, 33, data->city,
                   value_color);
    }
    if (data->help_text != NULL) {
        draw_wrapped_text(surface, font_data, font_size, font, 224, 510, 345,
                          data->help_text, label_color);
    }
    if (data->description != NULL) {
        draw_wrapped_text(surface, font_data, font_size, font, 611, 203, 155,
                          data->description, label_color);
    }
    if (data->logo_window != NULL) {
        render_blit(surface, data->logo_window, 626, 54);
    }
    if (data->scrollbar != NULL) {
        for (int32_t tile = 0; tile < 285; tile += data->scrollbar->height) {
            render_blit(surface, data->scrollbar, 780, 212 + tile);
        }
    }

    if (data->back_button != NULL) {
        for (int32_t tile = 0; tile < 204; tile += data->back_button->width) {
            render_blit(surface, data->back_button, 595 + tile, 509);
        }
    }
    if (data->start_button != NULL) {
        for (int32_t tile = 0; tile < 204; tile += data->start_button->width) {
            render_blit(surface, data->start_button, 595 + tile, 550);
        }
    }
    const uint8_t highlight[4] = {255, 225, 120, 120};
    if (data->selected_button == 0) {
        blend_rect(surface, 595, 509, 204, 38, highlight);
    } else if (data->selected_button == 1) {
        blend_rect(surface, 595, 550, 204, 38, highlight);
    }
    uint32_t width = ui_measure_text(font, "Back");
    draw_label(surface, font_data, font_size, font, 595 + (204 - (int32_t)width) / 2,
               509 + (38 - (int32_t)font->line_height) / 2, "Back",
               label_color);
    width = ui_measure_text(font, "Start Mission");
    draw_label(surface, font_data, font_size, font, 595 + (204 - (int32_t)width) / 2,
               550 + (38 - (int32_t)font->line_height) / 2, "Start Mission",
               label_color);
    return true;
}

bool screen_render_character_select(RenderSurface *surface,
                                    const uint8_t *tga_data, size_t tga_size,
                                    const CharacterSelectAssets *assets,
                                    const CharacterScreenData *data,
                                    uint8_t *decode_buffer,
                                    size_t decode_capacity) {
    if (assets == NULL || data == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    const uint8_t highlight[4] = {255, 225, 120, 120};
    char value_text[32];
    for (size_t index = 0; index < kCharacterSelectControlCount; index++) {
        const CharacterSelectControl *control = &kCharacterSelectControls[index];
        if (control->kind == CHARACTER_SELECT_KIND_TEXT) {
            const CharacterSelectFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id >= 1048 && control->id <= 1053) {
                int32_t value = data->attributes[control->id - 1048];
                snprintf(value_text, sizeof(value_text), "%d", value);
                text = value_text;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = control->x;
            if (control->align == 1) {
                draw_x = control->x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = control->x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, control->y, text, text_color)) {
                return false;
            }
        } else if (control->kind == CHARACTER_SELECT_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL &&
                !render_blit(surface, sprite, control->x, control->y)) {
                return false;
            }
        } else if (control->kind == CHARACTER_SELECT_KIND_SLIDER) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL) {
                uint32_t level = data->difficulty > 4 ? 4 : data->difficulty;
                int32_t offset = (int32_t)(level * control->width / 4);
                if (offset > (int32_t)control->width - (int32_t)sprite->width) {
                    offset = (int32_t)control->width - (int32_t)sprite->width;
                }
                if (!render_blit(surface, sprite, control->x + offset,
                                 control->y)) {
                    return false;
                }
            }
        } else if (control->kind == CHARACTER_SELECT_KIND_INPUT) {
            const CharacterSelectFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id == 1034 && data->enterprise_name != NULL) {
                text = data->enterprise_name;
            } else if (control->id == 1036 && data->player_name != NULL) {
                text = data->player_name;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              control->x, control->y, text, text_color)) {
                return false;
            }
        } else if (control->kind == CHARACTER_SELECT_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const CharacterSelectFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            bool selected = (control->id == 1076 && data->selected_button == 0) ||
                            (control->id == 1077 && data->selected_button == 1);
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, control->x + tile,
                                 control->y)) {
                    return false;
                }
            }
            if (selected) {
                blend_rect(surface, control->x, control->y,
                           (int32_t)control->width, (int32_t)sprite->height,
                           highlight);
            }
            uint32_t width = ui_measure_text(font->info, control->text);
            int32_t text_x = control->x +
                             ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = control->y +
                             ((int32_t)sprite->height -
                              (int32_t)font->info->line_height) /
                                 2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, control->text, text_color)) {
                return false;
            }
        }
    }
    return true;
}

bool screen_render_free_play(RenderSurface *surface, const uint8_t *tga_data,
                             size_t tga_size, const FreePlayAssets *assets,
                             const FreePlayScenario *scenario,
                             uint8_t *decode_buffer, size_t decode_capacity) {
    if (assets == NULL || scenario == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    const uint8_t highlight[4] = {255, 225, 120, 120};
    for (size_t index = 0; index < kFreePlayControlCount; index++) {
        const FreePlayControl *control = &kFreePlayControls[index];
        if (control->kind == FREE_PLAY_KIND_TEXT) {
            const FreePlayFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id == 1087 && scenario->player_name != NULL) {
                text = scenario->player_name;
            } else if (control->id == 1088 && scenario->enterprise_name != NULL) {
                text = scenario->enterprise_name;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = control->x;
            if (control->align == 1) {
                draw_x = control->x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = control->x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, control->y, text, text_color)) {
                return false;
            }
        } else if (control->kind == FREE_PLAY_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL &&
                !render_blit(surface, sprite, control->x, control->y)) {
                return false;
            }
        } else if (control->kind == FREE_PLAY_KIND_SLIDER) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite == NULL) {
                continue;
            }
            uint32_t level = 0;
            if (control->id == 1031) {
                level = scenario->difficulty;
            } else if (control->id == 1076) {
                level = scenario->game_length;
            } else if (control->id == 1079) {
                level = scenario->population;
            }
            if (level > 4) {
                level = 4;
            }
            int32_t offset = (int32_t)(level * control->width / 4);
            if (offset > (int32_t)control->width - (int32_t)sprite->width) {
                offset = (int32_t)control->width - (int32_t)sprite->width;
            }
            if (!render_blit(surface, sprite, control->x + offset,
                             control->y)) {
                return false;
            }
        } else if (control->kind == FREE_PLAY_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const FreePlayFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            bool selected =
                (control->id == 1250 && scenario->selected_button == 0) ||
                (control->id == 1251 && scenario->selected_button == 1);
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, control->x + tile,
                                 control->y)) {
                    return false;
                }
            }
            if (selected) {
                blend_rect(surface, control->x, control->y,
                           (int32_t)control->width, (int32_t)sprite->height,
                           highlight);
            }
            uint32_t width = ui_measure_text(font->info, control->text);
            int32_t text_x = control->x +
                             ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = control->y +
                             ((int32_t)sprite->height -
                              (int32_t)font->info->line_height) /
                                 2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, control->text, text_color)) {
                return false;
            }
        }
    }
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

bool screen_render_branch_list(RenderSurface *surface,
                               const BranchListSprites *sprites,
                               const uint8_t *font_data, size_t font_size,
                               const FntInfo *font,
                               const BranchListData *data) {
    if (surface == NULL || sprites == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (sprites->panel != NULL &&
        !render_blit(surface, sprites->panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Rent buildings", title_color);
    if (sprites->separator != NULL) {
        render_blit(surface, sprites->separator, window_x + 39, window_y + 297);
        render_blit(surface, sprites->separator, window_x + 39, window_y + 242);
    }
    if (sprites->branch_icon != NULL) {
        render_blit(surface, sprites->branch_icon, window_x + 99, window_y + 126);
    }
    if (sprites->warehouse_icon != NULL) {
        render_blit(surface, sprites->warehouse_icon, window_x + 141,
                    window_y + 126);
    }
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 126, "Branch", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 180,
               window_y + 126, "Stocks", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 149, "Mittel", value_color);
    draw_label(surface, font_data, font_size, font, window_x + 180,
               window_y + 149, "Mittel", value_color);
    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 253, "Rent per quarter:", label_color);
    uint32_t rent = data->entry_count > 0 ? data->entries[0].rent : 0;
    snprintf(value_text, sizeof(value_text), "%u$", rent);
    uint32_t rent_width = ui_measure_text(font, value_text);
    draw_label(surface, font_data, font_size, font,
               window_x + 167 + 65 - (int32_t)rent_width, window_y + 253,
               value_text, value_color);

    if (sprites->arrow_left != NULL) {
        render_blit(surface, sprites->arrow_left, window_x + 50, window_y + 273);
    }
    if (sprites->arrow_right != NULL) {
        render_blit(surface, sprites->arrow_right, window_x + 105,
                    window_y + 273);
    }
    snprintf(value_text, sizeof(value_text), "%d", data->selected + 1);
    draw_label(surface, font_data, font_size, font, window_x + 78,
               window_y + 274, value_text, label_color);
    if (sprites->button_background != NULL) {
        render_blit(surface, sprites->button_background, window_x + 142,
                    window_y + 274);
    }
    draw_label(surface, font_data, font_size, font, window_x + 160,
               window_y + 276, "Lease", label_color);

    draw_label(surface, font_data, font_size, font, window_x + 44,
               window_y + 303, "Persons in area of influence", label_color);
    if (sprites->storage_icon != NULL) {
        render_blit(surface, sprites->storage_icon, window_x + 93,
                    window_y + 43);
    }
    if (sprites->help_button != NULL) {
        render_blit(surface, sprites->help_button, window_x + 11, window_y - 1);
    }
    draw_wrapped_text(surface, font_data, font_size, font, window_x + 51,
                      window_y + 169, 180,
                      "You need warehouses to avoid buying expensive ingredients "
                      "from closest department store. From a warehouse you can "
                      "select a supplier to deliver to branches.",
                      label_color);
    if (sprites->table != NULL) {
        render_blit(surface, sprites->table, window_x + 47, window_y + 314);
    }
    static const int32_t row_y[2] = {316, 340};
    for (size_t index = 0; index < data->entry_count && index < 2; index++) {
        if ((int)index == data->selected) {
            blend_rect(surface, window_x + 48, window_y + row_y[index] - 1, 179,
                       20, (const uint8_t[4]){255, 225, 120, 150});
        }
        snprintf(value_text, sizeof(value_text), "%s %u",
                 data->entries[index].warehouse ? "Warehouse" : "Branch",
                 data->entries[index].tile_index);
        draw_label(surface, font_data, font_size, font, window_x + 52,
                   window_y + row_y[index], value_text, value_color);
        snprintf(value_text, sizeof(value_text), "%u", data->entries[index].rent);
        draw_label(surface, font_data, font_size, font, window_x + 160,
                   window_y + row_y[index], value_text, value_color);
    }
    return true;
}

bool screen_render_branch_details(RenderSurface *surface,
                                  const BranchDetailsSprites *sprites,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const BranchDetailsData *data) {
    if (surface == NULL || sprites == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (sprites->panel != NULL &&
        !render_blit(surface, sprites->panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Other staff", title_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 117, "Cooking", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 140, "Speed", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 163, "Motivation", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 48,
               window_y + 186, "Health", label_color);

    const int32_t stat_values[4] = {data->cooking, data->speed,
                                    data->motivation, data->health};
    const int32_t stat_y[4] = {134, 157, 180, 203};
    for (int index = 0; index < 4; index++) {
        int32_t value = stat_values[index];
        if (value < 0) {
            value = 0;
        }
        if (value > 100) {
            value = 100;
        }
        blend_rect(surface, window_x + 50, window_y + stat_y[index], 95, 8,
                   (const uint8_t[4]){80, 70, 60, 180});
        blend_rect(surface, window_x + 50, window_y + stat_y[index],
                   value * 95 / 100, 8,
                   (const uint8_t[4]){70, 150, 70, 230});
        if (sprites->slider != NULL) {
            render_blit(surface, sprites->slider,
                        window_x + 50 + value * 95 / 100 -
                            (int32_t)sprites->slider->width / 2,
                        window_y + stat_y[index] - 4);
        }
    }

    static const char *const button_labels[5] = {
        "Headhunt", "Bribe", "Bribe", "Bribe", "Edit",
    };
    static const int32_t button_y[5] = {98, 123, 146, 169, 192};
    const uint8_t button_active[4] = {255, 225, 120, 150};
    for (int index = 0; index < 5; index++) {
        if (sprites->button_background != NULL) {
            for (int32_t tile = 0; tile < 84; tile += sprites->button_background->width) {
                render_blit(surface, sprites->button_background,
                            window_x + 142 + tile, window_y + button_y[index]);
            }
        }
        if (index == data->selected_button) {
            blend_rect(surface, window_x + 142, window_y + button_y[index], 84,
                       21, button_active);
        }
        uint32_t width = ui_measure_text(font, button_labels[index]);
        draw_label(surface, font_data, font_size, font,
                   window_x + 142 + (84 - (int32_t)width) / 2,
                   window_y + button_y[index] + 2, button_labels[index],
                   label_color);
    }

    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 37,
               data->employee_name != NULL ? data->employee_name
                                            : "Carlos Estarda",
               value_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 49, "Age:", label_color);
    snprintf(value_text, sizeof(value_text), "%u", data->age);
    draw_label(surface, font_data, font_size, font, window_x + 183,
               window_y + 49, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 60,
               data->employee_role != NULL ? data->employee_role : "Koch",
               label_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 71, "Performance", label_color);
    snprintf(value_text, sizeof(value_text), "%d", data->performance);
    draw_label(surface, font_data, font_size, font, window_x + 183,
               window_y + 71, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 126,
               window_y + 83, "Salary ", label_color);
    snprintf(value_text, sizeof(value_text), "%u$", data->salary);
    draw_label(surface, font_data, font_size, font, window_x + 169,
               window_y + 83, value_text, value_color);

    if (sprites->separator != NULL) {
        render_blit(surface, sprites->separator, window_x + 39, window_y + 242);
        render_blit(surface, sprites->separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 51,
               window_y + 223, "Working location:", label_color);
    const char *location = data->working_location != NULL
                               ? data->working_location
                               : "Pizzeria";
    uint32_t location_width = ui_measure_text(font, location);
    draw_label(surface, font_data, font_size, font,
               window_x + 137 + 90 - (int32_t)location_width, window_y + 223,
               location, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 45,
               window_y + 253, "Owners:", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 45,
               window_y + 278,
               data->owner_name != NULL ? data->owner_name
                                         : "Pizza Tingeltangel",
               value_color);
    if (sprites->logo_frame != NULL) {
        render_blit(surface, sprites->logo_frame, window_x + 181,
                    window_y + 260);
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
        if (sprites->ratings[group] != NULL) {
            render_blit(surface, sprites->ratings[group],
                        window_x + rating_x[column], window_y + rating_y[row]);
        }
    }
    if (sprites->help_button != NULL) {
        render_blit(surface, sprites->help_button, window_x + 11, window_y - 1);
    }
    return true;
}

bool screen_render_branch_offer(RenderSurface *surface,
                                const BranchOfferSprites *sprites,
                                const uint8_t *font_data, size_t font_size,
                                const FntInfo *font, const BranchOfferData *data) {
    if (surface == NULL || sprites == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (sprites->panel != NULL &&
        !render_blit(surface, sprites->panel, window_x, window_y)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, window_x + 44, window_y + 5,
               "Expand stocks", title_color);
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
        if (sprites->ratings[group] != NULL) {
            render_blit(surface, sprites->ratings[group],
                        window_x + rating_x[column], window_y + rating_y[row]);
        }
    }

    if (sprites->separator != NULL) {
        render_blit(surface, sprites->separator, window_x + 39, window_y + 242);
        render_blit(surface, sprites->separator, window_x + 39, window_y + 297);
    }
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 258, "Costs:", label_color);
    snprintf(value_text, sizeof(value_text), "%u$", data->cost);
    uint32_t width = ui_measure_text(font, value_text);
    draw_label(surface, font_data, font_size, font,
               window_x + 102 + 80 - (int32_t)width, window_y + 258,
               value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 279, "Length:", label_color);
    snprintf(value_text, sizeof(value_text), "%uTage", data->expand_days);
    width = ui_measure_text(font, value_text);
    draw_label(surface, font_data, font_size, font,
               window_x + 87 + 55 - (int32_t)width, window_y + 279,
               value_text, value_color);

    if (sprites->button_background != NULL) {
        for (int32_t tile = 0; tile < 84; tile += sprites->button_background->width) {
            render_blit(surface, sprites->button_background,
                        window_x + 142 + tile, window_y + 274);
        }
    }
    if (data->selected_button == 0) {
        blend_rect(surface, window_x + 142, window_y + 274, 84, 21,
                   (const uint8_t[4]){255, 225, 120, 150});
    }
    width = ui_measure_text(font, "Expand");
    draw_label(surface, font_data, font_size, font,
               window_x + 142 + (84 - (int32_t)width) / 2, window_y + 276,
               "Expand", label_color);

    draw_label(surface, font_data, font_size, font, window_x + 49,
               window_y + 134, "Advantages:", title_color);
    draw_wrapped_text(surface, font_data, font_size, font, window_x + 49,
                      window_y + 152, 180,
                      " - greater capacity - better refrigeration - lower "
                      "transport costs",
                      label_color);
    if (sprites->help_button != NULL) {
        render_blit(surface, sprites->help_button, window_x + 11, window_y - 1);
    }
    if (sprites->storage_icon != NULL) {
        render_blit(surface, sprites->storage_icon, window_x + 93,
                    window_y + 48);
    }
    return true;
}

bool screen_render_personnel_overview(
    RenderSurface *surface, const PersonnelOverviewSprites *sprites,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const PersonnelOverviewData *data) {
    if (surface == NULL || sprites == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    const int32_t window_x = 561;
    const int32_t window_y = 218;
    if (sprites->panel != NULL &&
        !render_blit(surface, sprites->panel, window_x, window_y)) {
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
        if (sprites->tabs != NULL && sprites->tabs[index].pixels != NULL) {
            render_blit(surface, &sprites->tabs[index],
                        window_x + tab_x[index], window_y + 242);
        }
    }
    if (sprites->separator != NULL) {
        render_blit(surface, sprites->separator, window_x + 39, window_y + 297);
        render_blit(surface, sprites->separator, window_x + 39, window_y + 267);
    }
    draw_label(surface, font_data, font_size, font, window_x + 53,
               window_y + 163, "Cooking", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 136,
               window_y + 163, "Speed", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 53,
               window_y + 185, "Health", label_color);
    draw_label(surface, font_data, font_size, font, window_x + 152,
               window_y + 185, "Motivation", label_color);

    const int32_t stat_values[4] = {data->cooking, data->speed, data->health,
                                    data->motivation};
    static const int32_t bar_x[4] = {52, 52, 151, 151};
    static const int32_t bar_y[4] = {180, 202, 180, 202};
    for (int index = 0; index < 4; index++) {
        int32_t value = stat_values[index];
        if (value < 0) {
            value = 0;
        }
        if (value > 100) {
            value = 100;
        }
        blend_rect(surface, window_x + bar_x[index], window_y + bar_y[index],
                   80, 8, (const uint8_t[4]){80, 70, 60, 180});
        blend_rect(surface, window_x + bar_x[index], window_y + bar_y[index],
                   value * 80 / 100, 8, (const uint8_t[4]){70, 150, 70, 230});
        if (sprites->slider != NULL) {
            render_blit(surface, sprites->slider,
                        window_x + bar_x[index] + value * 80 / 100 -
                            (int32_t)sprites->slider->width / 2,
                        window_y + bar_y[index] - 4);
        }
    }
    if (sprites->arrow_left != NULL) {
        render_blit(surface, sprites->arrow_left, window_x + 53, window_y + 95);
    }
    if (sprites->arrow_right != NULL) {
        render_blit(surface, sprites->arrow_right, window_x + 93, window_y + 95);
    }
    if (sprites->button_background != NULL) {
        for (int32_t tile = 0; tile < 84; tile += sprites->button_background->width) {
            render_blit(surface, sprites->button_background,
                        window_x + 143 + tile, window_y + 100);
        }
    }
    if (data->selected_button == 0) {
        blend_rect(surface, window_x + 143, window_y + 100, 84, 21,
                   (const uint8_t[4]){255, 225, 120, 150});
    }
    draw_label(surface, font_data, font_size, font, window_x + 155,
               window_y + 102, "Employ", label_color);

    draw_label(surface, font_data, font_size, font, window_x + 127,
               window_y + 38,
               data->candidate_name != NULL ? data->candidate_name
                                             : "Carlos Estarda",
               value_color);
    draw_label(surface, font_data, font_size, font, window_x + 127,
               window_y + 50, "Age:", label_color);
    snprintf(value_text, sizeof(value_text), "%u", data->age);
    draw_label(surface, font_data, font_size, font, window_x + 190,
               window_y + 50, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 127,
               window_y + 61,
               data->profession != NULL ? data->profession : "Koch",
               label_color);
    draw_label(surface, font_data, font_size, font, window_x + 127,
               window_y + 72, "Performance", label_color);
    snprintf(value_text, sizeof(value_text), "%d", data->performance);
    draw_label(surface, font_data, font_size, font, window_x + 190,
               window_y + 72, value_text, value_color);
    draw_label(surface, font_data, font_size, font, window_x + 127,
               window_y + 84, "Salary ", label_color);
    snprintf(value_text, sizeof(value_text), "%u$", data->salary);
    draw_label(surface, font_data, font_size, font, window_x + 171,
               window_y + 84, value_text, value_color);

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
        if (sprites->ratings[group] != NULL) {
            render_blit(surface, sprites->ratings[group],
                        window_x + rating_x[column], window_y + rating_y[row]);
        }
    }
    if (sprites->help_button != NULL) {
        render_blit(surface, sprites->help_button, window_x + 11, window_y - 1);
    }
    if (sprites->photo_frame != NULL) {
        render_blit(surface, sprites->photo_frame, window_x + 52, window_y + 37);
    }
    if (sprites->photo_dummy != NULL) {
        render_blit(surface, sprites->photo_dummy, window_x + 57, window_y + 42);
    }
    if (sprites->button_background != NULL) {
        for (int32_t tile = 0; tile < 84; tile += sprites->button_background->width) {
            render_blit(surface, sprites->button_background,
                        window_x + 142 + tile, window_y + 274);
        }
    }
    if (data->selected_button == 1) {
        blend_rect(surface, window_x + 142, window_y + 274, 84, 21,
                   (const uint8_t[4]){255, 225, 120, 150});
    }
    draw_label(surface, font_data, font_size, font, window_x + 158,
               window_y + 276, "Back", label_color);
    if (sprites->plan_light != NULL) {
        render_blit(surface, sprites->plan_light, window_x + 57, window_y + 224);
    }
    static const char *const scale_labels[9] = {
        "0", "3", "6", "9", "12", "15", "18", "21", "24",
    };
    static const int32_t scale_x[9] = {56, 75, 96, 115, 132, 152, 172, 192, 211};
    for (int index = 0; index < 9; index++) {
        draw_label(surface, font_data, font_size, font, window_x + scale_x[index],
                   window_y + 213, scale_labels[index], label_color);
    }
    static const int32_t on_off_x[4] = {48, 120, 156, 84};
    for (int index = 0; index < 4; index++) {
        if (sprites->on_off[index] != NULL) {
            render_blit(surface, sprites->on_off[index], window_x + on_off_x[index],
                        window_y + 124);
        }
    }
    static const int32_t deco_x[4] = {39, 74, 40, 71};
    static const int32_t deco_y[4] = {9, 9, 20, 20};
    for (int index = 0; index < 4; index++) {
        if (sprites->slider_bars[index] != NULL) {
            render_blit(surface, sprites->slider_bars[index], window_x + deco_x[index],
                        window_y + deco_y[index]);
        }
    }
    for (int index = 0; index < 4; index++) {
        if (sprites->lower_sliders[index] != NULL) {
            render_blit(surface, sprites->lower_sliders[index], window_x + 58,
                        window_y + 231);
        }
    }
    return true;
}

bool screen_render_personnel_record(
    RenderSurface *surface, const PersonnelRecordAssets *assets,
    const PersonnelRecordData *data) {
    if (surface == NULL || assets == NULL || data == NULL) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    char value_text[32];
    if (assets->panel != NULL &&
        !render_blit(surface, assets->panel, PERSONNEL_RECORD_WINDOW_X,
                     PERSONNEL_RECORD_WINDOW_Y)) {
        return false;
    }
    for (size_t index = 0; index < kPersonnelRecordControlCount; index++) {
        const PersonnelRecordControl *control = &kPersonnelRecordControls[index];
        int32_t x = PERSONNEL_RECORD_WINDOW_X + control->x;
        int32_t y = PERSONNEL_RECORD_WINDOW_Y + control->y;
        if (control->kind == PERSONNEL_RECORD_KIND_TEXT) {
            const PersonnelRecordFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id == 1323 && data->employee_name != NULL) {
                text = data->employee_name;
            } else if (control->id == 1325 && data->profession != NULL) {
                text = data->profession;
            } else if (control->id == 1326) {
                snprintf(value_text, sizeof(value_text), "%u", data->age);
                text = value_text;
            } else if (control->id == 1322) {
                snprintf(value_text, sizeof(value_text), "%d",
                         data->performance);
                text = value_text;
            } else if (control->id == 1321) {
                snprintf(value_text, sizeof(value_text), "%u$",
                         data->salary);
                text = value_text;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = x;
            if (control->align == 1) {
                draw_x = x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, y, text, text_color)) {
                return false;
            }
        } else if (control->kind == PERSONNEL_RECORD_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL && !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == PERSONNEL_RECORD_KIND_SLIDER) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL && !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == PERSONNEL_RECORD_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const PersonnelRecordFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, x + tile, y)) {
                    return false;
                }
            }
            uint32_t width = ui_measure_text(font->info, control->text);
            int32_t text_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = y + ((int32_t)sprite->height -
                                  (int32_t)font->info->line_height) /
                                     2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, control->text, text_color)) {
                return false;
            }
        }
    }
    return true;
}

static bool balance_format_amount(char *buffer, size_t capacity, double amount) {
    if (capacity == 0) {
        return false;
    }
    long long whole = (long long)(amount < 0 ? amount - 0.5 : amount + 0.5);
    snprintf(buffer, capacity, "%+lld$", whole);
    return true;
}

bool screen_render_statistics_balance(
    RenderSurface *surface, const StatisticsBalanceAssets *assets,
    const StatisticsBalanceData *data) {
    if (surface == NULL || assets == NULL || data == NULL ||
        assets->sprites[BALANCE_ASSET_BACKGROUND] == NULL) {
        return false;
    }
    const uint8_t background_color[4] = {22, 26, 34, 255};
    const uint8_t text_color[4] = {0, 0, 0, 255};
    render_clear(surface, background_color);
    if (!render_blit(surface, assets->sprites[BALANCE_ASSET_BACKGROUND], 0, 0)) {
        return false;
    }
    double total = 0.0;
    for (size_t index = 0; index < data->income_count; index++) {
        total += data->incomes[index].amount;
    }
    for (size_t index = 0; index < data->expense_count; index++) {
        total -= data->expenses[index].amount;
    }
    size_t expense_index = 0;
    size_t income_index = 0;
    char value_text[64];
    char total_text[64];
    (void)balance_format_amount(total_text, sizeof(total_text), total);

    for (size_t index = 0; index < kBalanceControlCount; index++) {
        const BalanceControl *control = &kBalanceControls[index];
        if (control->kind == BALANCE_KIND_TEXT) {
            const StatisticsBalanceFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id == 1017 && data->branch_name != NULL) {
                text = data->branch_name;
            } else if (control->id == 1019) {
                text = total_text;
            } else if (strncmp(control->text, "#1.000.000$", 12) == 0 &&
                       (control->x == 201 || control->x == 200)) {
                if (expense_index < data->expense_count) {
                    balance_format_amount(value_text, sizeof(value_text),
                                          data->expenses[expense_index].amount);
                    text = value_text;
                }
                expense_index++;
            } else if (strncmp(control->text, "#1.000.000$", 12) == 0 &&
                       control->x == 455) {
                if (income_index < data->income_count) {
                    balance_format_amount(value_text, sizeof(value_text),
                                          data->incomes[income_index].amount);
                    text = value_text;
                }
                income_index++;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = control->x;
            if (control->align == 1) {
                draw_x = control->x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = control->x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, control->y, text, text_color)) {
                return false;
            }
            if (control->id == 1040 && data->validity != NULL) {
                uint32_t label_width = ui_measure_text(font->info, text);
                draw_label(surface, font->data, font->size, font->info,
                           control->x + (int32_t)label_width + 4, control->y,
                           data->validity, text_color);
            } else if (control->id == 1034 && data->period != NULL) {
                uint32_t label_width = ui_measure_text(font->info, text);
                draw_label(surface, font->data, font->size, font->info,
                           control->x + (int32_t)label_width + 4, control->y,
                           data->period, text_color);
            }
        } else {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite == NULL) {
                continue;
            }
            if (control->kind == BALANCE_KIND_SLIDER) {
                for (int32_t offset = 0; offset < (int32_t)control->width;
                     offset += (int32_t)sprite->height) {
                    if (!render_blit(surface, sprite, control->x,
                                     control->y + offset)) {
                        return false;
                    }
                }
            } else if (control->kind == BALANCE_KIND_BUTTON) {
                const StatisticsBalanceFont *font = &assets->fonts[control->font];
                if (font->data == NULL || font->info == NULL) {
                    return false;
                }
                for (int32_t offset = 0; offset < (int32_t)control->width;
                     offset += (int32_t)sprite->width) {
                    if (!render_blit(surface, sprite, control->x + offset,
                                     control->y)) {
                        return false;
                    }
                }
                uint32_t width = ui_measure_text(font->info, control->text);
                int32_t text_x = control->x +
                                 ((int32_t)control->width - (int32_t)width) / 2;
                int32_t text_y = control->y +
                                 ((int32_t)sprite->height -
                                  (int32_t)font->info->line_height) /
                                     2;
                if (!ui_draw_text(surface, font->data, font->size, font->info,
                                  text_x, text_y, control->text, text_color)) {
                    return false;
                }
            } else if (!render_blit(surface, sprite, control->x, control->y)) {
                return false;
            }
        }
    }
    return true;
}

bool screen_render_statistics_branch_balance(
    RenderSurface *surface, const RgbaSprite *background,
    const RgbaSprite *row_plate, const RgbaSprite *rating,
    const RgbaSprite *icon_personal, const RgbaSprite *icon_money,
    const RgbaSprite *icon_load, const RgbaSprite *icon_balance,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const StatisticsBranchBalanceData *data) {
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

    draw_label(surface, font_data, font_size, font, 605, 223,
               "Branch statistics", title_color);
    if (data->validity != NULL) {
        draw_label(surface, font_data, font_size, font, 609, 258, data->validity,
                   label_color);
    }
    if (data->period != NULL) {
        draw_label(surface, font_data, font_size, font, 609, 441, data->period,
                   label_color);
    }
    draw_label(surface, font_data, font_size, font, 648, 463,
               "Previous quarter", label_color);
    if (data->branch_name != NULL) {
        draw_label(surface, font_data, font_size, font, 614, 314,
                   data->branch_name, value_color);
    }
    snprintf(value_text, sizeof(value_text), "%.2f", data->total);
    draw_label(surface, font_data, font_size, font, 696, 282, value_text,
               value_color);
    draw_label(surface, font_data, font_size, font, 614, 282, "Total",
               title_color);

    if (row_plate != NULL) {
        render_blit(surface, row_plate, 611, 279);
    }
    for (size_t index = 0; index < data->row_count && index < 6; index++) {
        int32_t y = 310 + (int32_t)index * 21;
        if (row_plate != NULL) {
            render_blit(surface, row_plate, 611, y);
        }
        draw_label(surface, font_data, font_size, font, 614, y + 3,
                   data->rows[index].label, label_color);
        snprintf(value_text, sizeof(value_text), "%.2f",
                 data->rows[index].amount);
        draw_label(surface, font_data, font_size, font, 696, y + 3, value_text,
                   value_color);
    }

    if (rating != NULL) {
        render_blit(surface, rating, 245, 79);
    }
    if (icon_personal != NULL) {
        render_blit(surface, icon_personal, 616, 481);
    }
    if (icon_money != NULL) {
        render_blit(surface, icon_money, 682, 481);
    }
    if (icon_load != NULL) {
        render_blit(surface, icon_load, 748, 481);
    }
    if (icon_balance != NULL) {
        render_blit(surface, icon_balance, 748, 551);
    }
    return true;
}

bool screen_render_mission_goals(RenderSurface *surface, const RgbaSprite *panel,
                                 const RgbaSprite *separator,
                                 const uint8_t *font_data, size_t font_size,
                                 const FntInfo *font,
                                 const MissionGoalsData *data) {
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

    draw_label(surface, font_data, font_size, font,
               window_x + 44, window_y + 5,
               data->title != NULL ? data->title : "Town aims", title_color);
    if (data->help_text != NULL) {
        draw_wrapped_text(surface, font_data, font_size, font,
                          window_x + 47, window_y + 37, 185,
                          data->help_text, label_color);
    }
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 200, "Your tasks are therefore:", label_color);
    static const int32_t goal_y[3] = {214, 240, 267};
    static const char *const markers[3] = {"1.", "2.", "3."};
    for (int index = 0; index < 3; index++) {
        int32_t y = window_y + goal_y[index];
        draw_label(surface, font_data, font_size, font, window_x + 59, y,
                   markers[index], label_color);
        draw_label(surface, font_data, font_size, font, window_x + 72, y,
                   data->goal_labels[index] != NULL ? data->goal_labels[index]
                                                    : "",
                   label_color);
    }
    draw_label(surface, font_data, font_size, font, window_x + 47,
               window_y + 293, "Initial capital so far:", label_color);
    snprintf(value_text, sizeof(value_text), "%u $", data->capital);
    draw_label(surface, font_data, font_size, font, window_x + 140,
               window_y + 293, value_text, value_color);
    snprintf(value_text, sizeof(value_text), "%u Jahre", data->years);
    draw_label(surface, font_data, font_size, font, window_x + 140,
               window_y + 317, value_text, value_color);
    if (separator != NULL) {
        render_blit(surface, separator, window_x + 39, window_y + 332);
    }

    const uint8_t button_idle[4] = {140, 180, 140, 220};
    const uint8_t button_active[4] = {130, 230, 130, 235};
    blend_rect(surface, window_x + 48, window_y + 347, 180, 26,
               data->selected_button == 0 ? button_active : button_idle);
    uint32_t text_width = ui_measure_text(font, "Complete mission");
    draw_label(surface, font_data, font_size, font,
               window_x + 48 + (180 - (int32_t)text_width) / 2,
               window_y + 351, "Complete mission", label_color);
    return true;
}

bool screen_render_recipe_info_panel(RenderSurface *surface,
                                     const RgbaSprite *panel,
                                     const RgbaSprite *buttons,
                                     int selected) {
    if (surface == NULL || buttons == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    if (panel != NULL) {
        render_blit(surface, panel, 567, 248);
    }
    static const int32_t button_y[9] = {3, 33, 63, 93, 123, 273, 183, 213, 243};
    for (int index = 0; index < 9; index++) {
        if (buttons[index].pixels == NULL) {
            continue;
        }
        if (index == selected) {
            blend_rect(surface, 567, 248 + button_y[index], 39, 31,
                       (const uint8_t[4]){255, 225, 120, 150});
        }
        render_blit(surface, &buttons[index], 568, 251 + button_y[index]);
    }
    return true;
}

bool screen_render_options_sidebar(RenderSurface *surface,
                                   const RgbaSprite *panel,
                                   const RgbaSprite *buttons,
                                   int selected) {
    if (surface == NULL || buttons == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    if (panel != NULL) {
        render_blit(surface, panel, 567, 248);
    }
    static const int32_t button_y[5] = {93, 3, 63, 33, 123};
    for (int index = 0; index < 5; index++) {
        if (buttons[index].pixels == NULL) {
            continue;
        }
        if (index == selected) {
            blend_rect(surface, 568, 251 + button_y[index], 37, 31,
                       (const uint8_t[4]){255, 225, 120, 150});
        }
        render_blit(surface, &buttons[index], 568, 251 + button_y[index]);
    }
    return true;
}

bool screen_render_game_sidebar(RenderSurface *surface,
                                const RgbaSprite *panel,
                                const RgbaSprite *buttons,
                                int selected) {
    if (surface == NULL || buttons == NULL) {
        return false;
    }
    const uint8_t background[4] = {22, 26, 34, 255};
    render_clear(surface, background);
    if (panel != NULL) {
        render_blit(surface, panel, 567, 248);
    }
    static const int32_t button_y[10] = {3, 33, 63, 93, 123, 153, 183, 213,
                                         273, 243};
    for (int index = 0; index < 10; index++) {
        if (buttons[index].pixels == NULL) {
            continue;
        }
        if (index == selected) {
            blend_rect(surface, 568, 251 + button_y[index], 37, 31,
                       (const uint8_t[4]){255, 225, 120, 150});
        }
        render_blit(surface, &buttons[index], 568, 251 + button_y[index]);
    }
    return true;
}

static void draw_slider_track(RenderSurface *surface, const RgbaSprite *slider,
                              int32_t x, int32_t y, int32_t width,
                              int32_t value) {
    blend_rect(surface, x, y + 2, width, 4, (const uint8_t[4]){80, 70, 60, 180});
    if (slider != NULL) {
        int32_t clamped = value < 0 ? 0 : (value > 100 ? 100 : value);
        int32_t knob = x + clamped * width / 100 - (int32_t)slider->width / 2;
        render_blit(surface, slider, knob, y);
    }
}

bool screen_render_options_page(RenderSurface *surface,
                                const RgbaSprite *background,
                                const RgbaSprite *slider,
                                const RgbaSprite *separator,
                                const RgbaSprite *marker,
                                const uint8_t *font_data, size_t font_size,
                                const FntInfo *font,
                                const OptionsPageData *data) {
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

    draw_label(surface, font_data, font_size, font, 605, 224, "Options",
               title_color);
    draw_label(surface, font_data, font_size, font, 604, 255,
               "Volume of sound", title_color);
    draw_label(surface, font_data, font_size, font, 626, 275,
               "General volume", label_color);
    draw_label(surface, font_data, font_size, font, 626, 307, "Music",
               label_color);
    draw_label(surface, font_data, font_size, font, 626, 338, "Language",
               label_color);
    draw_slider_track(surface, slider, 635, 297, 140, data->general_volume);
    draw_slider_track(surface, slider, 635, 327, 140, data->music);
    draw_slider_track(surface, slider, 635, 358, 140, data->language);
    if (separator != NULL) {
        render_blit(surface, separator, 600, 376);
    }
    if (marker != NULL) {
        render_blit(surface, marker, 621, 412);
    }
    draw_label(surface, font_data, font_size, font, 647, 410,
               "People speak the local language", label_color);
    draw_label(surface, font_data, font_size, font, 604, 387, "Options",
               title_color);
    draw_label(surface, font_data, font_size, font, 627, 452,
               "Graphic level of detail", label_color);
    draw_slider_track(surface, slider, 638, 473, 140, data->graphic_detail);
    draw_label(surface, font_data, font_size, font, 628, 479, "damned high",
               label_color);
    draw_label(surface, font_data, font_size, font, 628, 508,
               "Autosave interval", label_color);
    draw_slider_track(surface, slider, 639, 529, 140, data->autosave);
    draw_label(surface, font_data, font_size, font, 638, 534, "4 minutes",
               label_color);
    return true;
}

bool screen_render_load_save_page(RenderSurface *surface,
                                  const RgbaSprite *background,
                                  const RgbaSprite *row_plate,
                                  const RgbaSprite *scrollbar,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const LoadSavePageData *data) {
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
    draw_label(surface, font_data, font_size, font, 605, 224, "Load/Savegame",
               title_color);
    draw_label(surface, font_data, font_size, font, 612, 258, "Select Savegame",
               label_color);

    static const int32_t row_y[LOAD_SAVE_ROW_COUNT] = {
        275, 296, 317, 338, 359, 380, 401, 422,
        443, 464, 485, 506, 527,
    };
    for (int index = 0; index < LOAD_SAVE_ROW_COUNT; index++) {
        if (row_plate != NULL) {
            render_blit(surface, row_plate, 613, row_y[index]);
        }
        if (index == data->selected) {
            blend_rect(surface, 613, row_y[index], 160, 21,
                       (const uint8_t[4]){255, 225, 120, 150});
        }
        const char *name = index < (int)data->count && data->names[index] != NULL
                               ? data->names[index]
                               : "Blablablablabla";
        draw_label(surface, font_data, font_size, font, 618, row_y[index] + 2,
                   name, label_color);
    }
    if (scrollbar != NULL) {
        for (int32_t tile = 0; tile < 270; tile += scrollbar->height) {
            render_blit(surface, scrollbar, 783, 281 + tile);
        }
    }
    return true;
}

bool screen_render_statistics_backdrop(
    RenderSurface *surface, const StatisticsBackdropSprites *sprites,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const StatisticsBackdropData *data) {
    if (surface == NULL || sprites == NULL || font == NULL || data == NULL) {
        return false;
    }
    const uint8_t background_color[4] = {22, 26, 34, 255};
    render_clear(surface, background_color);
    if (sprites->background == NULL ||
        !render_blit(surface, sprites->background, 0, 0)) {
        return false;
    }
    const uint8_t title_color[4] = {120, 20, 20, 255};
    const uint8_t label_color[4] = {40, 28, 20, 255};
    const uint8_t value_color[4] = {20, 20, 90, 255};
    char value_text[64];

    draw_label(surface, font_data, font_size, font, 605, 225,
               "Comparison of enterprises", title_color);
    draw_label(surface, font_data, font_size, font, 605, 254,
               "Comparable areas", label_color);
    static const int32_t icon_x[8] = {614, 658, 702, 702, 614, 658, 746, 746};
    static const int32_t icon_y[8] = {270, 270, 270, 313, 313, 313, 270, 313};
    for (int index = 0; index < 8; index++) {
        if (sprites->icons[index] != NULL) {
            render_blit(surface, sprites->icons[index], icon_x[index],
                        icon_y[index]);
        }
    }
    static const int32_t logo_x[6] = {768, 767, 767, 767, 767, 767};
    static const int32_t logo_y[6] = {559, 416, 451, 486, 525, 383};
    for (int index = 0; index < 6; index++) {
        if (sprites->logos[index] != NULL) {
            render_blit(surface, sprites->logos[index], logo_x[index],
                        logo_y[index]);
        }
    }
    static const int32_t row_y[COMPARISON_ROW_COUNT] = {385, 420, 455, 490,
                                                        525, 560};
    for (int index = 0; index < COMPARISON_ROW_COUNT; index++) {
        if (sprites->row_marker != NULL) {
            render_blit(surface, sprites->row_marker, 608, row_y[index] + 1);
        }
        if (index < (int)data->row_count && data->rows != NULL) {
            const ComparisonRow *row = &data->rows[index];
            if (row->name != NULL) {
                draw_label(surface, font_data, font_size, font, 631,
                           row_y[index], row->name, value_color);
            }
            draw_label(surface, font_data, font_size, font, 631,
                       row_y[index] + 12, "Points", label_color);
            snprintf(value_text, sizeof(value_text), "%u", row->points);
            uint32_t width = ui_measure_text(font, value_text);
            draw_label(surface, font_data, font_size, font,
                       686 + 85 - (int32_t)width, row_y[index] + 12,
                       value_text, value_color);
        }
    }
    if (data->total_text != NULL) {
        draw_label(surface, font_data, font_size, font, 32, 66,
                   data->total_text, value_color);
    }
    if (data->period_text != NULL) {
        draw_label(surface, font_data, font_size, font, 403, 516,
                   data->period_text, label_color);
    }
    if (sprites->help_button != NULL) {
        render_blit(surface, sprites->help_button, 572, 217);
    }
    if (sprites->button_background != NULL) {
        for (int32_t tile = 0; tile < 160; tile += sprites->button_background->width) {
            render_blit(surface, sprites->button_background, 615 + tile, 356);
        }
    }
    if (data->selected_button == 0) {
        blend_rect(surface, 615, 356, 160, 21,
                   (const uint8_t[4]){255, 225, 120, 150});
    }
    draw_label(surface, font_data, font_size, font, 630, 358,
               "Total evaluation", label_color);
    return true;
}

bool screen_render_office_desk(RenderSurface *surface, const uint8_t *tga_data,
                               size_t tga_size,
                               const OfficeDeskAssets *assets,
                               const OfficeDeskData *data,
                               uint8_t *decode_buffer,
                               size_t decode_capacity) {
    if (surface == NULL || assets == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    for (size_t index = 0; index < kOfficeDeskControlCount; index++) {
        const OfficeDeskControl *control = &kOfficeDeskControls[index];
        if (control->kind == OFFICE_KIND_TEXT) {
            const OfficeDeskFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (data != NULL) {
                if (control->id == 1039 && data->city != NULL) {
                    text = data->city;
                } else if (control->id == 1040 && data->clock != NULL) {
                    text = data->clock;
                } else if (control->id == 1077 &&
                           data->time_left_clock != NULL) {
                    text = data->time_left_clock;
                } else if (control->id == 1079 &&
                           data->time_left_label != NULL) {
                    text = data->time_left_label;
                } else if (control->id == 8005 && data->guid != NULL) {
                    text = data->guid;
                } else if (control->id == 8001 && data->date != NULL) {
                    text = data->date;
                }
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = control->x;
            if (control->align == 1) {
                draw_x = control->x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = control->x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, control->y, text, text_color)) {
                return false;
            }
        } else if (control->kind == OFFICE_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL &&
                !render_blit(surface, sprite, control->x, control->y)) {
                return false;
            }
        } else if (control->kind == OFFICE_KIND_ANIMATION) {
            int animation = -1;
            if (control->id == 1080) {
                animation = 0;
            } else if (control->id == 1045) {
                animation = 1;
            } else if (control->id == 1041) {
                animation = 2;
            } else if (control->id == 1042) {
                animation = 3;
            } else if (control->id == 1044) {
                animation = 4;
            } else if (control->id == 1043) {
                animation = 5;
            }
            if (animation >= 0 && assets->animations[animation] != NULL &&
                !render_blit(surface, assets->animations[animation],
                             control->x, control->y)) {
                return false;
            }
        }
    }
    return true;
}

bool screen_render_warehouse(RenderSurface *surface,
                             const WarehouseAssets *assets,
                             const WarehouseScreenData *data) {
    if (surface == NULL || assets == NULL) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    const uint8_t highlight[4] = {255, 225, 120, 120};
    char value_text[32];
    if (assets->panel != NULL &&
        !render_blit(surface, assets->panel, WAREHOUSE_WINDOW_X,
                     WAREHOUSE_WINDOW_Y)) {
        return false;
    }
    for (size_t index = 0; index < kWarehouseControlCount; index++) {
        const WarehouseControl *control = &kWarehouseControls[index];
        int32_t x = WAREHOUSE_WINDOW_X + control->x;
        int32_t y = WAREHOUSE_WINDOW_Y + control->y;
        if (control->kind == WAREHOUSE_KIND_TEXT) {
            const WarehouseFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (data != NULL) {
                if (control->id >= 1200 && control->id <= 1207) {
                    const char *branch = data->branch_names[control->id - 1200];
                    if (branch != NULL) {
                        text = branch;
                    }
                } else if (control->id >= 1300 && control->id <= 1307) {
                    snprintf(value_text, sizeof(value_text), "%u%%",
                             data->supplies[control->id - 1300]);
                    text = value_text;
                }
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = x;
            if (control->align == 1) {
                draw_x = x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, y, text, text_color)) {
                return false;
            }
        } else if (control->kind == WAREHOUSE_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL && !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == WAREHOUSE_KIND_SLIDER) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL &&
                !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == WAREHOUSE_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const WarehouseFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            bool selected =
                (control->id == 8173 && data != NULL &&
                 data->selected_button == 0) ||
                (control->id == 8177 && data != NULL &&
                 data->selected_button == 1);
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, x + tile, y)) {
                    return false;
                }
            }
            if (selected) {
                blend_rect(surface, x, y, (int32_t)control->width,
                           (int32_t)sprite->height, highlight);
            }
            const char *text = control->text;
            if (control->id == 8173 && data != NULL &&
                data->warehouse_name != NULL) {
                text = data->warehouse_name;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t text_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = y + ((int32_t)sprite->height -
                                  (int32_t)font->info->line_height) /
                                     2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, text, text_color)) {
                return false;
            }
        }
    }
    return true;
}

bool screen_render_building_project(RenderSurface *surface,
                                    const BuildingProjectAssets *assets,
                                    const BuildingProjectData *data) {
    if (surface == NULL || assets == NULL) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    const uint8_t highlight[4] = {255, 225, 120, 120};
    char value_text[32];
    if (assets->panel != NULL &&
        !render_blit(surface, assets->panel, BUILDING_PROJECT_WINDOW_X,
                     BUILDING_PROJECT_WINDOW_Y)) {
        return false;
    }
    for (size_t index = 0; index < kBuildingProjectControlCount; index++) {
        const BuildingProjectControl *control = &kBuildingProjectControls[index];
        int32_t x = BUILDING_PROJECT_WINDOW_X + control->x;
        int32_t y = BUILDING_PROJECT_WINDOW_Y + control->y;
        if (control->kind == BUILDING_PROJECT_KIND_TEXT) {
            const BuildingProjectFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (control->id == 1168) {
                snprintf(value_text, sizeof(value_text), "%u$",
                         data != NULL ? data->cost : 500000u);
                text = value_text;
            } else if (control->id == 1169) {
                snprintf(value_text, sizeof(value_text), "%u%%",
                         data != NULL ? data->effect : 53u);
                text = value_text;
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = x;
            if (control->align == 1) {
                draw_x = x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, y, text, text_color)) {
                return false;
            }
        } else if (control->kind == BUILDING_PROJECT_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL && !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == BUILDING_PROJECT_KIND_SLIDER) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL && !render_blit(surface, sprite, x, y)) {
                return false;
            }
        } else if (control->kind == BUILDING_PROJECT_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const BuildingProjectFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            const char *text = control->text;
            int option = -1;
            if (control->id == 1154) {
                option = 0;
            } else if (control->id == 1163) {
                option = 1;
            } else if (control->id == 1166) {
                option = 2;
            }
            if (option >= 0 && data != NULL &&
                data->option_labels[option] != NULL) {
                text = data->option_labels[option];
            }
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, x + tile, y)) {
                    return false;
                }
            }
            if (data != NULL && data->selected_button >= 0) {
                bool selected =
                    (option >= 0 && data->selected_button == option) ||
                    (control->id == 8003 && data->selected_button == 3);
                if (selected) {
                    blend_rect(surface, x, y, (int32_t)control->width,
                               (int32_t)sprite->height, highlight);
                }
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t text_x = x + ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = y + ((int32_t)sprite->height -
                                  (int32_t)font->info->line_height) /
                                     2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, text, text_color)) {
                return false;
            }
        }
    }
    return true;
}

bool screen_render_end_results(RenderSurface *surface, const uint8_t *tga_data,
                               size_t tga_size,
                               const EndResultsAssets *assets,
                               const EndResultsData *data,
                               uint8_t *decode_buffer,
                               size_t decode_capacity) {
    if (assets == NULL) {
        return false;
    }
    if (!screen_render_background(surface, tga_data, tga_size, decode_buffer,
                                  decode_capacity)) {
        return false;
    }
    const uint8_t text_color[4] = {0, 0, 0, 255};
    const uint8_t highlight[4] = {255, 225, 120, 120};
    char value_text[32];
    for (size_t index = 0; index < kEndResultsControlCount; index++) {
        const EndResultsControl *control = &kEndResultsControls[index];
        if (control->kind == END_RESULTS_KIND_TEXT) {
            const EndResultsFont *font = &assets->fonts[control->font];
            if (font->data == NULL || font->info == NULL) {
                return false;
            }
            const char *text = control->text;
            if (data != NULL) {
                if (control->id == 1214 && data->company_name != NULL) {
                    text = data->company_name;
                } else if (control->id == 1216) {
                    snprintf(value_text, sizeof(value_text), "%u",
                             data->points);
                    text = value_text;
                }
            }
            uint32_t width = ui_measure_text(font->info, text);
            int32_t draw_x = control->x;
            if (control->align == 1) {
                draw_x = control->x + control->width - (int32_t)width;
            } else if (control->align == 2) {
                draw_x = control->x + ((int32_t)control->width - (int32_t)width) / 2;
            }
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              draw_x, control->y, text, text_color)) {
                return false;
            }
        } else if (control->kind == END_RESULTS_KIND_SPRITE) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            if (sprite != NULL &&
                !render_blit(surface, sprite, control->x, control->y)) {
                return false;
            }
        } else if (control->kind == END_RESULTS_KIND_BUTTON) {
            const RgbaSprite *sprite = assets->sprites[control->asset];
            const EndResultsFont *font = &assets->fonts[control->font];
            if (sprite == NULL || font->data == NULL || font->info == NULL) {
                continue;
            }
            for (int32_t tile = 0; tile < (int32_t)control->width;
                 tile += (int32_t)sprite->width) {
                if (!render_blit(surface, sprite, control->x + tile,
                                 control->y)) {
                    return false;
                }
            }
            bool selected = data != NULL && data->selected_button >= 0;
            if (selected) {
                int button_index = -1;
                if (control->id == 1443) {
                    button_index = 0;
                } else if (control->id == 1444) {
                    button_index = 1;
                } else if (control->id == 1445) {
                    button_index = 2;
                } else if (control->id == 1446) {
                    button_index = 3;
                } else if (control->id == 1232) {
                    button_index = 4;
                }
                if (button_index == data->selected_button) {
                    blend_rect(surface, control->x, control->y,
                               (int32_t)control->width,
                               (int32_t)sprite->height, highlight);
                }
            }
            uint32_t width = ui_measure_text(font->info, control->text);
            int32_t text_x = control->x +
                             ((int32_t)control->width - (int32_t)width) / 2;
            int32_t text_y = control->y +
                             ((int32_t)sprite->height -
                              (int32_t)font->info->line_height) /
                                 2;
            if (!ui_draw_text(surface, font->data, font->size, font->info,
                              text_x, text_y, control->text, text_color)) {
                return false;
            }
        }
    }
    return true;
}
