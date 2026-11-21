/* Stats_FindRecordByType: finds the statistics record with the requested
   type (0x477c20). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct Stats {
    char pad[0x14e4];
    char records[0x14];
    int count;

    void FindRecordByType(int type);
};

void Stats::FindRecordByType(int type)
{
    int total = count;
    IDMapHelper *map = (IDMapHelper *)records;
    int index;

    if (type == -1) {
        map->Lookup(total - 1, 0);
        return;
    }
    for (index = 0; index < total; index++) {
        char *record = (char *)map->Lookup(index, 0);

        if (*(int *)(record + 4) == type)
            return;
    }
}
