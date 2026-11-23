extern char *DAT_0057c670;
extern "C" void *__cdecl memset(void *dest, int value, unsigned int count);

/* Recipe_RecomputeAllStats: recomputes placement and all derived recipe
   statistics (0x512620). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Screen {
    void AccumulateColorHistogram(void *record, int flags);
    void ScoreColorHistogram();
};

struct AI {
    void CheckPriceCompetitiveness();
};

struct PlayerStats {
    void Reset();
};

struct Recipe {
    void RecomputeLayoutQuality();
    void RecomputeAllStats(int param);
};

struct Stats {
    void ComputeWeightedAverages();
};

struct Rating {
    void StoreClampedScores();
};

struct Game {
    void ComputeMarketFactors();
    void ComputeFoodStats();
    void ComputeCompanyRatings(int param);
};

void Recipe::RecomputeAllStats(int param)
{
    int i;

    memset((char *)this + 0x1e0, 0, 0x60);
    i = 0;
    if (0 < *(int *)((char *)this + 0x5c)) {
        do {
            void *record = ((IDMap *)((char *)this + 0x48))->Lookup(i, 0);
            int table = *(int *)(DAT_0057c670 + 0xa8 + (unsigned)*(unsigned char *)((char *)record + 4) * 4);
            int offset = (unsigned)*(unsigned char *)((char *)record + 0x10) +
                         (unsigned)*(unsigned char *)((char *)record + 6) * 8;
            short height = *(short *)(table + 0x48 + offset * 2);

            *(int *)((char *)record + 0x14) =
                ((int)*(short *)(table + 8 + offset * 2) >> 1) + *(int *)((char *)record + 8);
            *(int *)((char *)record + 0x18) = ((int)height >> 1) + *(int *)((char *)record + 0xc);
            ((Screen *)this)->AccumulateColorHistogram(record,
                *(int *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18));
            i = i + 1;
        } while (i < *(int *)((char *)this + 0x5c));
    }
    ((AI *)this)->CheckPriceCompetitiveness();
    ((PlayerStats *)this)->Reset();
    ((Screen *)this)->ScoreColorHistogram();
    RecomputeLayoutQuality();
    ((Stats *)this)->ComputeWeightedAverages();
    ((Rating *)this)->StoreClampedScores();
    ((Game *)this)->ComputeMarketFactors();
    ((Game *)this)->ComputeFoodStats();
    ((Game *)this)->ComputeCompanyRatings(param);
}
