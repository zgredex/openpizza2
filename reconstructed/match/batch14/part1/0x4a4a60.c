/* CompanyOverview_AssignEmployeeToBuilding (0x4a4a60): moves an idle HQ
   worker to the selected branch and refreshes the overview rows. */
extern int DAT_0057c670;
extern int DAT_0057d264;
extern int DAT_005825a4;
extern int DAT_00580fc4;

int __fastcall Company_DispatchWorkerToBranch(void *manager, void *company,
                                              int worker);
void __cdecl CompanyOverview_UpdateBuildingRows(void *overview, int data);
void __fastcall Game_ShowConfirmationDialog(void *game, int message, int arg2,
                                            int arg3, int arg4);

struct IDMap {
    int Lookup(int key, int *out);
};

struct CompanyManager;

struct Game {
    char pad[0x90];
    CompanyManager *manager;
    void ShowConfirmationDialog(int message, int arg2, int arg3, int arg4);
};

struct CompanyManager {
    int DispatchWorkerToBranch(void *company, int worker);
};

void __cdecl CompanyOverview_AssignEmployeeToBuilding(int param_1, void *param_2)
{
    char *company;
    int worker;
    CompanyManager *manager;

    company = *(char **)((char *)DAT_0057c670 +
                         *(int *)((char *)DAT_0057c670 + 0x2ec) * 4 + 0x200);
    worker = ((IDMap *)(company + 0x148))->Lookup(param_1, 0);
    manager = ((Game *)DAT_0057c670)->manager;
    if (manager->DispatchWorkerToBranch(company, worker) != 0) {
        CompanyOverview_UpdateBuildingRows(param_2, DAT_0057d264);
    } else {
        ((Game *)DAT_0057c670)->ShowConfirmationDialog(-0x18651, DAT_005825a4,
                                                       DAT_00580fc4, 0);
    }
}
