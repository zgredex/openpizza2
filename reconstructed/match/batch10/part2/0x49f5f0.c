/* RecipeMenu_ChooseRecipe: select a recipe portion and update its label
   (0x49f5f0). */
extern "C" int DAT_0057c670;
extern "C" int DAT_00581ad0;

extern "C" void RecipeMenu_RefreshPortionPreview(void *menu, int choice);

struct Window_GadgetNotify_Text {
    void SetText(int id, int text);
};

extern "C" void RecipeMenu_ChooseRecipe(void *menu, int choice)
{
    struct Window_GadgetNotify_Text *text =
        (struct Window_GadgetNotify_Text *)menu;

    *(int *)(DAT_0057c670 + 0x98) = choice;
    RecipeMenu_RefreshPortionPreview(menu, choice);
    if (choice != 0) {
        text->SetText(0x40f, choice + 4);
        return;
    }
    text->SetText(0x40f, DAT_00581ad0);
}
