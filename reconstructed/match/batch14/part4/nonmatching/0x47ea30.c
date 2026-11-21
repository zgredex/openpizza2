/* Branch_UpdateConstructionQueue (0x47ea30): validates the construction
   queue, clears the queue flag and refreshes the object list. */
struct Order {
    int count;
    char pad[0x1c - 4];
    int field1c;
};

struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct GameGlobal {
    char pad[0x9c];
    void *currentBranch;
    char pad2[0x264 - 0xa0];
    void *control;
};

extern GameGlobal *DAT_0057c670;

struct UI {
    void QueueControlCommand(int command, int id, int value);
};

struct Branch {
    char pad[0x1998];
    IDMap orderMap;
    char pad2[0x1a24 - 0x19b0];
    int overflowFlag;

    void CancelConstructionAt(Order *order);
    void UpdateConstructionQueue();
    void UpdateObjectList2();
};

void Branch::UpdateConstructionQueue()
{
    int total = 0;
    int i = orderMap.count - 1;

    if (-1 < i) {
        do {
            Order *order = (Order *)orderMap.Lookup(i, 0);

            if (order->count < 1)
                CancelConstructionAt(order);
            if (order->field1c != 0)
                total += order->count;
            i--;
        } while (-1 < i);
        if (49999 < total)
            overflowFlag = 0;
    }
    if (DAT_0057c670->currentBranch == this &&
        DAT_0057c670->control != 0)
        ((UI *)DAT_0057c670->control)->QueueControlCommand(
            0xfffe79f4, 0x23, 0);
    UpdateObjectList2();
}
