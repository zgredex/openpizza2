/* Game_AnyBuildingRatingAbove (0x502890): checks whether any active building's rating is
   above the supplied limit. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Building {
    char pad[0x148];
    IDMap ratingMap;
    int ComputeBuildingRating(int index);
};

struct GameGlobal {
    char pad[0x200];
    Building *buildings[1];
    char pad2[0x2ec - 0x204];
    int currentBuilding;
};

extern GameGlobal *DAT_0057c670;

struct Game {
    char AnyBuildingRatingAbove(int limit);
};

char Game::AnyBuildingRatingAbove(int limit)
{
    Building *building =
        DAT_0057c670->buildings[DAT_0057c670->currentBuilding];
    int count = building->ratingMap.count;
    int i = 0;

    if (0 < count) {
        IDMap *map = (IDMap *)((char *)building + 0x148);

        for (; i < count; i++) {
            Building *record = (Building *)map->Lookup(i, 0);
            int j;

            for (j = 0; j <= 7; j++) {
                if (record->ComputeBuildingRating(j) > limit)
                    return 1;
            }
        }
    }
    return 0;
}
