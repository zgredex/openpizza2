#ifndef PC2_RECONSTRUCTED_RECIPE_STATE_H
#define PC2_RECONSTRUCTED_RECIPE_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define RECIPE_NAME_CAPACITY 64
#define RECIPE_MAX_TOPPINGS 16
#define MENU_MAX_RECIPES 32

typedef struct RecipeTopping {
    uint32_t ingredient_id;
    uint32_t quantity;
    uint8_t part;
    uint8_t sliced;
} RecipeTopping;

typedef struct Recipe {
    uint32_t id;
    char name[RECIPE_NAME_CAPACITY];
    double base_price;
    uint32_t category;
    RecipeTopping toppings[RECIPE_MAX_TOPPINGS];
    int topping_count;
    bool on_menu;
    uint32_t sales;
    int32_t quality;
} Recipe;

typedef struct BranchMenu {
    Recipe recipes[MENU_MAX_RECIPES];
    int count;
    uint32_t category;
} BranchMenu;

/*
 * Host-side recipe/menu state reconstructed from Recipe_Construct (0x50FC20),
 * Recipe_SetOnMenu (0x4E3460), Player_AddRecipeToMenu (0x49BD50),
 * Branch_ComputeRecipePrice (0x513BF0) and
 * Branch_ValidateMenuAndRecalculate (0x4F7C30).
 */
void recipe_init(Recipe *recipe, uint32_t id, const char *name, double base_price,
                 uint32_t category);
bool recipe_add_topping(Recipe *recipe, uint32_t ingredient_id, uint32_t quantity,
                        uint8_t part, uint8_t sliced);
void recipe_set_on_menu(Recipe *recipe, bool on_menu);
void recipe_record_sale(Recipe *recipe, uint32_t servings);
double recipe_compute_price(const Recipe *recipe, double price_percent,
                            double building_value, double price_offset);

void branch_menu_init(BranchMenu *menu, uint32_t category);
bool branch_menu_add(BranchMenu *menu, const Recipe *recipe);
bool branch_menu_remove(BranchMenu *menu, uint32_t recipe_id);
Recipe *branch_menu_find(BranchMenu *menu, uint32_t recipe_id);

#endif
