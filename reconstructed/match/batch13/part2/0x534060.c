/* Record_GetBounds48 (0x534060). */
struct RecordData {
    char pad0[0x20];
    short *leftTable;       /* 0x20 */
    short *topTable;        /* 0x24 */
    unsigned short *rightTable;  /* 0x28 */
    unsigned short *bottomTable; /* 0x2c */
    char pad1[0x2c];        /* to 0x4c */
};
struct RecordList {
    char pad0[0x20];
    short *leftTable;       /* 0x20 */
    short *topTable;        /* 0x24 */
    unsigned short *rightTable;  /* 0x28 */
    unsigned short *bottomTable; /* 0x2c */
    char pad1[0x1c];        /* to 0x4c */
    char *records;          /* 0x4c */

    void GetBounds48(int index, int *left, int *top, unsigned int *right,
                     unsigned int *bottom);
};

void RecordList::GetBounds48(int index, int *left, int *top,
                             unsigned int *right, unsigned int *bottom)
{
    int offset = index * 0x48;

    *left = *(short *)((char *)leftTable +
                       *(short *)(records + offset + 0x32) * 2);
    *top = *(short *)((char *)topTable +
                      *(short *)(records + offset + 0x32) * 2);
    *right = *(unsigned short *)((char *)rightTable +
                                 *(short *)(records + offset + 0x32) * 2);
    *bottom = *(unsigned short *)((char *)bottomTable +
                                  *(short *)(records + offset + 0x32) * 2);
}
