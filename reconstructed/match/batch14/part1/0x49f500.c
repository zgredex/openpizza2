/* RecipeMenu_ShowSelectedRecipe (0x49f500): shows the selected recipe in the
   recipe menu and updates the current selection. */
extern int DAT_0057cd98;
extern int DAT_0057cd9c;
extern int DAT_0057c670;
extern char *DAT_00581ad0;

struct IDMap {
    int Lookup(int key, int *out);
};

struct UI {
    void QueueControlCommand(int message, int wparam, int lparam);
};

struct Window_GadgetNotify_Text {
    void SetText(int id, char *text);
};

void __cdecl RecipeMenu_SetCurrentRecipe(void *menu, int recipe);

void __cdecl RecipeMenu_ShowSelectedRecipe(void *param_1)
{
    int recipe;

    recipe = ((IDMap *)(DAT_0057cd98 + 0x110))->Lookup(DAT_0057cd9c, 0);
    RecipeMenu_SetCurrentRecipe(param_1, recipe);
    if (recipe != 0) {
        ((Window_GadgetNotify_Text *)param_1)
            ->SetText(0x40f, (char *)(recipe + 4));
    } else {
        ((Window_GadgetNotify_Text *)param_1)->SetText(0x40f, DAT_00581ad0);
    }
    *(int *)(DAT_0057c670 + 0x98) = recipe;
    if (*(void **)(DAT_0057c670 + 0x264) != 0) {
        ((UI *)*(void **)(DAT_0057c670 + 0x264))
            ->QueueControlCommand(-0x18671, 0x23, 1);
    }
}
