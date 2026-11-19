#include "leaf_functions.h"

#include <stdlib.h>
#include <string.h>

void clamp_0_100(int32_t *value) {
    if (value == NULL) {
        return;
    }
    if (*value > 100) {
        *value = 100;
    }
    if (*value < 0) {
        *value = 0;
    }
}

int32_t distance_manhattan3(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
    int32_t dx = x1 - x2;
    int32_t dy = y1 - y2;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return dx * 3 + dy * 4;
}

void color_convert_555_to_565(uint16_t *colors, size_t count, bool enabled) {
    if (colors == NULL || !enabled) {
        return;
    }
    for (size_t index = 0; index < count; index++) {
        uint16_t value = colors[index];
        colors[index] = (uint16_t)(((value & 0xffe0u) << 1) |
                                   (value & 0x1fu));
    }
}

uint32_t color_rgb_to_16(uint8_t red, uint8_t green, uint8_t blue,
                         bool rgb565) {
    uint32_t value = (((uint32_t)(red & 0xf8u) << 5) |
                      (uint32_t)(green & 0xf8u));
    if (rgb565) {
        return (value << 3) | ((uint32_t)blue >> 3);
    }
    return (value << 2) | ((uint32_t)blue >> 3);
}

int32_t cost_compute_quantity_price(int32_t quantity, int32_t unit_price) {
    return (quantity / 10) * unit_price * 10;
}

int32_t company_percent_modifier(int32_t value, int32_t fallback,
                                 int32_t mode) {
    if (value == -1) {
        value = fallback;
    }
    if (mode == 1) {
        return (value * 100) / 10000;
    }
    if (mode == 2) {
        return (value * 100) / 5000;
    }
    return 100;
}

int32_t building_level_from_type(int32_t type, uint8_t variant) {
    switch (type) {
    case 0:
        if (variant < 2) {
            return 1;
        }
        if (variant == 2) {
            return 2;
        }
        break;
    case 1:
        if (variant == 0) {
            return 1;
        }
        if (variant == 1) {
            return 2;
        }
        if (variant == 2) {
            return 3;
        }
        break;
    case 2:
        if (variant == 0) {
            return 2;
        }
        if (variant == 1) {
            return 3;
        }
        if (variant == 2) {
            return 4;
        }
        break;
    case 3:
        if (variant == 0) {
            return 3;
        }
        if (variant == 1) {
            return 4;
        }
        if (variant == 2) {
            return 5;
        }
        break;
    default:
        break;
    }
    return -1;
}

double building_area_by_level(int32_t level) {
    switch (level) {
    case 0:
        return 2070.0;
    case 1:
        return 2916.0;
    case 2:
        return 3420.0;
    case 3:
        return 3960.0;
    default:
        return 0.0;
    }
}

uint32_t enum_map_direction(uint32_t raw) {
    switch (raw & 7u) {
    case 1:
        return 4;
    case 2:
        return 1;
    case 3:
        return 5;
    case 4:
        return 2;
    case 5:
        return 6;
    case 6:
        return 3;
    case 7:
        return 7;
    default:
        return 0;
    }
}

size_t array_count_non_zero20(const int32_t values[20][3]) {
    size_t count = 0;
    if (values == NULL) {
        return 0;
    }
    for (size_t index = 0; index < 20; index++) {
        if (values[index][0] != 0) {
            count++;
        }
    }
    return count;
}

size_t array_count_valid8(const int16_t values[8]) {
    size_t count = 0;
    if (values == NULL) {
        return 0;
    }
    for (size_t index = 0; index < 8; index++) {
        if (values[index] != -1) {
            count++;
        }
    }
    return count;
}

int32_t calendar_interpolate_monthly_value(int32_t day, unsigned month,
                                           const int32_t values[4]) {
    if (values == NULL) {
        return 0;
    }
    if (day < 12) {
        int32_t base = values[(month - 1u) & 3u] - 6;
        int32_t step = ((values[month & 3u] - base) + 6) * day;
        step = step / 6 + (step >> 31);
        return ((step >> 1) - (step >> 31)) + base;
    }
    int32_t base = values[month & 3u];
    int32_t peak = base + 6;
    int32_t step = ((base - peak) + -6) * (day - 12);
    step = step / 6 + (step >> 31);
    return ((step >> 1) - (step >> 31)) + peak;
}

int32_t building_get_sprite_variant(int32_t type) {
    if (type >= 0x81c && type <= 0x81f) {
        return 0;
    }
    if (type >= 0x820 && type <= 0x823) {
        return 1;
    }
    if (type >= 0x824 && type <= 0x827) {
        return 2;
    }
    if (type >= 0x828 && type <= 0x833) {
        return 3;
    }
    if (type >= 0x834 && type <= 0x837) {
        return 0;
    }
    if (type >= 0x838 && type <= 0x83b) {
        return 1;
    }
    if (type >= 0x83c && type <= 0x83f) {
        return 2;
    }
    if (type >= 0x840 && type <= 0x843) {
        return 0;
    }
    if (type >= 0x844 && type <= 0x847) {
        return 1;
    }
    if (type >= 0x848 && type <= 0x84b) {
        return 2;
    }
    if (type >= 0x84c && type <= 0x84f) {
        return 0;
    }
    if (type >= 0x850 && type <= 0x853) {
        return 1;
    }
    if (type >= 0x854 && type <= 0x857) {
        return 2;
    }
    if (type >= 0x858 && type <= 0x85b) {
        return 0;
    }
    if (type >= 0x85c && type <= 0x85f) {
        return 1;
    }
    if (type >= 0x860 && type <= 0x863) {
        return 2;
    }
    return -1;
}

bool array_are_both_counts_positive(const int32_t *counts, uint8_t first,
                                    uint8_t second) {
    if (counts == NULL) {
        return false;
    }
    return counts[first] >= 1 && counts[second] >= 1;
}

int32_t array_index_of_int(const int32_t *values, size_t count, int32_t key) {
    if (values == NULL) {
        return -1;
    }
    for (size_t index = 0; index < count; index++) {
        if (values[index] == key) {
            return (int32_t)index;
        }
    }
    return -1;
}

int32_t binary_search8(const int32_t records[][2], size_t count, int32_t key,
                       bool insert) {
    if (records == NULL || count == 0) {
        return insert ? 0 : -1;
    }
    size_t low = 0;
    size_t high = count;
    if (count > 1) {
        do {
            size_t middle = (high + low) >> 1;
            int32_t value = records[middle][1];
            if (value == key) {
                return (int32_t)middle;
            }
            if (value < key) {
                low = middle;
            } else {
                high = middle;
            }
        } while (low < high - 1);
    }
    int32_t value = records[low][1];
    if (value != key) {
        if (high < count && records[high][1] == key) {
            return (int32_t)high;
        }
        if (!insert) {
            return -1;
        }
        if (value < key) {
            return (int32_t)high;
        }
    }
    return (int32_t)low;
}

int32_t array_find_pair(const int32_t pairs[20][3], int32_t key) {
    if (pairs == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < 20; index++) {
        if (pairs[index][0] != 0 && pairs[index][1] == key) {
            return index;
        }
    }
    return -1;
}

bool array_get_pair8(const int32_t records[][2], size_t count, size_t index,
                     int32_t *first, int32_t *second) {
    if (records == NULL || first == NULL || second == NULL || index >= count) {
        return false;
    }
    *first = records[index][0];
    *second = records[index][1];
    return true;
}

int16_t counter_increment_short(int16_t *counter) {
    if (counter == NULL) {
        return 0;
    }
    *counter = (int16_t)(*counter + 1);
    return *counter;
}

uint8_t game_get_max_index4(const int8_t values[4]) {
    if (values == NULL) {
        return 0;
    }
    uint8_t best_index = 0;
    int32_t best_value = -1000;
    for (uint8_t index = 0; index < 4; index++) {
        int32_t value = values[index];
        if (best_value <= value) {
            best_index = index;
            best_value = value;
        }
    }
    return best_index;
}

size_t game_count_active_stats(const int32_t values[0x56]) {
    size_t count = 0;
    if (values == NULL) {
        return 0;
    }
    for (size_t index = 0; index < 0x56; index++) {
        if (values[index] > 0) {
            count++;
        }
    }
    return count;
}

void clear_ptr(int32_t *pointer) {
    if (pointer != NULL) {
        *pointer = 0;
    }
}

static int32_t read_i32(const uint8_t *pointer) {
    int32_t value;
    memcpy(&value, pointer, sizeof(value));
    return value;
}

static void write_i32(uint8_t *pointer, int32_t value) {
    memcpy(pointer, &value, sizeof(value));
}

int32_t array_get_field4_stride12(const uint8_t *base, size_t index) {
    if (base == NULL) {
        return 0;
    }
    return read_i32(base + 4u + index * 0xcu);
}

void array_set_field4_stride12(uint8_t *base, size_t index, int32_t value) {
    if (base == NULL) {
        return;
    }
    write_i32(base + 4u + index * 0xcu, value);
}

const uint8_t *array_get_stride60(const uint8_t *base, int32_t index) {
    if (base == NULL || index < 0) {
        return NULL;
    }
    return base + 0xdc8 + (size_t)index * 0x60u;
}

const uint8_t *array_get_record28(const uint8_t *primary,
                                  const uint8_t *secondary,
                                  int32_t selector, int32_t index) {
    if (index == -1) {
        return NULL;
    }
    const uint8_t *base = selector == 1 ? primary : secondary;
    if (base == NULL) {
        return NULL;
    }
    return base + (size_t)index * 0x28u;
}

