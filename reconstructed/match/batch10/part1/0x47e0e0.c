/* Branch_EnqueueConstructionOrder: appends a construction order record and
   refreshes the object's upgrade state (0x47e0e0). */
struct List {
    void Add(void *item);
};

struct OrderRecord {
    char pad[0x18];
    int first;
    int second;
    int value;
};

struct Game {
    void CheckObjectUpgrade();
};

struct Branch {
    char pad[0x14e0];
    int *source;
    char pad2[0x16f8 - 0x14e4];
    char list[0x14];
    char pad3[0xc];
    int field1718;

    void EnqueueConstructionOrder(struct OrderRecord *record, int first,
                                  int second);
};

void Branch::EnqueueConstructionOrder(struct OrderRecord *record, int first,
                                      int second)
{
    field1718 = 0;
    ((struct List *)list)->Add(record);
    record->first = first;
    record->second = second;
    record->value = *(int *)((char *)source + 0x1c) * second + first;
    ((struct Game *)this)->CheckObjectUpgrade();
}
