/* Game_Delete: destroying destructor, frees the object when flag bit 0 is set (0x4e9d70). */
extern void Mem_Free(void *block);

struct Game {
    void Destroy();
    Game *Delete(unsigned char flags);
};

Game *Game::Delete(unsigned char flags)
{
    Destroy();
    if (flags & 1) {
        Mem_Free(this);
    }
    return this;
}
