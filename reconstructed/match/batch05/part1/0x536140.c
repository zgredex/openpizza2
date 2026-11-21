/* Window_Delete: scalar deleting destructor (0x536140). */
void __fastcall Window_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Window_Delete(void *this_, int dummy, unsigned char flags)
{
    Window_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
