#ifndef PC2_RECONSTRUCTED_SCREEN_RENDER_H
#define PC2_RECONSTRUCTED_SCREEN_RENDER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../assets/assets.h"
#include "../menu/menu_state.h"
#include "../render/render_state.h"
#include "../statistics/statistics_state.h"
#include "character_select_layout.h"
#include "free_play_layout.h"
#include "office_desk_layout.h"
#include "statistics_balance_layout.h"

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
                        const RgbaSprite *button_sprite,
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

typedef struct CharacterSelectFont {
    const uint8_t *data;
    size_t size;
    const FntInfo *info;
} CharacterSelectFont;

typedef struct CharacterSelectAssets {
    const RgbaSprite *sprites[CHARACTER_SELECT_ASSET_COUNT];
    CharacterSelectFont fonts[CHARACTER_SELECT_FONT_COUNT];
} CharacterSelectAssets;

/* Composes Screen_CharacterSelect (0x46DBD0) exactly: the shipped
 * pe_charakterauswahl.tga plus all 66 constructor controls at their original
 * positions, fonts, alignments and strings. */
bool screen_render_character_select(RenderSurface *surface,
                                    const uint8_t *tga_data, size_t tga_size,
                                    const CharacterSelectAssets *assets,
                                    const CharacterScreenData *data,
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
/* Composes Screen_BuildGameSidebar (0x40BB00): DUMMYSPRITE window at
 * (567,248) and ten in-game image buttons at exact offsets. */
bool screen_render_game_sidebar(RenderSurface *surface,
                                const RgbaSprite *panel,
                                const RgbaSprite *buttons,
                                int selected);

#define LOAD_SAVE_ROW_COUNT 13

#define COMPARISON_ROW_COUNT 6

typedef struct ComparisonRow {
    const char *name;
    uint32_t points;
} ComparisonRow;

typedef struct StatisticsBackdropSprites {
    const RgbaSprite *background;
    const RgbaSprite *icons[8];
    const RgbaSprite *logos[6];
    const RgbaSprite *row_marker;
    const RgbaSprite *help_button;
    const RgbaSprite *button_background;
} StatisticsBackdropSprites;

typedef struct StatisticsBackdropData {
    const ComparisonRow *rows;
    size_t row_count;
    const char *total_text;
    const char *period_text;
    int selected_button;
} StatisticsBackdropData;

/* Composes Screen_StatisticsBackdrop (0x43E430): enterprise comparison
 * background, eight area icons, six logos and six company rows. */
bool screen_render_statistics_backdrop(
    RenderSurface *surface, const StatisticsBackdropSprites *sprites,
    const uint8_t *font_data, size_t font_size, const FntInfo *font,
    const StatisticsBackdropData *data);

typedef struct LoadSavePageData {
    const char *names[LOAD_SAVE_ROW_COUNT];
    size_t count;
    int selected;
} LoadSavePageData;

/* Composes Screen_SubStartMenu_A (0x4750B0): PE_SUB_STARTSCREEN background,
 * 13 save-row plates, names and the vertical scrollbar. */
bool screen_render_load_save_page(RenderSurface *surface,
                                  const RgbaSprite *background,
                                  const RgbaSprite *row_plate,
                                  const RgbaSprite *scrollbar,
                                  const uint8_t *font_data, size_t font_size,
                                  const FntInfo *font,
                                  const LoadSavePageData *data);

typedef struct OptionsPageData {
    int32_t general_volume;
    int32_t music;
    int32_t language;
    int32_t graphic_detail;
    int32_t autosave;
} OptionsPageData;

/* Composes Screen_SubStartMenu_B (0x46E960): PE_SUB_STARTSCREEN background,
 * volume/music/language sliders and graphics/autosave controls. */
bool screen_render_options_page(RenderSurface *surface,
                                const RgbaSprite *background,
                                const RgbaSprite *slider,
                                const RgbaSprite *separator,
                                const RgbaSprite *marker,
                                const uint8_t *font_data, size_t font_size,
                                const FntInfo *font,
                                const OptionsPageData *data);

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

typedef struct StatisticsBalanceFont {
    const uint8_t *data;
    size_t size;
    const FntInfo *info;
} StatisticsBalanceFont;

typedef struct StatisticsBalanceAssets {
    const RgbaSprite *sprites[BALANCE_ASSET_COUNT];
    StatisticsBalanceFont fonts[6];
} StatisticsBalanceAssets;

typedef struct StatisticsBalanceData {
    const char *branch_name;
    const char *period;
    const char *validity;
    const StatisticsBalanceRow *expenses;
    size_t expense_count;
    const StatisticsBalanceRow *incomes;
    size_t income_count;
} StatisticsBalanceData;

/* Composes Screen_StatisticsBalance (0x430FD0) exactly: the shipped
 * STATISTIKBILANZBACK background plus all 162 constructor controls, their
 * original positions, alignments, fonts and strings. */
bool screen_render_statistics_balance(
    RenderSurface *surface, const StatisticsBalanceAssets *assets,
    const StatisticsBalanceData *data);

typedef struct OfficeDeskFont {
    const uint8_t *data;
    size_t size;
    const FntInfo *info;
} OfficeDeskFont;

typedef struct OfficeDeskAssets {
    const RgbaSprite *sprites[OFFICE_ASSET_COUNT];
    OfficeDeskFont fonts[OFFICE_FONT_COUNT];
} OfficeDeskAssets;

typedef struct OfficeDeskData {
    const char *city;
    const char *clock;
    const char *time_left_clock;
    const char *time_left_label;
    const char *guid;
    const char *date;
} OfficeDeskData;

/* Composes Screen_BuildOfficeDesk (0x4258C0): BG002 desk background plus all
 * 42 constructor controls at their original positions and fonts. The six
 * animation windows are represented by exact table entries; their ANI frames
 * are not decoded yet and are not drawn. */
bool screen_render_office_desk(RenderSurface *surface, const uint8_t *tga_data,
                               size_t tga_size,
                               const OfficeDeskAssets *assets,
                               const OfficeDeskData *data,
                               uint8_t *decode_buffer,
                               size_t decode_capacity);

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

typedef struct PersonnelOverviewSprites {
    const RgbaSprite *panel;
    const RgbaSprite *tabs;
    const RgbaSprite *separator;
    const RgbaSprite *button_background;
    const RgbaSprite *help_button;
    const RgbaSprite *arrow_left;
    const RgbaSprite *arrow_right;
    const RgbaSprite *photo_frame;
    const RgbaSprite *photo_dummy;
    const RgbaSprite *plan_light;
    const RgbaSprite *slider;
    const RgbaSprite *on_off[4];
    const RgbaSprite *lower_sliders[4];
    const RgbaSprite *slider_bars[4];
    const RgbaSprite *ratings[8];
} PersonnelOverviewSprites;

typedef struct PersonnelOverviewData {
    const char *candidate_name;
    const char *profession;
    uint32_t age;
    int32_t health;
    int32_t motivation;
    int32_t cooking;
    int32_t speed;
    int32_t performance;
    uint32_t salary;
    int selected_tab;    /* 0..3 */
    int selected_button; /* 0 = Employ, 1 = Back, -1 = none */
} PersonnelOverviewData;

/* Composes Screen_PersonnelOverview (0x415620): staff tabs, stat gauges,
 * candidate details, Employ/Back buttons and eight rating strips. */
bool screen_render_personnel_overview(
    RenderSurface *surface, const PersonnelOverviewSprites *sprites,
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

typedef struct FreePlayFont {
    const uint8_t *data;
    size_t size;
    const FntInfo *info;
} FreePlayFont;

typedef struct FreePlayAssets {
    const RgbaSprite *sprites[FREE_PLAY_ASSET_COUNT];
    FreePlayFont fonts[FREE_PLAY_FONT_COUNT];
} FreePlayAssets;

/* Composes Screen_FreePlaySetup (0x472DA0) exactly: the shipped
 * pe_freies_spiel.tga plus all 157 constructor controls at their original
 * positions, fonts, alignments and strings. */
bool screen_render_free_play(RenderSurface *surface, const uint8_t *tga_data,
                             size_t tga_size, const FreePlayAssets *assets,
                             const FreePlayScenario *scenario,
                             uint8_t *decode_buffer, size_t decode_capacity);

typedef struct MissionBriefingData {
    const char *city;
    const char *description;
    const char *help_text;
    const RgbaSprite *logo_window;
    const RgbaSprite *back_button;
    const RgbaSprite *start_button;
    const RgbaSprite *scrollbar;
    int selected_button; /* 0 = Back, 1 = Start Mission */
} MissionBriefingData;

/* Composes Screen_MissionBriefing (0x474DF0): mission TGA, city/title,
 * description, help text, logo window, scrollbar and the two buttons. */
bool screen_render_briefing(RenderSurface *surface, const uint8_t *tga_data,
                            size_t tga_size, const uint8_t *font_data,
                            size_t font_size, const FntInfo *font,
                            const MissionBriefingData *data,
                            uint8_t *decode_buffer, size_t decode_capacity);

#endif
