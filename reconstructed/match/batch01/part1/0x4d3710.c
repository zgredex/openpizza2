/* Character_Delete: scalar deleting destructor (0x4d3710). */
void __fastcall Character_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Character_Delete(void *this_, int dummy, unsigned char flags)
{
    Character_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
