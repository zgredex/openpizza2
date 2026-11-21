/* RecipeMenu_ShowRecipeFileChooser: shows the saved-recipe file chooser or
   an empty-list message (0x498ef0). */
extern "C" int DAT_0057c670;
extern "C" int DAT_00581e34;
extern "C" int DAT_00580e80;
extern "C" int DAT_00581594;
extern "C" int DAT_0057ca04;

struct UIHelper {
    void ShowConfirmationDialog(int dialog, int a, int b, int c);
    void ShowScrollingListDialog(int dialog, int a, int b, int c, int d,
                                 int e);
};

extern "C" int __cdecl SaveGame_ScanSaveFileList(void);

extern "C" void __cdecl RecipeMenu_ShowRecipeFileChooser(void)
{
    if (SaveGame_ScanSaveFileList() == 0) {
        ((UIHelper *)DAT_0057c670)
            ->ShowConfirmationDialog(0xfffe79af, DAT_00581e34, DAT_00580e80,
                                     0);
        return;
    }
    ((UIHelper *)DAT_0057c670)
        ->ShowScrollingListDialog(0xfffe7981, DAT_00581e34, DAT_00581594,
                                  DAT_0057ca04, 0, 0);
}
