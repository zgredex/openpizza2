#ifndef PC2_RECONSTRUCTED_PIZ_CONTAINER_H
#define PC2_RECONSTRUCTED_PIZ_CONTAINER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../save/save_state.h"

#define PIZ_HEADER_SIZE 0xF0u
#define PIZ_DIRECTORY_SIZE 0x20u
#define PIZ_PREAMBLE_SIZE (PIZ_HEADER_SIZE + PIZ_DIRECTORY_SIZE)
#define PIZ_FIXED_PREFIX 2011u
#define PIZ_VERSION 0x11u
#define PIZ_MAGIC 0x13738317u
#define PIZ_START_MARKER 0x2Eu
#define PIZ_END_MARKER 0x2Au

#define PIZ_TILE_COUNT 2500
#define PIZ_TILE_RECORD_SIZE 50
#define PIZ_MAX_BRIEFINGS 4
#define PIZ_MAX_CHARACTERS 4
#define PIZ_MAX_MAPOBJECTS 4
#define PIZ_MAX_PERSONS 8
#define PIZ_MAX_CARS 4
#define PIZ_MAX_PLAYERS 6
#define PIZ_MAX_COMPANIES 6
#define PIZ_MAX_BRANCHES_PER_COMPANY 4
#define PIZ_MAX_PLANS_PER_COMPANY 2
#define PIZ_MAX_PAIRS_PER_COMPANY 2
#define PIZ_MAX_BIG_PER_COMPANY 1
#define PIZ_MAX_RECIPES_PER_COMPANY 4
#define PIZ_MAX_TOPPINGS_PER_RECIPE 8
#define PIZ_RECIPE_INCOME_CATEGORIES 26
#define PIZ_RECIPE_EXPENSE_CATEGORIES 25
#define PIZ_MAX_REPORTS_PER_COMPANY 2
#define PIZ_MAX_STORAGE_PER_COMPANY 2
#define PIZ_MAX_CONTAINER_SIZE 0x30000u

#pragma pack(push, 1)
typedef struct PizHeader {
    char title[0x40];
    char company[0x40];
    char city[0x40];
    uint8_t player_count;
    uint8_t player_flags[7];
    uint32_t game_calendar[4];
    uint16_t system_time[8];
    uint32_t version;
    uint32_t magic;
} PizHeader;

typedef struct PizBriefing {
    uint32_t id;
    char text[64];
} PizBriefing;

typedef struct PizCharacter {
    uint32_t id;
    char name[32];
    int32_t skill;
    int32_t motivation;
} PizCharacter;

typedef struct PizMapObject {
    uint32_t id;
    uint32_t type;
    uint32_t owner_slot;
    uint32_t tile_index;
    uint32_t state;
} PizMapObject;

typedef struct PizPerson {
    uint32_t id;
    uint32_t profession;
    uint32_t branch_id;
    int32_t skill;
} PizPerson;

typedef struct PizCar {
    uint32_t id;
    uint32_t type;
} PizCar;

typedef struct PizPlayer {
    uint32_t present;
    uint32_t slot;
    char name[32];
    double cash;
} PizPlayer;

typedef struct PizRecipeTopping {
    uint8_t ingredient;
    uint8_t category;
    uint8_t tier;
    int32_t x;
    int32_t y;
    uint8_t variant;
    uint8_t flag;
} PizRecipeTopping;

typedef struct PizBranchRecord {
    uint32_t id;
    char name[32];
    uint32_t style;
    uint32_t flags;
    uint32_t company_slot;
} PizBranchRecord;

typedef struct PizReportRecord {
    float income[PIZ_RECIPE_INCOME_CATEGORIES];
    float expense[PIZ_RECIPE_EXPENSE_CATEGORIES];
} PizReportRecord;

typedef struct PizPlanRecord {
    uint32_t active;          /* +0x04 */
    uint32_t type;            /* +0x08 */
    uint32_t media_type;      /* +0x10 */
    uint32_t flags;           /* +0x14 */
    uint32_t ingredient_index;/* +0x18 */
    uint32_t target_company;  /* +0x1C */
    uint32_t budget;          /* +0x20 */
    uint32_t target_billboard;/* +0x2C */
    uint32_t branch_id;       /* +0x0C */
    uint32_t unused;          /* +0x24 */
    uint32_t effect;          /* +0x28 */
} PizPlanRecord;

