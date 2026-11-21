/* Stats_GetMinMapField10: returns the smallest field 0x10 among a UI
   object's children, or zero when the child map is missing (0x5102f0). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

extern "C" int __fastcall Stats_GetMinMapField10(int param_1)
{
    IDMap *map = *(IDMap **)(param_1 + 0x304);
    int minimum = 99999999;
    int count;
    int i;
    int *child;

    if (map == 0)
        return 0;
    count = *(int *)((char *)map + 0x14);
    for (i = 0; i < count; i++) {
        child = ((IDMap *)*(void **)(param_1 + 0x304))->Lookup(i, 0);
        if (child[4] < minimum)
            minimum = child[4];
    }
    return minimum;
}
