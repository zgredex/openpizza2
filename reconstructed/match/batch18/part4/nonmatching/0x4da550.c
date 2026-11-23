extern char *DAT_0057c670;

/* City_SpawnResidentInPreferredCity: moves a resident into the preferred or a
   random city (0x4da550). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Game {
    int CountPlayerRecordsByField34(int city);
    int GetMostAdvancedCompany();
    int GetPlayerCount();
    void *GetPlayerBySlot(int slot);
    void *FindFreeObjectByOwner(int type, int flags);
};

struct Person {
    void AssignBranchStaffRole(int record, int role, int a, int b);
};

struct City {
    void SpawnResidentInPreferredCity();
};

extern "C" int __cdecl Random_RangeFast(int min, int max);

void City::SpawnResidentInPreferredCity()
{
    int player;
    unsigned int company;
    unsigned int value;

    if (((Game *)DAT_0057c670)->CountPlayerRecordsByField34((int)this) != 0) {
        company = ((Game *)this)->GetMostAdvancedCompany();
        value = Random_RangeFast(0, 100);
        if (0x24 < (int)value || company == 0xffffffff) {
            player = ((Game *)DAT_0057c670)->GetPlayerCount();
            company = Random_RangeFast(0, player - 1);
        }
        player = (int)((Game *)DAT_0057c670)->GetPlayerBySlot(company);
        if (*(int *)((char *)player + 0x15c) != 0) {
            int record;

            value = Random_RangeFast(0, *(int *)((char *)player + 0x15c) - 1);
            record = (int)((IDMap *)((char *)player + 0x148))->Lookup(value, 0);
            if (record != 0) {
                void *object = ((Game *)DAT_0057c670)->FindFreeObjectByOwner(0x18, 0);

                if (*(int *)((char *)object + 0xa4) == -1 &&
                    *(char *)((char *)object + 0x104) != '\0' &&
                    *(int *)((char *)object + 0x74) != 1) {
                    ((Person *)object)->AssignBranchStaffRole(record, 0xc, -1, 0);
                    {
                        int index = *(int *)((char *)player + 0x48);
                        int value = *((int *)((char *)this + 0xce0) + index);

                        *((int *)((char *)this + 0xce0) + index) = value + 1;
                    }
                }
            }
        }
    }
}
