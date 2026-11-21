/* Array_Clear: releases the buffer and resets the array fields (0x522ef0). */
struct Array {
    int pad0;
    void *buffer;
    int count;
    int fieldC;
    int field10;
    void Clear();
};

extern "C" void Mem_Free(void *block);

void Array::Clear()
{
    if (buffer != 0) {
        Mem_Free(buffer);
    }
    buffer = 0;
    fieldC = 0;
    count = 0;
    field10 = 0;
}
