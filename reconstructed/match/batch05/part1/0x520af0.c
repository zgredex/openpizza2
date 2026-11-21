/* UI_Child_Delete: scalar deleting destructor (0x520af0). */
void __fastcall UI_Child_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_Child_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_Child_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
