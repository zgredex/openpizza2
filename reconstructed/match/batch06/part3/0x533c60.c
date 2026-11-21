/* Record_ClearActive48: clears the active byte and word of one record
   (0x533c60).  Build: /O2 /TP. */
struct Record {
    char pad[0x48];
    int count;
    char *records;
    void ClearActive48(int index);
};

void Record::ClearActive48(int index)
{
    if (index >= 0 && index < count) {
        records[index * 72 + 0x3c] = 0;
        *(short *)(records + index * 72 + 0x30) = 0;
    }
}
