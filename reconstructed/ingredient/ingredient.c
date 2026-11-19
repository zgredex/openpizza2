#include "ingredient.h"

#include <string.h>

_Static_assert(sizeof(Ingredient) == 0xd8, "ingredient object must stay 0xD8 bytes");
_Static_assert(offsetof(Ingredient, name) == 0x88, "name offset");
_Static_assert(offsetof(Ingredient, kind) == 0xa8, "kind offset");
_Static_assert(offsetof(Ingredient, price_class) == 0xac, "price class offset");
_Static_assert(offsetof(Ingredient, field_b0) == 0xb0, "field b0 offset");
_Static_assert(offsetof(Ingredient, field_b4) == 0xb4, "field b4 offset");
_Static_assert(offsetof(Ingredient, field_b8) == 0xb8, "field b8 offset");
_Static_assert(offsetof(Ingredient, field_c0) == 0xc0, "field c0 offset");
_Static_assert(offsetof(Ingredient, field_c4) == 0xc4, "field c4 offset");
_Static_assert(offsetof(Ingredient, flag_c8) == 0xc8, "flag c8 offset");
_Static_assert(offsetof(Ingredient, flag_cc) == 0xcc, "flag cc offset");
_Static_assert(offsetof(Ingredient, flag_cd) == 0xcd, "flag cd offset");

void game_set_building_desc(Ingredient *ingredient, const char *name,
                            uint8_t kind, uint32_t field_a, uint32_t field_b,
                            uint32_t field_c, uint32_t field_d, uint32_t field_e,
                            uint32_t field_f, uint8_t flag_g, uint8_t flag_h,
                            uint8_t flag_i, uint8_t flag_j, uint8_t flag_k,
                            uint8_t flag_l) {
    if (ingredient == NULL || name == NULL) {
        return;
    }
    strncpy(ingredient->name, name, sizeof(ingredient->name) - 1);
    ingredient->name[sizeof(ingredient->name) - 1] = '\0';

    ingredient->kind = kind;
    ingredient->price_class = field_a;
    ingredient->field_b0 = field_b;
    ingredient->field_b4 = field_c;
    ingredient->field_b8 = field_d;
    ingredient->field_c0 = field_e;
    ingredient->field_c4 = field_f;
    ingredient->flag_cc = flag_g;
    ingredient->flag_cd = flag_h;
    ingredient->flag_c8 = flag_i;
    ingredient->flag_c9 = flag_j;
    ingredient->flag_ca = flag_k;
    ingredient->flag_cb = flag_l;
}
