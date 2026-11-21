/* Stats_GetAverageFlaggedValue (0x47ee60). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct StatRecord {
    char pad0[4];
    int value;              /* 0x04 */
    char pad1[0x14];        /* to 0x1c */
    int flagged;            /* 0x1c */
};
struct Stats {
    char pad0[0x1998];
    IDMap map;              /* 0x1998 */
    int count;              /* 0x19ac */

    int GetAverageFlaggedValue();
};

int Stats::GetAverageFlaggedValue()
{
    int sum = 0;
    int entries = 0;
    int index = 0;
    int total = count;

    if (total <= 0)
        return 0;
    do {
        StatRecord *record = (StatRecord *)map.Lookup(index, 0);

        if (record->flagged != 0) {
            sum += record->value;
            entries++;
        }
        index++;
    } while (index < total);
    if (entries == 0)
        return 0;
    return (sum / 10) / entries;
}
