/* Array_GetField20ByKey: finds an array entry by key and returns the record's
   field at 0x20, or zero when the key is absent (0x531780).  Build: /O2 /TP. */
struct ArrayEntry {
    char *record;
    int key;
};

struct Array {
    char pad[0xe8];
    ArrayEntry *entries;
    int FindIndex(int key, int mode);
    int GetField20ByKey(int key);
};

int Array::GetField20ByKey(int key)
{
    int index = FindIndex(key, 0);

    if (index == -1)
        return 0;
    return *(int *)(entries[index].record + 0x20);
}
