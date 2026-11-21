/* Gfx_RectList_Delete: scalar deleting destructor (0x534db0). */
void __fastcall Gfx_RectList_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Gfx_RectList_Delete(void *this_, int dummy, unsigned char flags)
{
    Gfx_RectList_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
