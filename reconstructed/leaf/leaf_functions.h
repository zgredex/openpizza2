#ifndef PC2_RECONSTRUCTED_LEAF_FUNCTIONS_H
#define PC2_RECONSTRUCTED_LEAF_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../assets/assets.h"

/* Leaf routines recovered from the original executable. Addresses refer to
 * decompiled_fastfood2_named_v2/functions_readable. */

/* Clamp_0_100 (0x477100). */
void clamp_0_100(int32_t *value);

/* Distance_Manhattan3 (0x4ED570): 3*|dx| + 4*|dy|. */
int32_t distance_manhattan3(int32_t x1, int32_t y1, int32_t x2, int32_t y2);

/* Color_Convert555To565 (0x539340), in-place RGB555 -> RGB565. */
void color_convert_555_to_565(uint16_t *colors, size_t count, bool enabled);

/* Color_RGBTo16 (0x5397E0); rgb565 selects the 5:6:5 path. */
uint32_t color_rgb_to_16(uint8_t red, uint8_t green, uint8_t blue,
                         bool rgb565);

/* Cost_ComputeQuantityPrice (0x4D40D0): (quantity/10)*unit_price*10. */
int32_t cost_compute_quantity_price(int32_t quantity, int32_t unit_price);

/* Company_GetPercentModifier (0x50F7F0); value -1 uses fallback. */
int32_t company_percent_modifier(int32_t value, int32_t fallback,
                                 int32_t mode);

/* Building_GetLevelFromType (0x4F9D50). */
int32_t building_level_from_type(int32_t type, uint8_t variant);

/* Building_GetAreaByLevel (0x48D020). */
double building_area_by_level(int32_t level);

/* Enum_MapDirection (0x4F1D90); input is masked with 7. */
uint32_t enum_map_direction(uint32_t raw);

/* Array_CountNonZero20 (0x514240): 20 triples, first int of each. */
size_t array_count_non_zero20(const int32_t values[20][3]);

/* Array_CountValid8 (0x4EDBD0): eight shorts, count != -1. */
size_t array_count_valid8(const int16_t values[8]);

/* Calendar_InterpolateMonthlyValue (0x4DC6A0). */
int32_t calendar_interpolate_monthly_value(int32_t day, unsigned month,
                                           const int32_t values[4]);

/* Building_GetSpriteVariant (0x4D2E80). */
int32_t building_get_sprite_variant(int32_t type);

/* Array_AreBothCountsPositive (0x512700). */
bool array_are_both_counts_positive(const int32_t *counts, uint8_t first,
                                    uint8_t second);

/* Array_IndexOfInt (0x5230D0). */
int32_t array_index_of_int(const int32_t *values, size_t count, int32_t key);

/* BinarySearch8 (0x531330): records are {payload,key} pairs. */
int32_t binary_search8(const int32_t records[][2], size_t count, int32_t key,
                       bool insert);

/* Array_FindPair (0x5140B0): 20 triples, first non-zero and second == key. */
int32_t array_find_pair(const int32_t pairs[20][3], int32_t key);

/* Array_GetPair8 (0x5312F0). */
bool array_get_pair8(const int32_t records[][2], size_t count, size_t index,
                     int32_t *first, int32_t *second);

/* Counter_IncrementShortBA (0x4F0E20). */
int16_t counter_increment_short(int16_t *counter);

/* Game_GetMaxIndex4 (0x4E47E0). */
uint8_t game_get_max_index4(const int8_t values[4]);

/* Game_CountActiveStats (0x50FE50): 0x56 ints, count > 0. */
size_t game_count_active_stats(const int32_t values[0x56]);

/* Clear_Ptr (0x403190). */
void clear_ptr(int32_t *pointer);

/* Array_GetField4Stride12 / Array_SetField4Stride12 (0x4F3B10 / 0x4ED310). */
int32_t array_get_field4_stride12(const uint8_t *base, size_t index);
void array_set_field4_stride12(uint8_t *base, size_t index, int32_t value);

/* Array_GetStride60 (0x4DA630). */
const uint8_t *array_get_stride60(const uint8_t *base, int32_t index);

/* Array_GetRecord28 (0x4F0CC0). */
const uint8_t *array_get_record28(const uint8_t *primary,
                                  const uint8_t *secondary,
                                  int32_t selector, int32_t index);

