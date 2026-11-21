/* Map_ClearObjectFlags: clears selected flags on a map object's render record
   (0x4d2d80). */
extern int *DAT_0057c670;

struct CS {
    void Enter();
    void Leave();
};

struct MapObject {
    void Render(void *record, int param);
};

struct Map {
    char pad[0x24];
    int index;

    void ClearObjectFlags(MapObject *object, unsigned int flags);
};

void Map::ClearObjectFlags(MapObject *object, unsigned int flags)
{
    unsigned int *record;

    (*(struct CS **)((char *)DAT_0057c670 + 0x240))->Enter();
    record = (unsigned int *)(*(int *)((char *)object + 0x4c) +
                              *(int *)((char *)this + 0x24) * 0xc);
    if (record != 0) {
        unsigned int value = *(unsigned int *)(record[2] + 0x1c);

        if (value == 0xffffffff) {
            (*(struct CS **)((char *)DAT_0057c670 + 0x240))->Leave();
            return;
        }
        *(unsigned int *)(record[2] + 0x1c) = ~flags & value;
        if (*(int *)(record[2] + 0x1c) == 0) {
            *(int *)(record[2] + 0x1c) = 0xffffffff;
        }
        object->Render(record, 1);
    }
    (*(struct CS **)((char *)DAT_0057c670 + 0x240))->Leave();
}
