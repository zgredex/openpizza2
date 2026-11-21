/* Array_SetField4Stride12: stores a dword in a 12-byte record (0x4ed310). */
void __stdcall Array_SetField4Stride12(int *array, int index, int value)
{
    int *base = *(int **)((char *)array + 8);
    *(int *)((char *)base + index * 12 + 4) = value;
}
