/* PC2 byte-match candidate: Array_GetPtrChecked (0x535d50, 26 bytes).
   Build: /O2 /TP.  Bounds-checked pointer array element fetch. */
struct Array {
    void **data;
    unsigned char pad_004[4];
    int count;
    void *GetPtrChecked(int index);
};

void *Array::GetPtrChecked(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return data[index];
}
