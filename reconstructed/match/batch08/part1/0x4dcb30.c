/* Game_IncrementPlayerCounterC20: increments a per-player counter and copies
   the current period into the player record (0x4dcb30). */
struct Player {
    char pad[0x60];
    unsigned int period;
};

struct Game {
    char pad[0xc20];
    int counters[1];
    struct Player *GetPlayerBySlot(int slot);
    void IncrementPlayerCounterC20(int slot);
};

extern int DAT_0057c670;

void Game::IncrementPlayerCounterC20(int slot)
{
    unsigned short period;

    counters[slot]++;
    period = *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 0xa);
    ((struct Game *)DAT_0057c670)->GetPlayerBySlot(slot)->period = period;
}
