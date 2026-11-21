/* SoundSample_Delete: scalar deleting destructor (0x53f5b0). */
void __fastcall SoundSample_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall SoundSample_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundSample_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
