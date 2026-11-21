/* Game_IsInputIndexUsed (0x502810): checks whether any active building uses
   an input index greater than the supplied limit. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Building {
    char pad[0x110];
    IDMap inputMap;
    int MapInputIndex(int index);
};

struct GameGlobal {
    char pad[0x200];
    Building *buildings[1];
    char pad2[0x2ec - 0x204];
    int currentBuilding;
};

extern GameGlobal *DAT_0057c670;

struct Game {
    char IsInputIndexUsed(int limit);
};

char Game::IsInputIndexUsed(int limit)
{
    Building *building =
        DAT_0057c670->buildings[DAT_0057c670->currentBuilding];
    int count = building->inputMap.count;
    int i = 0;

    if (0 < count) {
        IDMap *map = (IDMap *)((char *)building + 0x110);

        for (; i < count; i++) {
            Building *record = (Building *)map->Lookup(i, 0);
            int j;

            for (j = 0; j <= 7; j++) {
                if (record->MapInputIndex(j) > limit)
                    return 1;
            }
        }
    }
    return 0;
}
