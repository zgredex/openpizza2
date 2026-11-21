/* Stats_HasCurrentSales: returns 6 when the filtered sales sum is positive
   (0x480010). */
extern void *DAT_0057c670;

struct Stats {
    float SumFilteredFloats(int mode, int low, int high);
};

int __fastcall Stats_HasCurrentSales(Stats *stats)
{
    int *values = *(int **)((char *)DAT_0057c670 + 0x94);
    unsigned short high = *(unsigned short *)((char *)values + 10);
    unsigned short low = *(unsigned short *)((char *)values + 4);
    float sum = stats->SumFilteredFloats(0x19, low, high);

    if (sum > *(float *)0x55c2e4)
        return 6;
    return 0;
}
