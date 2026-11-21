/* Record_SetDoubles48B: stores two doubles into a 0x48-byte record
   (0x5335b0). */
struct RecordTable {
    char pad[0x48];
    int count;
    char *records;
    unsigned char SetDoubles48B(int index, double first, double second);
};

unsigned char RecordTable::SetDoubles48B(int index, double first,
                                         double second)
{
    if (index < 0 || index >= count)
        return 0;
    *(double *)(records + index * 0x48 + 0x18) = first;
    *(double *)(records + index * 0x48 + 0x20) = second;
    return 1;
}