bool building_is_special_type(int32_t type) {
    return type == 4 || type == 5 || type == 0xb || type == 0x21 ||
           type == 0xf;
}

int32_t building_map_subtype_to_state(int32_t subtype) {
    switch (subtype) {
    case 0:
        return 6;
    case 1:
        return 0;
    case 2:
        return 2;
    case 3:
        return 4;
    default:
        return -1;
    }
}

size_t game_get_player_count(const void *const players[6]) {
    if (players == NULL) {
        return 0;
    }
    size_t count = 0;
    for (size_t index = 0; index < 6; index++) {
        if (players[index] != NULL) {
            count++;
        }
    }
    return count;
}

int32_t game_get_player_field8(const void *const players[6], size_t index) {
    if (players == NULL || index >= 6 || players[index] == NULL) {
        return -1;
    }
    return read_i32((const uint8_t *)players[index] + 8u);
}

int32_t game_get_date_field0c(const uint8_t *date) {
    if (date == NULL) {
        return 0;
    }
    return read_i32(date + 0xcu);
}

void game_get_date_fields(const uint8_t *date, uint32_t *day,
                          int32_t *month_times5) {
    if (date == NULL || day == NULL || month_times5 == NULL) {
        return;
    }
    *day = date[7];
    *month_times5 = (int32_t)date[6] * 5;
}

uint32_t game_get_map_value(const uint8_t *map, uint32_t value) {
    if (value == 0xffffffffu || value == 0xfffffffeu) {
        return value;
    }
    if ((int32_t)value < 0 || map == NULL) {
        return 0xffffffffu;
    }
    uint16_t result;
    memcpy(&result, map + 0x2e4f4u + (size_t)value * 2u, sizeof(result));
    return result;
}

int32_t game_get_cost_for_type(int32_t field4, int32_t field8, int32_t type) {
    switch (type) {
    case 0:
        return (field4 * field4) / 10;
    case 1:
        return 0x32;
    case 2:
        return 500;
    case 3:
        return (field8 * field8) / 10;
    default:
        return 0;
    }
}

void array_clear_stride34(uint8_t *base) {
    if (base == NULL) {
        return;
    }
    for (size_t index = 0; index < 8; index++) {
        memset(base + 0x154e + index * 0x34u, 0, 8);
    }
}

void array_copy68(const uint8_t *base, int32_t *destination) {
    if (base == NULL || destination == NULL) {
        return;
    }
    memcpy(destination, base + 0x151c, 0x68u * sizeof(int32_t));
}

void array_search_set(const int32_t ids[3], int32_t *counts, int32_t value) {
    if (ids == NULL || counts == NULL) {
        return;
    }
    for (size_t index = 0; index < 3; index++) {
        if (ids[index] == value) {
            counts[value]++;
        }
    }
}

void array_set_slot(const int32_t ids[3], int32_t *counts, int32_t value,
                    int32_t slot_value) {
    if (ids == NULL || counts == NULL) {
        return;
    }
    for (size_t index = 0; index < 3; index++) {
        if (ids[index] == value) {
            counts[value] = slot_value;
        }
    }
}

void company_compute_totals(int32_t *company) {
    if (company == NULL) {
        return;
    }
    company[0xfc / 4] = company[0x12c / 4] + company[0x128 / 4] +
                        company[0x124 / 4] + company[0x120 / 4];
    company[0x100 / 4] = company[0x14c / 4] + company[0x148 / 4] +
                         company[0x144 / 4] + company[0x140 / 4];
    company[0x104 / 4] = company[0x17c / 4] + company[0x178 / 4] +
                         company[0x174 / 4] + company[0x170 / 4];
    company[0x108 / 4] = company[0x19c / 4] + company[0x198 / 4] +
                         company[0x194 / 4] + company[0x190 / 4];
    company[0x10c / 4] = company[0x16c / 4] + company[0x168 / 4] +
                         company[0x164 / 4] + company[0x160 / 4];
    company[0x110 / 4] = company[0x15c / 4] + company[0x158 / 4] +
                         company[0x154 / 4] + company[0x150 / 4];
    company[0x114 / 4] = company[0x13c / 4] + company[0x138 / 4] +
                         company[0x134 / 4] + company[0x130 / 4];
    company[0x118 / 4] = company[0x18c / 4] + company[0x188 / 4] +
                         company[0x184 / 4] + company[0x180 / 4];
    company[0x11c / 4] = company[0x118 / 4] + company[0xfc / 4] +
                         company[0x100 / 4] + company[0x104 / 4] +
                         company[0x108 / 4] + company[0x10c / 4] +
                         company[0x110 / 4] + company[0x114 / 4];
}

void employee_apply_skill_multipliers(EmployeeSkillMultipliers *employee,
                                      int32_t value, int32_t random_c,
                                      int32_t random_4, int32_t random_8,
                                      int32_t random_10) {
    if (employee == NULL) {
        return;
    }
    employee->value24 = value;
    employee->value28 = ((random_c - 1) * employee->field_c) / 100;
    employee->value2c = ((random_4 - 1) * employee->field4) / 100;
    employee->value30 = ((random_8 - 1) * employee->field8) / 100;
    employee->value34 = ((random_10 - 1) * employee->field_10) / 100;
}

const char *game_get_plan_name(int32_t plan) {
    switch (plan) {
    case 0:
        return "keinen Plan";
    case 1:
        return "schlafen";
    case 3:
        return "komplette KI";
    case 4:
        return "(Filiale)";
    case 5:
        return "neue Filiale kaufen";
    case 6:
        return "Filiale optimieren";
    case 7:
        return "Personal optimieren";
    case 8:
        return "Einrichtung optimieren";
    case 9:
        return "Manager";
    case 10:
        return "Rezepte verbessern";
    case 0xb:
        return "Filialen überprüfen";
    case 0xc:
        return "Lager überprüfen";
    case 0xd:
        return "Wachen überprüfen";
    case 0xe:
        return "Filiale abstoßen";
    case 0xf:
        return "Syndikat";
    case 0x10:
        return "Ärgern";
    case 0x11:
        return "Gangster verwalten";
    case 0x12:
        return "Umfeld anpassen";
    case 0x13:
        return "Werbung schalten";
    case 0x14:
        return "Sicherheit verbessern";
    case 0x15:
        return "Bürgermeister schmieren";
    case 0x16:
        return "HQ überprüfen";
    case 0x17:
        return "Erpressungen überprüfen";
    case 0x18:
        return "Spieler abwickeln";
    default:
        return "Unknown Plan";
    }
}

void clear_field228(uint8_t *object) {
    if (object != NULL) {
        write_i32(object + 0x228, 0);
    }
}

void entity_set_tile_id(uint8_t *entity, int32_t tile_id) {
    if (entity != NULL) {
        write_i32(entity + 0x24, tile_id);
    }
}

void dialog_set_result(uint8_t *dialog, int32_t result) {
    if (dialog == NULL) {
        return;
    }
    write_i32(dialog + 0x280, 1);
    write_i32(dialog + 0x27c, result);
}

uint32_t game_get_global_table_value(size_t index) {
    static const uint32_t table[21] = {
        0x3300ffu, 0xcc0000u, 0x00cc00u, 0x33ffffu, 0xff66ffu,
        0xffff00u, 0x0066ffu, 0x990066u, 0x99cc33u, 0x66ff99u,
        0xcc6666u, 0x009966u, 0x505214u, 0x5eb2ffu, 0xff9900u,
        0x000066u, 0x660000u, 0x003300u, 0x00ccffu, 0xc1ff00u,
        0x000000u,
    };
    return index < 21 ? table[index] : 0;
}

int32_t game_find_city_index(int32_t city_id) {
    static const int32_t table[7] = {
        200, 60927, 16711680, 42496, 13435085, 15197952, 26111,
    };
    for (int32_t index = 0; index < 7; index++) {
        if (table[index] == city_id) {
            return index;
        }
    }
    return 7;
}

const char *game_get_data_by_index(int32_t index) {
    switch (index) {
    case 0:
        return "Kids";
    case 1:
        return "Teens";
    case 2:
        return "Students";
    case 3:
        return "Louts";
    case 4:
        return "Yuppies";
    case 5:
        return "Big shots";
    case 6:
        return "Gothics";
    case 7:
        return "Tourist";
    case 10:
        return "Official";
    case 0xb:
        return "Fat man";
    case 0xc:
        return "Supplier ";
    case 0xd:
        return "Policeman ";
    case 0xe:
        return "Cleaning ";
    case 0xf:
    case 0x21:
        return "Celebrity ";
    case 0x10:
        return "Job-seeker ";
    case 0x11:
        return "Cook ";
    case 0x12:
        return "Manager ";
    case 0x13:
        return "Service ";
    case 0x14:
        return "Errand Boy ";
    case 0x16:
        return "Punk ";
    case 0x17:
        return "Guard ";
    case 0x18:
        return "Mayor ";
    case 0x1a:
        return "Rat ";
    case 0x1b:
        return "Cockroach ";
    case 0x1c:
        return "Woodworm ";
    case 0x1d:
        return "Gangster ";
    case 0x1e:
        return "Thug ";
    case 0x1f:
        return "Courier ";
    case 0x20:
        return "Exterminator ";
    case 0x22:
        return "Flyer Boy ";
    default:
        return "???";
    }
}

