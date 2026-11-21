/* List_Node_Delete: scalar deleting destructor (0x401420). */
void __fastcall List_Node_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall List_Node_Delete(void *this_, int dummy, unsigned char flags)
{
    List_Node_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
