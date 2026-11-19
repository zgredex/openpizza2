#ifndef PC2_RECONSTRUCTED_FREEPLAY_PROFILES_H
#define PC2_RECONSTRUCTED_FREEPLAY_PROFILES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Free-play player profile array at 0x57BC58.
 *
 * The six records are 0xC0 bytes each:
 *   +0x00..+0x3F  player name (64 bytes)
 *   +0x40..+0x7F  enterprise name (64 bytes)
 *   +0x80..+0xBF  settings:
 *                 +0x80 cash multiplier
 *                 +0x84 characteristic adjustment
 *                 +0x88..+0x9C Buyer/Gangsters/Specialist/Politicians/
 *                              Seller/Guard
 *                 +0xA0 gender, +0xA4 hair, +0xA8 eyes, +0xAC mouth,
 *                 +0xB0 head, +0xB4 logo, +0xB8 color, +0xBC active
 *
 * Evidence:
 * - SubStartMenu writes the player name to 0x57BC58 and the enterprise name
 *   to 0x57BC98 via String_Format (0x4C7B22..0x4C7B87).
 * - FreePlaySetup_InitWindow reads both names at 0x4CBD4F/0x4CBD60 and
 *   copies all 0xC0 bytes of record 0 for the preview (0x4CBD81).
 * - FreePlaySetup_InitWindow copies the settings arrays into record+0x80,
 *   +0x84 and +0xBC (0x4CBEBD/0x4CBEC3/0x4CBEC8).
 * - Game_InitScenario copies record+0x00 into Player+0x0C and formats the
 *   enterprise name from record+0x40 (0x481D90 lines 186/249).
 * - The remaining settings were proven by CharacterSelect, UI overlays and
 *   CompanyOverview; see typed_packets/freeplay_cash_multiplier.md.
 *
 * The old "profile base 0x57BCD8" was the settings half of record 0.  The
 * previously unknown +0x40..+0xBF covers record 1's player and enterprise
 * names, not unnamed fields of record 0.
 */
typedef struct FreePlayProfile {
    char player_name[0x40];         /* +0x00 */
    char company_name[0x40];        /* +0x40 */
    int32_t cash_multiplier;        /* +0x80, percent (100 = unchanged) */
    int32_t characteristic_adjust;  /* +0x84, -6..+6 AI adjustment points */
    int32_t buyer;                  /* +0x88, character value */
    int32_t gangsters;              /* +0x8C */
    int32_t specialist;             /* +0x90 */
    int32_t politicians;            /* +0x94 */
    int32_t seller;                 /* +0x98 */
    int32_t guard;                  /* +0x9C */
    int32_t gender;                 /* +0xA0, 0 = male, 1 = female */
    int32_t hair;                   /* +0xA4, 0..hair_count-1 */
    int32_t eyes;                   /* +0xA8, 0..eye_count-1 */
    int32_t mouth;                  /* +0xAC, 0..mouth_count-1 */
    int32_t head;                   /* +0xB0, 0..head_count-1 */
    int32_t logo;                   /* +0xB4, LOGOS__01..08 index 0..7 */
    int32_t color;                  /* +0xB8, color-table index 0..7 */
    int32_t active;                 /* +0xBC */
} FreePlayProfile;

/* Character appearance view used by UI_ComposeOverlayWindowFromRecord
 * (0x54BB00): the record stores gender/head/eyes/hair/mouth at these offsets.
 * Game_InitScenario copies profile +0xA0..+0xB0 into Character +0x24..+0x34. */
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
    FREEPLAY_PROFILE_PLAYER_NAME_OFFSET = 0x00,
    FREEPLAY_PROFILE_COMPANY_NAME_OFFSET = 0x40,
    FREEPLAY_PROFILE_CASH_OFFSET = 0x80,
    FREEPLAY_PROFILE_ADJUST_OFFSET = 0x84,
    FREEPLAY_PROFILE_BUYER_OFFSET = 0x88,
    FREEPLAY_PROFILE_GANGSTERS_OFFSET = 0x8C,
    FREEPLAY_PROFILE_SPECIALIST_OFFSET = 0x90,
    FREEPLAY_PROFILE_POLITICIANS_OFFSET = 0x94,
    FREEPLAY_PROFILE_SELLER_OFFSET = 0x98,
    FREEPLAY_PROFILE_GUARD_OFFSET = 0x9C,
    FREEPLAY_PROFILE_GENDER_OFFSET = 0xA0,
    FREEPLAY_PROFILE_HAIR_OFFSET = 0xA4,
    FREEPLAY_PROFILE_EYES_OFFSET = 0xA8,
    FREEPLAY_PROFILE_MOUTH_OFFSET = 0xAC,
    FREEPLAY_PROFILE_HEAD_OFFSET = 0xB0,
    FREEPLAY_PROFILE_LOGO_OFFSET = 0xB4,
    FREEPLAY_PROFILE_COLOR_OFFSET = 0xB8,
    FREEPLAY_PROFILE_ACTIVE_OFFSET = 0xBC,
    FREEPLAY_PROFILE_DEFAULT_MULTIPLIER = 100,
    FREEPLAY_PROFILE_DEFAULT_CAPITAL = 50000
};

