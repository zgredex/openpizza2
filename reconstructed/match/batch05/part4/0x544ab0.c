/* SoundSystem_Delete: deleting destructor for the sound system object (0x544ab0). */
void __fastcall SoundSystem_Destroy(void *this_);
void __cdecl Mem_Free(void *block);

void * __fastcall SoundSystem_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundSystem_Destroy(this_);
    if (flags & 1)
        Mem_Free((char *)this_ - 4);
    return (char *)this_ - 4;
}
