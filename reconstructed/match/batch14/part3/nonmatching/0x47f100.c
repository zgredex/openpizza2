/* Game_CheckObjectUpgrade (0x47f100): decides whether the selected object can
   be upgraded based on aged adjacent buildings and player count. */
struct MapObject;

struct Record {
    char pad[0xfa8];
    MapObject *mapObject;
};

struct IDMap {
    Record *Lookup(int key, int *result);
};

struct GameObject {
    char pad[0x28];
    int key;

    void SetObjectFlags(MapObject *object, int flag);
    void ClearObjectFlags(MapObject *object, int flag);
};

struct Game {
    char pad[0x28];
    unsigned int flags;
    char pad2[0x16f0 - 0x2c];
    GameObject *object;

    int CountAgedAdjacentBuildings();
    int CountPlayersByByte(int value);
    int CheckObjectUpgrade();
};

extern char *DAT_0057c670;

int Game::CheckObjectUpgrade()
{
    GameObject *object = this->object;
    Record *record =
        ((IDMap *)(DAT_0057c670 + 4))->Lookup(object->key, 0);
    MapObject *mapObject = record->mapObject;
    int aged = CountAgedAdjacentBuildings();
    int players = CountPlayersByByte(5);

    if (aged < 4 || players <= 0) {
        object->SetObjectFlags(mapObject, 0x10);
        flags |= 4;
        return 1;
    }
    object->ClearObjectFlags(mapObject, 0x10);
    flags &= 0xfb;
    return 0;
}
