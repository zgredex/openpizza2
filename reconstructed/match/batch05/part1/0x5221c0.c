/* UI_LabelElement_Delete: scalar deleting destructor (0x5221c0). */
void __fastcall UI_LabelElement_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_LabelElement_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_LabelElement_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
