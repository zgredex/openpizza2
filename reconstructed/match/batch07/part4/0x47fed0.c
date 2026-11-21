/* Game_CountFreeResidentialBuildings: sums the free residential building
   counts of all three residential types (0x47fed0). */
struct Game {
    int CountFreeBuildingsByType(int type);
};

struct Object {
    char pad[0x16f0];
    Game *map;
};

int __fastcall Game_CountFreeResidentialBuildings(Object *object)
{
    Game *map = object->map;
    int total;

    if (map == 0)
        return 0;
    total = map->CountFreeBuildingsByType(0x1c);
    total = total + map->CountFreeBuildingsByType(0x1b);
    return map->CountFreeBuildingsByType(0x1a) + total;
}
