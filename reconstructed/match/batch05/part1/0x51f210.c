/* UI_ImageElement_Delete: scalar deleting destructor (0x51f210). */
void __fastcall UI_ImageElement_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall UI_ImageElement_Delete(void *this_, int dummy, unsigned char flags)
{
    UI_ImageElement_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
