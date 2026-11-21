/* Game_GetPlayerStaffBand: maps the sum of four staff counters to a 0..3
   band (0x501df0). */
extern "C" int DAT_0057c670;

int Game_GetPlayerStaffBand(void)
{
    int player = *(int *)(DAT_0057c670 + 0x224 +
                          *(int *)(DAT_0057c670 + 0x2f0) * 4);
    int total = *(int *)(player + 0x68) + *(int *)(player + 0x58) +
                *(int *)(player + 0x50) + *(int *)(player + 0x40);

    if (4 < total)
        return 3;
    if (2 < total)
        return 2;
    return 0 < total;
}
