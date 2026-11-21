/* Company_OptimizeMenuPricing (0x4fe570): optimizes each plan of a company
   and reallocates menu sales. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Company {
    char pad[0x12c];
    IDMap planMap;

    int GetPlayerFieldC20();
};

struct Game {
    void AI_BuyUndervaluedBuildings(int index);
    void GamePlan_Optimize(int index, void *plan);
    void Company_AllocateMenuSales(int index);
    int OptimizeMenuPricing(int index);
};

int Game::OptimizeMenuPricing(int index)
{
    AI_BuyUndervaluedBuildings(index);
    Company *company =
        *(Company **)((char *)this + index * 0x168 + 0x70);
    int i;

    if (company->GetPlayerFieldC20() < 1)
        return 1;
    i = 0;
    if (0 < company->planMap.count) {
        do {
            void *plan = company->planMap.Lookup(i, 0);

            GamePlan_Optimize(index, plan);
            i++;
        } while (i < company->planMap.count);
    }
    Company_AllocateMenuSales(index);
    return 1;
}
