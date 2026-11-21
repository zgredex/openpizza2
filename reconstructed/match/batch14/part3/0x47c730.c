/* Game_ClearPendingMapObjects (0x47c730): releases every queued map object
   and clears the pending counter. */
struct PendingObject {
    virtual void Release(int flag);
    char pad[0x1c];
    int index;
};

struct TileEntry {
    char pad[8];
    char *cell;
};

struct TileMap {
    char pad[0x4c];
    TileEntry *entries;

    void SetTileFieldWithDefault(TileEntry *entry, int value, int flags);
};

struct IDMap {
    void *Lookup(int key, int *result);
    void RemoveByKey(void *object);
};

struct Game {
    char pad[0x14e0];
    TileMap *map;
    char pad2[0x1718 - 0x14e4];
    int pendingCount;
    char pad3[0x19e0 - 0x171c];
    IDMap pending;

    int Get_Field19F4();
    void ClearPendingMapObjects();
};

void Game::ClearPendingMapObjects()
{
    if (0 < Get_Field19F4()) {
        do {
            PendingObject *object =
                (PendingObject *)pending.Lookup(0, 0);
            int index = object->index;
            TileEntry *entry = &map->entries[index];
            char *cell = entry->cell;

            *(int *)(cell + 0x1c) = -1;
            map->SetTileFieldWithDefault(entry, -1, 1);
            pending.RemoveByKey(object);
            if (object != 0)
                object->Release(1);
        } while (0 < Get_Field19F4());
        pendingCount = 0;
    }
}
