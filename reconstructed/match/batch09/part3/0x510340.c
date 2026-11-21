/* UI_GetMaxChildField10: returns the largest field 0x10 among a UI object's
   children, or zero when the child map is missing (0x510340). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

extern "C" int __fastcall UI_GetMaxChildField10(int param_1)
{
    IDMap *map = *(IDMap **)(param_1 + 0x304);
    int maximum = -1;
    int count;
    int i;
    int *child;

    if (map == 0)
        return 0;
    count = *(int *)((char *)map + 0x14);
    for (i = 0; i < count; i++) {
        child = ((IDMap *)*(void **)(param_1 + 0x304))->Lookup(i, 0);
        if (child[4] > maximum)
            maximum = child[4];
    }
    return maximum;
}
