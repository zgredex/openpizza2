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
    uint8_t unknown_04[0x38];   /* +0x04..+0x3B */
    int32_t active;             /* +0x3C */
    uint8_t unknown_40[0x80];   /* +0x40..+0xBF */
} FreePlayProfile;

enum {
    FREEPLAY_PROFILE_COUNT = 6,
    FREEPLAY_PROFILE_STRIDE = 0xC0,
    FREEPLAY_PROFILE_CASH_OFFSET = 0x00,
    FREEPLAY_PROFILE_ACTIVE_OFFSET = 0x3C,
    FREEPLAY_PROFILE_DEFAULT_MULTIPLIER = 100,
    FREEPLAY_PROFILE_DEFAULT_CAPITAL = 50000
};

_Static_assert(sizeof(FreePlayProfile) == FREEPLAY_PROFILE_STRIDE,
               "FreePlayProfile must stay 0xC0 bytes");
_Static_assert(offsetof(FreePlayProfile, cash_multiplier) ==
                   FREEPLAY_PROFILE_CASH_OFFSET,
               "cash multiplier must stay at +0x00");
_Static_assert(offsetof(FreePlayProfile, active) ==
                   FREEPLAY_PROFILE_ACTIVE_OFFSET,
               "active flag must stay at +0x3C");
_Static_assert(FREEPLAY_PROFILE_COUNT == 6,
               "the setup array has six records");

/* Game_InitScenario 0x48203D..0x482059: (multiplier * capital) / 100. */
int32_t freeplay_compute_starting_cash(int32_t multiplier, int32_t capital);

/* Game_InitScenario 0x481EFE/0x481F01 default writes. */
void freeplay_profile_apply_defaults(FreePlayProfile *profile);

int32_t freeplay_profile_cash_multiplier(const FreePlayProfile *profile);
bool freeplay_profile_is_active(const FreePlayProfile *profile);

#endif