int32_t array_find_empty_slot8(const int16_t slots[8][6]) {
    if (slots == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < 8; index++) {
        if (slots[index][0] == -1) {
            return index;
        }
    }
    return -1;
}

void event_queue_set_entry_state22(EventQueueState *queue, int32_t id) {
    if (queue == NULL) {
        return;
    }
    uint32_t index = queue->head;
    if (index != queue->tail) {
        do {
            if (queue->entries[index].id == id) {
                queue->entries[index].state = 0x22;
            }
            index = (index + 1) & 0x3ffu;
        } while (index != queue->tail);
    }
}

char employee_next_sprite_variant(int32_t *variants, size_t index,
                                  int32_t minimum, int32_t maximum) {
    if (variants == NULL) {
        return '1';
    }
    int32_t previous = variants[index];
    if (minimum < maximum) {
        int32_t next = minimum;
        if (previous != maximum) {
            next = previous + 1;
        }
        variants[index] = next;
    }
    if (previous == 1 || previous != 2) {
        return '1';
    }
    return '2';
}

void building_reset_inventory(uint8_t *building, uint8_t *inventory,
                              const int32_t *scenario_table) {
    if (building == NULL || inventory == NULL || scenario_table == NULL) {
        return;
    }
    int32_t index = 0;
    memcpy(&index, inventory + 0x4c, sizeof(index));
    size_t base = (size_t)index * 0x168u;
    int32_t scenario_index = 0;
    memcpy(&scenario_index, building + base + 0x40, sizeof(scenario_index));
    int32_t value = (scenario_table[(size_t)scenario_index * 0x30u] * 50000) /
                    100;
    double amount = (double)value;
    memcpy(inventory + 0x108, &amount, sizeof(amount));

    uint8_t *record = building + base + 0x74;
    for (size_t slot = 0; slot < 10; slot++) {
        int32_t first = -1;
        int32_t last = 0;
        memcpy(record + 0, &first, sizeof(first));
        memcpy(record + 12, &last, sizeof(last));
        record += 16;
    }
    int32_t state = 3;
    memcpy(building + base + 0x12c, &state, sizeof(state));
}

int32_t array_find_index_stride60(const uint8_t *base,
                                   const uint8_t *target) {
    if (base == NULL || target == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < 4; index++) {
        if (base + 0xdc8 + (size_t)index * 0x60u == target) {
            return index;
        }
    }
    return -1;
}

void entity_apply_type_properties(EntityProperties *entity, int32_t type,
                                  const EntityTypeProperties *table,
                                  size_t count) {
    if (entity == NULL) {
        return;
    }
    entity->type = type;
    if (table == NULL || count == 0) {
        return;
    }
    const EntityTypeProperties *match = NULL;
    if (table[0].id == type) {
        match = &table[0];
    } else {
        for (size_t index = 1; index < count; index++) {
            if (table[index].id == -1) {
                return;
            }
            if (table[index].id == type) {
                match = &table[index];
                break;
            }
        }
    }
    if (match != NULL) {
        entity->field40 = match->field40;
        entity->field44 = match->field44;
        entity->field48 = match->field48;
    }
}

bool city_is_idle(const uint8_t *city) {
    if (city == NULL) {
        return true;
    }
    uintptr_t pointer = 0;
    memcpy(&pointer, city + 0x16f0, sizeof(pointer));
    if (pointer == 0) {
        return true;
    }
    int32_t flag = 0;
    memcpy(&flag, (const void *)pointer + 0x94, sizeof(flag));
    return flag != 0;
}

static const void *array_get_pointer(const void *const *values, size_t count,
                                     int32_t index) {
    if (values == NULL || index < 0 || (size_t)index >= count) {
        return NULL;
    }
    return values[index];
}

const void *array_get_ptr(const void *const *values, size_t count,
                          int32_t index) {
    return array_get_pointer(values, count, index);
}

const void *array_get_ptr4(const void *const *values, size_t count,
                           int32_t index) {
    return array_get_pointer(values, count, index);
}

const void *array_get_ptr_checked(const void *const *values, size_t count,
                                  int32_t index) {
    return array_get_pointer(values, count, index);
}

uint8_t font_get_char_width(const FntInfo *font, uint8_t character) {
    if (font == NULL || character < 0x20) {
        return 0;
    }
    uint32_t index = (uint32_t)character - 0x20u;
    if (index >= FNT_GLYPH_COUNT) {
        return 0;
    }
    return font->advances[index];
}

int32_t font_measure_text(const FntInfo *font, const char *text) {
    if (font == NULL || text == NULL) {
        return 0;
    }
    int32_t width = 0;
    for (size_t index = 0; text[index] != '\0'; index++) {
        uint8_t character = (uint8_t)text[index];
        uint32_t glyph = (uint32_t)character - 0x20u;
        width += glyph < FNT_GLYPH_COUNT ? font->advances[glyph]
                                         : font->advances[0];
    }
    return width;
}

int32_t font_measure_range(const FntInfo *font, const char *text,
                           int32_t start, int32_t end) {
    if (font == NULL || text == NULL || start < 0 || end <= start) {
        return 0;
    }
    int32_t width = 0;
    for (int32_t index = start; index < end && text[index] != '\0'; index++) {
        uint8_t character = (uint8_t)text[index];
        uint32_t glyph = (uint32_t)character - 0x20u;
        width += glyph < FNT_GLYPH_COUNT ? font->advances[glyph]
                                         : font->advances[0];
    }
    return width;
}

void game_clock_reset(uint8_t *clock, uint16_t calendar_state) {
    if (clock == NULL) {
        return;
    }
    uint16_t state = calendar_state;
    memcpy(clock + 4, &state, sizeof(state));
    clock[6] = 0;
    clock[7] = 0;
    clock[8] = 0;
    clock[0x18] = 0;
    clock[0x19] = 0;
    uint16_t zero16 = 0;
    memcpy(clock + 10, &zero16, sizeof(zero16));
    int32_t zero32 = 0;
    memcpy(clock + 0x0c, &zero32, sizeof(zero32));
    memcpy(clock + 0x10, &zero32, sizeof(zero32));
}

int32_t economy_apply_table_percent(const int32_t *table, int32_t row,
                                    int32_t index, int32_t value) {
    if (table == NULL) {
        return 0;
    }
    return (table[row * 9 + index] * value) / 100;
}

int32_t economy_get_modifier(int32_t type, int32_t index,
                             const EconomyModifierState *state) {
    if (state == NULL) {
        return 0;
    }
    static const int32_t table_17[24] = {
        0, 40, 120, 0, 20, 100, 0, 30, 200, 0, 40, 300,
        0, 20000, 50000, 0, 0, 5, 10, 0, 5, 10, 15, 5,
    };
    static const int32_t table_1d[24] = {
        100, 30, 70, 0, 20, 60, 0, 30, 90, 0, 40, 120,
        0, 20, 100, 0, 30, 200, 0, 40, 300, 0, 20000, 50000,
    };
    int32_t value = 0;
    if (type == 0x17) {
        value = table_17[index + state->row * 3];
        if (index == 1) {
            for (int32_t count = state->count_168; count > 0; count--) {
                value = (value * 15) / 10;
            }
            for (int32_t count = state->count_24c; count > 0; count--) {
                value = (value * 9) / 10;
            }
        } else if (index == 2) {
            for (int32_t count = state->count_164; count > 0; count--) {
                value = (value * 15) / 10;
            }
            for (int32_t count = state->count_248; count > 0; count--) {
                value = (value * 9) / 10;
            }
        }
    } else if (type == 0x1d) {
        value = table_1d[index + state->row * 3];
        if (index == 1) {
            for (int32_t count = state->count_a8; count > 0; count--) {
                value = (value * 15) / 10;
            }
            for (int32_t count = state->count_18c; count > 0; count--) {
                value = (value * 9) / 10;
            }
        }
    }
    return value;
}

const char *economy_get_modifier_message(int32_t row, int32_t index) {
    if (row != 0) {
        return NULL;
    }
    switch (index) {
    case 0:
        return "can't perform action";
    case 1:
        return "warning";
    case 2:
        return "fatal error";
    default:
        return NULL;
    }
}

void game_plan_construct(GamePlanState *plan) {
    if (plan == NULL) {
        return;
    }
    memset(plan, 0, sizeof(*plan));
    plan->fields[2] = 2;
    plan->fields[7] = -1;
    plan->fields[0xb] = -1;
    plan->fields[3] = -1;
}

void leaf_construction_order_construct(ConstructionOrderState *order,
                                  int32_t field4, int32_t field8) {
    if (order == NULL) {
        return;
    }
    memset(order, 0, sizeof(*order));
    order->fields[1] = field4;
    order->fields[2] = field8;
    order->fields[3] = 100;
    order->fields[5] = -1;
    order->fields[6] = -1;
    order->fields[7] = -1;
}

void furniture_type_construct(FurnitureTypeState *type) {
    if (type == NULL) {
        return;
    }
    memset(type, 0, sizeof(*type));
    type->fields[2] = 12;
    type->fields[3] = 11;
    type->fields[4] = 4;
    type->fields[5] = 3;
    type->fields[0x1c] = 0;
    type->fields[0x1d] = 0;
    for (size_t index = 0; index < 8; index++) {
        size_t base = 0x1e + index * 3;
        type->fields[base] = -1;
        type->fields[base + 1] = -1;
        type->fields[base + 2] = 0;
    }
}

