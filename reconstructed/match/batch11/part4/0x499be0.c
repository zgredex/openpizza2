/* NewRecipe_CloseIngredientPalette: closes the new-recipe ingredient palette
   and hides its buttons (0x499be0). */
struct UI {
    void ReleasePendingSprite();
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
};

struct World {
    char pad[0x264];
    struct Window *window;
};

extern int DAT_0057c670;
extern int DAT_0057c5e0;
extern char DAT_0057ca2c;
extern int DAT_00568914;

void CreateRecipePage_FillIngredientDetails(void *window, int value);

void NewRecipe_CloseIngredientPalette(void)
{
    int i;

    if (DAT_0057ca2c != 0) {
        struct Window *window = ((struct World *)DAT_0057c670)->window;

        ((struct UI *)DAT_0057c5e0)->ReleasePendingSprite();
        DAT_0057ca2c = 0;
        DAT_00568914 = -1;
        CreateRecipePage_FillIngredientDetails(window, -1);
        for (i = 0; i < 0xc; i++) {
            window->GadgetNotify_Button_SetState(i + 0x4ed, 0);
        }
    }
}
