/* CheatMenu_InitCompanyPage: disables the cheat page buttons and refreshes
   the AI status panel (0x4c5fc0). */
struct UI {
    void DisableButton(int id);
};

extern void __cdecl AIStatus_UpdateCompanyPanel(void *page);

void __cdecl CheatMenu_InitCompanyPage(void *page)
{
    ((struct UI *)page)->DisableButton(0x1f50);
    ((struct UI *)page)->DisableButton(0x1f51);
    ((struct UI *)page)->DisableButton(0x1f57);
    ((struct UI *)page)->DisableButton(0x1f58);
    AIStatus_UpdateCompanyPanel(page);
}
