/* UI_ShowPauseDialog (0x48d4c0). */
extern void *Dialog_Loading(int *id);
extern char DAT_004c63f0[];
extern char *DAT_0057c5e0;

struct Window {
    char pad0[0x48];
    void *handler;          /* 0x48 */

    void SetText(int id, int text);
};
struct UI {
    void AddUniquePair(int first, int second);
};
struct Host {
    void SetField228(void *object);
    void ShowWindowById(int id);
};

void __stdcall UI_ShowPauseDialog(int param_1, int param_2)
{
    int id;
    Window *window = (Window *)Dialog_Loading(&id);

    window->handler = DAT_004c63f0;
    window->SetText(0x3e9, param_2);
    window->SetText(0x3f9, param_1);
    ((UI *)window)->AddUniquePair(0x3f8, 0xd);
    ((Host *)DAT_0057c5e0)->SetField228(window);
    ((Host *)DAT_0057c5e0)->ShowWindowById(id);
}
