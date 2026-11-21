/* Sprite_ScalarDeletingDestructor: scalar deleting destructor (0x53c7d0). */
void __fastcall Sprite_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall Sprite_ScalarDeletingDestructor(void *this_, int dummy, unsigned char flags)
{
    Sprite_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
