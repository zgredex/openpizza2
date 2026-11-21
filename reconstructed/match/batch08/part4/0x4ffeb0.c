/* Game_AdjustPlayerObjectPercent: adjusts the percentage of a player's
   object (0x4ffeb0). */
extern void *DAT_0057c670;

struct Player;

struct Game {
    Player *GetPlayerBySlot(int slot);
    void AdjustPlayerObjectPercent(int slot, int percent);
};

struct Object {
    void AdjustShortPercent(int index, int percent);
};

void Game::AdjustPlayerObjectPercent(int slot, int percent)
{
    Player *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(slot);

    if (player != 0) {
        int index = *(int *)((char *)player + 0x4c);
        if (*(int *)((char *)this + index * 0x168 + 0x114) != 0)
            ((Object *)this)->AdjustShortPercent(index, percent);
    }
}