/* Building_IsSpecialType (0x509FC0). */
bool building_is_special_type(int32_t type);

/* Building_MapSubtypeToState (0x508FB0). */
int32_t building_map_subtype_to_state(int32_t subtype);

/* Game_GetPlayerCount (0x482720): six pointer slots at +0x200. */
size_t game_get_player_count(const void *const players[6]);

/* Game_GetPlayerField8 (0x482840): player field at +8. */
int32_t game_get_player_field8(const void *const players[6], size_t index);

/* Game_GetDateField0C (0x489B10). */
int32_t game_get_date_field0c(const uint8_t *date);

/* Game_GetDateFields (0x48B3C0). */
void game_get_date_fields(const uint8_t *date, uint32_t *day,
                          int32_t *month_times5);

/* Game_GetMapValue (0x4EAA10). */
uint32_t game_get_map_value(const uint8_t *map, uint32_t value);

/* Game_GetCostForType (0x4D4330). */
int32_t game_get_cost_for_type(int32_t field4, int32_t field8, int32_t type);

/* Array_ClearStride34 (0x47C590): clears eight bytes at 0x154E+i*0x34. */
void array_clear_stride34(uint8_t *base);

/* Array_Copy68 (0x47C3C0): copies 0x68 dwords from +0x151C. */
void array_copy68(const uint8_t *base, int32_t *destination);

/* Array_SearchSet (0x4F5FA0). */
void array_search_set(const int32_t ids[3], int32_t *counts, int32_t value);

/* Array_SetSlot (0x4F5F70). */
void array_set_slot(const int32_t ids[3], int32_t *counts, int32_t value,
                    int32_t slot_value);

/* Company_ComputeTotals (0x4E0010). */
void company_compute_totals(int32_t *company);

typedef struct EmployeeSkillMultipliers {
    int32_t field4;
    int32_t field8;
    int32_t field_c;
    int32_t field_10;
    int32_t value24;
    int32_t value28;
    int32_t value2c;
    int32_t value30;
    int32_t value34;
} EmployeeSkillMultipliers;

/* Employee_ApplySkillMultipliers (0x4D3EF0). */
void employee_apply_skill_multipliers(EmployeeSkillMultipliers *employee,
                                      int32_t value, int32_t random_c,
                                      int32_t random_4, int32_t random_8,
                                      int32_t random_10);

/* Game_GetPlanName (0x501580). */
const char *game_get_plan_name(int32_t plan);

/* Clear_Field228 (0x526D00). */
void clear_field228(uint8_t *object);

/* Entity_SetTileId (0x4D3070). */
void entity_set_tile_id(uint8_t *entity, int32_t tile_id);

/* Dialog_SetResult (0x526850). */
void dialog_set_result(uint8_t *dialog, int32_t result);

/* Game_GetGlobalTableValue (0x482710): 21-entry colour table. */
uint32_t game_get_global_table_value(size_t index);

/* Game_FindCityIndex (0x4E2250): seven-entry city-id table. */
int32_t game_find_city_index(int32_t city_id);

/* Game_GetDataByIndex (0x48D110): customer/staff labels. */
const char *game_get_data_by_index(int32_t index);

/* Array_FindEmptySlot8 (0x4E4180): first slot with id -1, or -1. */
int32_t array_find_empty_slot8(const int16_t slots[8][6]);

typedef struct EventQueueEntry {
    int32_t id;
    int32_t field4;
    int32_t state;
    int32_t field12;
    int32_t field16;
} EventQueueEntry;

typedef struct EventQueueState {
    uint32_t head;
    uint32_t tail;
    EventQueueEntry entries[1024];
} EventQueueState;

/* EventQueue_SetEntryState22 (0x525B70). */
void event_queue_set_entry_state22(EventQueueState *queue, int32_t id);

/* Employee_NextSpriteVariant (0x549930); returns '1' or '2'. */
char employee_next_sprite_variant(int32_t *variants, size_t index,
                                  int32_t minimum, int32_t maximum);

/* Building_ResetInventory (0x4FF9E0). */
void building_reset_inventory(uint8_t *building, uint8_t *inventory,
                              const int32_t *scenario_table);

/* Array_FindIndexStride60 (0x4DA690). */
int32_t array_find_index_stride60(const uint8_t *base,
                                   const uint8_t *target);

