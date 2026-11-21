/* Game_GetLowestValuePlayer: index of the active player with the lowest
   value at offset 0xdac (0x4d80e0). */
struct Game {
    int GetPlayerBySlot(int slot);
};

extern struct Game *DAT_0057c670;

int __fastcall Game_GetLowestValuePlayer(int game)
{
    int best = -1;
    unsigned int lowest = 999999999;
    int slot = 0;
    unsigned int *value = (unsigned int *)(game + 0xdac);

    do {
        int player = DAT_0057c670->GetPlayerBySlot(slot);

        if (player != 0 && *value < lowest) {
            lowest = *value;
            best = slot;
        }
        slot++;
        value++;
    } while (slot < 6);
    return best;
}
