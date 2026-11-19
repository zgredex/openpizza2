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

static void test_more_leafs(void) {
    uint8_t clear_buffer[0x154e + 8 * 0x34] = {0};
    memset(clear_buffer, 0xff, sizeof(clear_buffer));
    array_clear_stride34(clear_buffer);
    for (size_t index = 0; index < 8; index++) {
        size_t offset = 0x154e + index * 0x34u;
        for (size_t byte = 0; byte < 8; byte++) {
            assert(clear_buffer[offset + byte] == 0);
        }
        assert(clear_buffer[offset + 8] == 0xff);
    }
    array_clear_stride34(NULL);

    uint8_t copy_source[0x151c + 0x68 * 4] = {0};
    int32_t copy_destination[0x68] = {0};
    for (size_t index = 0; index < 0x68 * 4; index++) {
        copy_source[0x151c + index] = (uint8_t)(index + 1);
    }
    array_copy68(copy_source, copy_destination);
    assert(copy_destination[0] == (int32_t)0x04030201);
    assert(copy_destination[0x67] == (int32_t)0xA09F9E9D);

    int32_t ids[3] = {5, 7, 5};
    int32_t counts[8] = {0};
    array_search_set(ids, counts, 5);
    assert(counts[5] == 2);
    array_search_set(ids, counts, 7);
    assert(counts[7] == 1);
    array_search_set(ids, counts, 1);
    assert(counts[1] == 0);
    array_set_slot(ids, counts, 5, 99);
    assert(counts[5] == 99);
    array_set_slot(ids, counts, 2, 4);
    assert(counts[2] == 0);

    int32_t company[0x200 / 4] = {0};
    for (int index = 0; index < 4; index++) {
        company[(0x120 + index * 4) / 4] = index + 1;
        company[(0x140 + index * 4) / 4] = index + 2;
        company[(0x160 + index * 4) / 4] = index + 3;
        company[(0x180 + index * 4) / 4] = index + 4;
        company[(0x150 + index * 4) / 4] = index + 5;
        company[(0x130 + index * 4) / 4] = index + 6;
        company[(0x170 + index * 4) / 4] = index + 7;
        company[(0x190 + index * 4) / 4] = index + 8;
    }
    company_compute_totals(company);
    assert(company[0xfc / 4] == 10);
    assert(company[0x100 / 4] == 14);
    assert(company[0x104 / 4] == 34);
    assert(company[0x108 / 4] == 38);
    assert(company[0x10c / 4] == 18);
    assert(company[0x110 / 4] == 26);
    assert(company[0x114 / 4] == 30);
    assert(company[0x118 / 4] == 22);
    assert(company[0x11c / 4] == 192);

    EmployeeSkillMultipliers employee = {
        .field4 = 2000,
        .field8 = 3000,
        .field_c = 1000,
        .field_10 = 4000,
    };
    employee_apply_skill_multipliers(&employee, 77, 3, 2, 4, 5);
    assert(employee.value24 == 77);
    assert(employee.value28 == 20);
    assert(employee.value2c == 20);
    assert(employee.value30 == 90);
    assert(employee.value34 == 160);

    assert(strcmp(game_get_plan_name(0), "keinen Plan") == 0);
    assert(strcmp(game_get_plan_name(3), "komplette KI") == 0);
    assert(strcmp(game_get_plan_name(0xb), "Filialen überprüfen") == 0);
    assert(strcmp(game_get_plan_name(0x18), "Spieler abwickeln") == 0);
    assert(strcmp(game_get_plan_name(2), "Unknown Plan") == 0);
    assert(strcmp(game_get_plan_name(0x19), "Unknown Plan") == 0);
}

