/* CompanyProfile_UpdateRatingBars: fills the eight company-profile rating
   bars (0x4b8830). */
extern void *DAT_0057c670;
extern int DAT_005826d8;

struct Stats {
    int GetAverage8(int index);
};

extern "C" void __cdecl Rating_UpdateBarByKey(void *gadget, int id, int index,
                                              int value, int extra);

void __cdecl CompanyProfile_UpdateRatingBars(void *gadget)
{
    Stats *stats = *(Stats **)((char *)DAT_0057c670 + 0x9c);
    int i;

    for (i = 0; i < 8; i++)
        Rating_UpdateBarByKey(gadget, 0x58e, i, stats->GetAverage8(i),
                              DAT_005826d8);
}
