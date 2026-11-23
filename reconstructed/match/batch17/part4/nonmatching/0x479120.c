struct IDMap {
    int unused;
    void *Lookup(int index, int *out);
};

struct Record {
    int unused;
    int field4;
    char pad[8];
    int type;
};

struct Company {
    char pad0[0x16f8];
    IDMap map;
    char pad1[0x170c - 0x16fc];
    int count;
    char pad2[0x183c - 0x1710];
    int percentages[4];
    void ComputeTypePercentages();
};

struct GameData {
    char pad[0x74];
    IDMap typeMap;
};

extern GameData *DAT_0057c670;
extern float DAT_0055c320;

void Company::ComputeTypePercentages()
{
    int total = 0;
    int counts[5] = {0, 0, 0, 0, 0};
    int i = 0;
    if (0 < *(int *)((char *)this + 0x170c)) {
        do {
            Record *record = (Record *)((IDMap *)((char *)this + 0x16f8))->Lookup(i, 0);
            if (record != 0) {
                int type = *(int *)((char *)((IDMap *)((char *)DAT_0057c670 + 0x74))
                                        ->Lookup(record->field4, 0) +
                                    0x10);
                if (type != 4) {
                    total = total + 1;
                    counts[type] = counts[type] + 1;
                }
            }
            i++;
        } while (i < *(int *)((char *)this + 0x170c));
    }
    for (i = 0; i < 4; i++) {
        if (total < 1)
            percentages[i] = 0;
        else
            percentages[i] = (int)((float)counts[i] / (float)total * DAT_0055c320);
    }
}