typedef struct EntityTypeProperties {
    int32_t id;
    int32_t field40;
    int32_t field44;
    int32_t field48;
} EntityTypeProperties;

typedef struct EntityProperties {
    int32_t type;
    int32_t field40;
    int32_t field44;
    int32_t field48;
} EntityProperties;

/* Entity_ApplyTypeProperties (0x4D2B40). */
void entity_apply_type_properties(EntityProperties *entity, int32_t type,
                                  const EntityTypeProperties *table,
                                  size_t count);

/* City_IsIdle (0x480880). */
bool city_is_idle(const uint8_t *city);

/* Array_GetPtr / Array_GetPtr4 / Array_GetPtrChecked. */
const void *array_get_ptr(const void *const *values, size_t count,
                          int32_t index);
const void *array_get_ptr4(const void *const *values, size_t count,
                           int32_t index);
const void *array_get_ptr_checked(const void *const *values, size_t count,
                                  int32_t index);

/* Font_GetCharWidth / Font_MeasureText / Font_MeasureRange
 * (0x535650 / 0x5355F0 / 0x5356C0). */
uint8_t font_get_char_width(const FntInfo *font, uint8_t character);
int32_t font_measure_text(const FntInfo *font, const char *text);
int32_t font_measure_range(const FntInfo *font, const char *text,
                           int32_t start, int32_t end);

/* GameClock_Reset (0x4DD4A0). */
void game_clock_reset(uint8_t *clock, uint16_t calendar_state);

/* Economy_ApplyTablePercent (0x4DD0F0). */
int32_t economy_apply_table_percent(const int32_t *table, int32_t row,
                                    int32_t index, int32_t value);

typedef struct EconomyModifierState {
    int32_t row;
    int32_t count_168;
    int32_t count_24c;
    int32_t count_164;
    int32_t count_248;
    int32_t count_a8;
    int32_t count_18c;
} EconomyModifierState;

/* Economy_GetModifier (0x4E25B0). */
int32_t economy_get_modifier(int32_t type, int32_t index,
                             const EconomyModifierState *state);

/* Economy_GetModifier message branch for type 0x1E. */
const char *economy_get_modifier_message(int32_t row, int32_t index);

typedef struct GamePlanState {
    int32_t fields[12];
} GamePlanState;

/* GamePlan_Construct (0x50F630). */
void game_plan_construct(GamePlanState *plan);

typedef struct ConstructionOrderState {
    int32_t fields[9];
} ConstructionOrderState;

/* ConstructionOrder_Construct (0x4E5D60). */
void leaf_construction_order_construct(ConstructionOrderState *order,
                                  int32_t field4, int32_t field8);

typedef struct FurnitureTypeState {
    int32_t vtable;
    int32_t fields[0x36];
} FurnitureTypeState;

/* FurnitureType_Construct (0x4E3FB0). */
void furniture_type_construct(FurnitureTypeState *type);

/* FurnitureType_Destroy (0x4E4050). */
void furniture_type_destroy(FurnitureTypeState *type);

/* Game_GetPlayerBySlot (0x488BE0). */
const void *game_get_player_by_slot(const void *const players[6],
                                    int32_t slot);

/* Game_GetCurrentPlayerCompanyName (0x482820). */
int32_t game_get_current_player_company_name(const void *const players[6],
                                             int32_t current_slot);

/* Game_GetPlayerCity (0x4DDCC0). */
const void *game_get_player_city(const void *const players[6], int32_t index);

/* Game_FindPlayerSlot (0x488BC0). */
int32_t game_find_player_slot(const void *const players[6],
                              const void *player);

/* Game_FindGroupSlot (0x4E42C0). */
int32_t game_find_group_slot(const int16_t slots[6], int16_t value);

/* Game_CountGroupSlots (0x4E41A0). */
size_t game_count_group_slots(const int16_t slots[6]);

/* Game_GetCityData (0x4E4140). */
const void *game_get_city_data(const void *const *table, size_t count,
                               int32_t index);

/* Object_GetPair10 / Object_GetPair4 (0x535150 / 0x535160). */
void object_get_pair10(const uint8_t *object, int32_t *field10,
                       int32_t *field14);
void object_get_pair4(const uint8_t *object, int32_t *field4,
                      int32_t *field8);

/* Record_GetValue48 / Record_SetIndex48 (0x534960 / 0x534990). */
int32_t record_get_value48(const uint8_t *records, size_t count,
                           size_t index);
