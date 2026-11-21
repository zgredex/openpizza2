struct IDMap { void *Lookup(int key, int *out); };
struct Map { int *CollectBillboardDistances(int animation); };
struct Game { int pad; IDMap map; };
struct Branch {
    char pad[0x34]; int field34;
    char pad2[0x16f0 - 0x38]; int animation;
    char pad3[0x1a28 - 0x16f4]; int *billboards;
    int GetCachedBillboards();
};
extern Game *DAT_0057c670;
int Branch::GetCachedBillboards()
{
    if (billboards == 0) {
        IDMap *map = &DAT_0057c670->map;
        void *object = map->Lookup(field34, 0);
        int *result = ((struct Map *)object)->CollectBillboardDistances(animation);
        billboards = result;
    }
    {
        int *cache = billboards;
        return cache[5];
    }
}
