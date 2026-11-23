/* FurnitureMenu_InitChairPage: builds the chair page of the furniture menu
   and fills the eight rating bars (0x4c3070). */
extern int DAT_0057c5e0;
extern int DAT_0056adec;
extern int DAT_0057c670;
extern int DAT_00582320;

extern "C" void UI_Group_Create(void *ui, int a, int b, int c, int d, int e);
extern "C" void Window_UpdateFurniturePage(void *ui);
extern "C" void Rating_UpdateBarByKey(void *ui, int key, int index, int value,
                                      int color);

struct UI {
    void Group_ClearAll();
    void SetPosition(void *function, int arg);
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
};

struct Branch {
    int ComputeBuildingRating(int index);
};

extern "C" void FurnitureMenu_InitChairPage(void *param_1)
{
    void *pvVar1;
    int iVar2;
    int iVar4;

    *(int *)(DAT_0057c5e0 + 0x831c) = 1;
    ((UI *)param_1)->Group_ClearAll();
    UI_Group_Create(param_1, 0, 3, 0x1f63, 0x1f64, 0x1f65);
    DAT_0056adec = 2;
    ((Window *)param_1)->GadgetNotify_Button_SetState(0x1f65, 1);
    ((UI *)param_1)->SetPosition((void *)0x4c2ba0, 0);
    pvVar1 = *(void **)(DAT_0057c670 + 0x9c);
    Window_UpdateFurniturePage(param_1);
    iVar4 = 0;
    do {
        iVar2 = ((Branch *)pvVar1)->ComputeBuildingRating(iVar4);
        Rating_UpdateBarByKey(param_1, 0x559, iVar4, iVar2, DAT_00582320);
        iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
}