bool record_set_index48(uint8_t *records, size_t count, size_t index,
                        int32_t value, size_t value_limit);

/* Record_GetRect98 (0x534AC0): four uint32 pairs at +0x70/+0x78/+0x60/+0x68. */
bool record_get_rect98(const uint8_t *records, size_t index,
                       int32_t pairs[8]);

/* Record_GetBounds48 (0x534060). */
bool record_get_bounds48(const uint8_t *records, size_t index,
                         const int16_t *x_points, const int16_t *y_points,
                         const uint16_t *widths, const uint16_t *heights,
                         int32_t *x, int32_t *y, uint32_t *width,
                         uint32_t *height);

/* Record_GetPairPositions (0x534830). */
bool record_get_pair_positions(const uint8_t *records, size_t index,
                               int32_t pairs[4]);

/* Record_SetDoubles48 / Record_SetRect48 (0x5342E0 / 0x534320). */
bool record_set_doubles48(uint8_t *records, size_t count, size_t index,
                          double first, double second);
bool record_set_rect48(uint8_t *records, size_t count, size_t index,
                       int32_t first, int32_t second, uint64_t value);

/* Record_GetScreenRect48 / Record_GetScreenOffset
 * (0x5340D0 / 0x534790). */
bool record_get_screen_rect48(const uint8_t *records, size_t index,
                              const uint16_t *widths,
                              const uint16_t *heights, int32_t *x,
                              int32_t *y);
bool record_get_screen_offset(const uint8_t *records, size_t count,
                              size_t index, const int16_t *x_points,
                              const uint16_t *widths,
                              const uint16_t *heights, int32_t *x,
                              int32_t *y);

/* Object accessors. */
int32_t object_get_id(const uint8_t *object);
int32_t object_get_field0c(const uint8_t *object);
int32_t object_get_field10(const uint8_t *object);
void object_set_field0c(uint8_t *object, int32_t value);
void object_set_field8(uint8_t *object, int32_t value);
void object_set_field_fc(uint8_t *object, int32_t value);
void object_set_short28(uint8_t *object, int16_t value);
void object_get_pair68(const uint8_t *object, int32_t *first, int32_t *second);
void object_get_rect100(const uint8_t *object, int32_t rect[4]);
void object_set_flag104(uint8_t *object, uint8_t value);

/* Sprite accessors. */
uint32_t sprite_get_color_key(const uint8_t *sprite);
uint8_t sprite_get_format(const uint8_t *sprite);
void sprite_get_size(const uint8_t *sprite, int32_t *width, int32_t *height);
void sprite_get_hotspot(const uint8_t *sprite, int32_t *x, int32_t *y);
void sprite_set_hotspot(uint8_t *sprite, int16_t x, int16_t y);
void sprite_set_color_key(uint8_t *sprite, uint32_t color_key);

/* Game setting/date accessors. */
int32_t game_get_speed_setting(const uint8_t *game);
uint32_t game_get_starting_capital(int32_t difficulty);
uint32_t game_get_time_segment(const uint8_t *date);
void game_get_year_and_weekday(const uint8_t *date, uint32_t *year,
                               uint32_t *weekday);

/* State/ID predicates. */
bool state_is_1a_1b_1c(const uint8_t *object);
bool state_is_2d_or_2e(const uint8_t *object);
bool state_is_menu_state(const uint8_t *object);
bool is_special_id_range(int32_t id);
bool object_is_id_in_840_range(int32_t id);
bool object_is_known_id(int32_t id);
bool is_menu_id_352(int32_t id);
bool is_menu_id_351_or_355(int32_t id);
bool is_menu_id_34e_or_350(int32_t id);
bool is_menu_id_range(int32_t id);

/* Small product/stat/capacity accessors. */
bool product_has_stock(const int32_t *counts, uint8_t index);
double stats_get_amount_by_type(int32_t type);
int32_t storage_get_capacity(int32_t value);
int32_t supplier_get_value_plus_one(const int32_t *table, int32_t index);
int32_t rating_get_inverse100(int32_t value);
uint8_t object_get_byte36_max7(const uint8_t *object);
int32_t index_map8to5(const int32_t values[8], int32_t index);
uint8_t stats_get_level_from_four_counters(int32_t sum);
uint8_t stats_get_level_from_ten_counters(uint32_t sum);

