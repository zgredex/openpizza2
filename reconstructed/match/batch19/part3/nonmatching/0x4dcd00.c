/* Person_RefreshShopChoices (0x4dcd00). */

extern char *DAT_0057c670;
extern "C" int Random_RangeFast(int min, int max);

struct IDMapHelper {
    char pad[0x1c];

    void *Lookup(int key, int *out);
};

struct Map {
    virtual void Destroy(int flag);
};

struct City {
    Map *CollectVacantLots();
    Map *CollectBuildingsByType(int type, int arg, char flag);
};

struct Link {
    int target;                 /* 0x00 */
    int type;                   /* 0x04 */
};

struct Person {
    char pad0[0xd4];
    int choices[7];             /* 0xd4 */
};

extern "C" void __fastcall Person_RefreshShopChoices(void *object)
{
    City *city = (City *)DAT_0057c670;
    Map *vacant = ((City *)DAT_0057c670)->CollectVacantLots();
    int index = 0;

    if (*(int *)((char *)vacant + 0x14) > 0) {
        do {
            int record = (int)((IDMapHelper *)vacant)->Lookup(index, 0);
            unsigned value = Random_RangeFast(1, 100);

            if ((int)value > 0x50) {
                int *slot = (int *)(record + 0xd4);
                int count = 7;

                do {
                    int choice = *slot;

                    if (*(int *)(choice + 4) != 0) {
                        int type;

                        if (*(int *)(choice + 4) == 0xc &&
                            (value = Random_RangeFast(1, 100),
                             (int)value > 0x32))
                            type = 3;
                        else
                            type = *(int *)(choice + 4);
                        Map *buildings = ((City *)object)
                                             ->CollectBuildingsByType(type,
                                                                      choice,
                                                                      0);

                        if (*(int *)((char *)buildings + 0x14) > 0) {
                            value = Random_RangeFast(
                                0, *(int *)((char *)buildings + 0x14) - 1);
                            int found = (int)((IDMapHelper *)buildings)
                                            ->Lookup(value, 0);

                            if (found != 0)
                                *slot = found;
                        }
                        if (buildings != 0)
                            buildings->Destroy(1);
                    }
                    slot++;
                    count--;
                } while (count != 0);
            }
            index++;
        } while (index < *(int *)((char *)vacant + 0x14));
    }
    if (vacant != 0)
        vacant->Destroy(1);
}
