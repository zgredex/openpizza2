/* Array_Delete: scalar deleting destructor (0x522ed0). */
void __fastcall Array_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Array_Delete(void *this_, int dummy, unsigned char flags)
{
    Array_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
