/* UI_Tooltip_Delete: scalar deleting destructor (0x52e510). */
void __fastcall UI_Tooltip_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_Tooltip_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_Tooltip_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
