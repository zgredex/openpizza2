#ifndef PC2_RECONSTRUCTED_SCREEN_RENDER_H
#define PC2_RECONSTRUCTED_SCREEN_RENDER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../assets/assets.h"
#include "../menu/menu_state.h"
#include "../render/render_state.h"
#include "../statistics/statistics_state.h"

/*
 * Map/UI screen composition: decode a shipped TGA background into the RGBA
 * surface, then draw the reconstructed main-menu rows with the FNT decoder.
 */
bool screen_render_background(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, uint8_t *decode_buffer,
                              size_t decode_capacity);
bool screen_render_menu(RenderSurface *surface, const uint8_t *tga_data,
                        size_t tga_size, const uint8_t *font_data,
                        size_t font_size, const FntInfo *font,
                        const MenuState *menu, uint8_t *decode_buffer,
                        size_t decode_capacity);
#define CHARACTER_ATTRIBUTE_COUNT 6

typedef struct CharacterScreenData {
    const char *player_name;
    const char *enterprise_name;
    int32_t attributes[CHARACTER_ATTRIBUTE_COUNT];
    uint32_t difficulty;
    int selected_button; /* 0 = To main menu, 1 = Start game, -1 = none */
} CharacterScreenData;

/* Composes the character-selection page over the shipped
 * pe_charakterauswahl.tga using the control positions from
 * Screen_CharacterSelect (0x46DBD0). */
bool screen_render_character_select(RenderSurface *surface,
                                    const uint8_t *tga_data, size_t tga_size,
                                    const uint8_t *font_data, size_t font_size,
                                    const FntInfo *font, const CharacterScreenData *data,
                                    uint8_t *decode_buffer,
                                    size_t decode_capacity);

/* Composes the statistics view over the shipped bg003.tga clipboard, using
 * the city/date positions from StatisticsView_CreateWindow (0x443520) and the
 * CompanyOverview fields filled by Stats_Report_FillCompanyOverview (0x4DECF0). */
bool screen_render_statistics(RenderSurface *surface, const uint8_t *tga_data,
                              size_t tga_size, const uint8_t *font_data,
                              size_t font_size, const FntInfo *font,
                              const StatisticsState *state, const char *city,
                              const char *date, uint8_t *decode_buffer,
                              size_t decode_capacity);

typedef struct BranchDetailsData {
    const char *branch_name;
    const char *employee_name;
    const char *employee_role;
    const char *owner_name;
    uint32_t tile_index;
    uint32_t age;
    int32_t cooking;
    int32_t speed;
    int32_t motivation;
    int32_t health;
    int32_t performance;
    uint32_t salary;
    int selected_button; /* 0..4 headhunt/bribe/edit, -1 none */
} BranchDetailsData;

/* Composes Screen_BranchDetails (0x451DD0): SUBMENUE window, separators,
 * LOGORAHMEN frame, BEWERTUNG rating sprite, staff rows and action buttons. */
bool screen_render_branch_details(RenderSurface *surface, const RgbaSprite *panel,
                                  const RgbaSprite *separator,
                                  const RgbaSprite *logo_frame,
                                  const RgbaSprite *rating_sprite,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const BranchDetailsData *data);

typedef struct BranchListEntry {
    uint32_t tile_index;
    uint32_t rent;
    bool warehouse;
} BranchListEntry;

typedef struct BranchListData {
    const char *city;
    const BranchListEntry *entries;
    size_t entry_count;
    int selected;
} BranchListData;

/* Composes Screen_BranchList (0x42D560): the 239x382 SUBMENUE window at
 * (561,218), table, separators, branch/warehouse icons and the branch rows. */
bool screen_render_branch_list(RenderSurface *surface, const RgbaSprite *panel,
                               const RgbaSprite *table,
                               const RgbaSprite *separator,
                               const RgbaSprite *branch_icon,
                               const RgbaSprite *warehouse_icon,
                               const uint8_t *font_data, size_t font_size,
                               const FntInfo *font,
                               const BranchListData *data);

typedef struct FreePlayScenario {
    const char *city;
    const char *map;
    const char *player_name;
    const char *enterprise_name;
    uint32_t population;
    uint32_t game_length;
    uint32_t difficulty;
    uint32_t starting_capital;
    int32_t opponents[3];
    int selected_button; /* 0 = To main menu, 1 = Start game, -1 = none */
} FreePlayScenario;

/* Composes the free-play setup page over the shipped pe_freies_spiel.tga using
 * the control positions from FreePlaySetup_InitWindow (0x4CBCD0) and
 * Screen_FreePlaySetup (0x472DA0). */
bool screen_render_free_play(RenderSurface *surface, const uint8_t *tga_data,
                             size_t tga_size, const uint8_t *font_data,
                             size_t font_size, const FntInfo *font,
                             const FreePlayScenario *scenario,
                             uint8_t *decode_buffer, size_t decode_capacity);

/* Draws the London briefing page over the shipped briefing TGA. Returns the
 * number of wrapped body lines drawn, or -1 on failure. */
int screen_render_briefing(RenderSurface *surface, const uint8_t *tga_data,
                           size_t tga_size, const uint8_t *font_data,
                           size_t font_size, const FntInfo *font,
                           const char *title, const char *body,
                           const char *prompt, uint8_t *decode_buffer,
                           size_t decode_capacity);

#endif
