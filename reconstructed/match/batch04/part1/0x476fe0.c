/* Branch_Delete: scalar deleting destructor (0x476fe0). */
void __fastcall Branch_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Branch_Delete(void *this_, int dummy, unsigned char flags)
{
    Branch_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
