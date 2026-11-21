/* MovieWindow_Delete: scalar deleting destructor (0x52b210). */
void __fastcall MovieWindow_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall MovieWindow_Delete(void *this_, int dummy, unsigned char flags)
{
    MovieWindow_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
