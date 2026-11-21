/* Record_GetScreenSortY: converts a record's screen position and applies the
   vertical sort offset (0x4ef0c0). */
struct FloatPair {
    void GetTwoFloats48(int value, void *out1, int *out2);
};

struct SortArgs {
    int field0;
    int field4;
};

struct Record {
    int GetScreenSortY(SortArgs *args);
};

int Record::GetScreenSortY(SortArgs *args)
{
    SortArgs *saved = args;
    int ignored;

    ((FloatPair *)*(int *)((char *)args + 0x58))
        ->GetTwoFloats48(*(int *)args, &ignored, (int *)&args);
    if (saved->field4 == -1)
        return (int)args + 0xd0;
    return (int)args + *(int *)((char *)this + 0xfc);
}
