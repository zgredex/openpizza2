/* Rating_StoreDailyResults: stores the daily rating results for the current
   day (0x4d4480). */
struct World {
    char pad[0x94];
    char *dayRecord;
};

extern int DAT_0057c670;

struct Rating {
    char pad[0x44];
    int composite[100];
    int adjusted[100];
    int adjustA[100];
    int source[100];
    int adjustB[100];

    void StoreDailyResults();
    int GetComposite();
    int ClampAdjusted();
    int AdjustA();
    int AdjustB();
};

void Rating::StoreDailyResults()
{
    int index =
        *(unsigned short *)(((struct World *)DAT_0057c670)->dayRecord + 0xa) - 1;

    *(int *)((char *)this + 0x44 + index * 4) = GetComposite();
    *(int *)((char *)this + 0x1d4 + index * 4) = ClampAdjusted();
    *(int *)((char *)this + 0x364 + index * 4) = AdjustA();
    *(int *)((char *)this + 0x4f4 + index * 4) = *(int *)((char *)this + 0xc);
    *(int *)((char *)this + 0x684 + index * 4) = AdjustB();
}
