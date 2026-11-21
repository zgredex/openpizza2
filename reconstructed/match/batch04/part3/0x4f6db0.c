/* Game_CompanyManager_Delete: destroying destructor (0x4f6db0). */
extern void Mem_Free(void *block);

struct Game_CompanyManager {
    void Destructor();
    Game_CompanyManager *Delete(unsigned char flags);
};

Game_CompanyManager *Game_CompanyManager::Delete(unsigned char flags)
{
    Destructor();
    if (flags & 1) {
        Mem_Free(this);
    }
    return this;
}
