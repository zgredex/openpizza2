/* UI_ListEntry_Delete: scalar deleting destructor (0x403350). */
void __fastcall UI_ListEntry_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_ListEntry_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_ListEntry_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
