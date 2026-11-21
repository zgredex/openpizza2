/* GameWorld_Delete: deleting destructor for the game/world object (0x4817a0). */
void __fastcall GameState_Destruct(void *this_);
void Mem_Free(void *);

void * __fastcall GameWorld_Delete(void *this_, int dummy, unsigned char flags)
{
    GameState_Destruct(this_);
    if (flags & 1)
        Mem_Free(this_);
    return this_;
}
