/* City_EnsurePedestrianCoverage (0x4fd520). */

extern char *DAT_0057c670;
extern double DAT_0055c640;

struct IDMapHelper {
    char pad[0x1c];

    void *Lookup(int key, int *out);
};

struct Branch {
    void HireExterminator(int type, void *record);
};

struct Game {
    void *GetPlayerSubrecord(int slot, int index, int flag);
    int CountFreeResidentialBuildings();
    int CountFreeBuildingsByType(int type);
    int CountFilteredObjects(int type, int subtype, int object, int flag);
};

struct City {
    void EnsurePedestrianCoverage(int slot);
};

void City::EnsurePedestrianCoverage(int slot)
{
    int index = 0;
    int *list = (int *)((char *)this + slot * 0x168 + 0x70);

    if (*(int *)(*list + 0x15c) <= 0)
        return;
    do {
        void *record = ((Game *)this)->GetPlayerSubrecord(slot, index, 1);

        if (record != 0) {
            int key = *(int *)((char *)record + 0x34);
            void *branch = ((IDMapHelper *)(DAT_0057c670 + 4))
                               ->Lookup(key, 0);
            int count = ((Game *)record)->CountFreeResidentialBuildings();
            int object = *list;

            if (count > 0) {
                void *owner = *(void **)((char *)record + 0x16f0);

                if (((Game *)owner)->CountFreeBuildingsByType(0x20) <= 0) {
                    if (*(double *)(object + 0x108) > DAT_0055c640) {
                        if (((Game *)DAT_0057c670)
                                ->CountFilteredObjects(2, 0x20, (int)owner, -1) <= 0)
                            ((Branch *)branch)
                                ->HireExterminator(2, record);
                    } else {
                        if (((Game *)DAT_0057c670)
                                ->CountFilteredObjects(1, 0x20, (int)owner, -1) <= 0)
                            ((Branch *)branch)
                                ->HireExterminator(1, record);
                    }
                }
            }
        }
        index++;
    } while (index < *(int *)(*list + 0x15c));
}