void furniture_type_destroy(FurnitureTypeState *type) {
    if (type != NULL) {
        type->vtable = 0;
    }
}

const void *game_get_player_by_slot(const void *const players[6],
                                    int32_t slot) {
    if (players == NULL || slot < 0 || slot > 5) {
        return NULL;
    }
    return players[slot];
}

int32_t game_get_current_player_company_name(const void *const players[6],
                                             int32_t current_slot) {
    if (players == NULL || current_slot < 0 || current_slot > 5 ||
        players[current_slot] == NULL) {
        return -1;
    }
    return read_i32((const uint8_t *)players[current_slot] + 8u);
}

const void *game_get_player_city(const void *const players[6], int32_t index) {
    if (players == NULL || index < 0 || index > 5) {
        return NULL;
    }
    return players[index];
}

int32_t game_find_player_slot(const void *const players[6],
                              const void *player) {
    if (players == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < 6; index++) {
        if (players[index] == player) {
            return index;
        }
    }
    return -1;
}

int32_t game_find_group_slot(const int16_t slots[6], int16_t value) {
    if (slots == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < 6; index++) {
        if (slots[index] == value) {
            return index;
        }
    }
    return -1;
}

size_t game_count_group_slots(const int16_t slots[6]) {
    if (slots == NULL) {
        return 0;
    }
    size_t count = 0;
    while (count < 6 && slots[count] != -1) {
        count++;
    }
    return count;
}

const void *game_get_city_data(const void *const *table, size_t count,
                               int32_t index) {
    if (table == NULL || index < 0 || (size_t)index >= count) {
        return NULL;
    }
    return table[index];
}

void object_get_pair10(const uint8_t *object, int32_t *field10,
                       int32_t *field14) {
    if (object == NULL || field10 == NULL || field14 == NULL) {
        return;
    }
    *field10 = read_i32(object + 0x10);
    *field14 = read_i32(object + 0x14);
}

void object_get_pair4(const uint8_t *object, int32_t *field4,
                      int32_t *field8) {
    if (object == NULL || field4 == NULL || field8 == NULL) {
        return;
    }
    *field4 = read_i32(object + 4);
    *field8 = read_i32(object + 8);
}

int32_t record_get_value48(const uint8_t *records, size_t count,
                           size_t index) {
    if (records == NULL || index >= count) {
        return 0;
    }
    const uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return 0;
    }
    int16_t value = 0;
    memcpy(&value, record + 0x32, sizeof(value));
    return value;
}

bool record_set_index48(uint8_t *records, size_t count, size_t index,
                        int32_t value, size_t value_limit) {
    if (records == NULL || index >= count || value < 0 ||
        (size_t)value >= value_limit) {
        return false;
    }
    uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return false;
    }
    int16_t short_value = (int16_t)value;
    memcpy(record + 0x32, &short_value, sizeof(short_value));
    return true;
}

bool record_get_rect98(const uint8_t *records, size_t index,
                       int32_t pairs[8]) {
    if (records == NULL || pairs == NULL) {
        return false;
    }
    const uint8_t *record = records + index * 0x98u;
    pairs[0] = read_i32(record + 0x70);
    pairs[1] = read_i32(record + 0x74);
    pairs[2] = read_i32(record + 0x78);
    pairs[3] = read_i32(record + 0x7c);
    pairs[4] = read_i32(record + 0x60);
    pairs[5] = read_i32(record + 0x64);
    pairs[6] = read_i32(record + 0x68);
    pairs[7] = read_i32(record + 0x6c);
    return true;
}

int32_t game_get_active_screen_or_fallback(const uint8_t *game) {
    if (game == NULL) {
        return 0;
    }
    int32_t active = read_i32(game + 0x270);
    if (active == 0) {
        active = read_i32(game + 0x264);
    }
    return active;
}

void palette_convert256(const uint8_t *rgb, uint16_t *output, bool rgb565) {
    if (rgb == NULL || output == NULL) {
        return;
    }
    for (size_t index = 0; index < 256; index++) {
        uint8_t red = rgb[index * 3 + 0];
        uint8_t green = rgb[index * 3 + 1];
        uint8_t blue = rgb[index * 3 + 2];
        if (rgb565) {
            output[index] = (uint16_t)((((uint16_t)(red & 0xf8u) << 5) |
                                        (uint16_t)(green & 0xf8u))
                                       << 3 |
                                       (uint16_t)(blue >> 3));
        } else {
            output[index] = (uint16_t)((((uint16_t)(red & 0xf8u) << 5) |
                                        (uint16_t)(green & 0xf8u))
                                       << 2 |
                                       (uint16_t)(blue >> 3));
        }
    }
}

int32_t palette_find_index(const uint8_t *const *palettes, size_t count,
                           const uint8_t *candidate) {
    if (palettes == NULL || candidate == NULL) {
        return -1;
    }
    for (size_t index = 0; index < count; index++) {
        if (palettes[index] != NULL &&
            memcmp(palettes[index], candidate, 768) == 0) {
            return (int32_t)index;
        }
    }
    return -1;
}

int32_t record_get_type_index48(const uint8_t *records, size_t count,
                                size_t index, const uint8_t *sources) {
    if (records == NULL || sources == NULL || index >= count) {
        return -1;
    }
    int32_t type_index = read_i32(records + index * 0x48u);
    if (type_index < 0 ||
        sources[(size_t)type_index * 0x98u + 0x80] == 0) {
        return -1;
    }
    return type_index;
}

void game_plan_destructor(GamePlanState *plan) {
    if (plan != NULL) {
        plan->fields[0] = 0;
    }
}

void leaf_construction_order_destructor(ConstructionOrderState *order) {
    if (order != NULL) {
        order->fields[0] = 0;
    }
}

void award_node_destructor(void *node) {
    if (node != NULL) {
        write_i32(node, 0);
    }
}

void building_value_destroy(void *value) {
    if (value != NULL) {
        write_i32(value, 0);
    }
}

int64_t math_round_float(float value) {
    if (value >= 0.0f) {
        return (int64_t)(value + 0.5f);
    }
    return (int64_t)(value - 0.5f);
}

int64_t math_truncate_double(double value) {
    return (int64_t)value;
}

int32_t math_piecewise_linear(int32_t value) {
    if (value < 0x32) {
        return (value * 0x12) / 0x19;
    }
    return ((value - 0x32) * 0x20) / 0x19 + 0x24;
}

void string_skip_delimiters(const char *buffer, size_t *index) {
    if (buffer == NULL || index == NULL) {
        return;
    }
    while (buffer[*index] == ' ' || buffer[*index] == '\t' ||
           buffer[*index] == ',') {
        (*index)++;
    }
}

void text_skip_field_separators(const char *buffer, size_t *index) {
    if (buffer == NULL || index == NULL) {
        return;
    }
    for (;;) {
        char character = buffer[*index];
        if (character == '}' || character == '\0' ||
            (character > ' ' && character != ',')) {
            break;
        }
        (*index)++;
    }
}

int32_t text_get_line_height(const uint8_t *text) {
    if (text == NULL) {
        return 0;
    }
    return read_i32(text + 0x9b8);
}

void text_get_position(const uint8_t *text, int32_t *x, int32_t *y) {
    if (text == NULL || x == NULL || y == NULL) {
        return;
    }
    *x = read_i32(text + 0x9a0);
    *y = read_i32(text + 0x9a4);
}

void text_set_cursor(uint8_t *text, int32_t x, int32_t y) {
    if (text == NULL) {
        return;
    }
    write_i32(text + 0x9a0, x);
    write_i32(text + 0x9a4, y);
}

void text_set_metrics(uint8_t *text, int32_t x, int32_t y, int32_t param3) {
    if (text == NULL) {
        return;
    }
    int32_t previous_y = read_i32(text + 0x9b4);
    int32_t delta = y - previous_y;
    write_i32(text + 0x9a0, x);
    write_i32(text + 0x9bc, x);
    write_i32(text + 0x9a8, x);
    write_i32(text + 0x9a4, delta);
    write_i32(text + 0x9c0, delta);
    write_i32(text + 0x9ac, delta);
    write_i32(text + 0x9c4, param3);
}

void text_set_metrics2(uint8_t *text, int32_t x, int32_t y, int32_t param3) {
    if (text == NULL) {
        return;
    }
    write_i32(text + 0x9a0, x);
    write_i32(text + 0x9bc, x);
    write_i32(text + 0x9a8, x);
    write_i32(text + 0x9a4, y);
    write_i32(text + 0x9c0, y);
    write_i32(text + 0x9ac, y);
    write_i32(text + 0x9c4, param3);
}

bool record_get_bounds48(const uint8_t *records, size_t index,
                         const int16_t *x_points, const int16_t *y_points,
                         const uint16_t *widths, const uint16_t *heights,
                         int32_t *x, int32_t *y, uint32_t *width,
                         uint32_t *height) {
    if (records == NULL || x_points == NULL || y_points == NULL ||
        widths == NULL || heights == NULL || x == NULL || y == NULL ||
        width == NULL || height == NULL) {
        return false;
    }
    int16_t point = 0;
    memcpy(&point, records + index * 0x48u + 0x32, sizeof(point));
    *x = x_points[point];
    *y = y_points[point];
    *width = widths[point];
    *height = heights[point];
    return true;
}

