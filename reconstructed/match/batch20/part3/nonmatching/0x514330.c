extern int DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Array {
    void *GetStride60(int index);
};

struct List {
    void Add(void *item);
};

struct UI {
    void QueueControlCommand(int message, int wparam, int lparam);
};

struct GamePlayer;

struct Game {
    char pad[0x264];
    UI *control;
    GamePlayer *GetPlayerBySlot(int slot);
};

struct BuildingValue {
    float Compute(void *object, void *array);
};


struct Storage {
    char pad[0x24];
    int slot;
    int field28;
    int field2c;
    int field30;
    char pad2[0x10];
    List list;
    char pad3[0x10];
    int used;
    int GetCapacity();
    void DistributeCostToShops(float cost, char flag);
    void ProduceBatch();
};

void *operator new(unsigned int size);

void Storage::ProduceBatch()
{
    int capacity = GetCapacity();
    GamePlayer *object = (GamePlayer *)((IDMap *)(DAT_0057c670 + 4))->Lookup(field28, 0);
    int index = field30;
    void *array = ((Array *)object)->GetStride60(index);
    if (array == 0)
        return;
    int slotValue = slot;
    GamePlayer *player = ((Game *)DAT_0057c670)->GetPlayerBySlot(slotValue);
    int count = capacity - used;
    int limit = capacity / (field2c + 1);
    if (count > limit)
        count = limit;
    int *cell = (int *)array + slot + 5;
    *cell = *cell + count;
    while (count > 0) {
        int *record = (int *)operator new(0x20);
        int i;
        for (i = 0; i < 8; i++)
            record[i] = 0;
        *record = 200000;
        *(float *)(record + 4) = ((BuildingValue *)player)->Compute(object, array);
        record[1] = ((int *)array)[0];
        record[3] = ((int *)array)[1];
        list.Add(record);
        count--;
    }
    DistributeCostToShops(*(float *)((char *)object + 0x94) * 100.0f, 0);
    if (((Game *)DAT_0057c670)->control != 0)
        ((Game *)DAT_0057c670)->control->QueueControlCommand(-0x1861c, 0x23, 0);
}
