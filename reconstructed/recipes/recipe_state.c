#include "recipe_state.h"

#include <string.h>

void recipe_init(Recipe *recipe, uint32_t id, const char *name, double base_price,
                 uint32_t category) {
    if (recipe == NULL) {
        return;
    }
    memset(recipe, 0, sizeof(*recipe));
    recipe->id = id;
    if (name != NULL) {
        strncpy(recipe->name, name, sizeof(recipe->name) - 1);
    }
    recipe->base_price = base_price;
    recipe->category = category;
    recipe->on_menu = false;
    recipe->sales = 0;
    recipe->quality = 0;
}

bool recipe_add_topping(Recipe *recipe, uint32_t ingredient_id, uint32_t quantity,
                        uint8_t part, uint8_t sliced) {
    if (recipe == NULL || recipe->topping_count >= RECIPE_MAX_TOPPINGS) {
        return false;
    }
    recipe->toppings[recipe->topping_count] = (RecipeTopping){
        .ingredient_id = ingredient_id,
        .quantity = quantity,
        .part = part,
        .sliced = sliced,
    };
    recipe->topping_count += 1;
    return true;
}

void recipe_set_on_menu(Recipe *recipe, bool on_menu) {
    if (recipe != NULL) {
        recipe->on_menu = on_menu;
    }
}

void recipe_record_sale(Recipe *recipe, uint32_t servings) {
    if (recipe != NULL) {
        recipe->sales += servings;
    }
}

double recipe_compute_price(const Recipe *recipe, double price_percent,
                            double building_value, double price_offset) {
    if (recipe == NULL) {
        return 0.0;
    }
    return recipe->base_price * (price_percent * 0.01 * building_value) + price_offset;
}

void branch_menu_init(BranchMenu *menu, uint32_t category) {
    if (menu == NULL) {
        return;
    }
    memset(menu, 0, sizeof(*menu));
    menu->category = category;
}

bool branch_menu_add(BranchMenu *menu, const Recipe *recipe) {
    if (menu == NULL || recipe == NULL || menu->count >= MENU_MAX_RECIPES) {
        return false;
    }
    if (branch_menu_find(menu, recipe->id) != NULL) {
        return false;
    }
    menu->recipes[menu->count] = *recipe;
    menu->recipes[menu->count].on_menu = true;
    menu->count += 1;
    return true;
}

bool branch_menu_remove(BranchMenu *menu, uint32_t recipe_id) {
    if (menu == NULL) {
        return false;
    }
    for (int index = 0; index < menu->count; index++) {
        if (menu->recipes[index].id != recipe_id) {
            continue;
        }
        for (int move = index; move + 1 < menu->count; move++) {
            menu->recipes[move] = menu->recipes[move + 1];
        }
        menu->count -= 1;
        return true;
    }
    return false;
}

Recipe *branch_menu_find(BranchMenu *menu, uint32_t recipe_id) {
    if (menu == NULL) {
        return NULL;
    }
    for (int index = 0; index < menu->count; index++) {
        if (menu->recipes[index].id == recipe_id) {
            return &menu->recipes[index];
        }
    }
    return NULL;
}
