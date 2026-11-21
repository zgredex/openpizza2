/* Storage_OrderDelivery (0x514510). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    int CountFilteredObjects(int type, int subtype, int owner, int limit);
    void *FindRecordByField24(int value);
};
struct Array {
    int GetStride60(int index);
};
struct City {
    void SpawnDeliveryVehicles(void *storage, void *record);
};
struct Storage {
    char pad00[0x28];
    int field28;
    char pad2c[0x4];
    int field30;
    int field34;

    int GetFillPercent();
    void OrderDelivery();
};
extern "C" char *DAT_0057c670;

void Storage::OrderDelivery()
{
    int value = GetFillPercent();

    if (value <= 0x21) {
        value = ((struct Game *)DAT_0057c670)->CountFilteredObjects(
            0x18, 0xc, field34, -1);
        if (value <= 0 && *(int *)(field34 + 0x38) == 0 && field30 != -1) {
            int key = field28;
            char *record = (char *)((struct IDMap *)(DAT_0057c670 + 4))
                               ->Lookup(key, 0);
            int item = ((struct Array *)record)->GetStride60(field30);
            void *found = ((struct Game *)record)
                              ->FindRecordByField24(*(int *)(item + 0x10));
            ((struct City *)record)->SpawnDeliveryVehicles(this, found);
        }
    }
}
