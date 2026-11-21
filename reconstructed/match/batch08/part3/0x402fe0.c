/* FileObject_Destroy: releases the file object's three buffers (0x402fe0). */
extern "C" void __cdecl Mem_Free(void *ptr);

struct FileObject {
    void *vtable;              /* 0x0 */
    void *buffer1;             /* 0x4 */
    void *buffer2;             /* 0x8 */
    void *buffer3;             /* 0xc */
};

void __fastcall FileObject_Destroy(FileObject *self)
{
    self->vtable = (void *)0x55c2f4;
    if (self->buffer1 != 0)
        Mem_Free(self->buffer1);
    if (self->buffer2 != 0)
        Mem_Free(self->buffer2);
    if (self->buffer3 != 0)
        Mem_Free(self->buffer3);
}
