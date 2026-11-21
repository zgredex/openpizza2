/* ResourceManager_ScalarDeletingDestructor (0x401a00). */
void __fastcall ResourceManager_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall ResourceManager_ScalarDeletingDestructor(void *this_, int dummy,
                                                           unsigned char flags)
{
    ResourceManager_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
