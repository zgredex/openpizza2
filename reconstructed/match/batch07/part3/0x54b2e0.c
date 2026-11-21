/* IDMap_FindByField34: linear search for a record whose dword at 0x34
   matches (0x54b2e0). */
struct IDMap {
    int field0;
    void *Lookup(int index, int *out);
};

struct Record {
    char pad[0x34];
    int field34;
};

struct IDMap_t {
    char pad0[4];
    IDMap map;
    char pad[0x10];
    int count;
    Record *FindByField34(int value);
};

Record *IDMap_t::FindByField34(int value)
{
    int count = this->count;
    int index;
    Record *record;

    for (index = 0; index < count; index++) {
        record = (Record *)map.Lookup(index, 0);
        if (record->field34 == value)
            return record;
    }
    return 0;
}
