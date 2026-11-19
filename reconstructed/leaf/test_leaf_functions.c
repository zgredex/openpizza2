#include "leaf_functions.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void test_clamp(void) {
    int32_t value = 120;
    clamp_0_100(&value);
    assert(value == 100);
    value = -5;
    clamp_0_100(&value);
    assert(value == 0);
    value = 42;
    clamp_0_100(&value);
    assert(value == 42);
    clamp_0_100(NULL);
}

static void test_manhattan3(void) {
    assert(distance_manhattan3(1, 2, 4, 6) == 3 * 3 + 4 * 4);
    assert(distance_manhattan3(4, 6, 1, 2) == 25);
    assert(distance_manhattan3(-2, -3, 2, 3) == 36);
    assert(distance_manhattan3(0, 0, 0, 0) == 0);
}

static void test_colors(void) {
    uint16_t colors[3] = {0x7fffu, 0x001fu, 0x7c00u};
    color_convert_555_to_565(colors, 3, true);
    assert(colors[0] == 0xffdfu);
    assert(colors[1] == 0x001fu);
    assert(colors[2] == 0xf800u);
    color_convert_555_to_565(colors, 3, false);
    assert(colors[0] == 0xffdfu);

    assert(color_rgb_to_16(255, 255, 255, true) == 0xffdfu);
    assert(color_rgb_to_16(255, 0, 0, true) == 0xf800u);
    assert(color_rgb_to_16(0, 255, 0, true) == 0x07c0u);
    assert(color_rgb_to_16(0, 0, 255, true) == 0x001fu);
    assert(color_rgb_to_16(255, 255, 255, false) == 0x7fffu);
    assert(color_rgb_to_16(255, 0, 0, false) == 0x7c00u);
    assert(color_rgb_to_16(0, 255, 0, false) == 0x03e0u);
    assert(color_rgb_to_16(0, 0, 255, false) == 0x001fu);
}

static void test_quantity_price(void) {
    assert(cost_compute_quantity_price(25, 100) == 2000);
    assert(cost_compute_quantity_price(9, 100) == 0);
    assert(cost_compute_quantity_price(10, 37) == 370);
    assert(cost_compute_quantity_price(100, 0) == 0);
}

static void test_company_modifier(void) {
    assert(company_percent_modifier(5000, 0, 1) == 50);
    assert(company_percent_modifier(5000, 0, 2) == 100);
    assert(company_percent_modifier(5000, 0, 0) == 100);
    assert(company_percent_modifier(-1, 7500, 1) == 75);
    assert(company_percent_modifier(-1, 7500, 2) == 150);
    assert(company_percent_modifier(1, 0, 1) == 0);
}

static void test_building(void) {
    assert(building_level_from_type(0, 0) == 1);
    assert(building_level_from_type(0, 1) == 1);
    assert(building_level_from_type(0, 2) == 2);
    assert(building_level_from_type(0, 3) == -1);
    assert(building_level_from_type(1, 0) == 1);
    assert(building_level_from_type(1, 1) == 2);
    assert(building_level_from_type(1, 2) == 3);
    assert(building_level_from_type(2, 0) == 2);
    assert(building_level_from_type(2, 2) == 4);
    assert(building_level_from_type(3, 0) == 3);
    assert(building_level_from_type(3, 2) == 5);
    assert(building_level_from_type(4, 0) == -1);
    assert(building_area_by_level(0) == 2070.0);
    assert(building_area_by_level(1) == 2916.0);
    assert(building_area_by_level(2) == 3420.0);
    assert(building_area_by_level(3) == 3960.0);
    assert(building_area_by_level(4) == 0.0);
}

static void test_direction(void) {
    const uint32_t expected[8] = {0, 4, 1, 5, 2, 6, 3, 7};
    for (uint32_t raw = 0; raw < 8; raw++) {
        assert(enum_map_direction(raw) == expected[raw]);
    }
    assert(enum_map_direction(0xfffffff9u) == 4);
}

static void test_arrays(void) {
    int32_t values[20][3] = {{0}};
    assert(array_count_non_zero20(values) == 0);
    values[0][0] = 5;
    values[7][0] = -1;
    values[19][0] = 3;
    values[3][1] = 9;
    assert(array_count_non_zero20(values) == 3);
    const int16_t valid[8] = {-1, 0, 1, -1, 2, -1, -1, 7};
    assert(array_count_valid8(valid) == 4);
    assert(array_count_valid8(NULL) == 0);
    assert(array_count_non_zero20(NULL) == 0);
}

