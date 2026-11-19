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
