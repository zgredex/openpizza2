#ifndef PC2_RECONSTRUCTED_PLAYER_STATE_H
#define PC2_RECONSTRUCTED_PLAYER_STATE_H

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

typedef struct Player {
    uint32_t vtable;              /* +0x00 */
    uint32_t character;           /* +0x04, Character* in the original */
    int32_t slot;                 /* +0x08 */
    char player_name[0x20];       /* +0x0C..+0x2B */
    int32_t field_2c;             /* +0x2C */
    int32_t field_30;             /* +0x30 */
    int32_t field_34;             /* +0x34 */
    int32_t field_38;             /* +0x38 */
    int32_t character_values[6];  /* +0x3C: Buyer..Guard base values */
    int32_t extra_character_values[6]; /* +0x54 */
    int32_t field_6c[6];          /* +0x6C..+0x83 */
    int32_t field_84;             /* +0x84, constructor writes 1 */
    int32_t field_88;             /* +0x88, constructor writes 1 */
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
_Static_assert(offsetof(Player, field_2c) == 0x2C, "field 2c offset");
_Static_assert(offsetof(Player, field_30) == 0x30, "field 30 offset");
_Static_assert(offsetof(Player, field_34) == 0x34, "field 34 offset");
_Static_assert(offsetof(Player, field_38) == 0x38, "field 38 offset");
_Static_assert(offsetof(Player, character_values) == 0x3C,
               "character values offset");
_Static_assert(offsetof(Player, extra_character_values) == 0x54,
               "extra character values offset");
_Static_assert(offsetof(Player, field_6c) == 0x6C, "field 6c offset");
_Static_assert(offsetof(Player, field_84) == 0x84, "field 84 offset");
_Static_assert(offsetof(Player, field_88) == 0x88, "field 88 offset");
_Static_assert(offsetof(Player, events) == 0x8C, "event list offset");
_Static_assert(offsetof(Player, ai_state) == 0xA8, "AI state offset");
_Static_assert(offsetof(Player, mission_state) == 0xAC,
               "mission state offset");
_Static_assert(offsetof(PlayerEventList, total_added) == 0x14,
               "event count offset");

/* Deterministic constructor fields; the original installs vtable 0x55C684. */
void player_construct_fields(Player *player, uint32_t character_address,
                             int32_t slot, const char *name);

void player_set_character_values(Player *player, const int32_t values[6]);

/* Player_Save writes events.total_added at +0xA0 (= list+0x14). */
int32_t player_saved_event_count(const Player *player);

#endif
