/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
struct IDMap {
    int Lookup(int key, int *out);
};
struct Map {
    void *GetCell(int x, int y);
    void SetTileFieldWithDefault(void *cell, int value, int flag);
};
struct Game {
    void FindRecordByTripleKey(int a, int b, int c, int *out);
};
struct ConstructionOrder {
    unsigned char data[0x24];
    ConstructionOrder(int a, int b);
};
struct List {
    void Add(void *object);
};
struct Branch {
    void StartConstructionOnPlot(int key);
    void UpdateConstructionQueue(void);
    void UpdateObjectList2(void);
};
extern Game *g_game;

void Branch::StartConstructionOnPlot(int key)
{
    int iVar1;
    void *cell;
    ConstructionOrder *order;

    iVar1 = ((IDMap *)((char *)this + 0x1998))->Lookup(key, 0);
    if (iVar1 != 0) {
        *(int *)(iVar1 + 0x1c) = 1;
        cell = ((Map *)*(void **)((char *)this + 0x14e0))->GetCell(
            *(int *)(iVar1 + 0x14), *(int *)(iVar1 + 0x18));
        ((Map *)*(void **)((char *)this + 0x14e0))->SetTileFieldWithDefault(
            cell, 0x65, 1);
        g_game->FindRecordByTripleKey(7, 4, 3, &key);
        order = new ConstructionOrder(key, 0);
        *(int *)((char *)order + 0x18) = *(int *)(iVar1 + 0x14);
        *(int *)((char *)order + 0x1c) = *(int *)(iVar1 + 0x18);
        *(int *)((char *)order + 0x20) = **(int **)((char *)cell + 8);
        ((List *)((char *)this + 0x16f8))->Add(order);
        *(int *)(*(int *)((char *)this + 0x14e0) + 0xf4) = 1;
        UpdateConstructionQueue();
        UpdateObjectList2();
    }
}
