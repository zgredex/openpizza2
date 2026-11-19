#include "leaf_functions.h"

#include <stdlib.h>

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
