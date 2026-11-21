/* RecordList_ReadSlot98: copies one six-byte sub-record out of the slot array
   (0x5349e0). */
struct SubRecord {
    int field0;
    short field4;
};

struct RecordList {
    char pad[0x50];
    char *slots;
    char pad2[0x10];
    int count;

    void ReadSlot98(int index, int sub, SubRecord *out);
};

void RecordList::ReadSlot98(int index, int sub, SubRecord *out)
{
    if (index < 0 || index >= count) {
        out->field0 = 0;
        out->field4 = 0;
    } else if (sub >= 0 && sub < 0x10) {
        SubRecord *record =
            (SubRecord *)(slots + index * 0x98 + sub * 6);

        out->field0 = record->field0;
        out->field4 = record->field4;
    }
}
