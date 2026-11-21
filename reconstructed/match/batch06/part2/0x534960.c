/* Record_GetValue48: reads the short value of an active record (0x534960). */
struct Entry {
    char data[0x48];
};

struct Record {
    char pad0[0x48];
    int count;
    Entry *entries;
    int GetValue48(int index);
};

int Record::GetValue48(int index)
{
    Entry *entry;

    if (index < 0 || index >= count) {
        return 0;
    }
    entry = &entries[index];
    if (*(int *)entry == -1) {
        return 0;
    }
    return *(short *)((char *)entry + 0x32);
}
