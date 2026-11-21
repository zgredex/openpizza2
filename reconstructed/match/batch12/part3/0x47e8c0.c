/* Branch_CancelConstructionAt (0x47e8c0). */

struct Grid {
    void *GetCell(int x, int y);
    void Map_SetTileFieldWithDefault(void *cell, int value, int flag);
};

struct Branch {
    void CancelConstructionAt(void *record);
    void *FindRecordByPair(int x, int y);
    void RemoveConstructionOrder(void *record);
};

void Branch::CancelConstructionAt(void *record)
{
    void *cell;
    void *found;

    *(int *)((char *)record + 0x1c) = 0;
    cell = (*(struct Grid **)((char *)this + 0x14e0))->GetCell(
        *(int *)((char *)record + 0x14), *(int *)((char *)record + 0x18));
    (*(struct Grid **)((char *)this + 0x14e0))->Map_SetTileFieldWithDefault(
        cell, -1, 1);
    *(int *)(*(int *)((char *)this + 0x14e0) + 0xf4) = 1;
    found = FindRecordByPair(*(int *)((char *)record + 0x14),
                             *(int *)((char *)record + 0x18));
    if (found != 0) {
        RemoveConstructionOrder(found);
    }
}
