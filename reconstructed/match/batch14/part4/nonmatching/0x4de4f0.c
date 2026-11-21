/* Stats_SumGroupScores (0x4de4f0): sums a group score entry over all records,
   or delegates to a single record. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Stats {
    char pad[0x148];
    IDMap recordMap;

    float GetGroupScore(int group, int index);
    float SumGroupScores(int group, int index, Stats *single);
};

float Stats::SumGroupScores(int group, int index, Stats *single)
{
    float total = 0.0f;
    int count;
    int i;

    if (single != 0)
        return single->GetGroupScore(group, index);
    count = recordMap.count;
    i = 0;
    if (count <= 0)
        return total;
    do {
        Stats *record = (Stats *)recordMap.Lookup(i, 0);
        float value = record->GetGroupScore(group, index);

        i++;
        total += value;
    } while (i < count);
    return total;
}
