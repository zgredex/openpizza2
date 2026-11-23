/* City_TickBranches (0x4fc630). */

struct Game {
    void *GetPlayerSubrecord(int slot, int index, int flag);
    int CountFreeBuildingsByType(int type);
    void GetBestObject(int a, int b, float *out);
};

struct Branch {
    void ValidateMenuAndRecalculate(void *branch);
    void AutoTunePrice(void *branch);
};

struct Company {
    void OpenBranchAtSite(int slot, void *branch);
    void RefreshMenuSalesIfDue(int slot);
};

struct Customer {
    void VisitBranch(int slot, int branch, int a, int b, int c, int d);
};

struct City {
    void EnsurePedestrianCoverage(int slot);
    int TickBranches(int slot);
};

int City::TickBranches(int slot)
{
    int count =
        *(int *)(*(int *)((char *)this + slot * 0x168 + 0x70) + 0x15c);
    float local;
    int i;

    ((City *)this)->EnsurePedestrianCoverage(slot);
    for (i = 0; i < count; i++) {
        void *record = ((Game *)this)->GetPlayerSubrecord(slot, i, 1);

        if (record != 0 && *(void **)((char *)record + 0x16f0) != 0 &&
            ((Game *)*(void **)((char *)record + 0x16f0))
                    ->CountFreeBuildingsByType(0x1e) == 0)
            ((Game *)record)->GetBestObject(1, 0x22, &local);
    }
    for (i = 0; i < count; i++) {
        void *record = ((Game *)this)->GetPlayerSubrecord(slot, i, 1);

        if (record != 0 && *(int *)((char *)record + 0x2c) == 0) {
            unsigned flags = *(unsigned *)((char *)record + 0x28);

            if ((flags & 2) != 0) {
                ((Branch *)this)->ValidateMenuAndRecalculate(record);
                break;
            }
            if ((flags & 0x10) != 0) {
                ((Company *)this)->OpenBranchAtSite(slot, record);
                break;
            }
            if ((flags & 0x20) != 0) {
                ((Branch *)this)->AutoTunePrice(record);
                break;
            }
            if ((flags & 4) != 0) {
                ((Customer *)this)
                    ->VisitBranch(slot, (int)record, -1, -1, -1, -1);
                break;
            }
        }
    }
    ((Company *)this)->RefreshMenuSalesIfDue(slot);
    return 1;
}
