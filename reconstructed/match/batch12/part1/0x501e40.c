/* Game_GetActivityVolumeBand: classifies the current player's activity
   volume (0x501e40). */
extern void *DAT_0057c670;

struct Player {
    int CountActiveObjectsByType(int type);
};

int Game_GetActivityVolumeBand(void)
{
    struct Player *player = *(struct Player **)(
        (char *)DAT_0057c670 + 0x200 +
        *(int *)((char *)DAT_0057c670 + 0x2ec) * 4);
    int total = player->CountActiveObjectsByType(0x1f);

    total += player->CountActiveObjectsByType(0x1e);
    total += player->CountActiveObjectsByType(0x1d);

    if (total > 0x14) {
        return 3;
    }
    if (total > 0xa) {
        return 2;
    }
    return total > 4;
}
