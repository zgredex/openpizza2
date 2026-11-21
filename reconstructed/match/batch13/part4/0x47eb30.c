/* Branch_PayConstructionOrder (0x47eb30). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    struct Game *GetPlayerBySlot(int slot);
    void CanAfford(int currency, float amount, unsigned char flag, int limit);
};
struct Market {
    float ComputeWeightedAveragePrice(void *order, void *player);
};
struct Branch {
    char pad00[0x30];
    int slot30;
    char pad34[0x1964];
    struct IDMap map1998;

    void PayConstructionOrder(int orderId);
    void UpdateConstructionQueue();
};
extern "C" char *DAT_0057c670;
extern "C" float DAT_0055c2e4;

void Branch::PayConstructionOrder(int orderId)
{
    int *order = (int *)map1998.Lookup(orderId, 0);

    if (order != 0 && order[7] != 0) {
        void *player = ((struct Game *)DAT_0057c670)->GetPlayerBySlot(slot30);
        float price = ((struct Market *)DAT_0057c670)
                          ->ComputeWeightedAveragePrice(order, player);
        if (price > 0.0f) {
            ((struct Game *)this)->CanAfford(0xc, price, 0, -1);
        }
        UpdateConstructionQueue();
    }
}
