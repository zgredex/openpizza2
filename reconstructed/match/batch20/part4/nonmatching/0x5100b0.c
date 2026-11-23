extern float DAT_0055c2e4;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Stats {
    char pad[0x304];
    IDMap *map;
    float SumMaskedMapFloats(int type, char *mask, int other);
};

float Stats::SumMaskedMapFloats(int type, char *mask, int other)
{
    float sum = 0;
    int indices[8];
    int total;
    int i;
    int n;

    if (map == 0)
        return DAT_0055c2e4;
    total = *(int *)((char *)map + 0x14);
    if (mask == 0) {
        for (i = 0; i < total; i++) {
            int *record = (int *)map->Lookup(i, 0);
            if ((record[4] == type || type == -1) &&
                (other == -1 || record[5] == other))
                sum += *(float *)(record + 1);
        }
        return sum;
    }
    n = 0;
    for (i = 0; i < 8; i++) {
        if (mask[i] == 1) {
            indices[n] = i;
            n++;
        }
    }
    for (i = 0; i < total; i++) {
        int *record = (int *)map->Lookup(i, 0);
        if ((record[4] == type || type == -1) && n > 0) {
            int j;
            for (j = 0; j < n; j++) {
                if (indices[j] == record[6] &&
                    (other == -1 || record[5] == other))
                    sum += *(float *)(record + 1);
            }
        }
    }
    return sum;
}
