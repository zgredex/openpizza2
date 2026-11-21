/* Game_GetPlayerWealthBand: classifies the current player's wealth into four
   bands (0x501ea0). */
struct World {
    char pad[0x200];
    void *players[59];
    int playerIndex;
};

extern int DAT_0057c670;

int Game_GetPlayerWealthBand(void)
{
    struct World *world = (struct World *)DAT_0057c670;
    double wealth = *(double *)((char *)world->players[world->playerIndex] + 0x108);

    if (wealth > 1000000.0) {
        return 3;
    }
    if (wealth > 500000.0) {
        return 2;
    }
    if (wealth > 100000.0) {
        return 1;
    }
    return 0;
}
