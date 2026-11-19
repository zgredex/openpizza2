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
