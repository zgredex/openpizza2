/* PC2 byte-match candidate: Record_Clear48 (0x533a50, 29 bytes).
   Build: /O2 /TP.  Bounds-checked clear of a 0x48-byte record id. */
struct Record48 {
    int id;
    unsigned char pad_004[0x44];
};

struct RecordSet {
    unsigned char pad_000[0x48];
    int count;
    Record48 *records;
    void Clear(int index);
};

void RecordSet::Clear(int index)
{
    if (index >= 0 && index < count)
        records[index].id = -1;
}
