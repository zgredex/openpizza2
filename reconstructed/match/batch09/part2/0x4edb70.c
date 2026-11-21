/* Object_ClearRecordFirstBytes: clears the first byte of every 0x28-byte
   record buffer (0x4edb70). */
struct Object {
    void GetBufferPair(int buffer, int **base, int **count, int *a, int *b);
    void ClearRecordFirstBytes(int *buffer);
};

void Object::ClearRecordFirstBytes(int *buffer)
{
    int *base;
    int index;

    GetBufferPair((int)buffer, &base, &buffer, 0, 0);
    for (index = 0; index < *buffer; index++)
        *(char *)(*base + index * 0x28) = 0;
}
