/* IDMap_FreeValuesAndDestroy: frees all mapped values then deletes the map
   (0x4fc0b0). */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *out);
};

struct Base {
    virtual void Destroy(int flags);
};

extern "C" void __cdecl Mem_Free(void *ptr);

void __stdcall IDMap_FreeValuesAndDestroy(IDMap *map)
{
    int i = 0;
    int count = map->count;

    if (count > 0) {
        do {
            Mem_Free(map->Lookup(i, 0));
            i++;
        } while (i < count);
    }
    if (map != 0)
        ((Base *)map)->Destroy(1);
}
