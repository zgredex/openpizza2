#include "piz_container.h"

#include <string.h>

_Static_assert(sizeof(PizHeader) == PIZ_HEADER_SIZE, "piz header must stay 0xF0");
_Static_assert(offsetof(PizHeader, player_count) == 0xc0, "player count offset");
_Static_assert(offsetof(PizHeader, game_calendar) == 0xc8, "calendar offset");
_Static_assert(offsetof(PizHeader, system_time) == 0xd8, "system time offset");
_Static_assert(offsetof(PizHeader, version) == 0xe8, "version offset");
_Static_assert(offsetof(PizHeader, magic) == 0xec, "magic offset");

#define CHARACTER_SIZE 44u
#define MAPOBJECT_SIZE 20u
#define PERSON_SIZE 16u
#define CAR_SIZE 8u
#define PLAYER_SIZE 48u
#define COMPANY_SIZE 56u
#define TILE_TABLE_SIZE (PIZ_TILE_COUNT * PIZ_TILE_RECORD_SIZE)
#define TAIL_FIXED_SIZE 2176u

static void put_u32(uint8_t *buffer, size_t offset, uint32_t value) {
    buffer[offset + 0] = (uint8_t)(value & 0xffu);
    buffer[offset + 1] = (uint8_t)((value >> 8) & 0xffu);
    buffer[offset + 2] = (uint8_t)((value >> 16) & 0xffu);
    buffer[offset + 3] = (uint8_t)((value >> 24) & 0xffu);
}

static uint32_t get_u32(const uint8_t *buffer, size_t offset) {
    return (uint32_t)buffer[offset] | ((uint32_t)buffer[offset + 1] << 8) |
           ((uint32_t)buffer[offset + 2] << 16) |
           ((uint32_t)buffer[offset + 3] << 24);
}

static void put_text(uint8_t *buffer, size_t offset, const char *text, size_t size) {
    memset(buffer + offset, 0, size);
    if (text != NULL) {
        strncpy((char *)buffer + offset, text, size - 1);
    }
}

static void get_text(char *target, size_t size, const uint8_t *buffer, size_t offset) {
    memcpy(target, buffer + offset, size);
    target[size - 1] = '\0';
}

static size_t briefing_bytes(const PizContainer *container) {
    size_t total = 4;
    for (uint32_t index = 0; index < container->briefing_count; index++) {
        total += 8 + strlen(container->briefings[index].text) + 1;
    }
    return total;
}

void piz_container_init(PizContainer *container, const char *title,
                        const char *company, const char *city) {
    if (container == NULL) {
        return;
    }
    memset(container, 0, sizeof(*container));
    put_text((uint8_t *)&container->header.title, 0, title, 0x40);
    put_text((uint8_t *)&container->header.company, 0, company, 0x40);
    put_text((uint8_t *)&container->header.city, 0, city, 0x40);
    container->header.player_count = 1;
    container->header.version = PIZ_VERSION;
    container->header.magic = PIZ_MAGIC;
}

bool piz_container_add_briefing(PizContainer *container, uint32_t id,
                                const char *text) {
    if (container == NULL || container->briefing_count >= PIZ_MAX_BRIEFINGS ||
        text == NULL) {
        return false;
    }
    PizBriefing *briefing = &container->briefings[container->briefing_count];
    briefing->id = id;
    strncpy(briefing->text, text, sizeof(briefing->text) - 1);
    briefing->text[sizeof(briefing->text) - 1] = '\0';
    container->briefing_count += 1;
    return true;
}

bool piz_container_set_tile_name(PizContainer *container, uint32_t index,
                                 const char *name) {
    if (container == NULL || index >= PIZ_TILE_COUNT || name == NULL) {
        return false;
    }
    memset(container->tile_names[index], 0, PIZ_TILE_RECORD_SIZE);
    strncpy(container->tile_names[index], name, PIZ_TILE_RECORD_SIZE - 1);
    return true;
}

