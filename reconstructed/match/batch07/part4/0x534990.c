/* Record_SetIndex48: stores a short index into a 0x48-byte record
   (0x534990). */
struct Record48 {
    int id;
    char pad[0x2e];
    short index;
    char pad3[0x14];
};

struct RecordTable {
    char pad[0x48];
    int count;
    Record48 *records;
    char pad2[0x18];
    int limit;
    void SetIndex48(int index, int value);
};

void RecordTable::SetIndex48(int index, int value)
{
    Record48 *record;

    if (index < 0 || index >= count)
        return;
    record = &records[index];
    if (record->id == -1)
        return;
    if (value < 0 || value >= limit)
        return;
    record->index = (short)value;
}
