/* Array_RemoveValueLocked: removes the first array element with the given
   value under the global critical section (0x523050). */
struct CS {
    void Enter();
    void Leave();
};

struct Array {
    char pad[4];
    int *values;
    int count;
    char pad2[4];

    int RemoveValueLocked(int value);
    void RemoveAt(int index);
};

extern char DAT_00584180[];

int Array::RemoveValueLocked(int value)
{
    int i;

    ((struct CS *)DAT_00584180)->Enter();
    for (i = 0; i < count; i++) {
        if (values[i] == value) {
            RemoveAt(i);
            ((struct CS *)DAT_00584180)->Leave();
            return 1;
        }
    }
    ((struct CS *)DAT_00584180)->Leave();
    return 0;
}
