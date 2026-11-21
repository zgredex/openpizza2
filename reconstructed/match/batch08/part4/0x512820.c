/* IDMap_FindIndexByPointer: returns the index of a mapped pointer
   (0x512820). */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *out);
};

int __stdcall IDMap_FindIndexByPointer(IDMap *map, int pointer)
{
    int i;

    for (i = 0; i < map->count; i++) {
        void *value = map->Lookup(i, 0);
        if (pointer == (int)value)
            return i;
    }
    return -1;
}