static void test_calendar(void) {
    const int32_t values[4] = {100, 200, 300, 400};
    const int32_t expected_month0[10] = {394, 322, 250, 178, 130,
                                         106, 103, 100, 97, 95};
    const int32_t days[10] = {0, 3, 6, 9, 11, 12, 15, 18, 21, 23};
    for (int index = 0; index < 10; index++) {
        assert(calendar_interpolate_monthly_value(days[index], 0, values) ==
               expected_month0[index]);
    }
    assert(calendar_interpolate_monthly_value(0, 1, values) == 94);
    assert(calendar_interpolate_monthly_value(6, 1, values) == 150);
    assert(calendar_interpolate_monthly_value(12, 1, values) == 206);
    assert(calendar_interpolate_monthly_value(18, 1, values) == 200);
    assert(calendar_interpolate_monthly_value(6, 2, values) == 250);
}

static void test_sprite_variant(void) {
    assert(building_get_sprite_variant(0x81c) == 0);
    assert(building_get_sprite_variant(0x820) == 1);
    assert(building_get_sprite_variant(0x824) == 2);
    assert(building_get_sprite_variant(0x828) == 3);
    assert(building_get_sprite_variant(0x833) == 3);
    assert(building_get_sprite_variant(0x834) == 0);
    assert(building_get_sprite_variant(0x863) == 2);
    assert(building_get_sprite_variant(0x864) == -1);
    assert(building_get_sprite_variant(0x800) == -1);
}

static void test_array_helpers(void) {
    int32_t counts[256] = {0};
    counts[3] = 1;
    counts[7] = -1;
    assert(array_are_both_counts_positive(counts, 3, 3));
    assert(!array_are_both_counts_positive(counts, 3, 7));
    assert(!array_are_both_counts_positive(counts, 1, 2));

    const int32_t values[4] = {10, 20, 30, 20};
    assert(array_index_of_int(values, 4, 30) == 2);
    assert(array_index_of_int(values, 4, 20) == 1);
    assert(array_index_of_int(values, 4, 99) == -1);
    assert(array_index_of_int(NULL, 4, 30) == -1);

    const int32_t records[4][2] = {{7, 10}, {8, 20}, {9, 30}, {10, 40}};
    assert(binary_search8(records, 4, 30, false) == 2);
    assert(binary_search8(records, 4, 10, false) == 0);
    assert(binary_search8(records, 4, 40, false) == 3);
    assert(binary_search8(records, 4, 25, false) == -1);
    assert(binary_search8(records, 4, 25, true) == 2);
    assert(binary_search8(records, 4, 5, true) == 0);
    assert(binary_search8(records, 4, 50, true) == 4);
    assert(binary_search8(records, 0, 5, false) == -1);
    assert(binary_search8(records, 0, 5, true) == 0);

    int32_t first = 0;
    int32_t second = 0;
    assert(array_get_pair8(records, 4, 2, &first, &second));
    assert(first == 9 && second == 30);
    assert(!array_get_pair8(records, 4, 4, &first, &second));

    int32_t pairs[20][3] = {{0}};
    pairs[4][0] = 1;
    pairs[4][1] = 77;
    pairs[9][0] = 2;
    pairs[9][1] = 77;
    assert(array_find_pair(pairs, 77) == 4);
    assert(array_find_pair(pairs, 12) == -1);
}

static void test_counters(void) {
    int16_t counter = 41;
    assert(counter_increment_short(&counter) == 42);
    assert(counter == 42);
    assert(counter_increment_short(NULL) == 0);

    const int8_t values[4] = {-5, 20, 20, -1};
    assert(game_get_max_index4(values) == 2);
    const int8_t first[4] = {9, 1, 2, 3};
    assert(game_get_max_index4(first) == 0);

    int32_t stats[0x56] = {0};
    stats[0] = 1;
    stats[0x55] = 5;
    stats[4] = -2;
    assert(game_count_active_stats(stats) == 2);

    int32_t pointer = 99;
    clear_ptr(&pointer);
    assert(pointer == 0);
    clear_ptr(NULL);
}

static void write_i32_at(uint8_t *base, size_t offset, int32_t value) {
    memcpy(base + offset, &value, sizeof(value));
}

