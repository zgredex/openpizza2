struct MapRecord {
    char pad[0xfa8];
    void *object;
};

struct IDMap {
    int unused;
    MapRecord *Lookup(int index, int *out);
};

struct Map {
    char pad0[4];
    IDMap map;
    char pad1[0x24];
    int field2c;
    int field30;
    int field34;
    int field38;
    char pad2[0xf4 - 0x3c];
    int dirty;
    char pad3[0x2f4 - 0xf8];
    int currentIndex;
    char pad4[0x10168 - 0x2f8];
    int bound68;
    int bound6c;
    int bound70;
    int bound74;
    void SetScrollPosition(int x, int y);
    void DrawMinimap();
    void ScrollToClamped(Map *object, int x, int y);
};

extern int DAT_00571950;
extern int DAT_00571954;

void Map::ScrollToClamped(Map *object, int x, int y)
{
    int minX = *(int *)((char *)object + 0x1016c) + *(int *)((char *)object + 0x2c);
    int minY = *(int *)((char *)object + 0x30) - *(int *)((char *)object + 0x10174);
    int maxX = (*(int *)((char *)object + 0x34) - *(int *)((char *)object + 0x10168)) +
               DAT_00571950;
    int maxY = *(int *)((char *)object + 0x10170) + *(int *)((char *)object + 0x38) +
               DAT_00571954;
    if (x < minX)
        x = minX;
    if (y < minY)
        y = minY;
    if (x + DAT_00571950 >= maxX)
        x = maxX - DAT_00571950;
    if (DAT_00571954 + y >= maxY)
        y = maxY - DAT_00571954;
    object->SetScrollPosition(x, y);
    *(int *)((char *)object + 0xf4) = 1;
    MapRecord *record = ((IDMap *)((char *)this + 4))->Lookup(
        *(int *)((char *)this + 0x2f4), 0);
    if (object == *(void **)((char *)record + 0xfa8))
        DrawMinimap();
}
