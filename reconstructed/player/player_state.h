#ifndef PC2_RECONSTRUCTED_PLAYER_STATE_H
#define PC2_RECONSTRUCTED_PLAYER_STATE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "../character/character_state.h"

/* Player object, allocation size 0xB0.
 *
 * Evidence:
 * - Player_Construct (0x50E8E0) installs the vtable, constructs the event
 *   list at +0x8C and initializes the scalar fields.
 * - Player_Save (0x50EA90) / Player_Load (0x50ECA0) serialize the exact
 *   sequence below; Player_Save calls Character_Save on the +0x04 pointer.
 * - Game_InitScenario 0x4820C7 allocates 0xB0 bytes and calls the constructor
 *   at 0x4820E8.
 * - Game_InitScenario writes the slot to +0x08, copies the 32-byte player
 *   name to +0x0C and the six character values to +0x3C..+0x50.
 */
typedef struct PlayerEventList {
    uint32_t vtable;              /* +0x00 */
    uint32_t entries;             /* +0x04, 32-bit original address */
    uint32_t keys;                /* +0x08, 32-bit original address */
    int32_t count;                /* +0x0C */
    int32_t capacity;             /* +0x10 */
    int32_t total_added;          /* +0x14, saved as the event count */
    int32_t next_key;             /* +0x18 */
} PlayerEventList;

/* Player award/event node, allocation size 0xC.
 * Player_Event_StreamConstruct 0x5019D0; Save/Load 0x501A40/0x501A70.
 *
 * Every List_Add into Player+0x8C was audited: City_SettleAdvertisingCampaign
 * 0x4DCE70 writes 0, City_GenerateRatingNews 0x4D9780 writes 1 and 2, and
 * Player_Load restores serialized values. */
typedef enum PlayerEventType {
    PLAYER_EVENT_CITY_PRIZE = 0,       /* advertising-campaign prize */
    PLAYER_EVENT_BEST_RESTAURANT = 1,  /* best composite-rated branch */
    PLAYER_EVENT_BEST_BUILDING = 2,    /* best-quality building */
    PLAYER_EVENT_TYPE_COUNT = 3
} PlayerEventType;

typedef struct PlayerEvent {
    uint32_t vtable;              /* +0x00 */
    int32_t event_type;           /* +0x04, PlayerEventType */
    uint16_t date_word;           /* +0x08, copied from g_Game+0x94+4 */
    uint8_t padding_a[2];         /* +0x0A..+0x0B */
} PlayerEvent;

typedef struct Player {
    uint32_t vtable;              /* +0x00 */
    uint32_t character;           /* +0x04, Character* in the original */
    int32_t slot;                 /* +0x08 */
    char player_name[0x20];       /* +0x0C..+0x2B */
    int32_t reserved_2c;          /* +0x2C, copied only by the cached-profile path */
    int32_t reserved_30;          /* +0x30, copied only by the cached-profile path */
    int32_t reserved_34;          /* +0x34, only constructor/save/load */
    int32_t attacks_fended_off;   /* +0x38, sixth achievement metric */
    int32_t character_values[6];  /* +0x3C: Buyer..Guard base values */
    int32_t achievement_bonus_values[6]; /* +0x54 */
    int32_t achievement_tiers[6]; /* +0x6C..+0x83, values 0..4 */
    int32_t reserved_84;          /* +0x84, written 1; no reader */
    int32_t award_briefing_enabled; /* +0x88, cleared for AI slots */
    PlayerEventList events;       /* +0x8C..+0xA7 */
    uint32_t ai_state;            /* +0xA8, optional PlayerAIState address */
    uint32_t mission_state;       /* +0xAC, optional PlayerMissionState address */
} Player;

enum {
    PLAYER_SIZE = 0xB0,
    PLAYER_NAME_CAPACITY = 0x20,
    PLAYER_CHARACTER_VALUE_COUNT = 6
};

