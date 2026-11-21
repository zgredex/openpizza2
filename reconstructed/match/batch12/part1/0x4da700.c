/* Stats_GetPlayerSharePercent: returns a player's share of the rating total
   (0x4da700). */
extern int DAT_0057c670;

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct Stats {
    char pad[0xd40];
    int ratings[6];

    int GetPlayerSharePercent(int player);
};

int Stats::GetPlayerSharePercent(int player)
{
    int total = 0;
    int i;

    for (i = 0; i < 6; i++) {
        if (((struct Game *)DAT_0057c670)->GetPlayerBySlot(i) != 0) {
            total += 0x65 - ratings[i];
        }
    }
    return ((0x65 - ratings[player]) * 100) / total;
}
