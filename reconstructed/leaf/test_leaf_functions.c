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

static int32_t read_i32_at(const uint8_t *base, size_t offset) {
    int32_t value;
    memcpy(&value, base + offset, sizeof(value));
    return value;
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

static void test_stride_entity_city(void) {
    uint8_t stride_base[0xdc8 + 4 * 0x60] = {0};
    assert(array_find_index_stride60(stride_base,
                                     stride_base + 0xdc8) == 0);
    assert(array_find_index_stride60(stride_base,
                                     stride_base + 0xdc8 + 3 * 0x60) == 3);
    assert(array_find_index_stride60(stride_base,
                                     stride_base + 0xdc8 + 4 * 0x60) == -1);
    assert(array_find_index_stride60(NULL, stride_base) == -1);

    const EntityTypeProperties table[3] = {
        {2433, 50, -15, 1},
        {2436, 0, -32, 2},
        {-1, 0, 0, 0},
    };
    EntityProperties entity = {0, 7, 8, 9};
    entity_apply_type_properties(&entity, 2433, table, 3);
    assert(entity.type == 2433);
    assert(entity.field40 == 50 && entity.field44 == -15 &&
           entity.field48 == 1);
    entity = (EntityProperties){0, 7, 8, 9};
    entity_apply_type_properties(&entity, 2436, table, 3);
    assert(entity.field40 == 0 && entity.field44 == -32 &&
           entity.field48 == 2);
    entity = (EntityProperties){0, 7, 8, 9};
    entity_apply_type_properties(&entity, 999, table, 3);
    assert(entity.type == 999);
    assert(entity.field40 == 7 && entity.field44 == 8 &&
           entity.field48 == 9);
    entity_apply_type_properties(NULL, 1, table, 3);

    uint8_t city[0x1700] = {0};
    assert(city_is_idle(city));
    uint8_t state[0x100] = {0};
    uintptr_t pointer = (uintptr_t)state;
    memcpy(city + 0x16f0, &pointer, sizeof(pointer));
    assert(!city_is_idle(city));
    write_i32_at(state, 0x94, 1);
    assert(city_is_idle(city));
    write_i32_at(state, 0x94, 0);
    assert(!city_is_idle(city));
    assert(city_is_idle(NULL));

    const void *values[3] = {state, city, NULL};
    assert(array_get_ptr(values, 3, 0) == state);
    assert(array_get_ptr4(values, 3, 1) == city);
    assert(array_get_ptr_checked(values, 3, 2) == NULL);
    assert(array_get_ptr(values, 3, -1) == NULL);
    assert(array_get_ptr(values, 3, 3) == NULL);
    assert(array_get_ptr(NULL, 3, 0) == NULL);
}

static void test_font_clock_economy(void) {
    FntInfo font;
    memset(&font, 0, sizeof(font));
    font.advances[0] = 3;
    font.advances['A' - 0x20] = 7;
    font.advances['B' - 0x20] = 5;
    assert(font_get_char_width(&font, 'A') == 7);
    assert(font_get_char_width(&font, 'B') == 5);
    assert(font_get_char_width(&font, 'Z') == 0);
    assert(font_get_char_width(&font, 0x1f) == 0);
    assert(font_get_char_width(NULL, 'A') == 0);
    assert(font_measure_text(&font, "AB") == 12);
    assert(font_measure_text(&font, "A B") == 15);
    assert(font_measure_text(&font, "\t") == 3);
    assert(font_measure_text(&font, "") == 0);
    assert(font_measure_text(NULL, "AB") == 0);
    assert(font_measure_range(&font, "AB", 0, 1) == 7);
    assert(font_measure_range(&font, "AB", 1, 2) == 5);
    assert(font_measure_range(&font, "AB", 1, 9) == 5);
    assert(font_measure_range(&font, "AB", -1, 2) == 0);

    uint8_t clock[0x20];
    memset(clock, 0xff, sizeof(clock));
    game_clock_reset(clock, 0x1234);
    uint16_t state = 0;
    memcpy(&state, clock + 4, sizeof(state));
    assert(state == 0x1234);
    assert(clock[6] == 0 && clock[7] == 0 && clock[8] == 0);
    assert(clock[0x18] == 0 && clock[0x19] == 0);
    uint16_t zero16 = 1;
    memcpy(&zero16, clock + 10, sizeof(zero16));
    assert(zero16 == 0);
    int32_t zero32 = 1;
    memcpy(&zero32, clock + 0x0c, sizeof(zero32));
    assert(zero32 == 0);
    memcpy(&zero32, clock + 0x10, sizeof(zero32));
    assert(zero32 == 0);
    game_clock_reset(NULL, 0);

    int32_t table[18] = {0};
    table[1 * 9 + 2] = 250;
    assert(economy_apply_table_percent(table, 1, 2, 200) == 500);
    assert(economy_apply_table_percent(table, 0, 0, 200) == 0);
    assert(economy_apply_table_percent(NULL, 0, 0, 200) == 0);
}

static void test_economy_plan_order(void) {
    const EconomyModifierState state = {
        .row = 0,
        .count_168 = 1,
        .count_24c = 1,
        .count_164 = 1,
        .count_248 = 1,
        .count_a8 = 2,
        .count_18c = 1,
    };
    assert(economy_get_modifier(0x17, 1, &state) == 54);
    assert(economy_get_modifier(0x17, 2, &state) == 162);
    assert(economy_get_modifier(0x17, 0, &state) == 0);
    assert(economy_get_modifier(0x1d, 1, &state) == 60);
    assert(economy_get_modifier(0x1e, 0, &state) == 0);
    assert(economy_get_modifier(0x99, 1, &state) == 0);
    assert(economy_get_modifier(0x17, 1, NULL) == 0);
    assert(strcmp(economy_get_modifier_message(0, 0),
                  "can't perform action") == 0);
    assert(strcmp(economy_get_modifier_message(0, 1), "warning") == 0);
    assert(strcmp(economy_get_modifier_message(0, 2), "fatal error") == 0);
    assert(economy_get_modifier_message(1, 0) == NULL);

    GamePlanState plan;
    memset(&plan, 0xff, sizeof(plan));
    game_plan_construct(&plan);
    assert(plan.fields[1] == 0 && plan.fields[2] == 2);
    assert(plan.fields[3] == -1 && plan.fields[4] == 0);
    assert(plan.fields[7] == -1 && plan.fields[8] == 0);
    assert(plan.fields[9] == 0 && plan.fields[10] == 0);
    assert(plan.fields[0xb] == -1);
    game_plan_construct(NULL);

    ConstructionOrderState order;
    memset(&order, 0xff, sizeof(order));
    leaf_construction_order_construct(&order, 11, 22);
    assert(order.fields[1] == 11 && order.fields[2] == 22);
    assert(order.fields[3] == 100 && order.fields[4] == 0);
    assert(order.fields[5] == -1 && order.fields[6] == -1);
    assert(order.fields[7] == -1 && order.fields[8] == 0);
    leaf_construction_order_construct(NULL, 1, 2);
}

static void test_furniture_and_game_accessors(void) {
    FurnitureTypeState furniture;
    memset(&furniture, 0xff, sizeof(furniture));
    furniture_type_construct(&furniture);
    assert(furniture.vtable == 0);
    assert(furniture.fields[2] == 12 && furniture.fields[3] == 11);
    assert(furniture.fields[4] == 4 && furniture.fields[5] == 3);
    assert(furniture.fields[0x1c] == 0 && furniture.fields[0x1d] == 0);
    for (int index = 0; index < 8; index++) {
        size_t base = 0x1e + index * 3;
        assert(furniture.fields[base] == -1);
        assert(furniture.fields[base + 1] == -1);
        assert(furniture.fields[base + 2] == 0);
    }
    furniture.vtable = 123;
    furniture_type_destroy(&furniture);
    assert(furniture.vtable == 0);
    furniture_type_construct(NULL);
    furniture_type_destroy(NULL);

    uint8_t player[16] = {0};
    write_i32_at(player, 8, 4321);
    const void *players[6] = {NULL};
    players[2] = player;
    assert(game_get_player_by_slot(players, 2) == player);
    assert(game_get_player_by_slot(players, 0) == NULL);
    assert(game_get_player_by_slot(players, -1) == NULL);
    assert(game_get_player_by_slot(players, 6) == NULL);
    assert(game_get_current_player_company_name(players, 2) == 4321);
    assert(game_get_current_player_company_name(players, 0) == -1);
    assert(game_get_current_player_company_name(players, 9) == -1);
    assert(game_get_player_city(players, 2) == player);
    assert(game_get_player_city(players, 1) == NULL);
    assert(game_find_player_slot(players, player) == 2);
    assert(game_find_player_slot(players, player + 1) == -1);

    const int16_t group[6] = {4, 5, -1, 7, 8, 9};
    assert(game_find_group_slot(group, 5) == 1);
    assert(game_find_group_slot(group, 7) == 3);
    assert(game_find_group_slot(group, 6) == -1);
    assert(game_count_group_slots(group) == 2);
    const int16_t full[6] = {1, 2, 3, 4, 5, 6};
    assert(game_count_group_slots(full) == 6);
    const int16_t empty[6] = {-1, 2, 3, 4, 5, 6};
    assert(game_count_group_slots(empty) == 0);

    uint8_t city0[8] = {0};
    uint8_t city1[8] = {0};
    const void *city_table[2] = {city0, city1};
    assert(game_get_city_data(city_table, 2, 0) == city0);
    assert(game_get_city_data(city_table, 2, 1) == city1);
    assert(game_get_city_data(city_table, 2, 2) == NULL);
    assert(game_get_city_data(city_table, 2, -1) == NULL);
    assert(game_get_city_data(NULL, 2, 0) == NULL);
}

static void test_object_record_palette(void) {
    uint8_t object[0x20] = {0};
    write_i32_at(object, 0x10, 11);
    write_i32_at(object, 0x14, 22);
    write_i32_at(object, 4, 33);
    write_i32_at(object, 8, 44);
    int32_t first = 0;
    int32_t second = 0;
    object_get_pair10(object, &first, &second);
    assert(first == 11 && second == 22);
    object_get_pair4(object, &first, &second);
    assert(first == 33 && second == 44);
    object_get_pair10(NULL, &first, &second);

    uint8_t records[2 * 0x48] = {0};
    write_i32_at(records, 0, 123);
    write_i32_at(records, 0x48, -1);
    int16_t index_value = 7;
    memcpy(records + 0x32, &index_value, sizeof(index_value));
    assert(record_get_value48(records, 2, 0) == 7);
    assert(record_get_value48(records, 2, 1) == 0);
    assert(record_get_value48(records, 2, 2) == 0);
    assert(record_set_index48(records, 2, 0, 5, 6));
    memcpy(&index_value, records + 0x32, sizeof(index_value));
    assert(index_value == 5);
    assert(!record_set_index48(records, 2, 0, 6, 6));
    assert(!record_set_index48(records, 2, 1, 5, 6));

    uint8_t rect_records[0x98] = {0};
    const int32_t values[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    const size_t offsets[8] = {0x70, 0x74, 0x78, 0x7c,
                               0x60, 0x64, 0x68, 0x6c};
    for (size_t index = 0; index < 8; index++) {
        write_i32_at(rect_records, offsets[index], values[index]);
    }
    int32_t pairs[8] = {0};
    assert(record_get_rect98(rect_records, 0, pairs));
    for (size_t index = 0; index < 8; index++) {
        assert(pairs[index] == values[index]);
    }
    assert(!record_get_rect98(NULL, 0, pairs));
    assert(!record_get_rect98(rect_records, 0, NULL));

    uint8_t game[0x280] = {0};
    write_i32_at(game, 0x264, 4);
    write_i32_at(game, 0x270, 0);
    assert(game_get_active_screen_or_fallback(game) == 4);
    write_i32_at(game, 0x270, 9);
    assert(game_get_active_screen_or_fallback(game) == 9);
    assert(game_get_active_screen_or_fallback(NULL) == 0);

    uint8_t palette[256 * 3] = {0};
    palette[0] = 255;
    palette[1] = 255;
    palette[2] = 255;
    palette[3] = 255;
    palette[4] = 0;
    palette[5] = 0;
    uint16_t output[256] = {0};
    palette_convert256(palette, output, false);
    assert(output[0] == 0x7fff);
    assert(output[1] == 0x7c00);
    palette_convert256(palette, output, true);
    assert(output[0] == 0xffdf);
    assert(output[1] == 0xf800);
    palette_convert256(NULL, output, true);
}

static void test_destructors_palette_record(void) {
    GamePlanState plan;
    memset(&plan, 0xff, sizeof(plan));
    game_plan_destructor(&plan);
    assert(plan.fields[0] == 0);
    game_plan_destructor(NULL);

    ConstructionOrderState order;
    memset(&order, 0xff, sizeof(order));
    leaf_construction_order_destructor(&order);
    assert(order.fields[0] == 0);
    leaf_construction_order_destructor(NULL);

    int32_t node = 123;
    award_node_destructor(&node);
    assert(node == 0);
    award_node_destructor(NULL);

    int32_t building_value = 456;
    building_value_destroy(&building_value);
    assert(building_value == 0);
    building_value_destroy(NULL);

    uint8_t palette0[768] = {0};
    uint8_t palette1[768] = {0};
    uint8_t palette2[768] = {0};
    palette1[0] = 1;
    palette2[767] = 2;
    const uint8_t *palettes[3] = {palette0, palette1, palette2};
    assert(palette_find_index(palettes, 3, palette1) == 1);
    assert(palette_find_index(palettes, 3, palette2) == 2);
    uint8_t missing[768] = {0};
    missing[100] = 9;
    assert(palette_find_index(palettes, 3, missing) == -1);
    assert(palette_find_index(NULL, 3, palette0) == -1);

    uint8_t records[2 * 0x48] = {0};
    write_i32_at(records, 0, 1);
    write_i32_at(records, 0x48, 0);
    uint8_t sources[2 * 0x98] = {0};
    sources[0x98 + 0x80] = 1;
    assert(record_get_type_index48(records, 2, 0, sources) == 1);
    sources[0x80] = 1;
    assert(record_get_type_index48(records, 2, 1, sources) == 0);
    sources[0x80] = 0;
    assert(record_get_type_index48(records, 2, 1, sources) == -1);
    assert(record_get_type_index48(records, 2, 2, sources) == -1);
    assert(record_get_type_index48(NULL, 2, 0, sources) == -1);
}

static void test_math_string_text(void) {
    assert(math_round_float(1.4f) == 1);
    assert(math_round_float(1.5f) == 2);
    assert(math_round_float(-1.4f) == -1);
    assert(math_round_float(-1.5f) == -2);
    assert(math_truncate_double(3.9) == 3);
    assert(math_truncate_double(-3.9) == -3);
    assert(math_piecewise_linear(0) == 0);
    assert(math_piecewise_linear(25) == 18);
    assert(math_piecewise_linear(49) == 35);
    assert(math_piecewise_linear(50) == 36);
    assert(math_piecewise_linear(75) == 68);

    const char *delimiters = " ,\tfoo";
    size_t index = 0;
    string_skip_delimiters(delimiters, &index);
    assert(index == 3);
    string_skip_delimiters(NULL, &index);
    string_skip_delimiters(delimiters, NULL);

    const char *separators = " ,}rest";
    index = 0;
    text_skip_field_separators(separators, &index);
    assert(index == 2);
    index = 0;
    text_skip_field_separators("abc", &index);
    assert(index == 0);
    index = 0;
    text_skip_field_separators("", &index);
    assert(index == 0);

    uint8_t text[0xa00] = {0};
    write_i32_at(text, 0x9b8, 14);
    write_i32_at(text, 0x9b4, 10);
    assert(text_get_line_height(text) == 14);
    assert(text_get_line_height(NULL) == 0);
    text_set_cursor(text, 11, 22);
    int32_t x = 0;
    int32_t y = 0;
    text_get_position(text, &x, &y);
    assert(x == 11 && y == 22);
    text_set_metrics(text, 30, 40, 50);
    assert(read_i32_at(text, 0x9a0) == 30);
    assert(read_i32_at(text, 0x9a4) == 30);
    assert(read_i32_at(text, 0x9a8) == 30);
    assert(read_i32_at(text, 0x9bc) == 30);
    assert(read_i32_at(text, 0x9c0) == 30);
    assert(read_i32_at(text, 0x9ac) == 30);
    assert(read_i32_at(text, 0x9c4) == 50);
    text_set_metrics2(text, 60, 70, 80);
    assert(read_i32_at(text, 0x9a0) == 60);
    assert(read_i32_at(text, 0x9a4) == 70);
    assert(read_i32_at(text, 0x9c0) == 70);
    assert(read_i32_at(text, 0x9c4) == 80);
}

static double read_double_at(const uint8_t *base, size_t offset) {
    double value;
    memcpy(&value, base + offset, sizeof(value));
    return value;
}

static void test_record_bounds_positions(void) {
    uint8_t record[0x80] = {0};
    const int16_t x_points[3] = {10, -8, 30};
    const int16_t y_points[3] = {20, 40, 60};
    const uint16_t widths[3] = {100, 200, 300};
    const uint16_t heights[3] = {50, 60, 70};
    int16_t point = 1;
    memcpy(record + 0x32, &point, sizeof(point));
    int32_t x = 0;
    int32_t y = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    assert(record_get_bounds48(record, 0, x_points, y_points, widths, heights,
                               &x, &y, &width, &height));
    assert(x == -8 && y == 40 && width == 200 && height == 60);
    assert(!record_get_bounds48(NULL, 0, x_points, y_points, widths, heights,
                                &x, &y, &width, &height));

    write_i32_at(record, 0x18, 11);
    write_i32_at(record, 0x1c, 22);
    write_i32_at(record, 0x20, 33);
    write_i32_at(record, 0x24, 44);
    int32_t pairs[4] = {0};
    assert(record_get_pair_positions(record, 0, pairs));
    assert(pairs[0] == 11 && pairs[1] == 22 && pairs[2] == 33 &&
           pairs[3] == 44);
    write_i32_at(record, 0, -1);
    assert(!record_get_pair_positions(record, 0, pairs));

    uint8_t records[2 * 0x48] = {0};
    assert(record_set_rect48(records, 2, 0, 7, 8, 0x1122334455667788ULL));
    assert(read_i32_at(records, 8) == 7);
    assert(read_i32_at(records, 12) == 8);
    uint64_t rect_value = 0;
    memcpy(&rect_value, records + 0x10, sizeof(rect_value));
    assert(rect_value == 0x1122334455667788ULL);
    assert(record_set_doubles48(records, 2, 0, 2.9, -3.9));
    memcpy(records + 0x32, &point, sizeof(point));
    assert(read_double_at(records, 8) == 2.9);
    assert(read_double_at(records, 0x10) == -3.9);
    assert(record_get_screen_rect48(records, 0, widths, heights, &x, &y));
    assert(x == 202 && y == 57);
    assert(record_get_screen_offset(records, 2, 0, x_points, widths, heights,
                                    &x, &y));
    assert(x == 200 && y == 57);
    write_i32_at(records, 0x48, -1);
    assert(!record_get_screen_offset(records, 2, 1, x_points, widths, heights,
                                     &x, &y));
    assert(!record_get_screen_offset(records, 2, 2, x_points, widths, heights,
                                     &x, &y));
}

static void write_i16_at(uint8_t *base, size_t offset, int16_t value) {
    memcpy(base + offset, &value, sizeof(value));
}

static int16_t read_i16_at(const uint8_t *base, size_t offset) {
    int16_t value;
    memcpy(&value, base + offset, sizeof(value));
    return value;
}

static void test_object_sprite_settings(void) {
    uint8_t object[0x120] = {0};
    write_i32_at(object, 4, 99);
    write_i32_at(object, 8, 11);
    write_i32_at(object, 0x0c, 22);
    write_i32_at(object, 0x10, 33);
    write_i32_at(object, 0x68, 44);
    write_i32_at(object, 0x6c, 55);
    write_i32_at(object, 0x100, 1);
    write_i32_at(object, 0x104, 2);
    write_i32_at(object, 0x108, 3);
    write_i32_at(object, 0x10c, 4);
    assert(object_get_id(object) == 99);
    assert(object_get_id(NULL) == -1);
    assert(object_get_field0c(object) == 22);
    assert(object_get_field10(object) == 33);
    object_set_field0c(object, 66);
    object_set_field8(object, 77);
    object_set_field_fc(object, 88);
    assert(object_get_field0c(object) == 66);
    assert(object_get_field10(object) == 33);
    assert(read_i32_at(object, 8) == 77);
    assert(read_i32_at(object, 0xfc) == 88);
    object_set_short28(object, -1234);
    assert(read_i16_at(object, 0x28) == -1234);
    int32_t first = 0;
    int32_t second = 0;
    object_get_pair68(object, &first, &second);
    assert(first == 44 && second == 55);
    int32_t rect[4] = {0};
    object_get_rect100(object, rect);
    assert(rect[0] == 1 && rect[1] == 3 && rect[2] == 2 && rect[3] == 4);
    object_set_flag104(object, 0x5a);
    assert(object[0x104] == 0x5a);

    uint8_t sprite[0x40] = {0};
    sprite[4] = 0x06;
    sprite[5] = 0x10;
    write_i32_at(sprite, 0x1c, 0x1234);
    write_i16_at(sprite, 6, 10);
    write_i16_at(sprite, 8, 20);
    write_i16_at(sprite, 10, 3);
    write_i16_at(sprite, 12, 4);
    assert(sprite_get_format(sprite) == 0x06);
    assert(sprite_get_color_key(sprite) == 0x1234);
    int32_t width = 0;
    int32_t height = 0;
    sprite_get_size(sprite, &width, &height);
    assert(width == 5 && height == 20);
    sprite_get_hotspot(sprite, &width, &height);
    assert(width == 3 && height == 4);
    sprite_set_hotspot(sprite, 7, 8);
    sprite_get_hotspot(sprite, &width, &height);
    assert(width == 7 && height == 8);
    sprite_set_color_key(sprite, 0x5678);
    assert(sprite_get_color_key(sprite) == 0x5678);
    assert((sprite[4] & 2) != 0);
    sprite[4] |= 0x10;
    assert(sprite_get_color_key(sprite) == 0);
    write_i32_at(sprite, 0x30, 1);
    sprite[0x37] = 1;
    sprite_get_size(sprite, &width, &height);
    assert(width == 20 && height == 5);

    uint8_t game[0x2e30] = {0};
    write_i32_at(game, 0x2e1c, 0x41);
    write_i32_at(game, 0x2e20, 8);
    assert(game_get_speed_setting(game) == 2);
    write_i32_at(game, 0x2e1c, 0x40);
    assert(game_get_speed_setting(game) == 1);
    write_i32_at(game, 0x2e1c, 0x41);
    write_i32_at(game, 0x2e20, 7);
    assert(game_get_speed_setting(game) == 1);
    assert(game_get_starting_capital(0) == 1000000);
    assert(game_get_starting_capital(9) == 22000);
    assert(game_get_starting_capital(10) == 20000);
    assert(game_get_starting_capital(-1) == 20000);

    uint8_t date[32] = {0};
    date[7] = 8;
    date[8] = 3;
    write_i16_at(date, 4, 6);
    assert(game_get_time_segment(date) == 2);
    uint32_t year = 0;
    uint32_t weekday = 0;
    game_get_year_and_weekday(date, &year, &weekday);
    assert(year == 3 && weekday == 6);
}

static void test_state_id_predicates(void) {
    uint8_t object[0x48] = {0};
    write_i32_at(object, 0x30, 0x1a);
    assert(state_is_1a_1b_1c(object));
    write_i32_at(object, 0x30, 0x1c);
    assert(state_is_1a_1b_1c(object));
    write_i32_at(object, 0x30, 0x1d);
    assert(!state_is_1a_1b_1c(object));
    assert(state_is_menu_state(object));
    write_i32_at(object, 0x30, 0x17);
    assert(state_is_menu_state(object));
    write_i32_at(object, 0x30, 0x1f);
    assert(!state_is_menu_state(object));
    write_i32_at(object, 0x38, 0x2d);
    assert(state_is_2d_or_2e(object));
    write_i32_at(object, 0x38, 0x2f);
    assert(!state_is_2d_or_2e(object));

    assert(is_special_id_range(0x84c) && is_special_id_range(0x857));
    assert(!is_special_id_range(0x84b) && !is_special_id_range(0x858));
    assert(object_is_id_in_840_range(0x840) &&
           object_is_id_in_840_range(0x84b));
    assert(!object_is_id_in_840_range(0x83f));
    assert(object_is_known_id(-1));
    assert(object_is_known_id(0x356));
    assert(object_is_known_id(0x602));
    assert(!object_is_known_id(0x603));
    assert(object_is_known_id(0x19) && object_is_known_id(0x20));
    assert(!object_is_known_id(0x18) && !object_is_known_id(0x21));
    assert(is_menu_id_352(0x352));
    assert(is_menu_id_351_or_355(0x351) && is_menu_id_351_or_355(0x355));
    assert(is_menu_id_34e_or_350(0x34e) && is_menu_id_34e_or_350(0x350));
    for (int32_t id = 0x34d; id <= 0x355; id++) {
        assert(is_menu_id_range(id));
    }
    assert(!is_menu_id_range(0x34c));
    assert(!is_menu_id_range(0x356));
}

static void test_small_stats_accessors(void) {
    const int32_t counts[8] = {0, 1, 0, 2, 0, 0, 0, 0};
    assert(!product_has_stock(counts, 0));
    assert(product_has_stock(counts, 1));
    assert(!product_has_stock(NULL, 1));
    assert(stats_get_amount_by_type(0) == 576.0);
    assert(stats_get_amount_by_type(1) == 2322.0);
    assert(stats_get_amount_by_type(2) == 1368.0);
    assert(stats_get_amount_by_type(3) == 1656.0);
    assert(stats_get_amount_by_type(4) == 0.0);
    assert(storage_get_capacity(0) == 0x24);
    assert(storage_get_capacity(3) == 0x51);
    const int32_t supplier[3] = {9, 10, 11};
    assert(supplier_get_value_plus_one(supplier, 0) == 0);
    assert(supplier_get_value_plus_one(supplier, 1) == 11);
    assert(supplier_get_value_plus_one(supplier, 2) == 12);
    assert(rating_get_inverse100(0) == 100);
    assert(rating_get_inverse100(10) == 70);
    assert(rating_get_inverse100(40) == 0);
    uint8_t object[0x40] = {0};
    object[0x36] = 7;
    assert(object_get_byte36_max7(object) == 7);
    object[0x36] = 8;
    assert(object_get_byte36_max7(object) == 0);
    assert(object_get_byte36_max7(NULL) == 0);

    const int32_t values[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    assert(index_map8to5(values, 3) == 3);
    assert(index_map8to5(values, 8) == 5);
    assert(index_map8to5(values, -1) == 3);
    const int32_t high[8] = {200, 200, 200, 200, 200, 200, 200, 200};
    assert(index_map8to5(high, 0) == 100);
    assert(index_map8to5(values, 0) == 0);
    assert(index_map8to5(NULL, 0) == 0);

    assert(stats_get_level_from_four_counters(0) == 0);
    assert(stats_get_level_from_four_counters(2) == 1);
    assert(stats_get_level_from_four_counters(3) == 2);
    assert(stats_get_level_from_four_counters(4) == 2);
    assert(stats_get_level_from_four_counters(5) == 3);
    assert(stats_get_level_from_ten_counters(0) == 0);
    assert(stats_get_level_from_ten_counters(3) == 1);
    assert(stats_get_level_from_ten_counters(4) == 2);
    assert(stats_get_level_from_ten_counters(6) == 3);
}

static void test_table_grid_searches(void) {
    uint8_t matrix[0x1460 + 64 * 4] = {0};
    write_i32_at(matrix, 5000 + (2 + 1 * 9) * 4, 111);
    write_i32_at(matrix, 0x13d0 + (3 + 2 * 9) * 4, 222);
    write_i32_at(matrix, 0x1418 + (4 + 3 * 9) * 4, 333);
    write_i32_at(matrix, 0x1460 + (5 + 4 * 9) * 4, 444);
    assert(stats_get_matrix_variant_value(matrix, 0, 1, 2) == 111);
    assert(stats_get_matrix_variant_value(matrix, 1, 2, 3) == 222);
    assert(stats_get_matrix_variant_value(matrix, 2, 3, 4) == 333);
    assert(stats_get_matrix_variant_value(matrix, 3, 4, 5) == 444);
    assert(stats_get_matrix_variant_value(matrix, 9, 7, 1) == 7);

    uint8_t series[2 * 400 + 4] = {0};
    write_i32_at(series, (5 + 1 * 100) * 4 + 0x44, 55);
    assert(stats_get_or_sum_series(series, 1, 5) == 55);
    for (int index = 0; index < 100; index++) {
        write_i32_at(series, (index + 0 * 100) * 4 + 0x44, index + 1);
    }
    assert(stats_get_or_sum_series(series, 0, -1) == 5050);

    uint8_t map[0x2c234 + 0x30 * 4 * 4] = {0};
    write_i32_at(map, 0x2bf4c + (2 * 0x30 + 3) * 4, 123);
    write_i32_at(map, 0x2c234 + (1 * 0x30 + 2) * 4, 456);
    assert(map_get_2d_table_value(map, 0, 2, 3) == 123);
    assert(map_get_2d_table_value(map, 1, 1, 2) == 456);
    assert(map_get_2d_table_value(map, 2, 0, 0) == 0);

    uint8_t grid[0x60] = {0};
    uint8_t cells[4 * 12] = {0};
    write_i32_at(grid, 0x1c, 2);
    write_i32_at(grid, 0x20, 2);
    uintptr_t cell_base = (uintptr_t)cells;
    memcpy(grid + 0x4c, &cell_base, sizeof(cell_base));
    assert(grid_get_cell(grid, 0, 0) == cells);
    assert(grid_get_cell(grid, 1, 1) == cells + (2 * 1 + 1) * 12);
    assert(grid_get_cell(grid, 2, 0) == NULL);
    assert(grid_get_cell(grid, 0, 2) == NULL);

    float floats[72] = {0};
    floats[0] = -1.0f;
    floats[35] = 9.5f;
    assert(grid_get_max_value(floats) == 9.5f);
    assert(grid_get_max_value(NULL) == 0.0f);

    const int32_t values[4] = {7, 8, 9, 8};
    assert(global_array_find_index(values, 4, 9) == 2);
    assert(global_array_find_int(values, 4, 8) == 1);
    assert(save_list_find_index(values, 4, 7) == 0);
    assert(global_array_find_index(values, 4, 10) == -1);
    assert(global_array_find_index(NULL, 4, 7) == -1);

    int32_t market[0x100] = {0};
    market[0xa0 + 3 + 1 * 8] = 1;
    market[0xa0 + 4 + 1 * 8] = 2;
    assert(market_get_price_modifier(market, 1, 3) == 10);
    assert(market_get_price_modifier(market, 1, 4) == -10);
    assert(market_get_price_modifier(market, 1, 5) == 0);
    assert(market_get_price_modifier(NULL, 0, 0) == 0);
}

static void write_pointer_at(uint8_t *base, size_t offset, const void *ptr) {
    uintptr_t value = (uintptr_t)ptr;
    memcpy(base + offset, &value, sizeof(value));
}

static void test_map_object_helpers(void) {
    uint8_t map[0x100] = {0};
    write_i32_at(map, 0x0c, 4);
    write_i32_at(map, 0x10, 6);
    map_compute_iso_offsets(map);
    assert(read_i32_at(map, 0xd8) == 8);
    assert(read_i32_at(map, 0xdc) == 8);
    assert(read_i32_at(map, 0xe0) == 12);
    assert(read_i32_at(map, 0xe4) == 18);

    uint8_t points[2 * 12] = {0};
    write_i32_at(points, 0, 2);
    write_i32_at(points, 4, 3);
    write_i32_at(map, 0x1c, 10);
    write_i32_at(map, 0x20, 10);
    write_pointer_at(map, 0x4c, points);
    assert(map_compute_object_distance(map, 1, 2, 1, 1, 0) == 42);
    assert(map_compute_object_distance(map, 0, 0, 0, 0, -1) == 1000000);
    assert(map_compute_object_distance(map, 0, 0, 0, 0, 101) == 1000000);

    uint8_t child[0x40] = {0};
    write_i32_at(child, 0, 77);
    write_i32_at(child, 0x2c, 88);
    uint8_t object[0x120] = {0};
    write_pointer_at(object, 0x14, child);
    write_pointer_at(object, 200, child);
    assert(object_get_child_field14(object) == 77);
    assert(object_get_child_field2c(object) == 88);
    object_set_child_field2c(object, 99);
    assert(read_i32_at(child, 0x2c) == 99);
    object_set_child_short(object);
    assert(read_i16_at(child, 8) == -1);
    object_set_child_short8(object, 12);
    assert(read_i16_at(child, 8) == 12);
    object_set_child_short8(object, 12);

    uint8_t root[0x60] = {0};
    uint8_t parent[0x60] = {0};
    uint8_t top[0x60] = {0};
    write_i32_at(root, 0x4c, 3);
    write_i32_at(parent, 0x4c, 3);
    write_i32_at(top, 0x4c, 5);
    write_pointer_at(root, 0x54, parent);
    write_pointer_at(parent, 0x54, top);
    assert(object_get_root_type(root) == 5);
    assert(object_get_root_type(top) == 5);
    assert(object_get_root_type(NULL) == -1);

    write_i32_at(object, 0x10c, 0);
    assert(object_get_clamped_level(object) == 1);
    assert(read_i32_at(object, 0x10c) == 1);
    write_i32_at(object, 0x10c, 2);
    assert(object_get_clamped_level(object) == 2);
    write_i32_at(object, 0x10c, 4);
    assert(object_get_clamped_level(object) == 1);

    write_i32_at(object, 0x68, 11);
    write_i32_at(object, 0x6c, 22);
    write_i32_at(object, 0x78, 0);
    assert(object_get_active_value(object) == 0);
    write_i32_at(object, 0x78, 1);
    assert(object_get_active_value(object) == 22);
    write_i32_at(object, 0x6c, 0);
    write_i32_at(object, 0x68, 33);
    assert(object_get_active_value(object) == 33);

    object_reset108(object);
    assert(read_i32_at(object, 0x108) == -1);
    assert(read_i32_at(object, 0x8c) == -1);
    write_i32_at(object, 0x28, 5);
    object_clear_field28(object);
    assert(read_i32_at(object, 0x28) == 0);
    write_i32_at(object, 4, 5);
    object_clear_field4(object);
    assert(read_i32_at(object, 4) == 0);
    write_i32_at(object, 0x54, 5);
    object_clear_field54(object);
    assert(read_i32_at(object, 0x54) == 0);

    const size_t fields[7] = {0x54, 0x58, 0x70, 0x9c, 0x78, 0x6c, 100};
    for (size_t index = 0; index < 7; index++) {
        write_i32_at(object, fields[index], 123);
    }
    object_clear_fields_a(object);
    for (size_t index = 0; index < 7; index++) {
        assert(read_i32_at(object, fields[index]) == 0);
    }

    uint8_t state[0x40] = {0};
    write_pointer_at(object, 8, state);
    write_i32_at(state, 0x1c, 55);
    state[0x2c] = 1;
    state[0x2d] = 2;
    state[0x2e] = 3;
    state[0x2f] = 4;
    object_clear_state(object);
    assert(read_i32_at(state, 0x1c) == -1);
    assert(state[0x2c] == 0 && state[0x2d] == 0 && state[0x2e] == 0 &&
           state[0x2f] == 0);
}

static void test_scroll_market_rating_player(void) {
    uint8_t *map = calloc(0x10180, 1);
    assert(map != NULL);
    write_i32_at(map, 0x30, 200);
    write_i32_at(map, 0x38, 20);
    write_i32_at(map, 0xec, 100);
    write_i32_at(map, 0x10170, 400);
    write_i32_at(map, 0x10174, 50);
    assert(map_clamp_scroll_y(map, 50, 0));
    assert(read_i32_at(map, 0xec) == 150);
    assert(!map_clamp_scroll_y(map, 150, 0));
    assert(map_clamp_scroll_y(map, 1000, 0));
    assert(read_i32_at(map, 0xec) == 420);
    assert(map_clamp_scroll_y(map, 1000, 2));
    assert(read_i32_at(map, 0xec) == 364);
    free(map);

    assert(market_get_price_delta(0, 5) == 0);
    assert(market_get_price_delta(7, 5) == 0);
    assert(market_get_price_delta(2, -1) == 0xffffffd8u);
    assert(market_get_price_delta(2, 0) == 0);
    assert(market_get_price_delta(2, 1) == 0x28u);

    assert(rating_get_float(2.0f, 0, 1) == 15.0);
    assert(rating_get_float(2.0f, 5, 1) == 33.0);
    assert(rating_get_float(2.0f, 8, 1) == 33.0);
    assert(rating_get_float(2.0f, 7, 1) == 17.0);
    assert(rating_get_float(2.0f, 9, 1) == 5.0);

    uint8_t player[0x300] = {0};
    write_i32_at(player, 0x200 + 4, 4);
    write_i32_at(player, 0x220 + 4, 8);
    write_i32_at(player, 0x240 + 4, 12);
    write_i32_at(player, 0x260 + 4, 16);
    assert(game_get_player_quarter_stat(player, 1, 0) == 4);
    assert(game_get_player_quarter_stat(player, 1, 1) == 12);
    assert(game_get_player_quarter_stat(player, 1, 2) == 8);
    assert(game_get_player_quarter_stat(player, 1, 3) == 16);
    assert(game_get_player_quarter_stat(player, 1, 4) == 10);

    assert(game_get_player_staff_band(0) == 0);
    assert(game_get_player_staff_band(2) == 1);
    assert(game_get_player_staff_band(3) == 2);
    assert(game_get_player_staff_band(5) == 3);
    assert(game_get_player_wealth_band(50000.0) == 0);
    assert(game_get_player_wealth_band(100001.0) == 1);
    assert(game_get_player_wealth_band(500001.0) == 2);
    assert(game_get_player_wealth_band(1000001.0) == 3);
    assert(game_get_player_satisfaction_band(91) == 0);
    assert(game_get_player_satisfaction_band(90) == 1);
    assert(game_get_player_satisfaction_band(80) == 1);
    assert(game_get_player_satisfaction_band(60) == 2);
    assert(game_get_player_satisfaction_band(40) == 3);

    int32_t stats[0x56] = {0};
    double weights[0x56] = {0};
    stats[0] = 1;
    stats[1] = 2;
    stats[2] = 0;
    weights[0] = 1000.0;
    weights[1] = 2000.0;
    weights[2] = 3000.0;
    double weighted = game_get_player_weighted_stat(stats, weights);
    assert(weighted > 4.999999 && weighted < 5.000001);

    uint8_t child[0x20] = {0};
    write_i32_at(child, 0x14, 77);
    uint8_t record[0x80] = {0};
    uintptr_t child_pointer = (uintptr_t)child;
    memcpy(record + 0x68, &child_pointer, sizeof(child_pointer));
    assert(game_get_record_child14(record, 0) == 77);
    assert(game_get_record_child14(record, -1) == 0);

    uint8_t player_state[0x1200] = {0};
    player_reset_ai_state(player_state);
    assert(read_i32_at(player_state, 0x84) == 1);
    assert(read_i32_at(player_state, 0x88) == 0);
    double debt = 12.0;
    memcpy(player_state + 0x108, &debt, sizeof(debt));
    write_i32_at(player_state, 0x1e8, 99);
    player_reset_debt_hours(player_state);
    assert(read_i32_at(player_state, 0x1e8) == 0);
    player_set_slot_flag18(player_state, 2);
    assert(player_state[0x10e5 + 2 * 0x18] == 1);
}

static void test_tile_product_name_helpers(void) {
    uint8_t flags[0x20] = {0};
    write_i32_at(flags, 0x1c, 0x5);
    uint8_t defs[4 * 12] = {0};
    uintptr_t flag_pointer = (uintptr_t)flags;
    memcpy(defs + 12 + 8, &flag_pointer, sizeof(flag_pointer));
    assert(!tile_def_test_flag(defs, 0, 1));
    assert(tile_def_test_flag(defs, 1, 1));
    assert(!tile_def_test_flag(defs, 1, 2));
    assert(!tile_def_test_flag(NULL, 0, 1));

    assert(!product_map_category(0x11, 0));
    assert(product_map_category(0x12, 0));
    assert(!product_map_category(0, 0));
    assert(!product_map_category(8, 1));
    assert(product_map_category(9, 1));
    assert(product_map_category(1, 2));
    assert(!product_map_category(4, 2));
    assert(product_map_category(9, 3));
    assert(product_map_category(0x11, 3));
    assert(!product_map_category(0x12, 3));
    assert(!product_map_category(9, 4));

    uint8_t records[0x25 + 2 * 0x48] = {0};
    strcpy((char *)records + 0x25, "Alpha");
    strcpy((char *)records + 0x25 + 0x48, "Beta");
    assert(map_find_name_index(records, 2, "Alpha") == 0);
    assert(map_find_name_index(records, 2, "Beta") == 1);
    assert(map_find_name_index(records, 2, "Gamma") == -1);
    assert(map_find_name_index(NULL, 2, "Alpha") == -1);

    uint8_t strings[3 * 0x48] = {0};
    strcpy((char *)strings, "alpha");
    strcpy((char *)strings + 0x48, "charlie");
    strcpy((char *)strings + 2 * 0x48, "echo");
    int32_t index = -1;
    assert(string_list_find(strings, 3, "charlie", &index) == 1);
    assert(index == 1);
    assert(string_list_find(strings, 3, "bravo", &index) == 0);
    assert(index == 1);
    assert(string_list_find(strings, 3, "zulu", &index) == 0);
    assert(index == 3);
    assert(string_list_find(strings, 0, "alpha", &index) == 0);
    assert(index == 0);
    assert(string_list_find(strings, 3, "alpha", NULL) == 0);
}

static void test_remaining_setters(void) {
    uint8_t object[0x1800] = {0};
    write_i32_at(object, 0x108, 10);
    assert(object_is_state10(object));
    write_i32_at(object, 0x108, 9);
    assert(!object_is_state10(object));
    object_set_frame5(object, 3);
    assert(read_i32_at(object, 0x94) == 15);
    object_set_frame5(object, -1);
    assert(read_i32_at(object, 0x94) == -1);
    object_set_index171c(object, 77);
    assert(read_i32_at(object, 0x171c) == 77);
    assert(read_i32_at(object, 0x1720) == 0);
    assert(read_i32_at(object, 0x1724) == 0);
    object_set_field280(object, 88);
    assert(read_i32_at(object, 0x280) == 88);

    uint8_t records[2 * 0x48] = {0};
    write_i32_at(records, 0, 123);
    records[0] = 0;
    record_clear48(records, 2, 0);
    assert(read_i32_at(records, 0) == -1);
    write_i32_at(records, 0x48, 10);
    records[0x48 + 0x30] = 9;
    records[0x48 + 0x3c] = 7;
    record_clear_active48(records, 2, 1);
    assert(read_i16_at(records, 0x48 + 0x30) == 0);
    assert(records[0x48 + 0x3c] == 0);
    records[0x48 + 0x3e] = 5;
    record_clear_flags48(records, 2, 1);
    assert(records[0x48 + 0x3e] == 0);
    assert(records[0x48 + 0x3c] == 0);
    record_clear_flags48(records, 2, 0);
    assert(records[0 + 0x3e] == 0);

    uint8_t flags[0x40] = {0};
    uint8_t tile_defs[4 * 12] = {0};
    uintptr_t flags_pointer = (uintptr_t)flags;
    memcpy(tile_defs + 12 + 8, &flags_pointer, sizeof(flags_pointer));
    record_set_field2d0c(tile_defs, 1, 0x5a);
    assert(flags[0x2d] == 0x5a);

    uint8_t slots[2 * 0x98] = {0};
    assert(record_set_slot6_98(slots, 2, 1, 3, 0x11223344, 0x5566));
    assert(read_i32_at(slots, 0x98 + 18) == 0x11223344);
    assert(read_i16_at(slots, 0x98 + 18 + 4) == 0x5566);
    assert(!record_set_slot6_98(slots, 2, 2, 3, 1, 2));
    assert(!record_set_slot6_98(slots, 2, 0, 16, 1, 2));

    set_field168(object, 11);
    set_field228(object, 22);
    set_field9b8(object, 33);
    assert(read_i32_at(object, 0x168) == 11);
    assert(read_i32_at(object, 0x228) == 22);
    assert(read_i32_at(object, 0x9b8) == 33);

    uint8_t rect[0x1c0] = {0};
    int32_t values[4] = {10, 20, 30, 40};
    write_i32_at(rect, 0x1a4, -999);
    rect_set1a4(rect, values);
    assert(read_i32_at(rect, 0x1a4) == 10);
    assert(read_i32_at(rect, 0x1a8) == 20);
    assert(read_i32_at(rect, 0x1ac) == 30);
    assert(read_i32_at(rect, 0x1b0) == 40);
    const int32_t merge[4] = {5, 25, 25, 50};
    rect_set1a4(rect, merge);
    assert(read_i32_at(rect, 0x1a4) == 5);
    assert(read_i32_at(rect, 0x1a8) == 20);
    assert(read_i32_at(rect, 0x1ac) == 30);
    assert(read_i32_at(rect, 0x1b0) == 50);

    uint8_t sprite[0x40] = {0};
    uint8_t palette[16] = {0};
    uintptr_t palette_pointer = (uintptr_t)palette;
    memcpy(sprite + 0x20, &palette_pointer, sizeof(palette_pointer));
    assert(sprite_get_palette(sprite) == palette);
    sprite[0x12] = 10;
    sprite[0x13] = 0;
    sprite[0x14] = 20;
    sprite[0x15] = 0;
    uint32_t width = 0;
    uint32_t height = 0;
    sprite_get_render_size(sprite, &width, &height);
    assert(width == 10 && height == 20);
    write_i32_at(sprite, 0x30, 1);
    sprite[0x37] = 1;
    sprite_get_render_size(sprite, &width, &height);
    assert(width == 20 && height == 10);

    uint8_t surface[0x80] = {0};
    uint8_t pixels[256] = {0};
    uintptr_t pixel_pointer = (uintptr_t)pixels;
    memcpy(surface + 0x28, &pixel_pointer, sizeof(pixel_pointer));
    write_i32_at(surface, 4, 1);
    write_i32_at(surface, 0x0c, 2);
    write_i32_at(surface, 8, 3);
    write_i32_at(surface, 0x10, 4);
    int32_t surface_rect[4] = {0};
    surface_get_cursor_rect(surface, surface_rect);
    assert(surface_rect[0] == 1 && surface_rect[1] == 2);
    assert(surface_rect[2] == 3 && surface_rect[3] == 4);
    uint16_t surface_width = 16;
    uint16_t surface_height = 8;
    memcpy(surface + 0x1a, &surface_width, sizeof(surface_width));
    memcpy(surface + 0x1c, &surface_height, sizeof(surface_height));
    surface_reset(surface);
    assert(read_i32_at(surface, 4) == 0);
    assert(read_i32_at(surface, 0x0c) == 0);
    assert(read_i32_at(surface, 8) == 16);
    assert(read_i32_at(surface, 0x10) == 8);
    write_i32_at(surface, 100, 5);
    write_i32_at(surface, 0x68, 6);
    write_i32_at(surface, 0x6c, 20);
    write_i32_at(surface, 0x70, 30);
    surface_set_bounds(surface, 2, 7, 25, 28);
    assert(read_i32_at(surface, 4) == 5);
    assert(read_i32_at(surface, 0x0c) == 7);
    assert(read_i32_at(surface, 8) == 20);
    assert(read_i32_at(surface, 0x10) == 28);
    write_i32_at(surface, 0x20, 24);
    surface_set_pixel(surface, 2, 1, 0x1234);
    assert(read_i16_at(pixels, 24 + 2 * 3) == 0x1234);
    surface_set_pixel(surface, 16, 1, 0x5678);
    assert(read_i16_at(pixels, 24 + 16 * 3) == 0);
}

static void test_surface_sprite_stream(void) {
    uint8_t pixels[64];
    memset(pixels, 0xff, sizeof(pixels));
    uint8_t surface[0x80] = {0};
    uintptr_t pixel_pointer = (uintptr_t)pixels;
    memcpy(surface + 0x18, &pixel_pointer, sizeof(pixel_pointer));
    write_i32_at(surface, 8, 2);
    write_i32_at(surface, 4, 3);
    surface[0x10] = 8;
    surface_clear(surface);
    for (int index = 0; index < 6; index++) {
        assert(pixels[index] == 0);
    }
    assert(pixels[6] == 0xff);

    memset(pixels, 0xff, sizeof(pixels));
    memcpy(surface + 0x28, &pixel_pointer, sizeof(pixel_pointer));
    uint16_t width = 4;
    uint16_t height = 2;
    memcpy(surface + 0x1a, &width, sizeof(width));
    memcpy(surface + 0x1c, &height, sizeof(height));
    write_i32_at(surface, 0x20, 6);
    surface_clear_rows(surface);
    for (int index = 0; index < 4; index++) {
        assert(pixels[index] == 0);
        assert(pixels[12 + index] == 0);
    }
    assert(pixels[4] == 0xff);
    assert(pixels[16] == 0xff);

    uint8_t sprite[0x40] = {0};
    sprite_init_format(sprite, 10, 20, 0x1234, 16, 0x17, 3, 4);
    assert(read_i16_at(sprite, 10) == 3);
    assert(sprite[5] == 16);
    assert(read_i16_at(sprite, 0x0c) == 4);
    assert(read_i32_at(sprite, 0x18) == 0);
    assert(sprite[4] == 0x17);
    assert(read_i32_at(sprite, 0x1c) == 0x1234);
    assert(read_i16_at(sprite, 8) == 20);
    assert(read_i16_at(sprite, 0x14) == 20);
    assert(read_i16_at(sprite, 6) == 20);
    assert(read_i16_at(sprite, 0x12) == 20);

    uint8_t child[0x20] = {0};
    write_i32_at(child, 0x0c, 7);
    write_i32_at(child, 0x10, 8);
    uint8_t object[0x8400] = {0};
    uintptr_t child_pointer = (uintptr_t)child;
    memcpy(object + 0x8310, &child_pointer, sizeof(child_pointer));
    int32_t x = 0;
    int32_t y = 0;
    object_get_child_origin(object, &x, &y);
    assert(x == 7 && y == 8);
    write_i32_at(object, 0xd4, 5);
    write_i32_at(object, 0xd8, 5);
    write_i32_at(object, 0xdc, 6);
    assert(object_count_matching_slots(object, 5) == 2);

    uint8_t target0[0x40] = {0};
    uint8_t target1[0x40] = {0};
    write_i32_at(target0, 0x38, 99);
    write_i32_at(target1, 0x38, 88);
    uint8_t tile_defs[48] = {0};
    uintptr_t target0_pointer = (uintptr_t)target0;
    uintptr_t target1_pointer = (uintptr_t)target1;
    memcpy(tile_defs + 8, &target0_pointer, sizeof(target0_pointer));
    memcpy(tile_defs + 12 + 8, &target1_pointer, sizeof(target1_pointer));
    uintptr_t tile_pointer = (uintptr_t)tile_defs;
    memcpy(object + 0x4c, &tile_pointer, sizeof(tile_pointer));
    uint8_t slot[0x50] = {0};
    write_i32_at(slot, 0x44, 0);
    write_i32_at(slot, 0x48, 1);
    object_clear_slot_refs(object, slot);
    assert(read_i32_at(target0, 0x38) == 0);
    assert(read_i32_at(target1, 0x38) == 0);
    assert(read_i32_at(slot, 0x44) == -1);
    assert(read_i32_at(slot, 0x48) == -1);

    uint8_t stream[0x40] = {0};
    write_i32_at(stream, 4, 1);
    write_i32_at(stream, 8, 2);
    assert(stream_buffer_reset(stream));
    assert(read_i32_at(stream, 4) == 0);
    assert(read_i32_at(stream, 8) == 0);
    write_i32_at(stream, 0x28, 10);
    write_i32_at(stream, 0x2c, 30);
    assert(stream_get_available(stream) == 20);
    write_i32_at(stream, 0x28, 30);
    assert(stream_get_available(stream) == 0);
}

static void test_misc_getters(void) {
    uint8_t object[0x2000] = {0};
    write_i32_at(object, 0x19f4, 19);
    write_i32_at(object, 0x24, 24);
    write_i32_at(object, 0x2c, 44);
    write_i32_at(object, 0xf0, 240);
    assert(get_field19f4(object) == 19);
    assert(get_field24(object) == 24);
    assert(get_field2c(object) == 44);
    assert(get_field_f0(object) == 240);
    assert(get_subobject4(object) == object + 4);
    assert(get_subobject4(NULL) == NULL);

    uint16_t width = 12;
    uint16_t height = 34;
    memcpy(object + 0x12, &width, sizeof(width));
    memcpy(object + 0x14, &height, sizeof(height));
    uint32_t out_width = 0;
    uint32_t out_height = 0;
    get_width_height(object, &out_width, &out_height);
    assert(out_width == 12 && out_height == 34);

    write_i32_at(object, 0x68, 9);
    assert(record_list_get_count(object) == 9);
    assert(record_list_get_count(NULL) == 0);

    uint8_t records[2 * 0x48] = {0};
    records[0x3e] = 7;
    records[0x48 + 0x3e] = 8;
    uint8_t list[0x60] = {0};
    write_i32_at(list, 0x48, 2);
    uintptr_t records_pointer = (uintptr_t)records;
    memcpy(list + 0x4c, &records_pointer, sizeof(records_pointer));
    uint8_t child[0x60] = {0};
    write_i32_at(child, 0, 1);
    uintptr_t list_pointer = (uintptr_t)list;
    memcpy(child + 0x58, &list_pointer, sizeof(list_pointer));
    uintptr_t child_pointer = (uintptr_t)child;
    memcpy(object + 8, &child_pointer, sizeof(child_pointer));
    assert(record_get_flag3e48(object) == 8);
    write_i32_at(child, 0, 2);
    assert(record_get_flag3e48(object) == 0);
    write_i32_at(child, 0, -1);
    assert(record_get_flag3e48(object) == 0);

    assert(surface_is_ready(0));
    assert(!surface_is_ready(1));
    assert(stream_get_status(0, 0, 0) == 1);
    assert(stream_get_status(0, 0, -1) == -1);
    assert(stream_get_status(1, 0, 0) == 0);
    assert(stream_get_status(0, 1, 0) == 0);
}

static int32_t leaf_stream_value;
static int32_t test_stream_read(void *context) {
    (void)context;
    return ++leaf_stream_value;
}

static int leaf_release_count;
static void test_stream_release(void *context) {
    (void)context;
    leaf_release_count++;
}

static int leaf_init_count;
static int32_t leaf_init_size;
static void test_object_init(void *context, int32_t size, int32_t arg2,
                             int32_t arg3) {
    (void)context;
    (void)arg2;
    (void)arg3;
    leaf_init_count++;
    leaf_init_size = size;
}

static void test_stream_object_init(void) {
    StreamCharState stream = {0};
    uint8_t bytes[4] = {'a', 'b', 'c', 0};
    stream.current = (uintptr_t)bytes;
    stream.end = (uintptr_t)bytes + 2;
    assert(stream_get_char(&stream, test_stream_read, NULL) == 'b');
    stream.current += 1;
    assert(stream_get_char(&stream, test_stream_read, NULL) == 2);

    StreamCharState peek_stream = {0};
    peek_stream.flags = 1;
    peek_stream.peek = -1;
    leaf_stream_value = 0;
    assert(stream_get_char(&peek_stream, test_stream_read, NULL) == 2);
    assert(peek_stream.peek == 2);
    assert(stream_get_char(&peek_stream, test_stream_read, NULL) == 3);
    assert(stream_get_char(NULL, test_stream_read, NULL) == -1);

    uint8_t old_buffer[4] = {0};
    uint8_t new_buffer[4] = {0};
    StreamBufferState buffer = {0};
    buffer.buffer = old_buffer;
    buffer.release_enabled = 1;
    leaf_release_count = 0;
    stream_set_buffer(&buffer, new_buffer, test_stream_release, NULL);
    assert(leaf_release_count == 1);
    assert(buffer.buffer == new_buffer);
    assert((buffer.flags & 4) == 0);
    stream_set_buffer(&buffer, NULL, test_stream_release, NULL);
    assert(buffer.buffer == NULL);
    assert((buffer.flags & 4) != 0);

    ObjectInitState init = {0};
    init.initialize = test_object_init;
    leaf_init_count = 0;
    object_ensure_init(&init);
    assert(init.initialized == 1);
    assert(leaf_init_count == 1);
    assert(leaf_init_size == 0x34);
    object_ensure_init(&init);
    assert(leaf_init_count == 1);
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
    test_stride_entity_city();
    test_font_clock_economy();
    test_economy_plan_order();
    test_furniture_and_game_accessors();
    test_object_record_palette();
    test_destructors_palette_record();
    test_math_string_text();
    test_record_bounds_positions();
    test_object_sprite_settings();
    test_state_id_predicates();
    test_small_stats_accessors();
    test_table_grid_searches();
    test_map_object_helpers();
    test_scroll_market_rating_player();
    test_tile_product_name_helpers();
    test_remaining_setters();
    test_surface_sprite_stream();
    test_misc_getters();
    test_stream_object_init();
    puts("leaf function reconstruction: OK");
    return 0;
}