static void test_setters_and_tables(void) {
    uint8_t object[0x300] = {0};
    write_i32_at(object, 0x228, 1234);
    write_i32_at(object, 0x22c, 5678);
    clear_field228(object);
    int32_t value = 0;
    memcpy(&value, object + 0x228, sizeof(value));
    assert(value == 0);
    memcpy(&value, object + 0x22c, sizeof(value));
    assert(value == 5678);
    clear_field228(NULL);

    entity_set_tile_id(object, 0x12345678);
    memcpy(&value, object + 0x24, sizeof(value));
    assert(value == 0x12345678);

    uint8_t dialog[0x300] = {0};
    dialog_set_result(dialog, 77);
    memcpy(&value, dialog + 0x280, sizeof(value));
    assert(value == 1);
    memcpy(&value, dialog + 0x27c, sizeof(value));
    assert(value == 77);
    dialog_set_result(NULL, 1);

    assert(game_get_global_table_value(0) == 0x3300ffu);
    assert(game_get_global_table_value(4) == 0xff66ffu);
    assert(game_get_global_table_value(8) == 0x99cc33u);
    assert(game_get_global_table_value(20) == 0);
    assert(game_get_global_table_value(21) == 0);

    assert(game_find_city_index(200) == 0);
    assert(game_find_city_index(16711680) == 2);
    assert(game_find_city_index(26111) == 6);
    assert(game_find_city_index(1234) == 7);

    assert(strcmp(game_get_data_by_index(0), "Kids") == 0);
    assert(strcmp(game_get_data_by_index(5), "Big shots") == 0);
    assert(strcmp(game_get_data_by_index(10), "Official") == 0);
    assert(strcmp(game_get_data_by_index(0xf), "Celebrity ") == 0);
    assert(strcmp(game_get_data_by_index(0x21), "Celebrity ") == 0);
    assert(strcmp(game_get_data_by_index(0x22), "Flyer Boy ") == 0);
    assert(strcmp(game_get_data_by_index(99), "???") == 0);
}

static void test_leaf_queue_and_inventory(void) {
    int16_t slots[8][6] = {{0}};
    slots[3][0] = -1;
    assert(array_find_empty_slot8(slots) == 3);
    for (int index = 0; index < 8; index++) {
        slots[index][0] = -1;
    }
    assert(array_find_empty_slot8(slots) == 0);
    for (int index = 0; index < 8; index++) {
        slots[index][0] = 1;
    }
    assert(array_find_empty_slot8(slots) == -1);
    assert(array_find_empty_slot8(NULL) == -1);

    EventQueueState queue;
    memset(&queue, 0, sizeof(queue));
    queue.head = 1023;
    queue.tail = 2;
    queue.entries[1023].id = 5;
    queue.entries[0].id = 6;
    queue.entries[1].id = 5;
    event_queue_set_entry_state22(&queue, 5);
    assert(queue.entries[1023].state == 0x22);
    assert(queue.entries[1].state == 0x22);
    assert(queue.entries[0].state == 0);
    queue.head = 0;
    queue.tail = 0;
    event_queue_set_entry_state22(&queue, 5);
    event_queue_set_entry_state22(NULL, 5);

    int32_t variants[1] = {1};
    assert(employee_next_sprite_variant(variants, 0, 0, 3) == '1');
    assert(variants[0] == 2);
    assert(employee_next_sprite_variant(variants, 0, 0, 3) == '2');
    assert(variants[0] == 3);
    assert(employee_next_sprite_variant(variants, 0, 0, 3) == '1');
    assert(variants[0] == 0);
    variants[0] = 2;
    assert(employee_next_sprite_variant(variants, 0, 3, 3) == '2');
    assert(employee_next_sprite_variant(NULL, 0, 0, 3) == '1');

    size_t building_size = 2 * 0x168 + 0x200;
    uint8_t *building = calloc(building_size, 1);
    uint8_t *inventory = calloc(0x120, 1);
    int32_t *scenario_table = calloc(0x100, sizeof(int32_t));
    assert(building != NULL && inventory != NULL && scenario_table != NULL);
    int32_t index = 2;
    memcpy(inventory + 0x4c, &index, sizeof(index));
    int32_t scenario_index = 1;
    memcpy(building + 2 * 0x168 + 0x40, &scenario_index,
           sizeof(scenario_index));
    scenario_table[0x30] = 1000;
    memset(building + 2 * 0x168 + 0x74, 0xff, 10 * 16);
    building_reset_inventory(building, inventory, scenario_table);
    double amount = 0.0;
    memcpy(&amount, inventory + 0x108, sizeof(amount));
    assert(amount == 500000.0);
    for (int slot = 0; slot < 10; slot++) {
        int32_t first = 0;
        int32_t last = 0;
        memcpy(&first, building + 2 * 0x168 + 0x74 + slot * 16, 4);
        memcpy(&last, building + 2 * 0x168 + 0x74 + slot * 16 + 12, 4);
        assert(first == -1);
        assert(last == 0);
    }
    int32_t state = 0;
    memcpy(&state, building + 2 * 0x168 + 0x12c, sizeof(state));
    assert(state == 3);
    building_reset_inventory(NULL, inventory, scenario_table);
    free(building);
    free(inventory);
    free(scenario_table);
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
    test_more_leafs();
    test_setters_and_tables();
    test_leaf_queue_and_inventory();
    puts("leaf function reconstruction: OK");
    return 0;
}
