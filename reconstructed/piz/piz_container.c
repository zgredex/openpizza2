#include "piz_container.h"

#include <string.h>

_Static_assert(sizeof(PizHeader) == PIZ_HEADER_SIZE, "piz header must stay 0xF0");
_Static_assert(offsetof(PizHeader, player_count) == 0xc0, "player count offset");
_Static_assert(offsetof(PizHeader, game_calendar) == 0xc8, "calendar offset");
_Static_assert(offsetof(PizHeader, system_time) == 0xd8, "system time offset");
_Static_assert(offsetof(PizHeader, version) == 0xe8, "version offset");
_Static_assert(offsetof(PizHeader, magic) == 0xec, "magic offset");

#define CHARACTER_BODY_SIZE 2082u
#define PLAYER_BODY_SIZE 132u
#define COMPANY_BODY_SIZE 270u
#define COMPANY_NESTED_SIZE 36u
#define BRANCH_BODY_SIZE 6412u
#define BRANCH_TAIL_SIZE 48u
#define PLAN_BODY_SIZE 44u
#define PAIR_BODY_SIZE 12u
#define BIG_BODY_SIZE 416u
#define RECIPE_BODY_SIZE 713u
#define REPORT_BODY_SIZE 856u
#define STORAGE_BODY_SIZE 303u
#define AI_BODY_SIZE 554u
#define MISSION_BODY_SIZE 208u
#define CAR_SIZE 8u
#define MAPOBJECT_SIZE 20u
#define PERSON_SIZE 16u
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
        size_t length = strlen(text);
        if (length >= size) {
            length = size - 1;
        }
        memcpy(buffer + offset, text, length);
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

static size_t player_region_size(const PizContainer *container) {
    size_t total = 0;
    for (uint32_t slot = 0; slot < PIZ_MAX_PLAYERS; slot++) {
        total += 4;
        if (container->players[slot].present) {
            total += PLAYER_BODY_SIZE + CHARACTER_BODY_SIZE + 4 + 4 + 4;
        }
    }
    return total;
}