bool record_get_pair_positions(const uint8_t *records, size_t index,
                               int32_t pairs[4]) {
    if (records == NULL || pairs == NULL) {
        return false;
    }
    const uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return false;
    }
    pairs[0] = read_i32(record + 0x18);
    pairs[1] = read_i32(record + 0x1c);
    pairs[2] = read_i32(record + 0x20);
    pairs[3] = read_i32(record + 0x24);
    return true;
}

bool record_set_doubles48(uint8_t *records, size_t count, size_t index,
                          double first, double second) {
    if (records == NULL || index >= count) {
        return false;
    }
    uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return false;
    }
    memcpy(record + 8, &first, sizeof(first));
    memcpy(record + 0x10, &second, sizeof(second));
    return true;
}

bool record_set_rect48(uint8_t *records, size_t count, size_t index,
                       int32_t first, int32_t second, uint64_t value) {
    if (records == NULL || index >= count) {
        return false;
    }
    uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return false;
    }
    write_i32(record + 8, first);
    write_i32(record + 12, second);
    memcpy(record + 0x10, &value, sizeof(value));
    return true;
}

static double read_double(const uint8_t *pointer) {
    double value;
    memcpy(&value, pointer, sizeof(value));
    return value;
}

bool record_get_screen_rect48(const uint8_t *records, size_t index,
                              const uint16_t *widths,
                              const uint16_t *heights, int32_t *x,
                              int32_t *y) {
    if (records == NULL || widths == NULL || heights == NULL || x == NULL ||
        y == NULL) {
        return false;
    }
    const uint8_t *record = records + index * 0x48u;
    int16_t point = 0;
    memcpy(&point, record + 0x32, sizeof(point));
    int64_t offset_x = math_truncate_double(read_double(record + 8));
    int64_t offset_y = math_truncate_double(read_double(record + 0x10));
    *x = (int32_t)widths[point] + (int32_t)offset_x;
    *y = (int32_t)heights[point] + (int32_t)offset_y;
    return true;
}

bool record_get_screen_offset(const uint8_t *records, size_t count,
                              size_t index, const int16_t *x_points,
                              const uint16_t *widths,
                              const uint16_t *heights, int32_t *x,
                              int32_t *y) {
    if (records == NULL || x_points == NULL || widths == NULL ||
        heights == NULL || x == NULL || y == NULL || index >= count) {
        return false;
    }
    const uint8_t *record = records + index * 0x48u;
    if (read_i32(record) == -1) {
        return false;
    }
    int16_t point = 0;
    memcpy(&point, record + 0x32, sizeof(point));
    int64_t offset_x = math_truncate_double(read_double(record + 8));
    int64_t offset_y = math_truncate_double(read_double(record + 0x10));
    *x = (int32_t)offset_x + ((int32_t)x_points[point] >> 2) +
         (int32_t)widths[point];
    *y = (int32_t)heights[point] + (int32_t)offset_y;
    return true;
}

int32_t object_get_id(const uint8_t *object) {
    if (object == NULL) {
        return -1;
    }
    return read_i32(object + 4);
}

int32_t object_get_field0c(const uint8_t *object) {
    return object == NULL ? 0 : read_i32(object + 0x0c);
}

int32_t object_get_field10(const uint8_t *object) {
    return object == NULL ? 0 : read_i32(object + 0x10);
}

void object_set_field0c(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x0c, value);
    }
}

void object_set_field8(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 8, value);
    }
}

void object_set_field_fc(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0xfc, value);
    }
}

void object_set_short28(uint8_t *object, int16_t value) {
    if (object != NULL) {
        memcpy(object + 0x28, &value, sizeof(value));
    }
}

void object_get_pair68(const uint8_t *object, int32_t *first, int32_t *second) {
    if (object == NULL || first == NULL || second == NULL) {
        return;
    }
    *first = read_i32(object + 0x68);
    *second = read_i32(object + 0x6c);
}

void object_get_rect100(const uint8_t *object, int32_t rect[4]) {
    if (object == NULL || rect == NULL) {
        return;
    }
    rect[0] = read_i32(object + 0x100);
    rect[1] = read_i32(object + 0x108);
    rect[2] = read_i32(object + 0x104);
    rect[3] = read_i32(object + 0x10c);
}

void object_set_flag104(uint8_t *object, uint8_t value) {
    if (object != NULL) {
        object[0x104] = value;
    }
}

uint32_t sprite_get_color_key(const uint8_t *sprite) {
    if (sprite == NULL) {
        return 0;
    }
    if ((sprite[4] & 0x10u) == 0) {
        return (uint32_t)read_i32(sprite + 0x1c);
    }
    return 0;
}

uint8_t sprite_get_format(const uint8_t *sprite) {
    return sprite == NULL ? 0 : sprite[4];
}

void sprite_get_size(const uint8_t *sprite, int32_t *width, int32_t *height) {
    if (sprite == NULL || width == NULL || height == NULL) {
        return;
    }
    int32_t stored_width;
    memcpy(&stored_width, sprite + 6, sizeof(int16_t));
    if (sprite[5] > 0xe) {
        stored_width >>= 1;
    }
    int32_t stored_height;
    memcpy(&stored_height, sprite + 8, sizeof(int16_t));
    if (read_i32(sprite + 0x30) != 0 && sprite[0x37] != 0) {
        *width = stored_height;
        *height = stored_width;
    } else {
        *width = stored_width;
        *height = stored_height;
    }
}

void sprite_get_hotspot(const uint8_t *sprite, int32_t *x, int32_t *y) {
    if (sprite == NULL || x == NULL || y == NULL) {
        return;
    }
    if ((sprite[4] & 4u) == 0) {
        *x = 0;
        *y = 0;
        return;
    }
    int16_t hotspot_x;
    int16_t hotspot_y;
    memcpy(&hotspot_x, sprite + 10, sizeof(hotspot_x));
    memcpy(&hotspot_y, sprite + 12, sizeof(hotspot_y));
    *x = hotspot_x;
    *y = hotspot_y;
}

void sprite_set_hotspot(uint8_t *sprite, int16_t x, int16_t y) {
    if (sprite != NULL && (sprite[4] & 4u) != 0) {
        memcpy(sprite + 10, &x, sizeof(x));
        memcpy(sprite + 12, &y, sizeof(y));
    }
}

void sprite_set_color_key(uint8_t *sprite, uint32_t color_key) {
    if (sprite != NULL) {
        write_i32(sprite + 0x1c, (int32_t)color_key);
        sprite[4] |= 2;
    }
}

int32_t game_get_speed_setting(const uint8_t *game) {
    if (game == NULL) {
        return 1;
    }
    if (read_i32(game + 0x2e1c) < 0x41 || read_i32(game + 0x2e20) < 8) {
        return 1;
    }
    return 2;
}

uint32_t game_get_starting_capital(int32_t difficulty) {
    static const uint32_t table[10] = {
        1000000, 500000, 200000, 100000, 75000,
        50000, 40000, 30000, 25000, 22000,
    };
    if (difficulty < 0 || difficulty > 9) {
        return 20000;
    }
    return table[difficulty];
}

uint32_t game_get_time_segment(const uint8_t *date) {
    return date == NULL ? 0 : (uint32_t)date[7] / 3u;
}

void game_get_year_and_weekday(const uint8_t *date, uint32_t *year,
                               uint32_t *weekday) {
    if (date == NULL || year == NULL || weekday == NULL) {
        return;
    }
    *year = date[8];
    uint16_t weekday_value;
    memcpy(&weekday_value, date + 4, sizeof(weekday_value));
    *weekday = weekday_value;
}

bool state_is_1a_1b_1c(const uint8_t *object) {
    if (object == NULL) {
        return false;
    }
    int32_t state = read_i32(object + 0x30);
    return state == 0x1a || state == 0x1b || state == 0x1c;
}

bool state_is_2d_or_2e(const uint8_t *object) {
    if (object == NULL) {
        return false;
    }
    int32_t state = read_i32(object + 0x38);
    return state == 0x2d || state == 0x2e;
}

bool state_is_menu_state(const uint8_t *object) {
    if (object == NULL) {
        return false;
    }
    int32_t state = read_i32(object + 0x30);
    return state == 0x0d || state == 0x17 || state == 0x1d || state == 0x1e;
}

bool is_special_id_range(int32_t id) {
    return id >= 0x84c && id <= 0x857;
}

bool object_is_id_in_840_range(int32_t id) {
    return id >= 0x840 && id <= 0x84b;
}

bool object_is_known_id(int32_t id) {
    if (id == -1) {
        return true;
    }
    if (id > 0x355 && id < 0x603) {
        return true;
    }
    return id >= 0x19 && id <= 0x20;
}

bool is_menu_id_352(int32_t id) {
    return id == 0x352;
}

bool is_menu_id_351_or_355(int32_t id) {
    return id == 0x351 || id == 0x355;
}

bool is_menu_id_34e_or_350(int32_t id) {
    return id == 0x34e || id == 0x350;
}

bool is_menu_id_range(int32_t id) {
    return id == 0x34d || id == 0x34e || id == 0x34f || id == 0x352 ||
           id == 0x353 || id == 0x354 || id == 0x350 || id == 0x355 ||
           id == 0x351;
}

bool product_has_stock(const int32_t *counts, uint8_t index) {
    return counts != NULL && counts[index] > 0;
}

double stats_get_amount_by_type(int32_t type) {
    switch (type) {
    case 0:
        return 576.0;
    case 1:
        return 2322.0;
    case 2:
        return 1368.0;
    case 3:
        return 1656.0;
    default:
        return 0.0;
    }
}

