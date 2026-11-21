/* NameMap_GetString: localized name lookup with an empty-string fallback (0x4cda30). */
extern char DAT_00568310[];

struct IDMap {
    void *Lookup(int key, int *value);
};

void * __cdecl NameMap_GetString(IDMap *map, int key)
{
    void *value = map->Lookup(key, 0);

    if (value == 0)
        value = (void *)DAT_00568310;
    return value;
}