static void test_array_stride_helpers(void) {
    uint8_t records[4 * 12 + 4] = {0};
    array_set_field4_stride12(records, 2, 0x12345678);
    assert(array_get_field4_stride12(records, 2) == 0x12345678);
    assert(array_get_field4_stride12(records, 0) == 0);
    assert(array_get_field4_stride12(records, 3) == 0);
    assert(array_get_field4_stride12(NULL, 2) == 0);

    uint8_t buffer[0xdc8 + 3 * 0x60] = {0};
    assert(array_get_stride60(buffer, 0) == buffer + 0xdc8);
    assert(array_get_stride60(buffer, 2) == buffer + 0xdc8 + 2 * 0x60);
    assert(array_get_stride60(buffer, -1) == NULL);
    assert(array_get_stride60(NULL, 0) == NULL);

    uint8_t primary[3 * 0x28] = {0};
    uint8_t secondary[3 * 0x28] = {0};
    assert(array_get_record28(primary, secondary, 1, 2) == primary + 2 * 0x28);
    assert(array_get_record28(primary, secondary, 0, 1) == secondary + 0x28);
    assert(array_get_record28(primary, secondary, 1, -1) == NULL);
}

static void test_building_leafs(void) {
    assert(building_is_special_type(4));
    assert(building_is_special_type(5));
    assert(building_is_special_type(0xb));
    assert(building_is_special_type(0x21));
    assert(building_is_special_type(0xf));
    assert(!building_is_special_type(0));
    assert(!building_is_special_type(6));

    assert(building_map_subtype_to_state(0) == 6);
    assert(building_map_subtype_to_state(1) == 0);
    assert(building_map_subtype_to_state(2) == 2);
    assert(building_map_subtype_to_state(3) == 4);
    assert(building_map_subtype_to_state(4) == -1);
}

static void test_game_leafs(void) {
    const void *players[6] = {NULL};
    uint8_t player0[16] = {0};
    uint8_t player2[16] = {0};
    uint8_t player5[16] = {0};
    players[0] = player0;
    players[2] = player2;
    players[5] = player5;
    assert(game_get_player_count(players) == 3);
    assert(game_get_player_count(NULL) == 0);

    write_i32_at(player2, 8, 77);
    assert(game_get_player_field8(players, 0) == 0);
    assert(game_get_player_field8(players, 2) == 77);
    assert(game_get_player_field8(players, 1) == -1);
    assert(game_get_player_field8(NULL, 1) == -1);

    uint8_t date[32] = {0};
    date[6] = 3;
    date[7] = 19;
    write_i32_at(date, 0x0c, 0x1234);
    assert(game_get_date_field0c(date) == 0x1234);
    uint32_t day = 0;
    int32_t month_times5 = 0;
    game_get_date_fields(date, &day, &month_times5);
    assert(day == 19);
    assert(month_times5 == 15);
    assert(game_get_date_field0c(NULL) == 0);

    uint8_t *map = calloc(0x2e4f4 + 8, 1);
    assert(map != NULL);
    uint16_t tile = 0xbeef;
    memcpy(map + 0x2e4f4 + 4, &tile, sizeof(tile));
    assert(game_get_map_value(map, 2) == 0xbeef);
    assert(game_get_map_value(map, 0xffffffffu) == 0xffffffffu);
    assert(game_get_map_value(map, 0xfffffffeu) == 0xfffffffeu);
    assert(game_get_map_value(map, 0x80000000u) == 0xffffffffu);
    free(map);

    assert(game_get_cost_for_type(30, 40, 0) == 90);
    assert(game_get_cost_for_type(30, 40, 1) == 50);
    assert(game_get_cost_for_type(30, 40, 2) == 500);
    assert(game_get_cost_for_type(30, 40, 3) == 160);
    assert(game_get_cost_for_type(30, 40, 4) == 0);
}

int main(void) {
    test_clamp();
    test_manhattan3();
    test_colors();
    test_quantity_price();
    test_company_modifier();
    test_building();
    test_direction();
    test_arrays();
    test_calendar();
    test_sprite_variant();
    test_array_helpers();
    test_counters();
    test_array_stride_helpers();
    test_building_leafs();
    test_game_leafs();
    puts("leaf function reconstruction: OK");
    return 0;
}
