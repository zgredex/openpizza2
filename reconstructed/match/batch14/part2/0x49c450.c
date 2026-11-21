/* RecipeMenu_ShowRecipeChooser (0x49c450): shows the unassigned recipe
   chooser, or the empty/completed message when it has nothing to offer. */
extern int DAT_0057c670;
extern int DAT_0058282c;
extern int DAT_00581698;
extern int DAT_00581a00;
extern int DAT_00581208;
extern int DAT_0057ca8c;

int __cdecl Menu_BuildUnassignedMenuList(void);

struct Game {
    void ShowConfirmationDialog(int message, int arg2, int arg3, int arg4);
    void ShowScrollingListDialog(int message, int arg2, int arg3, int arg4,
                                 int arg5, int arg6);
};

void __cdecl RecipeMenu_ShowRecipeChooser(void)
{
    int count;

    count = Menu_BuildUnassignedMenuList();
    switch (count) {
    case -1:
        ((Game *)DAT_0057c670)
            ->ShowConfirmationDialog(-0x18651, DAT_0058282c, DAT_00581698, 0);
        break;
    case 0:
        ((Game *)DAT_0057c670)
            ->ShowConfirmationDialog(-0x18651, DAT_0058282c, DAT_00581a00, 0);
        break;
    default:
        ((Game *)DAT_0057c670)
            ->ShowScrollingListDialog(-0x1867a, DAT_0058282c, DAT_00581208,
                                      DAT_0057ca8c, 0, 0);
        break;
    }
}
