/* UI_Viewport_Delete: scalar deleting destructor (0x521160). */
void __fastcall UI_CustomControl_Destructor(void *this_);
void Mem_Free(void *);

void * __fastcall UI_Viewport_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_CustomControl_Destructor(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