int32_t storage_get_capacity(int32_t value) {
    return value * 0xf + 0x24;
}

int32_t supplier_get_value_plus_one(const int32_t *table, int32_t index) {
    if (index == 0) {
        return 0;
    }
    return table[index] + 1;
}

int32_t rating_get_inverse100(int32_t value) {
    int32_t result = value * -3 + 100;
    return result < 0 ? 0 : result;
}

uint8_t object_get_byte36_max7(const uint8_t *object) {
    if (object == NULL) {
        return 0;
    }
    uint8_t value = 0;
    memcpy(&value, object + 0x36, sizeof(value));
    return value > 7 ? 0 : value;
}

int32_t index_map8to5(const int32_t values[8], int32_t index) {
    int32_t value = 0;
    if (values == NULL) {
        return 0;
    }
    if (index == 8) {
        index = 5;
    }
    if (index == -1) {
        int32_t sum = 0;
        for (size_t slot = 0; slot < 8; slot++) {
            sum += values[slot];
        }
        value = (sum + ((sum >> 31) & 7)) >> 3;
    } else {
        value = values[index];
    }
    if (value < 0) {
        return 0;
    }
    return value > 100 ? 100 : value;
}

uint8_t stats_get_level_from_four_counters(int32_t sum) {
    if (sum > 4) {
        return 3;
    }
    if (sum < 3) {
        return sum > 0 ? 1 : 0;
    }
    return 2;
}

uint8_t stats_get_level_from_ten_counters(uint32_t sum) {
    if (sum > 5) {
        return 3;
    }
    if (sum < 4) {
        return sum > 0 ? 1 : 0;
    }
    return 2;
}

int32_t stats_get_matrix_variant_value(const uint8_t *object,
                                        int32_t variant, int32_t row,
                                        int32_t column) {
    if (object == NULL) {
        return variant == 0 || variant == 1 || variant == 2 || variant == 3
                   ? 0
                   : row;
    }
    size_t base;
    switch (variant) {
    case 0:
        base = 5000;
        break;
    case 1:
        base = 0x13d0;
        break;
    case 2:
        base = 0x1418;
        break;
    case 3:
        base = 0x1460;
        break;
    default:
        return row;
    }
    return read_i32(object + base + (size_t)(column + row * 9) * 4u);
}

int32_t stats_get_or_sum_series(const uint8_t *object, int32_t series,
                                int32_t index) {
    if (object == NULL) {
        return 0;
    }
    if (index != -1) {
        return read_i32(object + (size_t)(index + series * 100) * 4u + 0x44);
    }
    int32_t sum = 0;
    for (int32_t slot = 0; slot < 100; slot++) {
        sum += read_i32(object + (size_t)(series * 100 + slot) * 4u + 0x44);
    }
    return sum;
}

int32_t map_get_2d_table_value(const uint8_t *object, int32_t table,
                               int32_t row, int32_t column) {
    if (object == NULL) {
        return 0;
    }
    size_t base;
    if (table == 0) {
        base = 0x2bf4c;
    } else if (table == 1) {
        base = 0x2c234;
    } else {
        return 0;
    }
    return read_i32(object + base + (size_t)(row * 0x30 + column) * 4u);
}

const uint8_t *grid_get_cell(const uint8_t *grid, int32_t x, int32_t y) {
    if (grid == NULL) {
        return NULL;
    }
    int32_t width = read_i32(grid + 0x1c);
    int32_t height = read_i32(grid + 0x20);
    if (x < 0 || y < 0 || x >= width || y >= height) {
        return NULL;
    }
    uintptr_t base;
    memcpy(&base, grid + 0x4c, sizeof(base));
    return (const uint8_t *)(base + (size_t)(width * y + x) * 0xc);
}

float grid_get_max_value(const float *values) {
    if (values == NULL) {
        return 0.0f;
    }
    float maximum = 0.0f;
    for (size_t index = 0; index < 72; index++) {
        if (maximum < values[index]) {
            maximum = values[index];
        }
    }
    return maximum;
}

int32_t global_array_find_index(const int32_t *values, int32_t count,
                                int32_t key) {
    if (values == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < count; index++) {
        if (values[index] == key) {
            return index;
        }
    }
    return -1;
}

int32_t global_array_find_int(const int32_t *values, int32_t count,
                              int32_t key) {
    return global_array_find_index(values, count, key);
}

int32_t save_list_find_index(const int32_t *values, int32_t count,
                             int32_t key) {
    return global_array_find_index(values, count, key);
}

int32_t market_get_price_modifier(const int32_t *values, int32_t row,
                                  int32_t column) {
    if (values == NULL) {
        return 0;
    }
    int32_t value = values[column + 0xa0 + row * 8];
    if (value == 0) {
        return 0;
    }
    return value != 1 ? -10 : 10;
}

void map_compute_iso_offsets(uint8_t *map) {
    if (map == NULL) {
        return;
    }
    int32_t tile_width = read_i32(map + 0x0c);
    int32_t tile_height = read_i32(map + 0x10);
    write_i32(map + 0xd8, tile_width << 1);
    write_i32(map + 0xdc, tile_width << 1);
    write_i32(map + 0xe0, tile_height * 2);
    write_i32(map + 0xe4, tile_height * 3);
}

int32_t map_compute_object_distance(const uint8_t *map, int32_t x1, int32_t y1,
                                    int32_t x2, int32_t y2, int32_t index) {
    if (map == NULL || index < 0) {
        return 1000000;
    }
    int32_t width = read_i32(map + 0x1c);
    int32_t height = read_i32(map + 0x20);
    if (width * height < index) {
        return 1000000;
    }
    uintptr_t points;
    memcpy(&points, map + 0x4c, sizeof(points));
    const uint8_t *point = (const uint8_t *)points + (size_t)index * 0x0c;
    int32_t point_x = read_i32(point);
    int32_t point_y = read_i32(point + 4);
    int32_t tile_width = read_i32(map + 0x0c);
    int32_t tile_height = read_i32(map + 0x10);
    int32_t dx = ((tile_width >> 1) - x1 - x2) + point_x;
    int32_t dy = (((tile_height >> 1) + point_y) - y1 - y2) + tile_height;
    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }
    return dx * 3 + dy * 4;
}

int32_t object_get_root_type(const uint8_t *object) {
    if (object == NULL) {
        return -1;
    }
    int32_t type = read_i32(object + 0x4c);
    while (type == 3) {
        uintptr_t parent;
        memcpy(&parent, object + 0x54, sizeof(parent));
        object = (const uint8_t *)parent;
        type = read_i32(object + 0x4c);
    }
    return type;
}

int32_t object_get_child_field14(const uint8_t *object) {
    if (object == NULL) {
        return 0;
    }
    uintptr_t child;
    memcpy(&child, object + 0x14, sizeof(child));
    return child == 0 ? 0 : read_i32((const uint8_t *)child);
}

int32_t object_get_child_field2c(const uint8_t *object) {
    if (object == NULL) {
        return 0;
    }
    uintptr_t child;
    memcpy(&child, object + 200, sizeof(child));
    return child == 0 ? 0 : read_i32((const uint8_t *)child + 0x2c);
}

int32_t object_get_clamped_level(uint8_t *object) {
    if (object == NULL) {
        return 0;
    }
    int32_t level = read_i32(object + 0x10c);
    if (level < 1 || level > 3) {
        level = 1;
        write_i32(object + 0x10c, level);
    }
    return level;
}

uint32_t object_get_active_value(const uint8_t *object) {
    if (object == NULL) {
        return 0;
    }
    uint32_t active = (uint32_t)read_i32(object + 0x6c);
    if (active == 0) {
        return (uint32_t)read_i32(object + 0x68);
    }
    return read_i32(object + 0x78) != 0 ? active : 0;
}

void object_set_child_field2c(uint8_t *object, int32_t value) {
    if (object == NULL) {
        return;
    }
    uintptr_t child;
    memcpy(&child, object + 200, sizeof(child));
    if (child != 0) {
        write_i32((uint8_t *)child + 0x2c, value);
    }
}

void object_set_child_short(uint8_t *object) {
    if (object == NULL) {
        return;
    }
    uintptr_t child;
    memcpy(&child, object + 200, sizeof(child));
    if (child != 0) {
        int16_t value = -1;
        memcpy((uint8_t *)child + 8, &value, sizeof(value));
    }
}

void object_set_child_short8(uint8_t *object, int16_t value) {
    if (object == NULL) {
        return;
    }
    uintptr_t child;
    memcpy(&child, object + 200, sizeof(child));
    if (child != 0) {
        int16_t current;
        memcpy(&current, (uint8_t *)child + 8, sizeof(current));
        if (current != value) {
            memcpy((uint8_t *)child + 8, &value, sizeof(value));
        }
    }
}

void object_reset108(uint8_t *object) {
    if (object == NULL) {
        return;
    }
    write_i32(object + 0x108, -1);
    write_i32(object + 0x8c, -1);
}

void object_clear_field28(uint8_t *object) {
    if (object != NULL) {
        write_i32(object + 0x28, 0);
    }
}

void object_clear_field4(uint8_t *object) {
    if (object != NULL) {
        write_i32(object + 4, 0);
    }
}

void object_clear_field54(uint8_t *object) {
    if (object != NULL) {
        write_i32(object + 0x54, 0);
    }
}

