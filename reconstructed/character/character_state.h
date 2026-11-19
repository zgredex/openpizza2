#ifndef PC2_RECONSTRUCTED_CHARACTER_STATE_H
#define PC2_RECONSTRUCTED_CHARACTER_STATE_H

#include <stddef.h>
#include <stdint.h>

/* Character object at allocation size 0x828.
 *
 * Evidence:
 * - Character_Construct (0x4D3730) writes the vtable, sentinels, skills,
 *   appearance, age, timers, the 500-dword rating array and the tail IDs.
 * - Character_Save (0x4D3BA0) / Character_Load (0x4D3A50) serialize the
 *   exact field sequence below; both use the same offsets and widths.
 * - Person_SetSkill/Speed/Motivation/Health/Performance (0x4D4130/0x4D4140/
 *   0x4D4120/0x4D4150/0x4D4160) identify +0x04/+0x08/+0x0C/+0x10/+0x3C.
 * - Rating_DecayAndUpdateIndicators (0x4D4170) identifies the four signed
 *   timers at +0x14/+0x18/+0x1C/+0x20.
 * - Character_ComputeRatingArray (0x4AF7A0) fills rating data from +0x44.
 * - Game_InitScenario fills the appearance block +0x24..+0x34.
 */
typedef struct Character {
    uint32_t vtable;              /* +0x00 */
    int32_t skill;                /* +0x04 */
    int32_t speed;                /* +0x08 */
    int32_t motivation;           /* +0x0C */
    int32_t health;               /* +0x10 */
    int32_t skill_timer;          /* +0x14, signed decay countdown */
    int32_t speed_timer;          /* +0x18 */
    int32_t motivation_timer;     /* +0x1C */
    int32_t health_timer;         /* +0x20 */
    int32_t gender;               /* +0x24 */
    int32_t hair;                 /* +0x28 */
    int32_t eyes;                 /* +0x2C */
    int32_t mouth;                /* +0x30 */
    int32_t head;                 /* +0x34 */
    int32_t age;                  /* +0x38 */
    int32_t performance;          /* +0x3C */
    int32_t field_40;             /* +0x40, saved; constructor writes 0 */
    int32_t rating_data[500];     /* +0x44..+0x813 */
    int32_t registry_id;          /* +0x814, g_Game+0x3C map key */
    int32_t object_id;            /* +0x818 */
    int32_t player_slot;          /* +0x81C */
    int32_t branch_id;            /* +0x820 */
    uint8_t profession_type;      /* +0x824, 0..3 */
    uint8_t activity_state;       /* +0x825, constructor writes 2 */
    uint8_t padding_826[2];       /* +0x826..+0x827 */
} Character;

enum {
    CHARACTER_SIZE = 0x828,
    CHARACTER_RATING_COUNT = 500,
    CHARACTER_RATING_BLOCK_COUNT = 5,
    CHARACTER_RATING_BLOCK_SIZE = 100,
    CHARACTER_SKILL_MIN = 0x1E,
    CHARACTER_SKILL_MAX = 0x46,
    CHARACTER_AGE_MIN = 0x12,
    CHARACTER_AGE_MAX = 0x3C
};

_Static_assert(sizeof(Character) == CHARACTER_SIZE,
               "Character must stay 0x828 bytes");
_Static_assert(offsetof(Character, vtable) == 0x000, "vtable offset");
_Static_assert(offsetof(Character, skill) == 0x004, "skill offset");
_Static_assert(offsetof(Character, speed) == 0x008, "speed offset");
_Static_assert(offsetof(Character, motivation) == 0x00C, "motivation offset");
_Static_assert(offsetof(Character, health) == 0x010, "health offset");
_Static_assert(offsetof(Character, skill_timer) == 0x014, "skill timer offset");
_Static_assert(offsetof(Character, speed_timer) == 0x018, "speed timer offset");
_Static_assert(offsetof(Character, motivation_timer) == 0x01C,
               "motivation timer offset");
_Static_assert(offsetof(Character, health_timer) == 0x020, "health timer offset");
_Static_assert(offsetof(Character, gender) == 0x024, "gender offset");
_Static_assert(offsetof(Character, hair) == 0x028, "hair offset");
_Static_assert(offsetof(Character, eyes) == 0x02C, "eyes offset");
_Static_assert(offsetof(Character, mouth) == 0x030, "mouth offset");
_Static_assert(offsetof(Character, head) == 0x034, "head offset");
_Static_assert(offsetof(Character, age) == 0x038, "age offset");
_Static_assert(offsetof(Character, performance) == 0x03C, "performance offset");
_Static_assert(offsetof(Character, field_40) == 0x040, "field 40 offset");
_Static_assert(offsetof(Character, rating_data) == 0x044, "rating offset");
_Static_assert(offsetof(Character, registry_id) == 0x814, "registry offset");
_Static_assert(offsetof(Character, object_id) == 0x818, "object offset");
_Static_assert(offsetof(Character, player_slot) == 0x81C, "player slot offset");
_Static_assert(offsetof(Character, branch_id) == 0x820, "branch offset");
_Static_assert(offsetof(Character, profession_type) == 0x824,
               "profession offset");
_Static_assert(offsetof(Character, activity_state) == 0x825,
               "activity state offset");
_Static_assert(offsetof(Character, rating_data) +
                   CHARACTER_RATING_BLOCK_SIZE * 4 == 0x1D4,
               "rating block 1 offset");
_Static_assert(offsetof(Character, rating_data) +
                   CHARACTER_RATING_BLOCK_SIZE * 8 == 0x364,
               "rating block 2 offset");
_Static_assert(offsetof(Character, rating_data) +
                   CHARACTER_RATING_BLOCK_SIZE * 12 == 0x4F4,
               "rating block 3 offset");
_Static_assert(offsetof(Character, rating_data) +
                   CHARACTER_RATING_BLOCK_SIZE * 16 == 0x684,
               "rating block 4 offset");

/* Constructor-side deterministic fields.  The original also randomizes the
 * four skills (30..70) and age (18..60); callers supply those values. */
void character_construct_fields(Character *character, int32_t skill,
                                int32_t speed, int32_t motivation,
                                int32_t health, int32_t age,
                                uint8_t profession_type);

/* Rating_DecayAndUpdateIndicators (0x4D4170): move each signed timer toward
 * zero and apply the same delta to its stat. */
void character_apply_decay_timers(Character *character);

/* Person_SetPerformance (0x4D4160). */
void character_set_performance(Character *character, int32_t value);

int32_t character_rating_block(const Character *character, size_t block,
                               size_t index);

#endif
