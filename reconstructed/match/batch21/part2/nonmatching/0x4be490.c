// LeaseBuilding_UpdatePage @ 0x4be490 (156 bytes)
// Refreshes the building-lease page: tenant text/photo, lease record and
// the current monthly rent label, then refills the storage details.

extern "C" void Personnel_SetEmployeePhotoByKey(void *ui, int id, void *employee);
extern "C" void Gadget_SetTextf(void *ui, int id, char *format, int value);
extern "C" void StockPage_FillStorageDetails(void *ui);

extern char DAT_005683a4[];
extern int DAT_0057d700;
extern char *DAT_0057c670;

class Game {
public:
    void *GetPlayerBySlot(int slot);
    int FindRecordByField34(void *company);
};

class Window_GadgetNotify_Text {
public:
    void SetText(int id, char *text);
};

extern "C" void __cdecl LeaseBuilding_UpdatePage(void *ui)
{
    void *company = *(void **)(DAT_0057c670 + 0x218);
    void *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(
        *(int *)((char *)company + 8));

    ((Window_GadgetNotify_Text *)ui)->SetText(0x501, (char *)player + 8);
    Personnel_SetEmployeePhotoByKey(ui, 0x1f4d, player);
    DAT_0057d700 = ((Game *)player)->FindRecordByField34(company);
    int *finance = *(int **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
    int rent = 100000;
    if (finance[0x158 / 4] != 0)
        rent = 0;
    else if (finance[0x23c / 4] != 0)
        rent = 150000;
    Gadget_SetTextf(ui, 0x1f5e, DAT_005683a4, rent);
    StockPage_FillStorageDetails(ui);
}
