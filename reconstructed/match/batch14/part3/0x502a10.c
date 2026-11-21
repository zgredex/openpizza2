/* Game_AllBuildingCategoryRatingsAbove (0x502a10): checks whether every
   category rating of every active building is above the limit. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Building {
    char pad[0x148];
    IDMap ratingMap;
    int GetCustomerGroupRating(int group, int usePrice);
};

struct GameGlobal {
    char pad[0x200];
    Building *buildings[1];
    char pad2[0x2ec - 0x204];
    int currentBuilding;
};

extern GameGlobal *DAT_0057c670;

struct Game {
    char AllBuildingCategoryRatingsAbove(int limit);
};

char Game::AllBuildingCategoryRatingsAbove(int limit)
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
                if (record->GetCustomerGroupRating(j, 1) < limit)
                    return 0;
            }
        }
    }
    return 1;
}
