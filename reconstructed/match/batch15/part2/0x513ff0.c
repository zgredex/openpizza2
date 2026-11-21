/* Storage_SettlePendingOrders: averages pending order prices and charges the
   player (0x513ff0). */
extern int *DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct List {
    void Node_Reset();
};

struct Game {
    Game *GetPlayerBySlot(int slot);
    void CanAffordWithCurrency(int type, float value, int flag, int param);
};

struct Market {
    float ComputeWeightedAveragePrice(void *entry, void *player);
};

struct Storage {
    char pad[0x24];
    int playerSlot;
    char pad1[0x30];
    int count;

    void SettlePendingOrders();
};

extern "C" void Mem_Free(void *pointer);

void Storage::SettlePendingOrders()
{
    float total = 0.0f;
    int count = *(int *)((char *)this + 0x58);
    Game *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(playerSlot);
    int i = 0;

    while (i < count) {
        int *entry = (int *)((struct IDMap *)((char *)this + 0x44))
                         ->Lookup(i, 0);
        float price = ((Market *)DAT_0057c670)
                          ->ComputeWeightedAveragePrice(entry, player);

        total = (float)(price + total);
        Mem_Free(entry);
        i++;
    }
    ((struct List *)((char *)this + 0x44))->Node_Reset();
    player->CanAffordWithCurrency(0xc, total, 0, -1);
}
