/* Recipe_Delete: scalar deleting destructor (0x50fdd0). */
void __fastcall Recipe_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Recipe_Delete(void *this_, int dummy, unsigned char flags)
{
    Recipe_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
