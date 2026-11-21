/* Array_Destroy - 0x522f20, 21 bytes */
extern char DAT_0055c774;
extern void Mem_Free(void *memory);

struct Array
{
    void **vtable;
    void *buffer;

    void Destroy();
};

void Array::Destroy()
{
    *(void **)this = &DAT_0055c774;
    if (buffer != 0)
        Mem_Free(buffer);
}
