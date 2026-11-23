/* Stats_SumFilteredFloats2 (0x478090): same shape with twenty-five floats
   at +0x78. */
struct Record {
    char pad0[4];
    int index;
    int field;
    char padC[0x6c];
    float values[25];
};

struct IDMap {
    Record *Lookup(int index, int *out);
};

class Stats {
public:
    float SumFilteredFloats2(int column, int field, int index);
};

float Stats::SumFilteredFloats2(int column, int field, int index)
{
    float total = 0.0f;
    int count = *(int *)((char *)this + 0x14f8);

    for (int i = 0; i < count; i++) {
        Record *record = ((IDMap *)((char *)this + 0x14e4))->Lookup(i, 0);
        int rf = record->field;
        int ri = record->index;
        if ((rf == field || field == -1) && (index == -1 || index == ri)) {
            if (column == -1) {
                for (int j = 0; j < 25; j++) {
                    total += record->values[j];
                }
            } else {
                float value = record->values[column];
                total += value;
            }
        }
    }
    return total;
}
