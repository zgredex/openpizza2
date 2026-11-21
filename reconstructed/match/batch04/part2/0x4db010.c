/* City_SetPlayerAdvertisingBudget: stores a budget and rebuilds billboards (0x4db010). */
struct City {
    void UpdateSecurityPatrolFrames(int frame);
    void SetPlayerAdvertisingBudget(int player, int budget);
};

void City::SetPlayerAdvertisingBudget(int player, int budget)
{
    *(int *)((char *)this + player * 4 + 0xcb0) = budget;
    UpdateSecurityPatrolFrames(0);
}
