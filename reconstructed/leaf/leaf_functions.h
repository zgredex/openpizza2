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

#endif
