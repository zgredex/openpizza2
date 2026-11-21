/* RecipeMenu_NextRecipe: advances the selected recipe index and refreshes the
   display (0x49fa70). */
struct UIHelper {
    void Button_SetState(int id, int state);
};

extern "C" int __cdecl RecipeMenu_ShowSelectedRecipe(void *menu);

extern "C" void __cdecl RecipeMenu_NextRecipe(void *menu)
{
    int counter;
    int total;

    if (*(int *)(*(int *)0x57cd98 + 0x124) > 0) {
        ((UIHelper *)menu)->Button_SetState(0x3fc, 1);
        counter = *(int *)0x57cd9c + 1;
        *(int *)0x57cd9c = counter;
        total = *(int *)(*(int *)0x57cd98 + 0x124);
        if (counter < total) {
        } else {
            *(int *)0x57cd9c = 0;
        }
        RecipeMenu_ShowSelectedRecipe(menu);
    }
}
