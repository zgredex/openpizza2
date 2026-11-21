/* Dialog_Delete: scalar deleting destructor (0x52e9b0). */
void __fastcall Dialog_Destructor(void *this_);
void Mem_Free(void *);

void * __fastcall Dialog_Delete(void *this_, int dummy, unsigned char flags)
{
    Dialog_Destructor(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
