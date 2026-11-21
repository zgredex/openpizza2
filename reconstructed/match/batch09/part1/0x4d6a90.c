/* Map_FindRecordByFirstField: linear search of the map records by their first
   field (0x4d6a90). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Map {
    int *FindRecordByFirstField(int value);
};

int *Map::FindRecordByFirstField(int value)
{
    int index;

    for (index = 0; index < *(int *)((char *)this + 0xfdc); index++) {
        int *record = ((struct IDMap *)((char *)this + 0xfc8))->Lookup(index, 0);

        if (*record == value)
            return record;
    }
    return 0;
}
