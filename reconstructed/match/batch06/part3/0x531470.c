/* Array_SetField14ByKey: finds an array entry by key and stores a value in
   the record's field at 0x14 (0x531470).  Build: /O2 /TP. */
struct ArrayEntry {
    char *record;
    int key;
};

struct Array {
    char pad[0xe8];
    ArrayEntry *entries;
    int FindIndex(int key, int mode);
    void SetField14ByKey(int key, int value);
};

void Array::SetField14ByKey(int key, int value)
{
    int index = FindIndex(key, 0);

    if (index != -1)
        *(int *)(entries[index].record + 0x14) = value;
}
