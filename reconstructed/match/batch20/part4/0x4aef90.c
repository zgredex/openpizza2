extern int DAT_0057d640;
extern int DAT_0057d644;
extern int DAT_0057d648;

struct Array {
    void GetPairByKey(int key, int *first, int *second);
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
    void GadgetNotify_Slider_SetRange(int id, int min, int max, int flag);
    void GadgetNotify_Slider_SetValue(int id, int value, int flag);
    void GadgetNotify_Slider_SetChangeNotify(int id, int state);
};

struct UI {
    void RemoveObjectByKey(int key);
};

extern "C" void UI_Group_Create(void *group, int a, int b, ...);
extern "C" void Glossary_FillCityBuildingList(void *page, int value);
extern "C" void Glossary_ShowCityBuildingDetail(void *page);

void __cdecl Glossary_BranchesPage_Init(void *param_1)
{
    int first;
    int second;
    int other;
    int selected;

    ((Array *)param_1)->GetPairByKey(0x42e, &first, &second);
    ((Array *)param_1)->GetPairByKey(0x43f, &selected, &other);
    DAT_0057d640 = selected - first;
    ((Array *)param_1)->GetPairByKey(0x4b6, &selected, &other);
    DAT_0057d644 = other - second;
    UI_Group_Create(param_1, 0, 4, 0x3f9, 0x3f8, 0x3f7, 0x3fa);
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x3f8, 1);
    ((Window *)param_1)->GadgetNotify_Slider_SetRange(0x3f6, 0, 10, 0);
    ((Window *)param_1)->GadgetNotify_Slider_SetValue(0x3f6, DAT_0057d648, 0);
    ((Window *)param_1)->GadgetNotify_Slider_SetChangeNotify(0x3f6, 1);
    for (int i = 0x42f; i < 0x43f; i++)
        ((UI *)param_1)->RemoveObjectByKey(i);
    Glossary_FillCityBuildingList(param_1, DAT_0057d648);
    Glossary_ShowCityBuildingDetail(param_1);
    ((UI *)param_1)->RemoveObjectByKey(0x42e);
    ((UI *)param_1)->RemoveObjectByKey(0x43f);
    ((UI *)param_1)->RemoveObjectByKey(0x4b6);
}
