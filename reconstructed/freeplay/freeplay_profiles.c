#include "freeplay_profiles.h"

#include <string.h>

int32_t freeplay_compute_starting_cash(int32_t multiplier, int32_t capital) {
    /* The original uses 32-bit imul followed by the /100 magic sequence, so
     * the product wraps at 32 bits before the signed division. */
    uint32_t product = (uint32_t)multiplier * (uint32_t)capital;
    int32_t signed_product;
    memcpy(&signed_product, &product, sizeof(signed_product));
    return signed_product / 100;
}

void freeplay_profile_apply_defaults(FreePlayProfile *profile) {
    if (profile == NULL) {
        return;
    }
    profile->cash_multiplier = FREEPLAY_PROFILE_DEFAULT_MULTIPLIER;
    profile->active = 1;
}

int32_t freeplay_profile_cash_multiplier(const FreePlayProfile *profile) {
    return profile == NULL ? 0 : profile->cash_multiplier;
}

bool freeplay_profile_is_active(const FreePlayProfile *profile) {
    return profile != NULL && profile->active != 0;
}
