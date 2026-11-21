/* GamePlan_GetCompanyCategoryMetric: dispatches a company metric query
   (0x50fab0). */
struct Branch {
    int GetPriceRating(int arg);
    int GetMenuRating(int arg);
    int ComputeBuildingRating(int arg);
    int GetAverage8(int arg);
};

extern "C" int __fastcall GamePlan_GetCompanyCategoryMetric(
    void *unused1, void *unused2, struct Branch *branch, int arg, int category)
{
    switch (category) {
    case 1:
        return branch->GetPriceRating(arg);
    case 2:
        return branch->GetMenuRating(arg);
    case 4:
        return branch->ComputeBuildingRating(arg);
    case 8:
        return branch->GetAverage8(arg);
    }
    return 0;
}
