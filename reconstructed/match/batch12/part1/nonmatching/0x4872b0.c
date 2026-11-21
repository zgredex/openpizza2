/* UI_ClearActiveRecordSlots: clears the active record slots that reference
   flagged records (0x4872b0). */
extern void *DAT_0057c5cc;

struct IDMap {
    char pad[0x48];
    int count;
    char *records;
};

struct RecordTable {
    void ClearFlags48(int index);
};

extern "C" void __fastcall UI_ClearActiveRecordSlots(void *window)
{
    struct RecordTable *records =
        *(struct RecordTable **)((char *)DAT_0057c5cc + 0x2c3d4);
    int offset = 0x2c41c;

    do {
        int index = *(int *)((char *)DAT_0057c5cc + offset);

        if (index >= 0 && index < *(int *)((char *)records + 0x48)) {
            char *base = *(char **)((char *)records + 0x4c);
            unsigned char flags = base[0x3e + index * 0x48];

            if ((int)flags != 0) {
                records->ClearFlags48(index);
                *(int *)((char *)window + offset - 0x2c0b0) = -1;
            }
        }
        offset += 4;
    } while (offset < 0x2c434);
}
