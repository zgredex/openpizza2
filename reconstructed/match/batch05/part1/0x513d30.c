/* Storage_Delete: scalar deleting destructor (0x513d30). */
void __fastcall Storage_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Storage_Delete(void *this_, int dummy, unsigned char flags)
{
    Storage_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
