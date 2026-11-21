/* Stats_SumRecordFloatMatrix (0x4de280): sums a float matrix entry over all
   records, or delegates to a single record. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Stats {
    char pad[0x148];
    IDMap recordMap;

    float SumFloatMatrix(int row, int column);
    float SumRecordFloatMatrix(int row, int column, Stats *single);
};

float Stats::SumRecordFloatMatrix(int row, int column, Stats *single)
{
    float total = 0.0f;
    int count;
    int i;

    if (single != 0)
        return single->SumFloatMatrix(row, column);
    count = recordMap.count;
    i = 0;
    if (count <= 0)
        return 0.0f;
    do {
        Stats *record = (Stats *)recordMap.Lookup(i, 0);
        float value = record->SumFloatMatrix(row, column);

        i++;
        total += value;
    } while (i < count);
    return total;
}
