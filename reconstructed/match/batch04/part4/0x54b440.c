/* PC2 byte-match candidate: Array_GetPtr4 (0x54b440, 26 bytes).
   Build: /O2 /TP.  Bounds-checked pointer array element fetch. */
struct Array {
    void **data;
    int count;
    void *GetPtr4(int index);
};

void *Array::GetPtr4(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return data[index];
}