/* Table/grid mappers and searches. */
int32_t stats_get_matrix_variant_value(const uint8_t *object,
                                        int32_t variant, int32_t row,
                                        int32_t column);
int32_t stats_get_or_sum_series(const uint8_t *object, int32_t series,
                                int32_t index);
int32_t map_get_2d_table_value(const uint8_t *object, int32_t table,
                               int32_t row, int32_t column);
const uint8_t *grid_get_cell(const uint8_t *grid, int32_t x, int32_t y);
float grid_get_max_value(const float *values);
int32_t global_array_find_index(const int32_t *values, int32_t count,
                                int32_t key);
int32_t global_array_find_int(const int32_t *values, int32_t count,
                              int32_t key);
int32_t save_list_find_index(const int32_t *values, int32_t count,
                             int32_t key);
int32_t market_get_price_modifier(const int32_t *values, int32_t row,
                                  int32_t column);

/* Map/object helpers. */
void map_compute_iso_offsets(uint8_t *map);
int32_t map_compute_object_distance(const uint8_t *map, int32_t x1, int32_t y1,
                                    int32_t x2, int32_t y2, int32_t index);
int32_t object_get_root_type(const uint8_t *object);
int32_t object_get_child_field14(const uint8_t *object);
int32_t object_get_child_field2c(const uint8_t *object);
int32_t object_get_clamped_level(uint8_t *object);
uint32_t object_get_active_value(const uint8_t *object);
void object_set_child_field2c(uint8_t *object, int32_t value);
void object_set_child_short(uint8_t *object);
void object_set_child_short8(uint8_t *object, int16_t value);
void object_reset108(uint8_t *object);
void object_clear_field28(uint8_t *object);
void object_clear_field4(uint8_t *object);
void object_clear_field54(uint8_t *object);
void object_clear_fields_a(uint8_t *object);
void object_clear_state(uint8_t *object);

/* Map/player/market/rating helpers. */
bool map_clamp_scroll_y(uint8_t *map, int32_t requested, int32_t scroll_mode);
uint32_t market_get_price_delta(uint8_t class_byte, int32_t table_value);
double rating_get_float(float rating, int32_t type, int32_t difficulty);
int32_t game_get_player_quarter_stat(const uint8_t *object, int32_t index,
                                     int32_t type);
uint8_t game_get_player_staff_band(int32_t sum);
uint8_t game_get_player_wealth_band(double value);
uint8_t game_get_player_satisfaction_band(int32_t average);
double game_get_player_weighted_stat(const int32_t stats[0x56],
                                     const double weights[0x56]);
int32_t game_get_record_child14(const uint8_t *records, int32_t index);
void player_reset_ai_state(uint8_t *player);
void player_reset_debt_hours(uint8_t *player);
void player_set_slot_flag18(uint8_t *player, size_t index);

/* Tile/product/name lookup helpers. */
bool tile_def_test_flag(const uint8_t *tile_defs, size_t index, uint32_t mask);
bool product_map_category(uint8_t category, uint8_t group);
int32_t map_find_name_index(const uint8_t *records, int32_t count,
                            const char *name);
int32_t string_list_find(const uint8_t *records, int32_t count,
                         const char *key, int32_t *index);

/* Remaining simple object/record/rect/sprite/surface helpers. */
bool object_is_state10(const uint8_t *object);
void object_set_frame5(uint8_t *object, int32_t frame);
void object_set_index171c(uint8_t *object, int32_t value);
void object_set_field280(uint8_t *object, int32_t value);
void record_clear48(uint8_t *records, size_t count, int32_t index);
void record_clear_active48(uint8_t *records, size_t count, int32_t index);
void record_clear_flags48(uint8_t *records, size_t count, int32_t index);
void record_set_field2d0c(uint8_t *tile_defs, size_t index, uint8_t value);
bool record_set_slot6_98(uint8_t *records, size_t count, size_t index,
                         size_t slot, uint32_t value, uint16_t extra);
void set_field168(uint8_t *object, int32_t value);
void set_field228(uint8_t *object, int32_t value);
void set_field9b8(uint8_t *object, int32_t value);
void rect_set1a4(uint8_t *rect, const int32_t values[4]);
const void *sprite_get_palette(const uint8_t *sprite);
void sprite_get_render_size(const uint8_t *sprite, uint32_t *width,
                            uint32_t *height);
