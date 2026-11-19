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

typedef struct StatisticsBalanceRow {
    const char *label;
    double amount;
} StatisticsBalanceRow;

/* Composes Screen_RecipeInfoPanel (0x41A6D0): the 39x303 DUMMYSPRITE sidebar
 * at (567,248) with its nine 37x31 image buttons at the original y offsets. */
/* Composes Screen_BuildOptionsSidebar (0x425E70): DUMMYSPRITE window at
 * (567,248) and the five option image buttons at exact offsets. */
bool screen_render_options_sidebar(RenderSurface *surface,
                                   const RgbaSprite *panel,
                                   const RgbaSprite *buttons,
                                   int selected);

bool screen_render_recipe_info_panel(RenderSurface *surface,
                                     const RgbaSprite *panel,
                                     const RgbaSprite *buttons,
                                     int selected);

typedef struct MissionGoalsData {
    const char *title;
    const char *help_text;
    const char *goal_labels[3];
    uint8_t completed[3];
    int32_t progress[3];
    uint32_t years;
    uint32_t capital;
    int selected_button; /* 0 = Complete mission */
} MissionGoalsData;

/* Composes Screen_MissionGoals (0x42D990): town aims, three goal rows,
 * capital/years summary and the Complete mission button. */
bool screen_render_mission_goals(RenderSurface *surface, const RgbaSprite *panel,
                                 const RgbaSprite *separator,
                                 const uint8_t *font_data, size_t font_size,
                                 const FntInfo *font,
                                 const MissionGoalsData *data);

typedef struct StatisticsBranchBalanceData {
    const char *branch_name;
    const char *period;
    const char *validity;
    double total;
    const StatisticsBalanceRow *rows;
    size_t row_count;
    const RgbaSprite *rating;
} StatisticsBranchBalanceData;

/* Composes Window_BuildStatisticsBranchBalancePage (0x433790) over the
 * shipped STATISTIKFILIALBILANZ.spr with row plates, bottom icons and rating. */
bool screen_render_statistics_branch_balance(
    RenderSurface *surface, const RgbaSprite *background,
    const RgbaSprite *row_plate, const RgbaSprite *rating,
    const RgbaSprite *icon_personal, const RgbaSprite *icon_money,
    const RgbaSprite *icon_load, const RgbaSprite *icon_balance,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const StatisticsBranchBalanceData *data);

typedef struct StatisticsBalanceData {
    const char *branch_name;
    const char *period;
    const char *validity;
    const StatisticsBalanceRow *expenses;
    size_t expense_count;
    const StatisticsBalanceRow *incomes;
    size_t income_count;
} StatisticsBalanceData;

/* Composes Screen_StatisticsBalance (0x430FD0) over the shipped
 * STATISTIKBILANZBACK.spr, with TAB09 row plates and expense/income columns. */
bool screen_render_statistics_balance(
    RenderSurface *surface, const RgbaSprite *background,
    const RgbaSprite *row_plate, const uint8_t *font_data, size_t font_size,
    const FntInfo *font, const StatisticsBalanceData *data);

typedef struct PersonnelRecordData {
    const char *employee_name;
    const char *profession;
    uint32_t age;
    int32_t cooking;
    int32_t speed;
    int32_t motivation;
    int32_t health;
    const RgbaSprite *ratings[8];
} PersonnelRecordData;

/* Composes Screen_PersonnelRecord (0x4632C0): PERSOPLAN staff record, stat
 * rows, seven PERSOPLANLIGHT bars and eight customer-group rating strips. */
bool screen_render_personnel_record(
    RenderSurface *surface, const RgbaSprite *panel,
    const RgbaSprite *plan_sprite, const RgbaSprite *plan_light,
    const RgbaSprite *separator, const uint8_t *font_data, size_t font_size,
    const FntInfo *font, const PersonnelRecordData *data);

typedef struct PersonnelOverviewData {
    const char *candidate_name;
    const char *profession;
    uint32_t age;
    int32_t health;
    int32_t motivation;
    int32_t cooking;
    int32_t speed;
    const RgbaSprite *ratings[4];
    int selected_tab;    /* 0..3 */
    int selected_button; /* 0 = Employ, -1 = none */
} PersonnelOverviewData;

/* Composes Screen_PersonnelOverview (0x415620): staff tabs, stat gauges,
 * candidate details, Employ button and rating strips. */
bool screen_render_personnel_overview(
    RenderSurface *surface, const RgbaSprite *panel,
    const RgbaSprite *tabs, const RgbaSprite *separator,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const PersonnelOverviewData *data);

typedef struct BranchOfferSprites {
    const RgbaSprite *panel;
    const RgbaSprite *separator;
    const RgbaSprite *button_background;
    const RgbaSprite *help_button;
    const RgbaSprite *storage_icon;
    const RgbaSprite *ratings[8];
} BranchOfferSprites;

typedef struct BranchOfferData {
    uint32_t expand_days;
    uint32_t cost;
    int selected_button; /* 0 = Expand, -1 = none */
} BranchOfferData;

/* Composes Screen_BranchOffer (0x45C150): stock expansion offer with the
 * eight customer-group rating strips and the Expand button. */
bool screen_render_branch_offer(RenderSurface *surface,
                                const BranchOfferSprites *sprites,
                                const uint8_t *font_data, size_t font_size,
                                const FntInfo *font, const BranchOfferData *data);

typedef struct BranchDetailsSprites {
    const RgbaSprite *panel;
    const RgbaSprite *separator;
    const RgbaSprite *logo_frame;
    const RgbaSprite *help_button;
    const RgbaSprite *button_background;
    const RgbaSprite *slider;
    const RgbaSprite *ratings[8];
} BranchDetailsSprites;

typedef struct BranchDetailsData {
    const char *employee_name;
    const char *employee_role;
    const char *owner_name;
    const char *working_location;
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
 * LOGORAHMEN frame, eight customer-group ratings, staff rows and buttons. */
bool screen_render_branch_details(RenderSurface *surface,
                                  const BranchDetailsSprites *sprites,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const BranchDetailsData *data);

typedef struct BranchListSprites {
    const RgbaSprite *panel;
    const RgbaSprite *table;
    const RgbaSprite *separator;
    const RgbaSprite *branch_icon;
    const RgbaSprite *warehouse_icon;
    const RgbaSprite *arrow_left;
    const RgbaSprite *arrow_right;
    const RgbaSprite *help_button;
    const RgbaSprite *button_background;
    const RgbaSprite *storage_icon;
} BranchListSprites;

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
bool screen_render_branch_list(RenderSurface *surface,
                               const BranchListSprites *sprites,
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
