extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int GetCurrentPlayerCompanyName();
};

struct UI {
    void Group_ClearAll();
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
};

struct Array {
    void ToggleObjectActive(int id, int state);
};

extern "C" void UI_Group_Create(void *group, int a, int b, ...);

void __cdecl Screen_OptionsSidebar_SelectPage(void *param_1)
{
    int active = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);

    ((IDMap *)(DAT_0057c670 + 4))->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);
    ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName();
    ((UI *)param_1)->Group_ClearAll();
    UI_Group_Create(param_1, 0, 5, 0x3f1, 0x3f4, 0x3f3, 0x3f0, 0x3f5);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f1, active == 1);
    ((Array *)param_1)->ToggleObjectActive(0x3f1, active == 1);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f4, active == 2);
    ((Array *)param_1)->ToggleObjectActive(0x3f4, active == 2);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f3, active == 3);
    ((Array *)param_1)->ToggleObjectActive(0x3f3, active == 3);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f0, active == 4);
    ((Array *)param_1)->ToggleObjectActive(0x3f0, active == 4);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f5, active == 5);
    ((Array *)param_1)->ToggleObjectActive(0x3f5, active == 5);
}
