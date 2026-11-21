/* SoundBuffer_Delete: scalar deleting destructor (0x53f000). */
void __fastcall SoundBuffer_DestructBase(void *this_);
void Mem_Free(void *);

void * __fastcall SoundBuffer_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundBuffer_DestructBase(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
