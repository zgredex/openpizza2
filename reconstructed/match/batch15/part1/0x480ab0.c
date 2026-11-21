/* MapObject_RemoveAndRefund: removes a map object, cancels orders, and refunds
   its city share (0x480ab0). */
struct MapObject {
    char pad[0x20];
    int index;
};

struct Game {
    void DrawMapObjectSprite(void *map);
};

struct Object {
    void ClearState(void *record);
};

struct Map {
    void SetTileFieldWithDefault(void *record, int value, int param);
};

struct MapObjectVirtual {
    virtual void v0(int param);
};

struct Branch {
    char pad[0x14e0];
    void *map;

    void RemoveConstructionOrder(void *object);
    float ComputeCityPriceShare(void *object, float *value);
    void AddRecordValue(int type, float value, int flag);
    void RemoveAndRefund(MapObject *object);
};

void Branch::RemoveAndRefund(MapObject *object)
{
    int *record = (int *)(*(int *)((char *)map + 0x4c) + object->index * 0xc);

    if (record != 0 && record[2] != 0) {
        ((Game *)object)->DrawMapObjectSprite(map);
        ((Object *)map)->ClearState(record);
        ((Map *)map)->SetTileFieldWithDefault(record, -1, 1);
    }
    RemoveConstructionOrder(object);
    {
        float value;
        ComputeCityPriceShare(object, &value);
        AddRecordValue(0x15, value, -1);
    }
    if (object != 0) {
        ((MapObjectVirtual *)object)->v0(1);
    }
}
