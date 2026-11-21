/* Map_SetObjectMode: stores an object's mode byte in its tile definition and
   re-renders the object (0x4d2fa0).  Build: /O2 /TP. */
struct MapEntry {
    int field0;
    int field4;
    char *definition;
};

struct MapObject {
    char pad[0x4c];
    MapEntry *entries;
    void RenderObject(MapEntry *entry, int mode);
};

struct Map {
    char pad[0x24];
    int index;
    void RenderObject(MapEntry *entry, int mode);
    void SetObjectMode(MapObject *object, unsigned char mode);
};

void Map::SetObjectMode(MapObject *object, unsigned char mode)
{
    MapEntry *entry = &object->entries[index];

    if (entry != 0) {
        *(unsigned char *)(entry->definition + 0x2c) = mode;
        ((Map *)object)->RenderObject(entry, 1);
    }
}
