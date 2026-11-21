/* Storage_RemoveRecord (0x514080, 47 bytes).  Build: /O2 /TP.
   Finds the record's pair index and clears the two storage slots. */
struct Array {
    int FindPair(int key);
};

struct Storage {
    void RemoveRecord(int record);
};

void Storage::RemoveRecord(int record)
{
    int key = *(int *)(record + 0x3c);
    int index = ((Array *)this)->FindPair(key);

    if (index != -1) {
        *(int *)((char *)this + index * 0xc + 0x60) = 0;
        *(int *)((char *)this + index * 0xc + 0x64) = 0;
    }
}
