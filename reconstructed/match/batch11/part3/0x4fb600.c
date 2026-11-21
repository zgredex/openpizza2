/* Stats_SumRecordCounts: sums the record counts of a map, splitting the
   selected records from the total (0x4fb600). */
struct IDMap {
    char pad[0x14];
    int count;

    void *Lookup(int index, int *out);
};

struct Record {
    char pad[4];
    int count;
    char pad2[0x14];
    int selected;
};

void __stdcall Stats_SumRecordCounts(struct IDMap *map, int *selected, int *total)
{
    int i;
    int records;

    *selected = 0;
    *total = 0;
    records = map->count;
    for (i = 0; i < records; i++) {
        struct Record *record = (struct Record *)map->Lookup(i, 0);

        *total += record->count;
        if (record->selected != 0) {
            *selected += record->count;
        }
    }
}
