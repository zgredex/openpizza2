/* FileObject_Delete: scalar deleting destructor (0x402ef0). */
void __fastcall FileObject_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall FileObject_Delete(void *this_, int dummy, unsigned char flags)
{
    FileObject_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
