/* RestaurantInfoPanel_UpdateTabButtons: updates the restaurant info panel's
   ten tab buttons (0x4cf690). */
struct UIManager {
    void ClearAll();
    void CreateGroup(int a, int b, int c, ...);
    void ButtonSetState(int id, int value);
    void ToggleObjectActive(int id, int value);
    void SetChildVisibleByID(int id, int value);
    void RemoveObjectByKey(int id);
};

struct Game {
    int GetCurrentPlayerCompanyName();
    int CountObjectsByType(int type);
};

struct IDMap {
    void *Lookup(int key, int *out);
};

extern "C" {
extern int DAT_0057c670;
}

void __cdecl RestaurantInfoPanel_UpdateTabButtons(void *panel, int unused)
{
    int bVar3;
    int this_;
    int iVar2;
    int iVar4;
    int iVar5;
    int uVar6;
    UIManager *ui;

    ui = (UIManager *)panel;
    bVar3 = 0;
    this_ = *(int *)(DAT_0057c670 + 0x9c);
    if (*(int *)(this_ + 0x2c) != 0 || *(char *)(this_ + 0x16f5) != '\0') {
        int *slot = (int *)(DAT_0057c670 + 0x2a8);
        *(int *)(DAT_0057c670 + 0x2c8) = *slot;
        bVar3 = 1;
        *slot = 9;
    }
    iVar2 = *(int *)(DAT_0057c670 + 0x298 + *(int *)(DAT_0057c670 + 0x290) * 4);
    iVar4 = (int)((IDMap *)(DAT_0057c670 + 4))->Lookup(*(int *)(DAT_0057c670 + 0x2f4), 0);
    iVar5 = ((Game *)DAT_0057c670)->GetCurrentPlayerCompanyName();
    iVar4 = *(int *)(iVar4 + 0xc20 + iVar5 * 4);
    ui->ClearAll();
    ui->CreateGroup(0, 10, 0x3f4, 0x3f5, 0x3f6, 0x3f7, 0x3f8, 0x3f9, 0x3fa,
                    0x3fb, 0x3fe, 0x3fd);
    ui->ButtonSetState(0x3f4, (iVar2 == 1));
    ui->ToggleObjectActive(0x3f4, (iVar2 == 1));
    uVar6 = !bVar3;
    ui->SetChildVisibleByID(0x3f4, uVar6);
    if (iVar2 == 2 || iVar2 == 0xb)
        iVar5 = 1;
    else
        iVar5 = 0;
    ui->ButtonSetState(0x3f5, iVar5);
    if (iVar2 == 2 || iVar2 == 0xb)
        iVar5 = 1;
    else
        iVar5 = 0;
    ui->ToggleObjectActive(0x3f5, iVar5);
    ui->SetChildVisibleByID(0x3f5, uVar6);
    ui->ButtonSetState(0x3f6, (iVar2 == 3));
    ui->ToggleObjectActive(0x3f6, (iVar2 == 3));
    ui->SetChildVisibleByID(0x3f6, uVar6);
    ui->ButtonSetState(0x3f7, (iVar2 == 4));
    ui->ToggleObjectActive(0x3f7, (iVar2 == 4));
    ui->SetChildVisibleByID(0x3f7, uVar6);
    ui->ButtonSetState(0x3f8, (iVar2 == 5));
    ui->ToggleObjectActive(0x3f8, (iVar2 == 5));
    if (iVar4 <= 0 || bVar3)
        iVar5 = 0;
    else
        iVar5 = 1;
    ui->SetChildVisibleByID(0x3f8, iVar5);
    ui->ButtonSetState(0x3f9, (iVar2 == 6));
    ui->ToggleObjectActive(0x3f9, (iVar2 == 6));
    if (iVar4 <= 0 || bVar3)
        iVar5 = 0;
    else
        iVar5 = 1;
    ui->SetChildVisibleByID(0x3f9, iVar5);
    ui->ButtonSetState(0x3fa, (iVar2 == 7));
    ui->ToggleObjectActive(0x3fa, (iVar2 == 7));
    if (iVar4 <= 0 || bVar3)
        iVar5 = 0;
    else
        iVar5 = 1;
    ui->SetChildVisibleByID(0x3fa, iVar5);
    iVar5 = ((Game *)this_)->CountObjectsByType(1);
    ui->ButtonSetState(0x3fb, (iVar2 == 8));
    ui->ToggleObjectActive(0x3fb, (iVar2 == 8));
    if (iVar4 <= 2 || bVar3 || iVar5 <= 0)
        iVar5 = 0;
    else
        iVar5 = 1;
    ui->SetChildVisibleByID(0x3fb, iVar5);
    if (*(int *)(this_ + 0x38) < 2) {
        ui->ButtonSetState(0x3fe, (iVar2 == 9));
        ui->ToggleObjectActive(0x3fe, (iVar2 == 9));
        ui->SetChildVisibleByID(0x3fe, (0 < iVar4));
    } else {
        ui->ButtonSetState(0x3fe, 0);
        ui->RemoveObjectByKey(0x3fe);
    }
    uVar6 = (iVar2 == 10);
    ui->ButtonSetState(0x3fd, uVar6);
    ui->ToggleObjectActive(0x3fd, uVar6);
    ui->SetChildVisibleByID(0x3fd, uVar6);
}
