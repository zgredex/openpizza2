/* Storage_ChargePurchaseCost - 0x5140e0, 22 bytes */
struct Storage
{
    char pad[0x3c];
    char initialized;
    int cost;

    void DistributeCostToShops(float cost, char flag);
    void ChargePurchaseCost();
};

void Storage::ChargePurchaseCost()
{
    if (*(char *)((char *)this + 0x3c) == 0)
        DistributeCostToShops((float)*(int *)((char *)this + 0x40), 1);
}
