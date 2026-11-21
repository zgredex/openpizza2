/* SoundBuffer_DeleteObject: scalar deleting destructor (0x540890). */
void __fastcall SoundBuffer_DestructDerived(void *this_);
void Mem_Free(void *);

void * __fastcall SoundBuffer_DeleteObject(void *this_, int dummy, unsigned char flags)
{
    SoundBuffer_DestructDerived(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
