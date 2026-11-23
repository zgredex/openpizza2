/* IDMapHelper::InsertGrow (0x4015b0). */
extern "C" void *memcpy(void *, const void *, unsigned int);

extern "C" void __fastcall CS_Enter(void *);
extern "C" void __fastcall CS_Leave(void *);
extern "C" void *operator_new(unsigned int size);
extern "C" void Mem_Free(void *);
extern "C" int g_Liste_Lock;

struct IDMapHelper {
    int type;
    void *values;
    void *indices;
    int count;
    int capacity;
    int total;
    int maxIndex;
    int InsertGrow(int value, int index);
};

int IDMapHelper::InsertGrow(int value, int index)
{
    CS_Enter(&g_Liste_Lock);
    if (count >= capacity) {
        if (values == 0) {
            values = operator_new(0x50);
            indices = operator_new(0x50);
        } else {
            void *newValues = operator_new(capacity * 4 + 0x50);
            void *newIndices;
            memcpy(newValues, values, capacity * 4);
            newIndices = operator_new(capacity * 4 + 0x50);
            memcpy(newIndices, indices, capacity * 4);
            Mem_Free(values);
            values = newValues;
            Mem_Free(indices);
            indices = newIndices;
        }
        capacity += 0x14;
    }
    ((int *)values)[count] = value;
    ((int *)indices)[count] = index;
    count++;
    total++;
    if (index >= maxIndex) {
        maxIndex = index + 1;
    }
    CS_Leave(&g_Liste_Lock);
    return index;
}
