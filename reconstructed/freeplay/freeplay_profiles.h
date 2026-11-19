#ifndef PC2_RECONSTRUCTED_FREEPLAY_PROFILES_H
#define PC2_RECONSTRUCTED_FREEPLAY_PROFILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Free-play player profile array at 0x57BCD8.
 *
 * Evidence:
 * - FreePlaySetup_InitWindow copies six 0xC0-stride records from the parallel
 *   settings arrays 0x57B97C/0x57B994/0x57B9AC (0x4CBEB7..0x4CBED1).
 * - Game_InitScenario indexes the array with player_index * 0xC0
 *   (0x482083/0x482089) and reads +0x00 and +0x3C.
 * - Game_InitScenario applies the default writes +0x00 = 100 and +0x3C = 1
 *   (0x481EFE/0x481F01).
 *
 * Field names stay offset-based until a save/load pair or broader reader set
 * proves a semantic name.  No save/load path for this array was found.
 */
typedef struct FreePlayProfile {
    int32_t cash_multiplier;    /* +0x00, percent (100 = unchanged) */
    uint8_t unknown_04[0x1C];   /* +0x04..+0x1F */
    int32_t gender;             /* +0x20, 0 = male, 1 = female */
    int32_t hair;               /* +0x24, 0..hair_count-1 */
    int32_t eyes;               /* +0x28, 0..eye_count-1 */
    int32_t mouth;              /* +0x2C, 0..mouth_count-1 */
    int32_t head;               /* +0x30, 0..head_count-1 */
    int32_t logo;               /* +0x34, LOGOS__01..08 index 0..7 */
    int32_t color;              /* +0x38, color-table index 0..7 */
    int32_t active;             /* +0x3C */
    uint8_t unknown_40[0x80];   /* +0x40..+0xBF */
} FreePlayProfile;

/* Character appearance view used by UI_ComposeOverlayWindowFromRecord
 * (0x54BB00): the record stores gender/head/eyes/hair/mouth at these offsets.
 * Game_InitScenario copies profile +0x20..+0x30 into Character +0x24..+0x34. */
typedef struct FreePlayCharacterAppearance {
    uint8_t unknown_00[0x24];
    int32_t gender;             /* +0x24 */
    int32_t hair;               /* +0x28 */
    int32_t eyes;               /* +0x2C */
    int32_t mouth;              /* +0x30 */
    int32_t head;               /* +0x34 */
    uint8_t unknown_38[0x7F0];
} FreePlayCharacterAppearance;

enum {
    FREEPLAY_PROFILE_COUNT = 6,
    FREEPLAY_PROFILE_STRIDE = 0xC0,
    FREEPLAY_PROFILE_CASH_OFFSET = 0x00,
    FREEPLAY_PROFILE_GENDER_OFFSET = 0x20,
    FREEPLAY_PROFILE_HAIR_OFFSET = 0x24,
    FREEPLAY_PROFILE_EYES_OFFSET = 0x28,
    FREEPLAY_PROFILE_MOUTH_OFFSET = 0x2C,
    FREEPLAY_PROFILE_HEAD_OFFSET = 0x30,
    FREEPLAY_PROFILE_LOGO_OFFSET = 0x34,
    FREEPLAY_PROFILE_COLOR_OFFSET = 0x38,
    FREEPLAY_PROFILE_ACTIVE_OFFSET = 0x3C,
    FREEPLAY_PROFILE_DEFAULT_MULTIPLIER = 100,
    FREEPLAY_PROFILE_DEFAULT_CAPITAL = 50000
};

_Static_assert(sizeof(FreePlayProfile) == FREEPLAY_PROFILE_STRIDE,
               "FreePlayProfile must stay 0xC0 bytes");
_Static_assert(offsetof(FreePlayProfile, cash_multiplier) ==
                   FREEPLAY_PROFILE_CASH_OFFSET,
               "cash multiplier must stay at +0x00");
_Static_assert(offsetof(FreePlayProfile, gender) ==
                   FREEPLAY_PROFILE_GENDER_OFFSET,
               "gender must stay at +0x20");
_Static_assert(offsetof(FreePlayProfile, hair) ==
                   FREEPLAY_PROFILE_HAIR_OFFSET,
               "hair must stay at +0x24");
_Static_assert(offsetof(FreePlayProfile, eyes) ==
                   FREEPLAY_PROFILE_EYES_OFFSET,
               "eyes must stay at +0x28");
_Static_assert(offsetof(FreePlayProfile, mouth) ==
                   FREEPLAY_PROFILE_MOUTH_OFFSET,
               "mouth must stay at +0x2C");
_Static_assert(offsetof(FreePlayProfile, head) ==
                   FREEPLAY_PROFILE_HEAD_OFFSET,
               "head must stay at +0x30");
_Static_assert(offsetof(FreePlayProfile, logo) ==
                   FREEPLAY_PROFILE_LOGO_OFFSET,
               "logo must stay at +0x34");
_Static_assert(offsetof(FreePlayProfile, color) ==
                   FREEPLAY_PROFILE_COLOR_OFFSET,
               "color must stay at +0x38");
_Static_assert(offsetof(FreePlayProfile, active) ==
                   FREEPLAY_PROFILE_ACTIVE_OFFSET,
               "active flag must stay at +0x3C");
_Static_assert(FREEPLAY_PROFILE_COUNT == 6,
               "the setup array has six records");
_Static_assert(sizeof(FreePlayCharacterAppearance) == 0x828,
               "character view must match the 0x828-byte object");
_Static_assert(offsetof(FreePlayCharacterAppearance, gender) == 0x24,
               "character gender must stay at +0x24");
_Static_assert(offsetof(FreePlayCharacterAppearance, hair) == 0x28,
               "character hair must stay at +0x28");
_Static_assert(offsetof(FreePlayCharacterAppearance, eyes) == 0x2C,
               "character eyes must stay at +0x2C");
_Static_assert(offsetof(FreePlayCharacterAppearance, mouth) == 0x30,
               "character mouth must stay at +0x30");
_Static_assert(offsetof(FreePlayCharacterAppearance, head) == 0x34,
               "character head must stay at +0x34");

/* Game_InitScenario 0x48203D..0x482059: (multiplier * capital) / 100. */
int32_t freeplay_compute_starting_cash(int32_t multiplier, int32_t capital);

/* Game_InitScenario 0x481EFE/0x481F01 default writes. */
void freeplay_profile_apply_defaults(FreePlayProfile *profile);

int32_t freeplay_profile_cash_multiplier(const FreePlayProfile *profile);
bool freeplay_profile_is_active(const FreePlayProfile *profile);

/* Game_InitScenario 0x481D90: copies profile +0x20..+0x30 into Character
 * +0x24..+0x34. */
void freeplay_profile_copy_appearance(const FreePlayProfile *profile,
                                      FreePlayCharacterAppearance *character);

#endif
