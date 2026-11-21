/* SoundTrack_Delete: scalar deleting destructor (0x541f10). */
void __fastcall SoundTrack_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall SoundTrack_Delete(void *this_, int dummy, unsigned char flags)
{
    SoundTrack_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
