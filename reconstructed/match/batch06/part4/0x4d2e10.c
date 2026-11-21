/* TileDef_TestFlag: tests a flag bit on the tile definition referenced by a
   map entry (0x4d2e10).  Build: /O2 /TP. */
struct TileDef {
    char pad[0x1c];
    unsigned int flags;
};

struct TileEntry {
    int field0;
    int field4;
    TileDef *definition;
};

struct TileObject {
    char pad[0x4c];
    TileEntry *entries;
};

struct Map {
    char pad[0x24];
    int index;
    int TestFlag(TileObject *object, unsigned int flag);
};

int Map::TestFlag(TileObject *object, unsigned int flag)
{
    TileEntry *entry = &object->entries[index];

    if (entry != 0)
        return (entry->definition->flags & flag) != 0;
    return 0;
}