size_t piz_container_size(const PizContainer *container) {
    if (container == NULL) {
        return 0;
    }
    size_t total = PIZ_FIXED_PREFIX;
    total += briefing_bytes(container);
    total += TILE_TABLE_SIZE;
    total += 4; /* isomap count */
    total += 4 + (size_t)container->character_count * CHARACTER_SIZE;
    total += 4 + (size_t)container->mapobject_count * MAPOBJECT_SIZE;
    total += 4 + (size_t)container->person_count * PERSON_SIZE;
    total += 4 + (size_t)container->car_count * CAR_SIZE;
    total += PIZ_MAX_PLAYERS * PLAYER_SIZE;
    total += PIZ_MAX_COMPANIES * COMPANY_SIZE;
    total += TAIL_FIXED_SIZE;
    total += save_state_encoded_size();
    total += 4; /* end marker */
    return total;
}

size_t piz_container_encode(const PizContainer *container, uint8_t *buffer,
                            size_t capacity) {
    if (container == NULL || buffer == NULL) {
        return 0;
    }
    const size_t total = piz_container_size(container);
    if (capacity < total || total > PIZ_MAX_CONTAINER_SIZE) {
        return 0;
    }
    memset(buffer, 0, total);
    memcpy(buffer, &container->header, sizeof(PizHeader));
    put_u32(buffer, PIZ_PREAMBLE_SIZE, PIZ_START_MARKER);

    size_t offset = PIZ_FIXED_PREFIX;
    put_u32(buffer, offset, container->briefing_count);
    offset += 4;
    for (uint32_t index = 0; index < container->briefing_count; index++) {
        const PizBriefing *briefing = &container->briefings[index];
        put_u32(buffer, offset, briefing->id);
        offset += 4;
        size_t length = strlen(briefing->text) + 1;
        put_u32(buffer, offset, (uint32_t)length);
        offset += 4;
        memcpy(buffer + offset, briefing->text, length);
        offset += length;
    }

    memcpy(buffer + offset, container->tile_names, TILE_TABLE_SIZE);
    offset += TILE_TABLE_SIZE;

    size_t isomap_start = offset;
    put_u32(buffer, offset, 0);
    offset += 4;
    size_t character_start = offset;
    put_u32(buffer, offset, container->character_count);
    offset += 4;
    for (uint32_t index = 0; index < container->character_count; index++) {
        put_u32(buffer, offset, container->characters[index].id);
        put_text(buffer, offset + 4, container->characters[index].name, 32);
        put_u32(buffer, offset + 36, (uint32_t)container->characters[index].skill);
        put_u32(buffer, offset + 40, (uint32_t)container->characters[index].motivation);
        offset += CHARACTER_SIZE;
    }
    size_t mapobject_start = offset;
    put_u32(buffer, offset, container->mapobject_count);
    offset += 4;
    for (uint32_t index = 0; index < container->mapobject_count; index++) {
        put_u32(buffer, offset, container->mapobjects[index].id);
        put_u32(buffer, offset + 4, container->mapobjects[index].type);
        put_u32(buffer, offset + 8, container->mapobjects[index].owner_slot);
        put_u32(buffer, offset + 12, container->mapobjects[index].tile_index);
        put_u32(buffer, offset + 16, container->mapobjects[index].state);
        offset += MAPOBJECT_SIZE;
    }
    size_t person_start = offset;
    put_u32(buffer, offset, container->person_count);
    offset += 4;
    for (uint32_t index = 0; index < container->person_count; index++) {
        put_u32(buffer, offset, container->persons[index].id);
        put_u32(buffer, offset + 4, container->persons[index].profession);
        put_u32(buffer, offset + 8, container->persons[index].branch_id);
        put_u32(buffer, offset + 12, (uint32_t)container->persons[index].skill);
        offset += PERSON_SIZE;
    }
    size_t car_start = offset;
    put_u32(buffer, offset, container->car_count);
    offset += 4;
    for (uint32_t index = 0; index < container->car_count; index++) {
        put_u32(buffer, offset, container->cars[index].id);
        put_u32(buffer, offset + 4, container->cars[index].type);
        offset += CAR_SIZE;
    }
    size_t player_start = offset;
    for (uint32_t slot = 0; slot < PIZ_MAX_PLAYERS; slot++) {
        const PizPlayer *player = &container->players[slot];
        put_u32(buffer, offset, player->present);
        put_u32(buffer, offset + 4, player->slot);
        put_text(buffer, offset + 8, player->name, 32);
        memcpy(buffer + offset + 40, &player->cash, 8);
        offset += PLAYER_SIZE;
    }
    size_t company_start = offset;
    for (uint32_t slot = 0; slot < PIZ_MAX_COMPANIES; slot++) {
        const PizCompany *company = &container->companies[slot];
        put_u32(buffer, offset, company->present);
        put_u32(buffer, offset + 4, company->slot);
        put_text(buffer, offset + 8, company->name, 32);
        memcpy(buffer + offset + 40, &company->cash, 8);
        put_u32(buffer, offset + 48, company->branches);
        put_u32(buffer, offset + 52, company->share_x100);
        offset += COMPANY_SIZE;
    }
    size_t tail_start = offset;
    offset += 2160;
    put_u32(buffer, offset, 1);
    put_u32(buffer, offset + 4, 0);
    put_u32(buffer, offset + 8, 0);
    offset += 12;
    put_u32(buffer, offset, 0);
    offset += 4;
    size_t save_written = save_state_encode(&container->save, buffer + offset,
                                            total - offset - 4);
    if (save_written == 0) {
        return 0;
    }
    offset += save_written;
    put_u32(buffer, offset, PIZ_END_MARKER);
    offset += 4;
    if (offset != total) {
        return 0;
    }

    put_u32(buffer, PIZ_HEADER_SIZE + 0 * 4, (uint32_t)person_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 1 * 4, (uint32_t)character_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 2 * 4, (uint32_t)mapobject_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 3 * 4, (uint32_t)company_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 4 * 4, (uint32_t)player_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 5 * 4, (uint32_t)tail_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 6 * 4, (uint32_t)car_start);
    put_u32(buffer, PIZ_HEADER_SIZE + 7 * 4, (uint32_t)total);
    (void)isomap_start;
    return total;
}