static size_t company_region_size(const PizContainer *container) {
    size_t total = 0;
    for (uint32_t slot = 0; slot < PIZ_MAX_COMPANIES; slot++) {
        total += 4;
        if (container->companies[slot].present) {
            total += COMPANY_BODY_SIZE + COMPANY_NESTED_SIZE;
            total += (size_t)container->companies[slot].plan_count * PLAN_BODY_SIZE;
            total += (size_t)container->companies[slot].recipe_count *
                     (4 + RECIPE_BODY_SIZE);
            total += (size_t)container->companies[slot].branch_count *
                     (4 + BRANCH_BODY_SIZE + BRANCH_TAIL_SIZE);
            total += (size_t)container->companies[slot].report_count *
                     REPORT_BODY_SIZE;
            total += (size_t)container->companies[slot].storage_count *
                     (4 + STORAGE_BODY_SIZE);
            total += (size_t)container->companies[slot].pair_count * PAIR_BODY_SIZE;
            total += (size_t)container->companies[slot].big_count * BIG_BODY_SIZE;
        }
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
    container->players[0].present = 1;
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
    total += 4;
    total += 4 + (size_t)container->character_count * (4 + CHARACTER_BODY_SIZE);
    total += 4 + (size_t)container->mapobject_count * MAPOBJECT_SIZE;
    total += 4 + (size_t)container->person_count * PERSON_SIZE;
    total += 4 + (size_t)container->car_count * CAR_SIZE;
    total += player_region_size(container);
    total += company_region_size(container);
    total += TAIL_FIXED_SIZE;
    total += save_state_encoded_size();
    total += 4;
    return total;
}

static void write_character_body(uint8_t *buffer, const PizCharacter *character) {
    memset(buffer, 0, CHARACTER_BODY_SIZE);
    put_u32(buffer, 0, (uint32_t)character->skill);
    put_u32(buffer, 4, (uint32_t)character->motivation);
    put_text(buffer, 44, character->name, 32);
}

static void write_player_body(uint8_t *buffer, const PizPlayer *player) {
    memset(buffer, 0, PLAYER_BODY_SIZE);
    put_text(buffer, 12, player->name, 32);
    memcpy(buffer + 56, &player->cash, 8);
}

/*
 * CompanyData_Save fixed prefix (0x4E1540 / save_schema.json): 64-byte name,
 * then the schema field sequence. Cash is the double stored at serialized
 * offset 0x56 (object +0x108). The nine trailing counts are GamePlan, recipe,
 * featured-recipe, branch, StatsPeriodReport, Storage, pair and 0x1A0-byte
 * record lists; this batch serializes the fixed prefix and zero counts.
 */
static void write_company_body(uint8_t *buffer, const PizCompany *company) {
    memset(buffer, 0, COMPANY_BODY_SIZE);
    put_text(buffer, 0, company->name, 64);
    put_u32(buffer, 64, company->slot);
    memcpy(buffer + 86, &company->cash, 8);
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

    put_u32(buffer, offset, 0);
    offset += 4;
    size_t character_start = offset;
    put_u32(buffer, offset, container->character_count);
    offset += 4;
    for (uint32_t index = 0; index < container->character_count; index++) {
        put_u32(buffer, offset, container->characters[index].id);
        offset += 4;
        write_character_body(buffer + offset, &container->characters[index]);
        offset += CHARACTER_BODY_SIZE;
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
        uint32_t present = player->present ? 1u : 0u;
        put_u32(buffer, offset, present);
        offset += 4;
        if (!present) {
            continue;
        }
        write_player_body(buffer + offset, player);
        offset += PLAYER_BODY_SIZE;
        PizCharacter empty = {0};
        const PizCharacter *character = container->character_count ? &container->characters[0] : &empty;
        write_character_body(buffer + offset, character);
        offset += CHARACTER_BODY_SIZE;
        put_u32(buffer, offset, 0);
        put_u32(buffer, offset + 4, 0);
        put_u32(buffer, offset + 8, 0);
        offset += 12;
    }
    size_t company_start = offset;
    for (uint32_t slot = 0; slot < PIZ_MAX_COMPANIES; slot++) {
        const PizCompany *company = &container->companies[slot];
        uint32_t present = company->present ? 1u : 0u;
        put_u32(buffer, offset, present);
        offset += 4;
        if (!present) {
            continue;
        }
        write_company_body(buffer + offset, company);
        offset += COMPANY_BODY_SIZE;
        put_u32(buffer, offset, 0); /* company list index */
        offset += 4;
        uint32_t plan_count = company->plan_count;
        if (plan_count > PIZ_MAX_PLANS_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, plan_count);
        offset += 4;
        for (uint32_t plan = 0; plan < plan_count; plan++) {
            for (int field = 0; field < 11; field++) {
                put_u32(buffer, offset, company->plans[plan].fields[field]);
                offset += 4;
            }
        }
        uint32_t recipe_count = company->recipe_count;
        if (recipe_count > PIZ_MAX_RECIPES_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, recipe_count);
        offset += 4;
        for (uint32_t recipe = 0; recipe < recipe_count; recipe++) {
            put_u32(buffer, offset, company->recipes[recipe].id);
            offset += 4;
            memset(buffer + offset, 0, RECIPE_BODY_SIZE);
            put_text(buffer, offset, company->recipes[recipe].name, 64);
            offset += RECIPE_BODY_SIZE;
        }
        put_u32(buffer, offset, 0); /* featured recipe flag */
        offset += 4;
        uint32_t branch_count = company->branch_count;
        if (branch_count > PIZ_MAX_BRANCHES_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, branch_count);
        offset += 4;
        for (uint32_t branch = 0; branch < branch_count; branch++) {
            put_u32(buffer, offset, company->branches[branch].id);
            offset += 4;
            memset(buffer + offset, 0, BRANCH_BODY_SIZE + BRANCH_TAIL_SIZE);
            offset += BRANCH_BODY_SIZE + BRANCH_TAIL_SIZE;
        }
        uint32_t report_count = company->report_count;
        if (report_count > PIZ_MAX_REPORTS_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, report_count);
        offset += 4;
        for (uint32_t report = 0; report < report_count; report++) {
            memset(buffer + offset, 0, REPORT_BODY_SIZE);
            offset += REPORT_BODY_SIZE;
        }
        uint32_t storage_count = company->storage_count;
        if (storage_count > PIZ_MAX_STORAGE_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, storage_count);
        offset += 4;
        for (uint32_t storage = 0; storage < storage_count; storage++) {
            put_u32(buffer, offset, company->storage[storage].id);
            offset += 4;
            memset(buffer + offset, 0, STORAGE_BODY_SIZE);
            offset += STORAGE_BODY_SIZE;
        }
        uint32_t pair_count = company->pair_count;
        if (pair_count > PIZ_MAX_PAIRS_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, pair_count);
        offset += 4;
        for (uint32_t pair = 0; pair < pair_count; pair++) {
            put_u32(buffer, offset, company->pairs[pair].id);
            offset += 4;
            memcpy(buffer + offset, &company->pairs[pair].value, 8);
            offset += 8;
        }
        uint32_t big_count = company->big_count;
        if (big_count > PIZ_MAX_BIG_PER_COMPANY) {
            return 0;
        }
        put_u32(buffer, offset, big_count);
        offset += 4;
        for (uint32_t big = 0; big < big_count; big++) {
            memcpy(buffer + offset, company->big[big].data, BIG_BODY_SIZE);
            offset += BIG_BODY_SIZE;
        }
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
        if (offset + 4 + CHARACTER_BODY_SIZE > length) {
            return false;
        }
        PizCharacter *character = &container->characters[index];
        character->id = get_u32(buffer, offset);
        offset += 4;
        character->skill = (int32_t)get_u32(buffer, offset);
        character->motivation = (int32_t)get_u32(buffer, offset + 4);
        get_text(character->name, 32, buffer, offset + 44);
        offset += CHARACTER_BODY_SIZE;
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
        if (offset + 4 > length) {
            return false;
        }
        PizPlayer *player = &container->players[slot];
        player->present = get_u32(buffer, offset);
        offset += 4;
        if (!player->present) {
            continue;
        }
        if (offset + PLAYER_BODY_SIZE + CHARACTER_BODY_SIZE + 12 > length) {
            return false;
        }
        get_text(player->name, 32, buffer, offset + 12);
        memcpy(&player->cash, buffer + offset + 56, 8);
        offset += PLAYER_BODY_SIZE;
        offset += CHARACTER_BODY_SIZE;
        uint32_t event_count = get_u32(buffer, offset);
        offset += 4;
        if (offset + event_count * 6 > length) {
            return false;
        }
        offset += event_count * 6;
        uint32_t has_ai = get_u32(buffer, offset);
        offset += 4;
        if (has_ai) {
            if (offset + AI_BODY_SIZE > length) {
                return false;
            }
            offset += AI_BODY_SIZE;
        }
        uint32_t has_mission = get_u32(buffer, offset);
        offset += 4;
        if (has_mission) {
            if (offset + MISSION_BODY_SIZE > length) {
                return false;
            }
            offset += MISSION_BODY_SIZE;
        }
    }
    offset = company_start;
    for (uint32_t slot = 0; slot < PIZ_MAX_COMPANIES; slot++) {
        if (offset + 4 > length) {
            return false;
        }
        PizCompany *company = &container->companies[slot];
        company->present = get_u32(buffer, offset);
        offset += 4;
        if (!company->present) {
            continue;
        }
        if (offset + COMPANY_BODY_SIZE + COMPANY_NESTED_SIZE > length) {
            return false;
        }
        get_text(company->name, 64, buffer, offset);
        company->slot = get_u32(buffer, offset + 64);
        memcpy(&company->cash, buffer + offset + 86, 8);
        offset += COMPANY_BODY_SIZE;
        if (get_u32(buffer, offset) != 0) { /* company list index */
            return false;
        }
        offset += 4;
        uint32_t plan_count = get_u32(buffer, offset);
        offset += 4;
        if (plan_count > PIZ_MAX_PLANS_PER_COMPANY) {
            return false;
        }
        company->plan_count = plan_count;
        for (uint32_t plan = 0; plan < plan_count; plan++) {
            if (offset + PLAN_BODY_SIZE > length) {
                return false;
            }
            for (int field = 0; field < 11; field++) {
                company->plans[plan].fields[field] = get_u32(buffer, offset);
                offset += 4;
            }
        }
        uint32_t recipe_count = get_u32(buffer, offset);
        offset += 4;
        if (recipe_count > PIZ_MAX_RECIPES_PER_COMPANY) {
            return false;
        }
        company->recipe_count = recipe_count;
        for (uint32_t recipe = 0; recipe < recipe_count; recipe++) {
            if (offset + 4 + RECIPE_BODY_SIZE > length) {
                return false;
            }
            company->recipes[recipe].id = get_u32(buffer, offset);
            offset += 4;
            get_text(company->recipes[recipe].name, 64, buffer, offset);
            offset += RECIPE_BODY_SIZE;
        }
        if (get_u32(buffer, offset) != 0) { /* featured recipe flag */
            return false;
        }
        offset += 4;
        uint32_t branch_count = get_u32(buffer, offset);
        offset += 4;
        if (branch_count > PIZ_MAX_BRANCHES_PER_COMPANY) {
            return false;
        }
        company->branch_count = branch_count;
        for (uint32_t branch = 0; branch < branch_count; branch++) {
            if (offset + 4 + BRANCH_BODY_SIZE + BRANCH_TAIL_SIZE > length) {
                return false;
            }
            company->branches[branch].id = get_u32(buffer, offset);
            offset += 4 + BRANCH_BODY_SIZE + BRANCH_TAIL_SIZE;
        }
        uint32_t report_count = get_u32(buffer, offset);
        offset += 4;
        if (report_count > PIZ_MAX_REPORTS_PER_COMPANY) {
            return false;
        }
        company->report_count = report_count;
        if (offset + (size_t)report_count * REPORT_BODY_SIZE > length) {
            return false;
        }
        offset += (size_t)report_count * REPORT_BODY_SIZE;
        uint32_t storage_count = get_u32(buffer, offset);
        offset += 4;
        if (storage_count > PIZ_MAX_STORAGE_PER_COMPANY) {
            return false;
        }
        company->storage_count = storage_count;
        for (uint32_t storage = 0; storage < storage_count; storage++) {
            if (offset + 4 + STORAGE_BODY_SIZE > length) {
                return false;
            }
            company->storage[storage].id = get_u32(buffer, offset);
            offset += 4 + STORAGE_BODY_SIZE;
        }
        uint32_t pair_count = get_u32(buffer, offset);
        offset += 4;
        if (pair_count > PIZ_MAX_PAIRS_PER_COMPANY) {
            return false;
        }
        company->pair_count = pair_count;
        for (uint32_t pair = 0; pair < pair_count; pair++) {
            if (offset + PAIR_BODY_SIZE > length) {
                return false;
            }
            company->pairs[pair].id = get_u32(buffer, offset);
            memcpy(&company->pairs[pair].value, buffer + offset + 4, 8);
            offset += PAIR_BODY_SIZE;
        }
        uint32_t big_count = get_u32(buffer, offset);
        offset += 4;
        if (big_count > PIZ_MAX_BIG_PER_COMPANY) {
            return false;
        }
        company->big_count = big_count;
        for (uint32_t big = 0; big < big_count; big++) {
            if (offset + BIG_BODY_SIZE > length) {
                return false;
            }
            memcpy(company->big[big].data, buffer + offset, BIG_BODY_SIZE);
            offset += BIG_BODY_SIZE;
        }
        company->share_x100 = 0;
    }

    size_t save_offset = tail_start + TAIL_FIXED_SIZE;
    if (save_offset > length ||
        !save_state_decode(&container->save, buffer + save_offset,
                           length - save_offset - 4)) {
        return false;
    }
    (void)offset;
    return piz_container_size(container) == length;
}
