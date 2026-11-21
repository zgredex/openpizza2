/* Storage_ReceivePendingOrder (0x5142c0). */

struct IDMap {
    void *Lookup(int index, int *out);
    void RemoveRecursive(int value);
};

struct Storage {
    char pad0[0x44];
    struct IDMap map;
    char pad1[0x58 - 0x45];
    int orderState;
    char pad2[0x68 - 0x5c];
    int counters[1];
    int ReceivePendingOrder(int item);
};

void __fastcall Storage_OrderDelivery(Storage *self);

struct ItemArray {
    int FindPair(int item);
};

int Storage::ReceivePendingOrder(int item)
{
    int result;
    int index;

    if (orderState == 0) {
        Storage_OrderDelivery(this);
        return 0;
    }
    result = (int)((struct IDMap *)((char *)this + 0x44))->Lookup(0, 0);
    ((struct IDMap *)((char *)this + 0x44))->RemoveRecursive(0);
    index = ((struct ItemArray *)this)->FindPair(item);
    if (index != -1) {
        *(int *)((char *)this + index * 0xc + 0x68) =
            *(int *)((char *)this + index * 0xc + 0x68) + 1;
    }
    Storage_OrderDelivery(this);
    return result;
}
