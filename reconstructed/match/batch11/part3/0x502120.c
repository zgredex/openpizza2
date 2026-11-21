/* Game_GetPlayerSatisfactionBand: maps the player's average satisfaction to
   four bands (0x502120). */
struct World {
    char pad[0x200];
    void *players[59];
    int playerIndex;
};

extern int DAT_0057c670;

int Game_GetPlayerSatisfactionBand(void)
{
    struct World *world = (struct World *)DAT_0057c670;
    int *player = (int *)world->players[world->playerIndex];
    int average = (player[0x3e] + player[0x3d] + player[0x3c]) / 3;

    if (average > 90) {
        return 0;
    }
    if (average > 70) {
        return 1;
    }
    return (average <= 50) + 2;
}
