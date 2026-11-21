/* Game_GetPlayerCount: counts the six occupied player slots (0x482720). */
int __fastcall Game_GetPlayerCount(int game)
{
    int count = 0;
    int *player = (int *)(game + 0x200);
    int remaining = 6;

    do {
        if (*player != 0)
            count++;
        player++;
    } while (--remaining != 0);
    return count;
}
