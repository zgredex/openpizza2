extern char *DAT_0057c670;
extern "C" void *__cdecl memset(void *dest, int value, unsigned int count);

/* Company_RecordDailyStatistics: appends a zeroed or fully computed statistics
   block for the current day (0x4dec10). */
struct Stats_Report {
    void FillCompanyOverview(int *out);
};



struct Stats {
    void FillCompanyCategoryLeaders(int *out);
    void ComputePlayerAggregateStats(int *out);
    void ComputeCompanyRatingStats(int *out);
};

struct Game {
    void ComputeCompanyRankStats(int *out);
    void ComputeCompanyOverviewStats(int *out);
    void FillCompanyRankingStats(int *out);
};



struct List {
    void Add(void *item);
};

struct Company {
    char pad[0x4c];
    int field4c;
    char pad2[0x19c - 0x50];
    void FillStatisticsBlock(int *out);
    void ComputeTotals(int *out);
    void RecordDailyStatistics();
};

void Company::RecordDailyStatistics()
{
    char *block = new char[0x1a0];

    if (*(int *)(*(int *)(DAT_0057c670 + 0x90) + field4c * 0x168 + 0x12c) != 0x18) {
        ((Stats_Report *)this)->FillCompanyOverview((int *)&block);
        FillStatisticsBlock((int *)&block);
        ((Stats *)this)->FillCompanyCategoryLeaders((int *)&block);
        ((Stats *)this)->ComputePlayerAggregateStats((int *)&block);
        ((Game *)this)->ComputeCompanyRankStats((int *)&block);
        ((Game *)this)->ComputeCompanyOverviewStats((int *)&block);
        ((Game *)this)->FillCompanyRankingStats((int *)&block);
        ((Stats *)this)->ComputeCompanyRatingStats((int *)&block);
        ComputeTotals((int *)&block);
        ((List *)((char *)this + 0x19c))->Add(block);
        return;
    }
    memset(block, 0, 0x1a0);
    ((List *)((char *)this + 0x19c))->Add(block);
}
