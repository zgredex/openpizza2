/* Stats_SumFilteredFloats (0x477fe0): sums the selected record float for
   every record matching the field/index filter, or all twenty-six when the
   column is -1. */
struct Record {
    char pad0[4];
    int index;
    int field;
    char padC[4];
    float values[26];
};

struct IDMap {
    Record *Lookup(int index, int *out);
};

class Stats {
public:
    float SumFilteredFloats(int column, int field, int index);
};

float Stats::SumFilteredFloats(int column, int field, int index)
{
    float total = 0.0f;
    int count = *(int *)((char *)this + 0x14f8);

    for (int i = 0; i < count; i++) {
        Record *record = ((IDMap *)((char *)this + 0x14e4))->Lookup(i, 0);
        int rf = record->field;
        int ri = record->index;
        if ((rf == field || field == -1) && (index == -1 || index == ri)) {
            if (column == -1) {
                for (int j = 0; j < 26; j++) {
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