_Static_assert(sizeof(FreePlayProfile) == FREEPLAY_PROFILE_STRIDE,
               "FreePlayProfile must stay 0xC0 bytes");
_Static_assert(offsetof(FreePlayProfile, player_name) ==
                   FREEPLAY_PROFILE_PLAYER_NAME_OFFSET,
               "player name must stay at +0x00");
_Static_assert(offsetof(FreePlayProfile, company_name) ==
                   FREEPLAY_PROFILE_COMPANY_NAME_OFFSET,
               "company name must stay at +0x40");
_Static_assert(offsetof(FreePlayProfile, cash_multiplier) ==
                   FREEPLAY_PROFILE_CASH_OFFSET,
               "cash multiplier must stay at +0x80");
_Static_assert(offsetof(FreePlayProfile, characteristic_adjust) ==
                   FREEPLAY_PROFILE_ADJUST_OFFSET,
               "characteristic adjustment must stay at +0x84");
_Static_assert(offsetof(FreePlayProfile, buyer) ==
                   FREEPLAY_PROFILE_BUYER_OFFSET,
               "buyer must stay at +0x88");
_Static_assert(offsetof(FreePlayProfile, gangsters) ==
                   FREEPLAY_PROFILE_GANGSTERS_OFFSET,
               "gangsters must stay at +0x8C");
_Static_assert(offsetof(FreePlayProfile, specialist) ==
                   FREEPLAY_PROFILE_SPECIALIST_OFFSET,
               "specialist must stay at +0x90");
_Static_assert(offsetof(FreePlayProfile, politicians) ==
                   FREEPLAY_PROFILE_POLITICIANS_OFFSET,
               "politicians must stay at +0x94");
_Static_assert(offsetof(FreePlayProfile, seller) ==
                   FREEPLAY_PROFILE_SELLER_OFFSET,
               "seller must stay at +0x98");
_Static_assert(offsetof(FreePlayProfile, guard) ==
                   FREEPLAY_PROFILE_GUARD_OFFSET,
               "guard must stay at +0x9C");
_Static_assert(offsetof(FreePlayProfile, gender) ==
                   FREEPLAY_PROFILE_GENDER_OFFSET,
               "gender must stay at +0xA0");
_Static_assert(offsetof(FreePlayProfile, hair) ==
                   FREEPLAY_PROFILE_HAIR_OFFSET,
               "hair must stay at +0xA4");
_Static_assert(offsetof(FreePlayProfile, eyes) ==
                   FREEPLAY_PROFILE_EYES_OFFSET,
               "eyes must stay at +0xA8");
_Static_assert(offsetof(FreePlayProfile, mouth) ==
                   FREEPLAY_PROFILE_MOUTH_OFFSET,
               "mouth must stay at +0xAC");
_Static_assert(offsetof(FreePlayProfile, head) ==
                   FREEPLAY_PROFILE_HEAD_OFFSET,
               "head must stay at +0xB0");
_Static_assert(offsetof(FreePlayProfile, logo) ==
                   FREEPLAY_PROFILE_LOGO_OFFSET,
               "logo must stay at +0xB4");
_Static_assert(offsetof(FreePlayProfile, color) ==
                   FREEPLAY_PROFILE_COLOR_OFFSET,
               "color must stay at +0xB8");
_Static_assert(offsetof(FreePlayProfile, active) ==
                   FREEPLAY_PROFILE_ACTIVE_OFFSET,
               "active flag must stay at +0xBC");
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

/* Game_InitScenario 0x481D90: one random +/-1 adjustment of a character value.
 * The original keeps every value strictly between -4 and 4. */
bool freeplay_adjust_characteristic(int32_t *value, int32_t delta);

/* Game_InitScenario 0x481D90: copies profile +0xA0..+0xB0 into Character
 * +0x24..+0x34. */
void freeplay_profile_copy_appearance(const FreePlayProfile *profile,
                                      FreePlayCharacterAppearance *character);

#endif
