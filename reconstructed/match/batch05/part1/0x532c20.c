/* Animation_ScalarDeletingDestructor: scalar deleting destructor (0x532c20). */
void __fastcall SpriteFile_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall Animation_ScalarDeletingDestructor(void *this_, int dummy, unsigned char flags)
{
    SpriteFile_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
