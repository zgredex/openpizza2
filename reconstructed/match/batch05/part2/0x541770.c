/* SoundStreamBuffer_DeleteObject: scalar deleting destructor (0x541770). */
void __fastcall SoundStreamBuffer_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall SoundStreamBuffer_DeleteObject(void *this_, int dummy, unsigned char flags)
{
    SoundStreamBuffer_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
