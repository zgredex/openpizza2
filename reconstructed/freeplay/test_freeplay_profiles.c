#include "freeplay_profiles.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_layout(void) {
    assert(sizeof(FreePlayProfile) == 0xC0);
    assert(offsetof(FreePlayProfile, cash_multiplier) == 0x00);
    assert(offsetof(FreePlayProfile, active) == 0x3C);
    assert(FREEPLAY_PROFILE_COUNT == 6);
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
    assert(profile.unknown_04[0x37] == 0xAA);
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

int main(void) {
    test_layout();
    test_starting_cash();
    test_defaults_and_accessors();
    puts("free-play profile reconstruction: OK");
    return 0;
}
