/* Record_AssignVariant (0x534bc0). */
struct Variant {
    char pad0[0x80];
    char valid;             /* 0x80 */
    char pad1[0x17];
};
struct Record {
    int variant;            /* 0x00 */
    char pad0[0x3a];
    char flags;             /* 0x3e */
    char pad1[9];
};
struct RecordList {
    char pad0[0x4c];
    Record *records;        /* 0x4c */
    Variant *variants;      /* 0x50 */
    char pad1[0x10];        /* to 0x64 */
    int variantCount;       /* 0x64 */

    void AssignVariant(int record, int variant);
    void ClearFlags48(int record);
    void SelectVariant(int record, int variant);
};

void RecordList::AssignVariant(int record, int variant)
{
    char flags;

    if (variant < 0 || variant >= variantCount)
        return;
    if (variants[variant].valid == 0)
        return;
    flags = records[record].flags;
    if (flags != 0)
        ClearFlags48(record);
    records[record].variant = variant;
    if (flags != 0)
        SelectVariant(record, -1);
}
