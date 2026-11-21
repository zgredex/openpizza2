/* Stats_ComputeCategory7: maps the sum of four statistics counters to a 0..3
   level (0x502180). */
extern "C" int DAT_0057c670;

int Stats_ComputeCategory7(void)
{
    int player = *(int *)(DAT_0057c670 + 0x224 +
                          *(int *)(DAT_0057c670 + 0x2f0) * 4);
    int total = *(int *)(player + 0x64) + *(int *)(player + 0x60) +
                *(int *)(player + 0x4c) + *(int *)(player + 0x48);

    if (4 < total)
        return 3;
    if (2 < total)
        return 2;
    return 0 < total;
}
