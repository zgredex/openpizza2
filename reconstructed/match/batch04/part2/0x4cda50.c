/* NameMap_GetRecordString: record text lookup with an empty-string fallback (0x4cda50). */
extern char DAT_00568310[];

struct IDMap {
    void *Lookup(int key, int *value);
};

void * __cdecl NameMap_GetRecordString(IDMap *map, int key)
{
    void *value = map->Lookup(key, 0);

    if (value == 0)
        return (void *)DAT_00568310;
    return (char *)value + 0x40;
}
