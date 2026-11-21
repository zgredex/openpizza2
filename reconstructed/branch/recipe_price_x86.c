#include <stddef.h>
#include <stdint.h>

/* The early and late fields remain opaque to this routine. */
typedef struct {
    uint8_t prefix[0x14a8];
    int32_t price_percent;
    int32_t price_offset;
} PriceBranch;

_Static_assert(offsetof(PriceBranch, price_percent) == 0x14a8, "price percent offset");
_Static_assert(offsetof(PriceBranch, price_offset) == 0x14ac, "price offset offset");

/* The original-image linker resolves these routines by address. */
extern long double __attribute__((fastcall)) branch_get_building_value(const PriceBranch *);
extern long double __attribute__((thiscall)) recipe_get_base_price(const void *);
extern const float pc2_price_percent_factor;

/* Branch_ComputeRecipePrice (0x513BF0) returns via x87 ST(0). */
long double __attribute__((thiscall))
branch_compute_recipe_price(const void *recipe, const PriceBranch *branch, int32_t percent) {
    if (percent == -999) {
        percent = branch->price_percent;
    }
    int32_t offset = branch->price_offset;
    long double building_value = branch_get_building_value(branch);
    /* The original stores the multiplier as a binary32 before using it. */
    volatile float multiplier = (long double)percent * pc2_price_percent_factor * building_value;
    return recipe_get_base_price(recipe) * multiplier + offset;
}
