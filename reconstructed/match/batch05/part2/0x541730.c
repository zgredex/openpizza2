/* SoundBuffer_ScalarDeletingDestructor: scalar deleting destructor (0x541730). */
void __fastcall SoundBuffer_DestroyInterfaces(void *this_);
void Mem_Free(void *);

void * __fastcall SoundBuffer_ScalarDeletingDestructor(void *this_, int dummy, unsigned char flags)
{
    SoundBuffer_DestroyInterfaces(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
