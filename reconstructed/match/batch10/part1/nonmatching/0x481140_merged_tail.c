/* Branch_GetCachedBillboards: lazily collects and caches billboard distances
   for a branch (0x481140). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Map {
    int *CollectBillboardDistances(int animation);
};

struct Branch {
    char pad[0x34];
    int field34;
    char pad2[0x16f0 - 0x38];
    int animation;
    char pad3[0x1a28 - 0x16f4];
    int *billboards;

    int GetCachedBillboards();
};

extern char *DAT_0057c670;

int Branch::GetCachedBillboards()
{
    if (billboards == 0) {
        void *object = ((struct IDMap *)(DAT_0057c670 + 4))->Lookup(
            field34, 0);
        int *result = ((struct Map *)object)->CollectBillboardDistances(
            animation);

        billboards = result;
        return result[5];
    }
    return billboards[5];
}
