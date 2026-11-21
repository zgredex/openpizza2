/* MapObject_RemoveFromMap: detaches an object from the map grid and releases
   its footprint list (0x481050). */
struct FootprintCells {
    virtual void Destroy(int flag);
};

struct MapGrid {
    void *CollectFootprintCells(void *object, int flag);
    void DrawObjectList(int first, void *cells);
    void MarkPlayerFootprints(void *object, int flag);
};

struct MapObject {
    char pad[0x14e0];
    MapGrid *map;

    void RemoveFromMap(void *object);
};

struct ObjectHelper {
    void RemoveAndRefund(void *object);
};

void MapObject::RemoveFromMap(void *object)
{
    void *cells = map->CollectFootprintCells(object, 0);

    map->DrawObjectList(0, cells);
    ((ObjectHelper *)this)->RemoveAndRefund(object);
    if (cells != 0)
        ((FootprintCells *)cells)->Destroy(1);
    map->MarkPlayerFootprints(this, 1);
}
