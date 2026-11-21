/* SoundMixerThread_Delete: scalar deleting destructor (0x5427c0). */
void __fastcall SoundMixerThread_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall SoundMixerThread_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundMixerThread_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
