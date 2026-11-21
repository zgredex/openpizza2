/* Stats_GetLevelFromTenCounters: derive a level from ten byte counters. */
extern int DAT_0057c670;

int Stats_GetLevelFromTenCounters(void)
{
    int sum = 0;
    int i;
    char *player = (char *)*(int *)(DAT_0057c670 + 0x200 +
                                    *(int *)(DAT_0057c670 + 0x2ec) * 4);

    for (i = 0; i < 10; i++)
        sum += *(unsigned char *)(player + 0xe4 + i);
    if (sum > 5)
        return 3;
    if (sum > 3)
        return 2;
    return sum > 0;
}
