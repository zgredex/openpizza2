/* Object_ClearAssignedRecord: release the record assigned to an object. */
struct RecordMap {
    void *Lookup1998(int id);
};

struct Object {
    void SetFieldA4Locked(int value);
    int ClearAssignedRecord(RecordMap *map);
};

int Object::ClearAssignedRecord(RecordMap *map)
{
    if (*(int *)((char *)this + 0xa4) == 4) {
        int *record = (int *)map->Lookup1998(*(int *)((char *)this + 0x88));

        if (record != 0 && *record > 0) {
            SetFieldA4Locked(-1);
            *record = 0;
            return 1;
        }
    }
    return 0;
}
