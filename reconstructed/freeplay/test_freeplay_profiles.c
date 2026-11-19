#include "freeplay_profiles.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_layout(void) {
    assert(sizeof(FreePlayProfile) == 0xC0);
    assert(offsetof(FreePlayProfile, cash_multiplier) == 0x00);
    assert(offsetof(FreePlayProfile, gender) == 0x20);
    assert(offsetof(FreePlayProfile, hair) == 0x24);
    assert(offsetof(FreePlayProfile, eyes) == 0x28);
    assert(offsetof(FreePlayProfile, mouth) == 0x2C);
    assert(offsetof(FreePlayProfile, head) == 0x30);
    assert(offsetof(FreePlayProfile, logo) == 0x34);
    assert(offsetof(FreePlayProfile, color) == 0x38);
    assert(offsetof(FreePlayProfile, active) == 0x3C);
    assert(FREEPLAY_PROFILE_COUNT == 6);
    assert(sizeof(FreePlayCharacterAppearance) == 0x828);
    assert(offsetof(FreePlayCharacterAppearance, gender) == 0x24);
    assert(offsetof(FreePlayCharacterAppearance, hair) == 0x28);
    assert(offsetof(FreePlayCharacterAppearance, eyes) == 0x2C);
    assert(offsetof(FreePlayCharacterAppearance, mouth) == 0x30);
    assert(offsetof(FreePlayCharacterAppearance, head) == 0x34);
}

static void test_starting_cash(void) {
    assert(freeplay_compute_starting_cash(100, 50000) == 50000);
    assert(freeplay_compute_starting_cash(50, 50000) == 25000);
    assert(freeplay_compute_starting_cash(150, 1000000) == 1500000);
    assert(freeplay_compute_starting_cash(0, 50000) == 0);
    assert(freeplay_compute_starting_cash(-50, 50000) == -25000);
    /* 0x10000 * 0x10000 wraps to zero in the original 32-bit imul. */
    assert(freeplay_compute_starting_cash(0x10000, 0x10000) == 0);
}

static void test_defaults_and_accessors(void) {
    FreePlayProfile profile;
    memset(&profile, 0xAA, sizeof(profile));
    freeplay_profile_apply_defaults(&profile);
    assert(profile.cash_multiplier == 100);
    assert(profile.active == 1);
    assert(profile.unknown_04[0] == 0xAA);
    assert(profile.unknown_04[0x1B] == 0xAA);
    assert(profile.gender == (int32_t)0xAAAAAAAAu);
    assert(profile.hair == (int32_t)0xAAAAAAAAu);
    assert(profile.eyes == (int32_t)0xAAAAAAAAu);
    assert(profile.mouth == (int32_t)0xAAAAAAAAu);
    assert(profile.head == (int32_t)0xAAAAAAAAu);
    assert(profile.logo == (int32_t)0xAAAAAAAAu);
    assert(profile.color == (int32_t)0xAAAAAAAAu);
    assert(profile.unknown_40[0] == 0xAA);
    assert(profile.unknown_40[0x7F] == 0xAA);

    assert(freeplay_profile_cash_multiplier(&profile) == 100);
    assert(freeplay_profile_is_active(&profile));
    assert(freeplay_profile_cash_multiplier(NULL) == 0);
    assert(!freeplay_profile_is_active(NULL));

    FreePlayProfile profiles[FREEPLAY_PROFILE_COUNT];
    memset(profiles, 0, sizeof(profiles));
    for (int index = 0; index < FREEPLAY_PROFILE_COUNT; index++) {
        freeplay_profile_apply_defaults(&profiles[index]);
        profiles[index].cash_multiplier = 100 + index;
    }
    for (int index = 0; index < FREEPLAY_PROFILE_COUNT; index++) {
        const FreePlayProfile *slot =
            (const FreePlayProfile *)((const uint8_t *)profiles +
                                      (size_t)index * FREEPLAY_PROFILE_STRIDE);
        assert(freeplay_profile_cash_multiplier(slot) == 100 + index);
        assert(freeplay_profile_is_active(slot));
    }
    profiles[3].active = 0;
    assert(!freeplay_profile_is_active(&profiles[3]));
}

static void test_appearance_copy(void) {
    FreePlayProfile profile;
    memset(&profile, 0, sizeof(profile));
    profile.gender = 1;
    profile.hair = 2;
    profile.eyes = 3;
    profile.mouth = 4;
    profile.head = 5;
    profile.logo = 6;
    profile.color = 7;
    FreePlayCharacterAppearance character;
    memset(&character, 0xAA, sizeof(character));
    freeplay_profile_copy_appearance(&profile, &character);
    assert(character.gender == 1);
    assert(character.hair == 2);
    assert(character.eyes == 3);
    assert(character.mouth == 4);
    assert(character.head == 5);
    assert(character.unknown_00[0] == 0xAA);
    assert(character.unknown_38[0] == 0xAA);
}

int main(void) {
    test_layout();
    test_starting_cash();
    test_defaults_and_accessors();
    test_appearance_copy();
    puts("free-play profile reconstruction: OK");
    return 0;
}