void surface_get_cursor_rect(const uint8_t *surface, int32_t rect[4]);
void surface_reset(uint8_t *surface);
void surface_set_bounds(uint8_t *surface, int32_t left, int32_t top,
                        int32_t right, int32_t bottom);
void surface_set_pixel(uint8_t *surface, int32_t x, int32_t y,
                       uint16_t value);

/* Surface/sprite/object/stream helpers. */
void surface_clear(uint8_t *surface);
void surface_clear_rows(uint8_t *surface);
void sprite_init_format(uint8_t *sprite, int16_t width, uint16_t height,
                        uint32_t color_key, int32_t bpp, uint8_t flags,
                        uint16_t hotspot_x, uint16_t hotspot_y);
void object_get_child_origin(const uint8_t *object, int32_t *x, int32_t *y);
int32_t object_count_matching_slots(const uint8_t *object, int32_t value);
void object_clear_slot_refs(uint8_t *object, uint8_t *slot);
bool stream_buffer_reset(uint8_t *buffer);
int32_t stream_get_available(const uint8_t *stream);

/* Simple field/subobject getters and record/stream status helpers. */
int32_t get_field19f4(const uint8_t *object);
int32_t get_field24(const uint8_t *object);
int32_t get_field2c(const uint8_t *object);
int32_t get_field_f0(const uint8_t *object);
const uint8_t *get_subobject4(const uint8_t *object);
void get_width_height(const uint8_t *object, uint32_t *width,
                      uint32_t *height);
int32_t record_list_get_count(const uint8_t *list);
uint8_t record_get_flag3e48(const uint8_t *object);
bool surface_is_ready(int32_t query_result);
int32_t stream_get_status(int32_t flags, int32_t field10,
                          int32_t status_result);

typedef struct StreamCharState {
    int32_t flags;
    int32_t peek;
    uintptr_t current;
    uintptr_t end;
} StreamCharState;

/* Stream_GetChar (0x54D372): callback-backed stream read. */
int32_t stream_get_char(StreamCharState *state,
                        int32_t (*read)(void *context), void *context);

typedef struct StreamBufferState {
    uint8_t *buffer;
    uint32_t flags;
    int32_t release_enabled;
} StreamBufferState;

/* Stream_SetBuffer (0x54D921). */
void stream_set_buffer(StreamBufferState *state, uint8_t *buffer,
                       void (*release)(void *context), void *context);

typedef struct ObjectInitState {
    int32_t initialized;
    void (*initialize)(void *context, int32_t size, int32_t arg2,
                       int32_t arg3);
    void *context;
} ObjectInitState;

/* Object_EnsureInit (0x520CD0). */
void object_ensure_init(ObjectInitState *state);

/* Game setting/counter setters. */
void game_set_difficulty(uint8_t *object, int32_t difficulty);
void game_set_hq_level(uint8_t *object, int32_t level);
void game_set_global_word16(uint8_t *object, uint16_t value,
                            uint32_t *calendar_state);
void game_increment_visit_counter(uint8_t *object, int32_t index);

typedef struct SpriteClearCallbacks {
    void (*set_params)(void *sprite, const uint32_t params[27]);
    void (*clear_buffers)(void *sprite, const uint32_t params[25]);
} SpriteClearCallbacks;

/* Sprite_ClearBuffers (0x53A060), callback-backed virtual calls. */
void sprite_clear_buffers(void *sprite,
                          const SpriteClearCallbacks *callbacks);

/* Player_InitSlotFlags (0x4E3DD0). */
void player_init_slot_flags(uint8_t *player, size_t index);

/* PlayerCompany_InitDefaults (0x50F590), 21 default values. */
void player_company_init_defaults(uint8_t *company,
                                  const int32_t defaults[21]);

typedef struct BuildingDescData {
    const char *name;
    uint8_t byte_a8;
    int32_t value_ac;
    int32_t value_b0;
    int32_t value_b4;
    int32_t value_b8;
    int32_t value_c0;
    int32_t value_c4;
    uint8_t byte_cc;
    uint8_t byte_cd;
    uint8_t byte_c8;
    uint8_t byte_c9;
    uint8_t byte_ca;
    uint8_t byte_cb;
} BuildingDescData;

/* Game_SetBuildingDesc (0x4E4860). */
void leaf_game_set_building_desc(uint8_t *object, const BuildingDescData *data);

