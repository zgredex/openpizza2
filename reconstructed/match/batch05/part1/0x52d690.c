/* UI_ButtonElement_Delete: scalar deleting destructor (0x52d690). */
void __fastcall UI_ButtonElement_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_ButtonElement_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_ButtonElement_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
