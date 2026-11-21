/* CompanyMenu_InitStylePage: builds the company style-selection page
   (0x492440). */
struct Window_GadgetNotify_Button {
    void SetState(int id, int state);
};

extern int DAT_0057c6b8;
extern void __cdecl UI_Group_Create(void *page, int x, int y, int first,
                                    int second, int third);
extern void __cdecl RenovationScreen_UpdatePage(void *page);

void __cdecl CompanyMenu_InitStylePage(void *page)
{
    UI_Group_Create(page, 0, 3, 0x1f4a, 0x1f4b, 0x1f4c);
    ((struct Window_GadgetNotify_Button *)page)
        ->SetState(DAT_0057c6b8 + 0x1f4a, 1);
    RenovationScreen_UpdatePage(page);
}
