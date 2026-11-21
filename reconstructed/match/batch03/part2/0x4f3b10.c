/* Array_GetField4Stride12 - 0x4f3b10, 21 bytes */
int __stdcall Array_GetField4Stride12(int base, int index)
{
    return *(int *)(*(int *)(base + 8) + index * 0xc + 4);
}
