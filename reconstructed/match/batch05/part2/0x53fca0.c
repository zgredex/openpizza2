/* SoundPakManager_Delete: scalar deleting destructor (0x53fca0). */
void __fastcall SoundPakManager_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall SoundPakManager_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundPakManager_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
