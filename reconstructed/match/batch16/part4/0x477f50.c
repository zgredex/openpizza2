/* Stats_SumFilteredRecordFloats20 (0x477f50): sums the first twenty floats
   of every record matching the field/index filter. */
struct Record {
    char pad0[4];
    int index;
    int field;
    char padC[4];
    float values[20];
};
struct IDMap { Record *Lookup(int index, int *out); };
class Stats { public: float SumFilteredRecordFloats20(int field, int index); };
float Stats::SumFilteredRecordFloats20(int field, int index)
{
    float total = 0.0f;
    int count = *(int *)((char *)this + 0x14f8);
    for (int i = 0; i < count; i++) {
        Record *record = ((IDMap *)((char *)this + 0x14e4))->Lookup(i, 0);
        int rf = record->field; int ri = record->index;
        if ((rf == field || field == -1) && (index == -1 || index == ri))        {
            for (int j = 0; j < 20; j++) { total += record->values[j]; }
        }
    }
    return total;
}
