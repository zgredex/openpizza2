/* DirectSoundBuffer_Delete: releases the buffer's child object and frees the
   wrapper when the deleting flag is set (0x53fc10).  Build: /O2 /TP. */
struct DirectSoundBuffer {
    void *vtable;
    void *child;
};

void __cdecl Mem_Free(void *block);

void *__fastcall DirectSoundBuffer_Delete(DirectSoundBuffer *self, int dummy,
                                          unsigned char flags)
{
    void *child = self->child;

    *(void **)self = (void *)0x55c860;
    if (child != 0)
        (*(void (__stdcall **)(void *))((*(char **)child) + 8))(child);
    if (flags & 1)
        Mem_Free(self);
    return self;
}
