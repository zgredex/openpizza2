/* UI_ContextMenu_Delete: scalar deleting destructor (0x5286e0). */
void __fastcall UI_ContextMenu_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_ContextMenu_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_ContextMenu_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
