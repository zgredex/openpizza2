/* Player_Delete: scalar deleting destructor (0x50e9c0). */
void __fastcall Player_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Player_Delete(void *this_, int dummy, unsigned char flags)
{
    Player_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