void object_clear_fields_a(uint8_t *object) {
    if (object == NULL) {
        return;
    }
    static const size_t offsets[7] = {0x54, 0x58, 0x70, 0x9c, 0x78, 0x6c, 100};
    for (size_t index = 0; index < 7; index++) {
        write_i32(object + offsets[index], 0);
    }
}

void object_clear_state(uint8_t *object) {
    if (object == NULL) {
        return;
    }
    uintptr_t child;
    memcpy(&child, object + 8, sizeof(child));
    if (child == 0) {
        return;
    }
    uint8_t *state = (uint8_t *)child;
    write_i32(state + 0x1c, -1);
    state[0x2c] = 0;
    state[0x2d] = 0;
    state[0x2e] = 0;
    state[0x2f] = 0;
}

bool map_clamp_scroll_y(uint8_t *map, int32_t requested, int32_t scroll_mode) {
    if (map == NULL) {
        return false;
    }
    int32_t previous = read_i32(map + 0xec);
    int32_t minimum = read_i32(map + 0x30) - read_i32(map + 0x10174);
    int32_t current = requested;
    if (current < minimum) {
        current = minimum;
    }
    int32_t maximum;
    if (scroll_mode == 2) {
        maximum = read_i32(map + 0x10170) - 0x38 + read_i32(map + 0x38);
    } else {
        maximum = read_i32(map + 0x38) + read_i32(map + 0x10170);
    }
    if (current > maximum) {
        current = maximum;
    }
    write_i32(map + 0xec, current);
    return previous != current;
}

uint32_t market_get_price_delta(uint8_t class_byte, int32_t table_value) {
    if (class_byte == 0 || class_byte >= 7) {
        return 0;
    }
    if (table_value == -1) {
        return 0xffffffd8u;
    }
    return table_value != 0 ? 0x28u : 0;
}

double rating_get_float(float rating, int32_t type, int32_t difficulty) {
    double base = (double)(0xb - difficulty) * 0.5;
    double value = rating;
    switch (type) {
    case 0:
        return value * 3.0 + base + 4.0;
    case 1:
        return value * 4.0 + base + 5.0;
    case 2:
        return value * 4.0 + base + 8.0;
    case 3:
        return value * 3.0 + base + 8.0;
    case 4:
        return value * 7.0 + base + 10.0;
    case 5:
    case 8:
        return value * 10.0 + base + 8.0;
    case 6:
        return value * 3.0 + base + 7.0;
    case 7:
        return base + 12.0;
    default:
        return base;
    }
}

int32_t game_get_player_quarter_stat(const uint8_t *object, int32_t index,
                                     int32_t type) {
    if (object == NULL) {
        return 0;
    }
    size_t offset;
    switch (type) {
    case 0:
        offset = 0x200;
        break;
    case 1:
        offset = 0x240;
        break;
    case 2:
        offset = 0x220;
        break;
    case 3:
        offset = 0x260;
        break;
    default: {
        int32_t a = read_i32(object + 0x260 + (size_t)index * 4);
        int32_t b = read_i32(object + 0x240 + (size_t)index * 4);
        int32_t c = read_i32(object + 0x220 + (size_t)index * 4);
        int32_t d = read_i32(object + 0x200 + (size_t)index * 4);
        return (a + b + c + d) >> 2;
    }
    }
    return read_i32(object + offset + (size_t)index * 4);
}

uint8_t game_get_player_staff_band(int32_t sum) {
    if (sum > 4) {
        return 3;
    }
    if (sum < 3) {
        return sum > 0 ? 1 : 0;
    }
    return 2;
}

uint8_t game_get_player_wealth_band(double value) {
    if (value > 1000000.0) {
        return 3;
    }
    if (value > 500000.0) {
        return 2;
    }
    if (value > 100000.0) {
        return 1;
    }
    return 0;
}

uint8_t game_get_player_satisfaction_band(int32_t average) {
    if (average > 0x5a) {
        return 0;
    }
    if (average < 0x47) {
        return (uint8_t)((average < 0x33) + 2);
    }
    return 1;
}

double game_get_player_weighted_stat(const int32_t stats[0x56],
                                     const double weights[0x56]) {
    if (stats == NULL || weights == NULL) {
        return 0.0;
    }
    double total = 0.0;
    for (size_t index = 0; index < 0x56; index++) {
        if (stats[index] > 0) {
            total += weights[index] * 0.001 * (double)stats[index];
        }
    }
    return total;
}

int32_t game_get_record_child14(const uint8_t *records, int32_t index) {
    if (records == NULL || index < 0) {
        return 0;
    }
    uintptr_t child;
    memcpy(&child, records + (size_t)index * 0x48 + 0x68, sizeof(child));
    if (child == 0) {
        return 0;
    }
    return read_i32((const uint8_t *)child + 0x14);
}

void player_reset_ai_state(uint8_t *player) {
    if (player == NULL) {
        return;
    }
    write_i32(player + 0x84, 1);
    write_i32(player + 0x88, 0);
}

void player_reset_debt_hours(uint8_t *player) {
    if (player == NULL) {
        return;
    }
    double value;
    memcpy(&value, player + 0x108, sizeof(value));
    if (value >= 0.0) {
        write_i32(player + 0x1e8, 0);
    }
}

void player_set_slot_flag18(uint8_t *player, size_t index) {
    if (player != NULL) {
        player[0x10e5u + index * 0x18u] = 1;
    }
}

bool tile_def_test_flag(const uint8_t *tile_defs, size_t index, uint32_t mask) {
    if (tile_defs == NULL) {
        return false;
    }
    uintptr_t flags;
    memcpy(&flags, tile_defs + index * 0x0c + 8, sizeof(flags));
    if (flags == 0) {
        return false;
    }
    return ((uint32_t)read_i32((const uint8_t *)flags + 0x1c) & mask) != 0;
}

bool product_map_category(uint8_t category, uint8_t group) {
    static const uint8_t group0[] = {
        0, 0x11, 0x1c, 0x1e, 0x24, 0x30, 0x27, 0x2a, 0x2b,
        0x2c, 0x2d, 0x31, 0x39, 0x3a, 0x3b, 0x41, 0xff,
    };
    static const uint8_t group1[] = {
        0, 8, 10, 13, 14, 15, 16, 22, 28, 36, 39, 43,
        44, 45, 48, 51, 53, 54, 55, 59, 60, 62, 63, 0xff,
    };
    static const uint8_t group2[] = {
        0, 1, 2, 3, 7, 9, 10, 13, 17, 18, 19, 20, 21, 24, 27, 32,
        34, 35, 37, 40, 45, 48, 49, 51, 54, 55, 56, 57, 58, 60, 61,
        65, 0xff,
    };
    static const uint8_t group3[] = {9, 0x11, 0x26, 0x35, 0x3b, 0x3e, 0x41, 0xff};
    const uint8_t *table;
    bool invert;
    switch (group) {
    case 0:
        table = group0;
        invert = false;
        break;
    case 1:
        table = group1;
        invert = false;
        break;
    case 2:
        table = group2;
        invert = true;
        break;
    case 3:
        table = group3;
        invert = true;
        break;
    default:
        return false;
    }
    for (size_t index = 0; table[index] != 0xff; index++) {
        if (table[index] == category) {
            return invert;
        }
    }
    return !invert;
}

int32_t map_find_name_index(const uint8_t *records, int32_t count,
                            const char *name) {
    if (records == NULL || name == NULL) {
        return -1;
    }
    for (int32_t index = 0; index < count; index++) {
        const char *candidate = (const char *)(records + 0x25 + (size_t)index * 0x48);
        if (strcmp(candidate, name) == 0) {
            return index;
        }
    }
    return -1;
}

int32_t string_list_find(const uint8_t *records, int32_t count,
                         const char *key, int32_t *index) {
    if (index == NULL) {
        return 0;
    }
    *index = 0;
    if (records == NULL || key == NULL || count <= 0) {
        return 0;
    }
    int32_t low = 0;
    int32_t high = count - 1;
    while (low <= high) {
        int32_t middle = (low + high) >> 1;
        const char *candidate = (const char *)(records + (size_t)middle * 0x48);
        int comparison = strcmp(key, candidate);
        if (comparison == 0) {
            *index = middle;
            return 1;
        }
        if (comparison < 0) {
            high = middle - 1;
        } else {
            low = middle + 1;
        }
    }
    *index = low;
    return 0;
}

bool object_is_state10(const uint8_t *object) {
    return object != NULL && read_i32(object + 0x108) == 10;
}

void object_set_frame5(uint8_t *object, int32_t frame) {
    if (object != NULL) {
        write_i32(object + 0x94, frame == -1 ? -1 : frame * 5);
    }
}

void object_set_index171c(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x171c, value);
        write_i32(object + 0x1724, 0);
        write_i32(object + 0x1720, 0);
    }
}

void object_set_field280(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x280, value);
    }
}

void record_clear48(uint8_t *records, size_t count, int32_t index) {
    if (records != NULL && index >= 0 && (size_t)index < count) {
        write_i32(records + (size_t)index * 0x48u, -1);
    }
}

void record_clear_active48(uint8_t *records, size_t count, int32_t index) {
    if (records == NULL || index < 0 || (size_t)index >= count) {
        return;
    }
    uint8_t *record = records + (size_t)index * 0x48u;
    record[0x3c] = 0;
    uint16_t zero = 0;
    memcpy(record + 0x30, &zero, sizeof(zero));
}

