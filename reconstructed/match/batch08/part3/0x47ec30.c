/* IDMap_FreeValuesAndReset: frees every mapped value and resets the map
   (0x47ec30). */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *out);
};

struct List_Node {
    void Reset();
};

extern "C" void __cdecl Mem_Free(void *ptr);

void __stdcall IDMap_FreeValuesAndReset(IDMap *map)
{
    int i = 0;
    int count = map->count;

    if (count > 0) {
        do {
            void *value = map->Lookup(i, 0);
            if (value != 0)
                Mem_Free(value);
            i++;
        } while (i < count);
    }
    ((List_Node *)map)->Reset();
}
