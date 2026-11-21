/* Stats_SumValuesByCategory (0x510030): sums the values of records that
   match a category and storage mode. */
extern float DAT_0055c2e4;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Stats {
    char pad[0x304];
    IDMap *records;
    float SumValuesByCategory(int category, int storageMode);
};

float Stats::SumValuesByCategory(int category, int storageMode)
{
    float total;
    int count;
    int index;
    int record;

    total = 0.0f;
    if (records == 0) {
        return 0.0f;
    }
    count = *(int *)((char *)records + 0x14);
    index = 0;
    if (count > 0) {
        do {
            record = records->Lookup(index, 0);
            if ((*(int *)(record + 0x10) == category || category == -1) &&
                (storageMode == -1 ||
                 *(int *)(record + 0x14) == storageMode)) {
                total = total + *(float *)(record + 8);
            }
            index = index + 1;
        } while (index < count);
    }
    return total;
}
