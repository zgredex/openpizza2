/* Record_GetTwoFloats48: reads two doubles from a 0x48-byte record and
   truncates them to int (0x534370). */
struct Record {
    char pad[0x48];
    int count;
    char *records;

    int GetTwoFloats48(int index, int *first, int *second);
};

int Record::GetTwoFloats48(int index, int *first, int *second)
{
    if (index < 0 || index >= count)
        return 0;
    if (*(int *)(records + index * 0x48) == -1)
        return 0;
    *first = (int)*(double *)(records + index * 0x48 + 8);
    *second = (int)*(double *)(records + index * 0x48 + 0x10);
    return 1;
}
