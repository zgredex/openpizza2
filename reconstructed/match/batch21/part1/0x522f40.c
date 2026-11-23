/* Array::InsertGrow (0x522f40). */
extern "C" void *operator_new(unsigned int size);
extern "C" void Mem_Free(void *ptr);
extern "C" void *memcpy(void *dst, const void *src, unsigned int size);

class CS {
public:
    void Enter();
    void Leave();
};

extern "C" CS DAT_00584180;

class Array {
public:
    int unused;
    int *values;
    int count;
    int capacity;
    int total;
    int InsertGrow(int value);
};

int Array::InsertGrow(int value)
{
    DAT_00584180.Enter();
    if (count >= capacity) {
        if (values == 0) {
            values = (int *)operator_new(0x50);
        } else {
            int *newValues = (int *)operator_new(capacity * 4 + 0x50);
            memcpy(newValues, values, capacity * 4);
            Mem_Free(values);
            values = newValues;
        }
        capacity += 0x14;
    }
    values[count] = value;
    int n = count + 1;
    int t = total + 1;
    count = n;
    total = t;
    DAT_00584180.Leave();
    return count - 1;
}
