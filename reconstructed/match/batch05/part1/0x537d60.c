/* Renderer_Delete: scalar deleting destructor (0x537d60). */
void __fastcall Renderer_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Renderer_Delete(void *this_, int dummy, unsigned char flags)
{
    Renderer_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
