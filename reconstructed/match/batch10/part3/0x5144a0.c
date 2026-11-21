/* Stats_GetAverageRecordValue: average the tenths of a record map. */
struct IDMap {
    void *Lookup(int key, int *out);
};

int __fastcall Stats_GetAverageRecordValue(int param_1)
{
    int count = *(int *)(param_1 + 0x58);
    int sum = 0;
    int i = 0;

    if (count > 0) {
        do {
            int *record = (int *)((IDMap *)(param_1 + 0x44))->Lookup(i, 0);
            sum += record[1];
            i++;
        } while (i < count);
    }
    if (count == 0)
        return 0;
    return (sum / 10) / count;
}
