/* Array_GetRecord28: returns a 0x28-byte record from one of two arrays
   (0x4f0cc0). */
struct Array {
    char pad[0x9c];
    char *recordsA;
    char *recordsB;
    void *GetRecord28(int which, int index);
};

void *Array::GetRecord28(int which, int index)
{
    if (index == -1)
        return 0;
    if (which == 1)
        return recordsA + index * 0x28;
    return recordsB + index * 0x28;
}