typedef struct PizPairRecord {
    uint32_t id;    /* company object ID */
    uint32_t type;  /* object type, e.g. 0x17 */
    uint32_t state; /* object state */
} PizPairRecord;

typedef struct PizBigRecord {
    uint32_t total_customers;  /* +0x60 */
    uint32_t max_customers;    /* +0x64 */
    uint32_t total_profit;     /* +0x68 */
    uint32_t max_profit;       /* +0x6C */
    uint32_t total_ratio;      /* +0x70 */
    uint32_t max_ratio;        /* +0x74 */
    uint32_t value_78;         /* +0x78 */
    uint32_t value_7c;         /* +0x7C */
    uint32_t score_customers;  /* +0x190 */
    uint32_t score_profit;     /* +0x194 */
    uint32_t score_ratio;      /* +0x198 */
    uint32_t score_value;      /* +0x19C */
    uint32_t reserved[92];
} PizBigRecord;

typedef struct PizRecipeRecord {
    uint32_t id;
    char name[64];
    uint32_t topping_count;
    PizRecipeTopping toppings[PIZ_MAX_TOPPINGS_PER_RECIPE];
} PizRecipeRecord;

typedef struct PizStorageRecord {
    uint32_t id;
    char name[32];
} PizStorageRecord;

typedef struct PizCompany {
    uint32_t present;
    uint32_t slot;
    char name[32];
    double cash;
    uint32_t plan_count;
    PizPlanRecord plans[PIZ_MAX_PLANS_PER_COMPANY];
    uint32_t recipe_count;
    PizRecipeRecord recipes[PIZ_MAX_RECIPES_PER_COMPANY];
    uint32_t branch_count;
    PizBranchRecord branches[PIZ_MAX_BRANCHES_PER_COMPANY];
    uint32_t report_count;
    PizReportRecord reports[PIZ_MAX_REPORTS_PER_COMPANY];
    uint32_t storage_count;
    PizStorageRecord storage[PIZ_MAX_STORAGE_PER_COMPANY];
    uint32_t pair_count;
    PizPairRecord pairs[PIZ_MAX_PAIRS_PER_COMPANY];
    uint32_t big_count;
    PizBigRecord big[PIZ_MAX_BIG_PER_COMPANY];
    uint32_t share_x100;
} PizCompany;

typedef struct PizContainer {
    PizHeader header;
    SaveState save;
    uint32_t briefing_count;
    PizBriefing briefings[PIZ_MAX_BRIEFINGS];
    char tile_names[PIZ_TILE_COUNT][PIZ_TILE_RECORD_SIZE];
    uint32_t character_count;
    PizCharacter characters[PIZ_MAX_CHARACTERS];
    uint32_t mapobject_count;
    PizMapObject mapobjects[PIZ_MAX_MAPOBJECTS];
    uint32_t person_count;
    PizPerson persons[PIZ_MAX_PERSONS];
    uint32_t car_count;
    PizCar cars[PIZ_MAX_CARS];
    PizPlayer players[PIZ_MAX_PLAYERS];
    PizCompany companies[PIZ_MAX_COMPANIES];
} PizContainer;
#pragma pack(pop)

/*
 * Expanded .piz save container reconstructed from save_schema.json and
 * tools/piz_payload.py. It keeps the real 0xF0 header, 0x20 directory,
 * fixed preamble through the 25-byte game calendar, variable briefing list,
 * 2500 x 50-byte tile-name table, then directory-bounded character,
 * map-object, person, car, player and company regions.
 */
void piz_container_init(PizContainer *container, const char *title,
                        const char *company, const char *city);
bool piz_container_add_briefing(PizContainer *container, uint32_t id,
                                const char *text);
bool piz_container_set_tile_name(PizContainer *container, uint32_t index,
                                 const char *name);
size_t piz_container_size(const PizContainer *container);
size_t piz_container_encode(const PizContainer *container, uint8_t *buffer,
                            size_t capacity);
bool piz_container_decode(PizContainer *container, const uint8_t *buffer,
                          size_t length);

#endif
