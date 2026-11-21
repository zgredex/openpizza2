/* List_ContainerDestroy: scalar deleting destructor (0x545b00). */
void __fastcall List_ContainerDestruct(void *this_);
void Mem_Free(void *);

void * __fastcall List_ContainerDestroy(void *this_, int dummy, unsigned char flags)
{
    List_ContainerDestruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
