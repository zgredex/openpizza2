/* SoundBuffer_Delete2: scalar deleting destructor (0x546730). */
void __fastcall SoundBuffer_Destructor(void *this_);
void Mem_Free(void *);

void * __fastcall SoundBuffer_Delete2(void *this_, int dummy, unsigned char flags)
{
    SoundBuffer_Destructor(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
