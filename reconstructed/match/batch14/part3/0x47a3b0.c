/* Branch_GetCustomerGroupRating (0x47a3b0): averages the building, menu and
   optional price ratings and clamps the result to 0..100. */
struct Branch {
    int Stats_GetAverage8(int group);
    int Branch_ComputeBuildingRating(int group);
    int Branch_GetMenuRating(int group);
    int Branch_GetPriceComparisonRating(int group, int *flag);
    int Rating_ComputeBuildingScore(int group);
    int GetCustomerGroupRating(int group, int usePrice);
};

int Branch::GetCustomerGroupRating(int group, int usePrice)
{
    int flag;
    int divisor = 3;
    int sum = Stats_GetAverage8(group);
    int rating;

    sum += Branch_ComputeBuildingRating(group);
    sum += Branch_GetMenuRating(group);
    if (usePrice != 0) {
        rating = Branch_GetPriceComparisonRating(group, &flag);
        if (flag != 0) {
            sum += rating;
            divisor = 4;
        }
    }
    rating = Rating_ComputeBuildingScore(group) + sum / divisor;
    if (rating < 0)
        return 0;
    if (rating > 100)
        return 100;
    return rating;
}
