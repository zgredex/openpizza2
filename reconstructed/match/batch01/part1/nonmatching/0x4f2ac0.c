/* Grid_CollectFootprintCellsAtCell (0x4f2ac0). */
struct Map {
    int FindIndex(int key, int unused);
};

struct GameRoot {
    char pad[0x74];
    Map map;
};

extern GameRoot *DAT_0057c670;

struct ConstructionOrder {
    char pad[0x14];
    int field18;
    int field1c;
    int extra;
    ConstructionOrder(int index);
    virtual ~ConstructionOrder();
};

struct Grid {
    void *CollectFootprintCellsAtCell(int key, int field18, int field1c, int param);
    void *CollectFootprintCells(ConstructionOrder *order, int param);
};

void *Grid::CollectFootprintCellsAtCell(int key, int field18, int field1c, int param)
{
    ConstructionOrder *order =
        new ConstructionOrder(DAT_0057c670->map.FindIndex(key, 0));
    order->field18 = field18;
    order->field1c = field1c;
    void *result = CollectFootprintCells(order, param);
    if (order != 0)
        delete order;
    return result;
}
