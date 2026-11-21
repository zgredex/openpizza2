/* Stats_ComputeRatingShare: returns a rating share
   (0x4da700). */
extern int DAT_0057c670;

struct Game {
    void *GetPlayerBySlot(int slot);
};

struct Stats {
    char pad[0xc98];
    int ratings[6];

    int ComputeRatingShare(int player);
};

int Stats::ComputeRatingShare(int player)
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
