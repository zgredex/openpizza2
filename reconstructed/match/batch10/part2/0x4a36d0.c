/* CompanyMenu_InitBranchOverview: reset the branch overview selection and
   refresh the staff costs (0x4a36d0). */
extern "C" int DAT_00568ef0;
extern "C" int DAT_00568ef4;
extern "C" int DAT_0057d01c;
extern "C" int DAT_0057d014;
extern "C" int DAT_0057d018;
extern "C" int DAT_0057c670;

struct Game {
    int CountAssignedAssetSlots(int *first, int *second);
};

extern "C" void HeadquartersPanel_UpdateStaffCosts(void *menu);

extern "C" void CompanyMenu_InitBranchOverview(void *menu)
{
    DAT_00568ef0 = -1;
    DAT_00568ef4 = -1;
    DAT_0057d01c = 0;
    DAT_0057d014 = ((struct Game *)DAT_0057c670)->CountAssignedAssetSlots(
        &DAT_00568ef0, &DAT_00568ef4);
    DAT_0057d018 = 1;
    HeadquartersPanel_UpdateStaffCosts(menu);
}
