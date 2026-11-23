// Stats_GetFilteredFloatDelta @ 0x4e0df0 (150 bytes)
// Sums two filtered float fields and returns their difference.

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class Record {
public:
    int field0;
    int field4;
    int field8;
    float SumFloatArray26();
};

class Object {
public:
    float SumFloat25();
};

class Stats {
public:
    char pad0[0x164];
    IDMap map;
    int count;

    float GetFilteredFloatDelta(int type, int code);
};

float Stats::GetFilteredFloatDelta(int type, int code)
{
    int count = this->count;
    float upper = 0;
    float lower = 0;
    int index = 0;

    if (count > 0) {
        do {
            Record *record = (Record *)this->map.Lookup(index, 0);
            if ((record->field4 != -2 || code == -2) && record->field8 == type &&
                (code == -1 || code == record->field4)) {
                upper += record->SumFloatArray26();
                lower += ((Object *)record)->SumFloat25();
            }
            index++;
        } while (index < count);
    }
    return (float)(upper - lower);
}
