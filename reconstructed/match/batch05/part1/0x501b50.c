/* Player_AIState_Delete: scalar deleting destructor (0x501b50). */
void __fastcall Player_AIState_Destroy(void *this_);
void Mem_Free(void *);

void * __fastcall Player_AIState_Delete(void *this_, int dummy, unsigned char flags)
{
    Player_AIState_Destroy(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