bool piz_container_decode(PizContainer *container, const uint8_t *buffer,
                          size_t length) {
    if (container == NULL || buffer == NULL || length < PIZ_FIXED_PREFIX ||
        length > PIZ_MAX_CONTAINER_SIZE) {
        return false;
    }
    memset(container, 0, sizeof(*container));
    memcpy(&container->header, buffer, sizeof(PizHeader));
    if (container->header.magic != PIZ_MAGIC ||
        container->header.version != PIZ_VERSION) {
        return false;
    }
    if (get_u32(buffer, PIZ_PREAMBLE_SIZE) != PIZ_START_MARKER ||
        get_u32(buffer, length - 4) != PIZ_END_MARKER) {
        return false;
    }
    const uint32_t person_start = get_u32(buffer, PIZ_HEADER_SIZE + 0 * 4);
    const uint32_t character_start = get_u32(buffer, PIZ_HEADER_SIZE + 1 * 4);
    const uint32_t mapobject_start = get_u32(buffer, PIZ_HEADER_SIZE + 2 * 4);
    const uint32_t company_start = get_u32(buffer, PIZ_HEADER_SIZE + 3 * 4);
    const uint32_t player_start = get_u32(buffer, PIZ_HEADER_SIZE + 4 * 4);
    const uint32_t tail_start = get_u32(buffer, PIZ_HEADER_SIZE + 5 * 4);
    const uint32_t car_start = get_u32(buffer, PIZ_HEADER_SIZE + 6 * 4);
    const uint32_t end = get_u32(buffer, PIZ_HEADER_SIZE + 7 * 4);
    if (end != length ||
        !(character_start <= mapobject_start && mapobject_start <= person_start &&
          person_start <= car_start && car_start <= player_start &&
          player_start <= company_start && company_start <= tail_start &&
          tail_start <= length)) {
        return false;
    }

    size_t offset = PIZ_FIXED_PREFIX;
    container->briefing_count = get_u32(buffer, offset);
    offset += 4;
    if (container->briefing_count > PIZ_MAX_BRIEFINGS) {
        return false;
    }
    for (uint32_t index = 0; index < container->briefing_count; index++) {
        if (offset + 8 > length) {
            return false;
        }
        container->briefings[index].id = get_u32(buffer, offset);
        uint32_t text_length = get_u32(buffer, offset + 4);
        offset += 8;
        if (text_length == 0 || text_length > sizeof(container->briefings[index].text) ||
            offset + text_length > length) {
            return false;
        }
        memcpy(container->briefings[index].text, buffer + offset, text_length);
        container->briefings[index].text[text_length - 1] = '\0';
        offset += text_length;
    }
    if (offset + TILE_TABLE_SIZE > length) {
        return false;
    }
    memcpy(container->tile_names, buffer + offset, TILE_TABLE_SIZE);
    offset += TILE_TABLE_SIZE;

    container->character_count = get_u32(buffer, character_start);
    if (container->character_count > PIZ_MAX_CHARACTERS) {
        return false;
    }
    offset = character_start + 4;
    for (uint32_t index = 0; index < container->character_count; index++) {
        if (offset + CHARACTER_SIZE > length) {
            return false;
        }
        PizCharacter *character = &container->characters[index];
        character->id = get_u32(buffer, offset);
        get_text(character->name, 32, buffer, offset + 4);
        character->skill = (int32_t)get_u32(buffer, offset + 36);
        character->motivation = (int32_t)get_u32(buffer, offset + 40);
        offset += CHARACTER_SIZE;
    }

    container->mapobject_count = get_u32(buffer, mapobject_start);
    if (container->mapobject_count > PIZ_MAX_MAPOBJECTS) {
        return false;
    }
    offset = mapobject_start + 4;
    for (uint32_t index = 0; index < container->mapobject_count; index++) {
        if (offset + MAPOBJECT_SIZE > length) {
            return false;
        }
        container->mapobjects[index].id = get_u32(buffer, offset);
        container->mapobjects[index].type = get_u32(buffer, offset + 4);
        container->mapobjects[index].owner_slot = get_u32(buffer, offset + 8);
        container->mapobjects[index].tile_index = get_u32(buffer, offset + 12);
        container->mapobjects[index].state = get_u32(buffer, offset + 16);
        offset += MAPOBJECT_SIZE;
    }

    container->person_count = get_u32(buffer, person_start);
    if (container->person_count > PIZ_MAX_PERSONS) {
        return false;
    }
    offset = person_start + 4;
    for (uint32_t index = 0; index < container->person_count; index++) {
        if (offset + PERSON_SIZE > length) {
            return false;
        }
        container->persons[index].id = get_u32(buffer, offset);
        container->persons[index].profession = get_u32(buffer, offset + 4);
        container->persons[index].branch_id = get_u32(buffer, offset + 8);
        container->persons[index].skill = (int32_t)get_u32(buffer, offset + 12);
        offset += PERSON_SIZE;
    }

    container->car_count = get_u32(buffer, car_start);
    if (container->car_count > PIZ_MAX_CARS) {
        return false;
    }
    offset = car_start + 4;
    for (uint32_t index = 0; index < container->car_count; index++) {
        if (offset + CAR_SIZE > length) {
            return false;
        }
        container->cars[index].id = get_u32(buffer, offset);
        container->cars[index].type = get_u32(buffer, offset + 4);
        offset += CAR_SIZE;
    }

    offset = player_start;
    for (uint32_t slot = 0; slot < PIZ_MAX_PLAYERS; slot++) {
        if (offset + PLAYER_SIZE > length) {
            return false;
        }
        PizPlayer *player = &container->players[slot];
        player->present = get_u32(buffer, offset);
        player->slot = get_u32(buffer, offset + 4);
        get_text(player->name, 32, buffer, offset + 8);
        memcpy(&player->cash, buffer + offset + 40, 8);
        offset += PLAYER_SIZE;
    }
    offset = company_start;
    for (uint32_t slot = 0; slot < PIZ_MAX_COMPANIES; slot++) {
        if (offset + COMPANY_SIZE > length) {
            return false;
        }
        PizCompany *company = &container->companies[slot];
        company->present = get_u32(buffer, offset);
        company->slot = get_u32(buffer, offset + 4);
        get_text(company->name, 32, buffer, offset + 8);
        memcpy(&company->cash, buffer + offset + 40, 8);
        company->branches = get_u32(buffer, offset + 48);
        company->share_x100 = get_u32(buffer, offset + 52);
        offset += COMPANY_SIZE;
    }

    size_t save_offset = tail_start + TAIL_FIXED_SIZE;
    if (save_offset > length ||
        !save_state_decode(&container->save, buffer + save_offset,
                           length - save_offset - 4)) {
        return false;
    }
    return piz_container_size(container) == length;
}
