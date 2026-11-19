#include "piz_container.h"

#include <string.h>

_Static_assert(sizeof(PizHeader) == PIZ_HEADER_SIZE, "piz header must stay 0xF0");
_Static_assert(offsetof(PizHeader, player_count) == 0xc0, "player count offset");
_Static_assert(offsetof(PizHeader, game_calendar) == 0xc8, "calendar offset");
_Static_assert(offsetof(PizHeader, system_time) == 0xd8, "system time offset");
_Static_assert(offsetof(PizHeader, version) == 0xe8, "version offset");
_Static_assert(offsetof(PizHeader, magic) == 0xec, "magic offset");

static void write_u32(uint8_t *buffer, size_t offset, uint32_t value) {
    buffer[offset + 0] = (uint8_t)(value & 0xffu);
    buffer[offset + 1] = (uint8_t)((value >> 8) & 0xffu);
    buffer[offset + 2] = (uint8_t)((value >> 16) & 0xffu);
    buffer[offset + 3] = (uint8_t)((value >> 24) & 0xffu);
}

static uint32_t read_u32(const uint8_t *buffer, size_t offset) {
    return (uint32_t)buffer[offset] | ((uint32_t)buffer[offset + 1] << 8) |
           ((uint32_t)buffer[offset + 2] << 16) |
           ((uint32_t)buffer[offset + 3] << 24);
}

static void copy_text(char *target, size_t size, const char *source) {
    memset(target, 0, size);
    if (source != NULL) {
        strncpy(target, source, size - 1);
    }
}

void piz_container_init(PizContainer *container, const char *title,
                        const char *company, const char *city) {
    if (container == NULL) {
        return;
    }
    memset(container, 0, sizeof(*container));
    copy_text(container->header.title, sizeof(container->header.title), title);
    copy_text(container->header.company, sizeof(container->header.company), company);
    copy_text(container->header.city, sizeof(container->header.city), city);
    container->header.player_count = 1;
    container->header.version = PIZ_VERSION;
    container->header.magic = PIZ_MAGIC;
}

size_t piz_container_size(void) {
    return PIZ_PREAMBLE_SIZE + 4 + save_state_encoded_size() + 4;
}

size_t piz_container_encode(const PizContainer *container, uint8_t *buffer,
                            size_t capacity) {
    if (container == NULL || buffer == NULL) {
        return 0;
    }
    const size_t total = piz_container_size();
    if (capacity < total) {
        return 0;
    }
    memset(buffer, 0, total);
    memcpy(buffer, &container->header, sizeof(PizHeader));

    for (int index = 0; index < 8; index++) {
        write_u32(buffer, PIZ_HEADER_SIZE + (size_t)index * 4,
                  (uint32_t)total);
    }
    write_u32(buffer, PIZ_PREAMBLE_SIZE, PIZ_START_MARKER);
    size_t written = save_state_encode(&container->save, buffer + PIZ_PREAMBLE_SIZE + 4,
                                       total - PIZ_PREAMBLE_SIZE - 4);
    if (written == 0) {
        return 0;
    }
    write_u32(buffer, total - 4, PIZ_END_MARKER);
    return total;
}

bool piz_container_decode(PizContainer *container, const uint8_t *buffer,
                          size_t length) {
    if (container == NULL || buffer == NULL || length != piz_container_size()) {
        return false;
    }
    memcpy(&container->header, buffer, sizeof(PizHeader));
    if (container->header.magic != PIZ_MAGIC ||
        container->header.version != PIZ_VERSION) {
        return false;
    }
    if (read_u32(buffer, PIZ_PREAMBLE_SIZE) != PIZ_START_MARKER ||
        read_u32(buffer, length - 4) != PIZ_END_MARKER) {
        return false;
    }
    if (read_u32(buffer, PIZ_HEADER_SIZE + 7 * 4) != length) {
        return false;
    }
    return save_state_decode(&container->save, buffer + PIZ_PREAMBLE_SIZE + 4,
                             length - PIZ_PREAMBLE_SIZE - 8);
}
