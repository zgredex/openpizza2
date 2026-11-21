/* Branch_SettleDueConstructionOrders: pays every due construction order for
   the given day (0x47eed0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct OrderRecord {
    char pad[4];
    int dueDay;
    char pad2[0x14];
    int pending;
};

struct Branch {
    char pad[0x1998];
    char map[0x14];
    int count;

    void SettleDueConstructionOrders(int day);
    void PayConstructionOrder(int index);
};

void Branch::SettleDueConstructionOrders(int day)
{
    int i;

    for (i = 0; i < count; i++) {
        struct OrderRecord *order =
            (struct OrderRecord *)((struct IDMap *)map)->Lookup(i, 0);

        if (order->pending != 0 && order->dueDay <= day * 10) {
            PayConstructionOrder(i);
        }
    }
}
