// Game_RecomputeCompanyMenuSales: recomputes menu sales for one player slot.

extern char DAT_0057c670[];

struct IDMap {
    char *Lookup(int key, int *index);
};

struct Game {
    void ResetRecordTurnCounters();
    int CountActiveCompanies();
    char *GetActiveCompanyById(int index);
    char IsRecordLinked(void *record);
    char *CollectUnprofitableBranches();
    int RecomputeCompanyMenuSales(int slot);
};

struct VList {
    virtual void Destroy(int flag);
};

struct Company {
    char *CollectUnprofitableBranches();
};

struct Stats {
    float SumMaskedMapFloats(int period, int mask, int limit);
};

struct Recipe {
    void SetOnMenu(void *record, int flag);
};

int Game::RecomputeCompanyMenuSales(int slot)
{
    char *company = *(char **)((char *)this + slot * 0x168 + 0x70);
    char *branch = (char *)this + slot * 0x168;
    int period;
    int index;

    ((Game *)company)->ResetRecordTurnCounters();
    period = *(unsigned short *)(*(int *)(*(char **)DAT_0057c670 + 0x94) + 10);
    index = 0;
    if (((Game *)company)->CountActiveCompanies() > 0) {
        do {
            char *record = ((Game *)company)->GetActiveCompanyById(index);
            if (period >= 100)
                period = 99;
            {
                float value = ((Stats *)record)->SumMaskedMapFloats(
                    period - 1, 0, -1);
                *(int *)(record + 0x30c) += (int)value;
            }
            index++;
        } while (index < ((Game *)company)->CountActiveCompanies());
    }
    if ((*(unsigned char *)(branch + 0x12a) & 0x10) != 0) {
        char *list = ((Company *)company)->CollectUnprofitableBranches();
        index = 0;
        if (*(int *)(list + 0x14) > 0) {
            do {
                void *record = ((IDMap *)list)->Lookup(index, 0);
                if (((Game *)company)->IsRecordLinked(record))
                    ((Recipe *)company)->SetOnMenu(record, 0);
                index++;
            } while (index < *(int *)(list + 0x14));
        }
        if (list != 0)
            ((VList *)list)->Destroy(1);
    }
    return 1;
}
