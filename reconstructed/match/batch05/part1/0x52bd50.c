/* UI_TextElement_Delete: scalar deleting destructor (0x52bd50). */
void __fastcall UI_TextElement_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_TextElement_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_TextElement_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
