/* RecipeMenu_ShowMenuFileChooser: shows the saved-menu file chooser or an
   empty-list message (0x49c4d0). */
extern "C" int DAT_0057c670;
extern "C" int DAT_0058282c;
extern "C" int DAT_00581a1c;
extern "C" int DAT_0057ca8c;
extern "C" int DAT_00582c8c;

struct UIHelper {
    void ShowConfirmationDialog(int dialog, int a, int b, int c);
    void ShowScrollingListDialog(int dialog, int a, int b, int c, int d,
                                 int e);
};

extern "C" int __cdecl SaveMenu_ScanMenuFileList(void);

extern "C" void __cdecl RecipeMenu_ShowMenuFileChooser(void)
{
    if (SaveMenu_ScanMenuFileList() > 0) {
        ((UIHelper *)DAT_0057c670)
            ->ShowScrollingListDialog(0xfffe7987, DAT_0058282c, DAT_00581a1c,
                                      DAT_0057ca8c, 0, 0);
        return;
    }
    ((UIHelper *)DAT_0057c670)
        ->ShowConfirmationDialog(0xfffe79af, DAT_0058282c, DAT_00582c8c, 0);
}