void record_clear_flags48(uint8_t *records, size_t count, int32_t index) {
    if (records == NULL || index < 0 || (size_t)index >= count) {
        return;
    }
    uint8_t *record = records + (size_t)index * 0x48u;
    if (read_i32(record) != -1) {
        record[0x3e] = 0;
        record[0x3c] = 0;
    }
}

void record_set_field2d0c(uint8_t *tile_defs, size_t index, uint8_t value) {
    if (tile_defs == NULL) {
        return;
    }
    uintptr_t target;
    memcpy(&target, tile_defs + index * 0x0cu + 8, sizeof(target));
    if (target != 0) {
        ((uint8_t *)target)[0x2d] = value;
    }
}

bool record_set_slot6_98(uint8_t *records, size_t count, size_t index,
                         size_t slot, uint32_t value, uint16_t extra) {
    if (records == NULL || index >= count || slot >= 0x10) {
        return false;
    }
    uint8_t *target = records + index * 0x98u + slot * 6u;
    memcpy(target, &value, sizeof(value));
    memcpy(target + 4, &extra, sizeof(extra));
    return true;
}

void set_field168(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x168, value);
    }
}

void set_field228(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x228, value);
    }
}

void set_field9b8(uint8_t *object, int32_t value) {
    if (object != NULL) {
        write_i32(object + 0x9b8, value);
    }
}

void rect_set1a4(uint8_t *rect, const int32_t values[4]) {
    if (rect == NULL || values == NULL) {
        return;
    }
    int32_t current = read_i32(rect + 0x1a4);
    if (current == -999) {
        write_i32(rect + 0x1a4, values[0]);
        write_i32(rect + 0x1a8, values[1]);
        write_i32(rect + 0x1ac, values[2]);
        write_i32(rect + 0x1b0, values[3]);
        return;
    }
    int32_t left = current < values[0] ? current : values[0];
    write_i32(rect + 0x1a4, left);
    int32_t right = read_i32(rect + 0x1ac);
    if (right < values[2]) {
        right = values[2];
    }
    write_i32(rect + 0x1ac, right);
    int32_t top = read_i32(rect + 0x1a8);
    if (values[1] < top) {
        top = values[1];
    }
    write_i32(rect + 0x1a8, top);
    int32_t bottom = read_i32(rect + 0x1b0);
    if (bottom < values[3]) {
        bottom = values[3];
    }
    write_i32(rect + 0x1b0, bottom);
}

const void *sprite_get_palette(const uint8_t *sprite) {
    if (sprite == NULL) {
        return NULL;
    }
    uintptr_t palette;
    memcpy(&palette, sprite + 0x20, sizeof(palette));
    return (const void *)palette;
}

void sprite_get_render_size(const uint8_t *sprite, uint32_t *width,
                            uint32_t *height) {
    if (sprite == NULL || width == NULL || height == NULL) {
        return;
    }
    uint16_t stored_width;
    uint16_t stored_height;
    memcpy(&stored_width, sprite + 0x12, sizeof(stored_width));
    memcpy(&stored_height, sprite + 0x14, sizeof(stored_height));
    if (read_i32(sprite + 0x30) == 0 || sprite[0x37] == 0) {
        *width = stored_width;
        *height = stored_height;
    } else {
        *width = stored_height;
        *height = stored_width;
    }
}

void surface_get_cursor_rect(const uint8_t *surface, int32_t rect[4]) {
    if (surface == NULL || rect == NULL) {
        return;
    }
    rect[0] = read_i32(surface + 4);
    rect[1] = read_i32(surface + 0x0c);
    rect[2] = read_i32(surface + 8);
    rect[3] = read_i32(surface + 0x10);
}

void surface_reset(uint8_t *surface) {
    if (surface == NULL) {
        return;
    }
    write_i32(surface + 0x0c, 0);
    write_i32(surface + 4, 0);
    uint16_t width;
    uint16_t height;
    memcpy(&width, surface + 0x1a, sizeof(width));
    memcpy(&height, surface + 0x1c, sizeof(height));
    write_i32(surface + 8, width);
    write_i32(surface + 0x10, height);
}

void surface_set_bounds(uint8_t *surface, int32_t left, int32_t top,
                        int32_t right, int32_t bottom) {
    if (surface == NULL) {
        return;
    }
    int32_t value = read_i32(surface + 100);
    write_i32(surface + 4, value > left ? value : left);
    value = read_i32(surface + 0x68);
    write_i32(surface + 0x0c, value > top ? value : top);
    value = read_i32(surface + 0x6c);
    write_i32(surface + 8, right < value ? right : value);
    value = read_i32(surface + 0x70);
    write_i32(surface + 0x10, bottom < value ? bottom : value);
}

void surface_set_pixel(uint8_t *surface, int32_t x, int32_t y,
                       uint16_t value) {
    if (surface == NULL) {
        return;
    }
    uint16_t width;
    uint16_t height;
    memcpy(&width, surface + 0x1a, sizeof(width));
    memcpy(&height, surface + 0x1c, sizeof(height));
    if (x < 0 || y < 0 || x >= width || y >= height) {
        return;
    }
    int32_t stride = read_i32(surface + 0x20);
    uintptr_t base;
    memcpy(&base, surface + 0x28, sizeof(base));
    uint8_t *target = (uint8_t *)base + (size_t)stride * y + (size_t)x * 3;
    memcpy(target, &value, sizeof(value));
}

void surface_clear(uint8_t *surface) {
    if (surface == NULL) {
        return;
    }
    uint32_t size = (uint32_t)(surface[0x10] >> 3) *
                    (uint32_t)read_i32(surface + 8) *
                    (uint32_t)read_i32(surface + 4);
    uintptr_t buffer;
    memcpy(&buffer, surface + 0x18, sizeof(buffer));
    memset((void *)buffer, 0, size);
}

void surface_clear_rows(uint8_t *surface) {
    if (surface == NULL) {
        return;
    }
    uintptr_t buffer;
    memcpy(&buffer, surface + 0x28, sizeof(buffer));
    if (buffer == 0) {
        return;
    }
    uint16_t width;
    uint16_t height;
    memcpy(&width, surface + 0x1a, sizeof(width));
    memcpy(&height, surface + 0x1c, sizeof(height));
    int32_t stride = read_i32(surface + 0x20);
    uint8_t *row = (uint8_t *)buffer;
    for (uint16_t y = 0; y < height; y++) {
        memset(row, 0, width);
        row += (size_t)stride * 2u;
    }
}

void sprite_init_format(uint8_t *sprite, int16_t width, uint16_t height,
                        uint32_t color_key, int32_t bpp, uint8_t flags,
                        uint16_t hotspot_x, uint16_t hotspot_y) {
    if (sprite == NULL) {
        return;
    }
    memcpy(sprite + 10, &hotspot_x, sizeof(hotspot_x));
    sprite[5] = (uint8_t)bpp;
    memcpy(sprite + 0x0c, &hotspot_y, sizeof(hotspot_y));
    write_i32(sprite + 0x18, 0);
    int16_t stride = (int16_t)((bpp >> 3) * width);
    sprite[4] = flags;
    write_i32(sprite + 0x1c, (int32_t)color_key);
    memcpy(sprite + 8, &height, sizeof(height));
    memcpy(sprite + 0x14, &height, sizeof(height));
    memcpy(sprite + 6, &stride, sizeof(stride));
    memcpy(sprite + 0x12, &stride, sizeof(stride));
}

void object_get_child_origin(const uint8_t *object, int32_t *x, int32_t *y) {
    if (object == NULL || x == NULL || y == NULL) {
        return;
    }
    uintptr_t child;
    memcpy(&child, object + 0x8310, sizeof(child));
    if (child == 0) {
        *x = 0;
        *y = 0;
        return;
    }
    *x = read_i32((const uint8_t *)child + 0x0c);
    *y = read_i32((const uint8_t *)child + 0x10);
}

int32_t object_count_matching_slots(const uint8_t *object, int32_t value) {
    if (object == NULL) {
        return 0;
    }
    int32_t count = 0;
    for (size_t index = 0; index < 8; index++) {
        if (read_i32(object + 0xd4 + index * 4) == value) {
            count++;
        }
    }
    return count;
}

void object_clear_slot_refs(uint8_t *object, uint8_t *slot) {
    if (object == NULL || slot == NULL) {
        return;
    }
    uintptr_t tile_defs;
    memcpy(&tile_defs, object + 0x4c, sizeof(tile_defs));
    static const size_t fields[2] = {0x44, 0x48};
    for (size_t index = 0; index < 2; index++) {
        int32_t slot_index = read_i32(slot + fields[index]);
        if (slot_index == -1) {
            continue;
        }
        uint8_t *record = (uint8_t *)tile_defs + (size_t)slot_index * 0x0cu;
        uintptr_t target;
        memcpy(&target, record + 8, sizeof(target));
        if (target != 0) {
            write_i32((uint8_t *)target + 0x38, 0);
        }
        write_i32(slot + fields[index], -1);
    }
}

bool stream_buffer_reset(uint8_t *buffer) {
    if (buffer == NULL) {
        return false;
    }
    memset(buffer, 0, 16);
    return true;
}

int32_t stream_get_available(const uint8_t *stream) {
    if (stream == NULL) {
        return 0;
    }
    uint32_t first = (uint32_t)read_i32(stream + 0x28);
    uint32_t second = (uint32_t)read_i32(stream + 0x2c);
    return first < second ? (int32_t)(second - first) : 0;
}