typedef struct GameDateTimeState {
    int32_t year;
    int32_t day_of_year;
    int32_t milliseconds;
    int32_t current_year;
    int32_t current_day_of_year;
    int32_t current_milliseconds;
} GameDateTimeState;

/* Game_SetDateTime (0x552921). */
void game_set_datetime(GameDateTimeState *state, int32_t mode,
                       int32_t selector, int32_t year, int32_t month,
                       int32_t week, int32_t weekday, int32_t day_offset,
                       int32_t hour, int32_t minute, int32_t second,
                       int32_t millisecond, int32_t timezone_offset);

/* Remaining small lookup/initializer helpers. */
int32_t personnel_get_training_level(const int32_t *table, int32_t index);
int32_t sparse_map_lookup48(const uint8_t *object, int32_t index);
int32_t map_find_index(const int32_t *values, int32_t count, int32_t key);
int32_t map_lookup_linear(const int32_t *keys, const int32_t *values,
                          int32_t count, int32_t key);
void options_get_global_settings(const int32_t source[4],
                                 int32_t destination[4]);
void file_object_init_base(uint8_t *object, const void *vtable);
int32_t map_count_buildable_neighbors(const uint8_t *base, int32_t first,
                                      int32_t second, int32_t offset);

/* Small reference/list/window helpers. */
void game_set_child_field94(uint8_t *object, int32_t value);
bool game_clear_object_references(int32_t *slot, int32_t value);
const char *city_get_localized_name(const char *const *names, size_t count,
                                    int32_t index);
int32_t list_find_by_key(const int32_t *nodes, int32_t head, int32_t key);
void window_clear_state(uint8_t *window);

/* Map hover tile update, mission setting copy and animation point pairs. */
void map_set_hover_tile(uint8_t *hover, const int32_t input[2],
                        const int32_t values[15], int32_t base);

typedef struct MissionSettings {
    int32_t rating_float_state;
    int32_t scenario_state;
    int32_t objectives_flag;
    int32_t freeplay_state_35c;
    int32_t freeplay_flag;
    int32_t company_actions_flag_360;
    int32_t company_actions_flag;
    int32_t freeplay_state_350;
    int32_t freeplay_state_354;
    int32_t freeplay_state_358;
} MissionSettings;

/* Mission_ApplySettings (0x4DC080). */
void mission_apply_settings(const uint8_t *source, MissionSettings *settings);

/* Animation_SetPointPairs (0x534B30). */
void animation_set_point_pairs(uint8_t *frames, size_t index,
                               const int32_t pair1[2], const int32_t pair2[2],
                               const int32_t pair4[2],
                               const int32_t pair5[2]);

/* Window/UI geometry and setter helpers. */
void window_get_rect(const uint8_t *window, int32_t rect[4]);
void ui_set_position(uint8_t *window, int32_t x, int32_t y);
void ui_set_absolute_position(uint8_t *window, int32_t x, int32_t y);
void ui_set_child_position(uint8_t *window, int32_t x, int32_t y);
void ui_get_outer_rect(const uint8_t *window, int32_t rect[4]);
void ui_get_view_rect(const uint8_t *window, int32_t rect[4]);
void ui_set_window_offsets(uint8_t *window);
void ui_set_layout_params(uint8_t *window, int32_t first, int32_t second);
void ui_set_event_callback(uint8_t *window, int32_t callback);
void ui_set_window_proc(uint8_t *window, int32_t callback);

/* Remaining simple UI state helpers. */
const uint8_t *ui_get_theme(const uint8_t *window);
void ui_set_menu_toggle(uint8_t *window, int32_t value);
void ui_clear_field230(uint8_t *window, int32_t value);
void ui_clear_scroll_drag(uint8_t *window);
uint8_t ui_get_first_enabled_index(const uint8_t *font);

typedef struct UIValidSizeState {
    int32_t flag18;
    int32_t flag20;
    int32_t flag14;
    int32_t min_x;
    int32_t min_y;
    int32_t limit_x;
    int32_t limit_y;
    int32_t offset_x;
    int32_t offset_y;
} UIValidSizeState;

/* UI_IsValidSize (0x520B60). */
bool ui_is_valid_size(const UIValidSizeState *state, int32_t x, int32_t y,
                      bool (*test)(void *context, int32_t x, int32_t y),
                      void *context);

