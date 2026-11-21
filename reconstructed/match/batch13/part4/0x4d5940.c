/* Map_BuildOccupiedCellList (0x4d5940). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Array {
    int GetRecord28(int flag, int index);
};
struct List {
    void Add(void *node);
    void Node_Reset();
};
struct Node {
    virtual void Destroy(int flag);
};
struct City {
    int *CollectBuildingsByType(int type, int unused1, int unused2);
};
struct Map {
    char pad00[0xfa8];
    int fieldFa8;

    void BuildOccupiedCellList();
};

void Map::BuildOccupiedCellList()
{
    int *list = ((struct City *)this)->CollectBuildingsByType(0x20, 0, 0);
    int index = 0;

    if (0 < list[5]) {
        do {
            int record = (int)((struct IDMap *)list)->Lookup(index, 0);
            int item = ((struct Array *)*(int *)((char *)this + 0xfa8))
                           ->GetRecord28(1, *(int *)(record + 0x54));
            if (item != 0 && *(char *)(item + 6) == 2) {
                ((struct List *)(*(int *)((char *)this + 0xfa8) + 0x11c))
                    ->Add((void *)item);
            }
            index = index + 1;
        } while (index < list[5]);
    }
    ((struct List *)list)->Node_Reset();
    if (list != 0) {
        ((struct Node *)list)->Destroy(1);
    }
}
