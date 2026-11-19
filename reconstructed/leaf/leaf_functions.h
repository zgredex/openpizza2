#ifndef PC2_RECONSTRUCTED_LEAF_FUNCTIONS_H
#define PC2_RECONSTRUCTED_LEAF_FUNCTIONS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

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

#endif