typedef struct UIPendingCommandState {
    int32_t pending;
    void (*notify)(void *context, int32_t command, int32_t arg2,
                   int32_t arg3);
    void *context;
} UIPendingCommandState;

/* UI_ClearPendingCommand (0x520CF0). */
void ui_clear_pending_command(UIPendingCommandState *state);

/* Window_GetChildAndNotify (0x54A5D0). */
const void *window_get_child_and_notify(
    const uint8_t *window, void (*notify)(void *child, const void *parent));

/* UI_FindWindowByID (0x528040). */
const void *ui_find_window_by_id(const void *const *windows, int32_t count,
                                 int32_t id, int32_t *index);

typedef struct UIActiveChildState {
    void *child;
    void (*notify)(void *context, int32_t command, int32_t arg2,
                   int32_t arg3);
} UIActiveChildState;

/* UI_SetActiveChild (0x528200). */
void ui_set_active_child(UIActiveChildState *state, void *child);

typedef struct UIModalState {
    int32_t modal_value;
    void *handler;
    int32_t field_8340;
    int32_t field_8348;
    void (*notify)(void *handler, int32_t command, int32_t arg2,
                   int32_t arg3);
} UIModalState;

/* UI_SetModalHandler (0x527CC0). */
void ui_set_modal_handler(UIModalState *state, int32_t value, void *handler);

typedef struct UITransientState {
    uint32_t head;
    uint32_t tail;
    int32_t entries[1024][3];
} UITransientState;

/* UI_ClearTransientEntries (0x528090). */
void ui_clear_transient_entries(UITransientState *state, bool clear_first,
                                bool clear_second);

/* UI_HitTestChild (0x520BC0). */
bool ui_hit_test_child(const UIValidSizeState *state, int32_t x, int32_t y,
                       bool (*test)(void *context, int32_t x, int32_t y),
                       void *context);

typedef struct UIVisibleState {
    int32_t visible;
    void (*mouse_move)(void *context);
    void (*queue_command)(void *context, int32_t control, int32_t command,
                          int32_t arg);
} UIVisibleState;

/* UI_SetWindowVisible (0x532890). */
bool ui_set_window_visible(UIVisibleState *state, int32_t visible);

/* Game_GetActiveScreenOrFallback (0x482910). */
int32_t game_get_active_screen_or_fallback(const uint8_t *game);

/* Palette_Convert256 (0x535E50). */
void palette_convert256(const uint8_t *rgb, uint16_t *output, bool rgb565);

/* Palette_FindIndex (0x535CB0): compares 768-byte palettes. */
int32_t palette_find_index(const uint8_t *const *palettes, size_t count,
                           const uint8_t *candidate);

/* Record_GetTypeIndex48 (0x534A80). */
int32_t record_get_type_index48(const uint8_t *records, size_t count,
                                size_t index, const uint8_t *sources);

/* Destructor vtables modelled as a cleared vtable marker. */
void game_plan_destructor(GamePlanState *plan);
void leaf_construction_order_destructor(ConstructionOrderState *order);
void award_node_destructor(void *node);
void building_value_destroy(void *value);

/* Math_RoundFloat / Math_TruncateDouble / Math_PiecewiseLinear
 * (0x403850 / 0x511FA0 / 0x50FBE0). */
int64_t math_round_float(float value);
int64_t math_truncate_double(double value);
int32_t math_piecewise_linear(int32_t value);

/* String_SkipDelimiters (0x4DB2E0). */
void string_skip_delimiters(const char *buffer, size_t *index);

/* Text_SkipFieldSeparators (0x52CB70). */
void text_skip_field_separators(const char *buffer, size_t *index);

/* Text_GetLineHeight / Text_GetPosition / Text_SetCursor
 * (0x535510 / 0x5355B0 / 0x5355D0). */
int32_t text_get_line_height(const uint8_t *text);
void text_get_position(const uint8_t *text, int32_t *x, int32_t *y);
void text_set_cursor(uint8_t *text, int32_t x, int32_t y);

/* Text_SetMetrics / Text_SetMetrics2 (0x535520 / 0x535570). */
void text_set_metrics(uint8_t *text, int32_t x, int32_t y, int32_t param3);
void text_set_metrics2(uint8_t *text, int32_t x, int32_t y, int32_t param3);

#endif
