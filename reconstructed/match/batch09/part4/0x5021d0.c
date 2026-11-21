/* Stats_GetLevelFromFourCounters: maps the sum of four player counters to a
   0..3 level (0x5021d0). */
extern "C" int DAT_0057c670;

int Stats_GetLevelFromFourCounters(void)
{
    int player = *(int *)(DAT_0057c670 + 0x224 +
                          *(int *)(DAT_0057c670 + 0x2f0) * 4);
    int total = *(int *)(player + 0x5c) + *(int *)(player + 0x54) +
                *(int *)(player + 0x44) + *(int *)(player + 0x3c);

    if (4 < total)
        return 3;
    if (2 < total)
        return 2;
    return 0 < total;
}
