/* Array_GetPtr: bounds-checked element pointer accessor (0x5230b0). */
struct Array {
    char pad[4];
    void **data;
    int count;
    void *GetPtr(int index);
};

void *Array::GetPtr(int index)
{
    if (index < 0 || index >= count) {
        return 0;
    }
    return data[index];
}
