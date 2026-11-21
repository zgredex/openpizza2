/* Array_GetStride60: address of a 0x60-byte array element (0x4da630). */
struct Array {
    int GetStride60(int index);
};

int Array::GetStride60(int index)
{
    if (index >= 0)
        return (int)this + index * 0x60 + 0xdc8;
    return 0;
}
