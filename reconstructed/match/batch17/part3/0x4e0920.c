struct Record {
    int unused0;
    int type;
    char pad[8];
    float values[0x1a];
};

struct IDMap {
    Record *Lookup(int index, int *out);
};

struct Stats {
    char pad1[0x148];
    IDMap map1;
    int count1;
    IDMap map2;
    int count2;
    float SumRecordFloatsByType(int index, int type);
    float SumFilteredFloats(int index, int unused, int type);
};

extern float DAT_0055c2e4;

float Stats::SumRecordFloatsByType(int index, int type)
{
    float total = DAT_0055c2e4;
    int count = *(int *)((char *)this + 0x178);
    for (int i = 0; i < count; i++) {
        Record *record = ((IDMap *)((char *)this + 0x164))->Lookup(i, 0);
        if (type == record->type) {
            if (index == -1) {
                for (int j = 0; j < 0x1a; j++)
                    total += record->values[j];
            } else {
                float value = record->values[index];
                total += value;
            }
        }
    }
    count = *(int *)((char *)this + 0x15c);
    for (i = 0; i < count; i++) {
        Record *record = ((IDMap *)((char *)this + 0x148))->Lookup(i, 0);
        total += ((Stats *)record)->SumFilteredFloats(index, -1, type);
    }
    return total;
}
