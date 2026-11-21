/* UI_ShowAIStatusWindow: creates the cheat/debug AI status window once
   (0x482b30). */
extern void *DAT_0057c5e0;

struct Window {
    void ShowWindowById(int id);
};

extern "C" void * __cdecl AI_DebugStatusWindow_Create(int *out);
extern "C" void __cdecl CheatMenu_InitCompanyPage(void *page);

void __fastcall UI_ShowAIStatusWindow(void *self)
{
    if (*(int *)((char *)self + 0x268) == 0) {
        int id;
        void *window = AI_DebugStatusWindow_Create(&id);
        *(void **)((char *)self + 0x268) = window;
        CheatMenu_InitCompanyPage(window);
        ((Window *)DAT_0057c5e0)->ShowWindowById(id);
    }
}
