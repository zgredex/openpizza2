#include "recipe_state.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static void assert_close(double actual, double expected, double tolerance) {
    assert(fabs(actual - expected) <= tolerance);
}

static void test_recipe_and_price(void) {
    Recipe recipe;
    recipe_init(&recipe, 42, "Margherita", 12.0, 1);
    assert(recipe.id == 42);
    assert(strcmp(recipe.name, "Margherita") == 0);
    assert(recipe.base_price == 12.0);
    assert(recipe.category == 1);
    assert(!recipe.on_menu);
    assert(recipe.topping_count == 0);

    assert(recipe_add_topping(&recipe, 487, 2, 0, 0));
    assert(recipe_add_topping(&recipe, 505, 1, 1, 1));
    assert(recipe.topping_count == 2);
    assert(recipe.toppings[0].ingredient_id == 487);
    assert(recipe.toppings[1].part == 1);

    assert_close(recipe_compute_price(&recipe, 100.0, 1.0, 0.0), 12.0, 1e-12);
    assert_close(recipe_compute_price(&recipe, 110.0, 1.2, 0.5), 16.34, 1e-12);

    recipe_set_on_menu(&recipe, true);
    assert(recipe.on_menu);
    recipe_record_sale(&recipe, 3);
    recipe_record_sale(&recipe, 2);
    assert(recipe.sales == 5);
}

static void test_branch_menu_assignment(void) {
    BranchMenu menu;
    branch_menu_init(&menu, 1);
    assert(menu.count == 0);
    assert(menu.category == 1);

    Recipe first;
    recipe_init(&first, 1, "Margherita", 12.0, 1);
    recipe_add_topping(&first, 487, 1, 0, 0);
    Recipe second;
    recipe_init(&second, 2, "Diavola", 14.0, 1);
    recipe_add_topping(&second, 509, 2, 0, 1);

    assert(branch_menu_add(&menu, &first));
    assert(branch_menu_add(&menu, &second));
    assert(menu.count == 2);
    assert(menu.recipes[0].on_menu);
    assert(!branch_menu_add(&menu, &first));

    Recipe *found = branch_menu_find(&menu, 2);
    assert(found != NULL);
    assert(strcmp(found->name, "Diavola") == 0);

    assert(branch_menu_remove(&menu, 1));
    assert(menu.count == 1);
    assert(branch_menu_find(&menu, 1) == NULL);
    assert(branch_menu_find(&menu, 2) != NULL);
    assert(!branch_menu_remove(&menu, 99));
}

int main(void) {
    test_recipe_and_price();
    test_branch_menu_assignment();
    puts("recipe menu reconstruction: OK");
    return 0;
}
