/* GuardMenu_FillSummary (0x4bd230). */
extern "C" void *g_Game;
extern "C" char *g_GuardMenu_FillSummary_State_0057d6fc;
extern "C" char s_UiLabel_0_00564220[];
extern "C" char s_FormatInt[];
extern "C" char s_FormatMoney[];
extern "C" void Gadget_SetTextf(void *page, int id, char *format, ...);

struct BuildingManager {
    int CountFreeBuildingsByType(int type);
};

struct Game {
    void *GetPlayerCity();
    int CountFreeSlots(int type);
    int CountActiveObjectsByType(int type);
};

struct Window_GadgetNotify_Text {
    void SetText(int id, char *text);
};

struct Window_GadgetNotify_Slider {
    void SetValue(int id, int value, int flag);
};

extern "C" void GuardMenu_FillSummary(void *page)
{
    void *player;
    void *city;
    void *freeBuildings;
    int value1;
    int value2;
    int count;
    int base;
    int percent;
    int total;

    player = *(void **)((char *)g_Game + 0x200 +
                        *(int *)((char *)g_Game + 0x2ec) * 4);
    city = ((Game *)player)->GetPlayerCity();
    value1 = *(int *)((char *)city + 0x68);
    value2 = *(int *)((char *)city + 0x50);
    base = value1 + value2;
    percent = base * -0x1e + 100;

    freeBuildings = *(void **)((char *)player + 0x1d8);
    if (freeBuildings == 0) {
        ((Window_GadgetNotify_Text *)page)->SetText(0x1f59, s_UiLabel_0_00564220);
    } else {
        count = ((BuildingManager *)freeBuildings)->CountFreeBuildingsByType(0x17);
        Gadget_SetTextf(page, 0x1f59, s_FormatInt, count);
    }
    count = ((Game *)g_Game)->CountFreeSlots(0x17);
    Gadget_SetTextf(page, 0x1f7c, s_FormatInt, count);
    total = ((Game *)player)->CountActiveObjectsByType(0x17);
    Gadget_SetTextf(page, 0x1f7a, s_FormatInt, total);
    Gadget_SetTextf(page, 0x1f78, s_FormatMoney,
                    (percent * 500 / 100) * total);
    ((Window_GadgetNotify_Slider *)page)->SetValue(
        0x1f4f, *(int *)(g_GuardMenu_FillSummary_State_0057d6fc + 0xa8), 0);
}