_Static_assert(sizeof(PlayerEventList) == 0x1C,
               "PlayerEventList must stay 0x1C bytes");
_Static_assert(sizeof(Player) == PLAYER_SIZE, "Player must stay 0xB0 bytes");
_Static_assert(offsetof(Player, vtable) == 0x00, "vtable offset");
_Static_assert(offsetof(Player, character) == 0x04, "character offset");
_Static_assert(offsetof(Player, slot) == 0x08, "slot offset");
_Static_assert(offsetof(Player, player_name) == 0x0C, "name offset");
_Static_assert(offsetof(Player, reserved_2c) == 0x2C, "field 2c offset");
_Static_assert(offsetof(Player, reserved_30) == 0x30, "field 30 offset");
_Static_assert(offsetof(Player, reserved_34) == 0x34, "field 34 offset");
_Static_assert(offsetof(Player, attacks_fended_off) == 0x38,
               "field 38 offset");
_Static_assert(offsetof(Player, character_values) == 0x3C,
               "character values offset");
_Static_assert(offsetof(Player, achievement_bonus_values) == 0x54,
               "achievement bonus offset");
_Static_assert(offsetof(Player, achievement_tiers) == 0x6C,
               "achievement tiers offset");
_Static_assert(offsetof(Player, reserved_84) == 0x84, "field 84 offset");
_Static_assert(offsetof(Player, award_briefing_enabled) == 0x88,
               "field 88 offset");
_Static_assert(offsetof(Player, events) == 0x8C, "event list offset");
_Static_assert(offsetof(Player, ai_state) == 0xA8, "AI state offset");
_Static_assert(offsetof(Player, mission_state) == 0xAC,
               "mission state offset");
_Static_assert(offsetof(PlayerEventList, total_added) == 0x14,
               "event count offset");
_Static_assert(sizeof(PlayerEvent) == 0x0C, "PlayerEvent must stay 0xC");
_Static_assert(offsetof(PlayerEvent, event_type) == 0x04,
               "event type offset");
_Static_assert(offsetof(PlayerEvent, date_word) == 0x08, "date offset");
_Static_assert(PLAYER_EVENT_CITY_PRIZE == 0, "city prize event value");
_Static_assert(PLAYER_EVENT_BEST_RESTAURANT == 1, "restaurant event value");
_Static_assert(PLAYER_EVENT_BEST_BUILDING == 2, "building event value");

/* Deterministic constructor fields; the original installs vtable 0x55C684. */
void player_construct_fields(Player *player, uint32_t character_address,
                             int32_t slot, const char *name);

void player_set_character_values(Player *player, const int32_t values[6]);

/* Player_ResetAiState 0x50EFC0: called for every AI slot by Game_InitScenario.
 * The human slot keeps award briefings enabled; AI slots do not.
 * The byte-offset leaf equivalent is leaf/leaf_functions.c:player_reset_ai_state. */
void player_apply_ai_slot_defaults(Player *player);

/* One of the four attack-outcome writers (Person_ApplyAttackOutcome 0x50C0F0,
 * Person_ResolveGroupFight 0x50C2E0, Object_ActionRemove 0x50A580,
 * Character_OnArriveAtDestination 0x50D930) increments this counter. */
void player_record_attack_fended_off(Player *player);

/* Player_MissionState_Tick 0x50EFE0: advance one achievement tier and its
 * matching bonus character value. Tier metrics:
 * 0 employees 25/50/100/150, 1 attacks carried out 10/50/100/150,
 * 2 medals 1/5/10/15, 3 restaurants 2/4/6/8,
 * 4 quarterly sales 100k/200k/300k/400k, 5 attacks fended off 1/10/50/100. */
bool player_advance_achievement(Player *player, size_t index);

void player_event_init(PlayerEvent *event, int32_t event_type,
                       uint16_t date_word);

/* Player_Save writes events.total_added at +0xA0 (= list+0x14). */
int32_t player_saved_event_count(const Player *player);

#endif
