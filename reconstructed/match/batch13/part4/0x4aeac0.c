/* Glossary_BuildingsPage_Init (0x4aeac0). */
struct Window_GadgetNotify_Button {
    void SetState(int id, int state);
};
struct Window_GadgetNotify_Text {
    void SetText(int id, int text);
};
struct UI {
    void RemoveObjectByKey(int key);
};
extern "C" void UI_Group_Create(void *ui, int first, int count, int a,
                                int b, int c, int d);
extern "C" void Glossary_ShowCompanyBuildingDetail(void *ui);
extern "C" int DAT_00583fd4[];

extern "C" void __cdecl Glossary_BuildingsPage_Init(void *ui)
{
    UI_Group_Create(ui, 0, 4, 0x3f9, 0x3f8, 0x3f7, 0x3fa);
    ((struct Window_GadgetNotify_Button *)ui)->SetState(0x3f7, 1);
    ((struct UI *)ui)->RemoveObjectByKey(0x3f6);
    {
    int id = 0x41f;
    int *text = DAT_00583fd4;
    do {
        ((struct Window_GadgetNotify_Text *)ui)->SetText(id, *text);
        text = text + 1;
        id = id + 1;
    } while ((int)text < 0x584008);
    }
    Glossary_ShowCompanyBuildingDetail(ui);
}
