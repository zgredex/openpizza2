#include "ingredient.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_olives_descriptor(void) {
    Ingredient ingredient;
    memset(&ingredient, 0xaa, sizeof(ingredient));

    game_set_building_desc(&ingredient, "Olives", 1, 7, 4, 2, 1, 0, 0x402e0000u,
                           0, 0xff, 1, 0, 0, 0);

    assert(strcmp(ingredient.name, "Olives") == 0);
    assert(ingredient.kind == 1);
    assert(ingredient.price_class == 7);
    assert(ingredient.field_b0 == 4);
    assert(ingredient.field_b4 == 2);
    assert(ingredient.field_b8 == 1);
    assert(ingredient.field_c0 == 0);
    assert(ingredient.field_c4 == 0x402e0000u);
    assert(ingredient.flag_c8 == 1);
    assert(ingredient.flag_c9 == 0);
    assert(ingredient.flag_ca == 0);
    assert(ingredient.flag_cb == 0);
    assert(ingredient.flag_cc == 0);
    assert(ingredient.flag_cd == 0xff);
}

int main(void) {
    test_olives_descriptor();
    puts("ingredient descriptor reconstruction: OK");
    return 0;
}
