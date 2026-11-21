/* RecipeMenu_PrevRecipe: step to the previous recipe (0x49fa20). */
extern "C" int DAT_0057cd98;
extern "C" int DAT_0057cd9c;

extern "C" void RecipeMenu_ShowSelectedRecipe(void *menu);

struct Window_GadgetNotify_Button {
    void SetState(int id, int state);
};

extern "C" void RecipeMenu_PrevRecipe(void *menu)
{
    if (*(int *)(DAT_0057cd98 + 0x124) > 0) {
        ((struct Window_GadgetNotify_Button *)menu)->SetState(0x3fc, 1);
        DAT_0057cd9c = DAT_0057cd9c - 1;
        if (DAT_0057cd9c < 0)
            DAT_0057cd9c = *(int *)(DAT_0057cd98 + 0x124) - 1;
        RecipeMenu_ShowSelectedRecipe(menu);
    }
}
