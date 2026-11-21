/* Game_AnyBuildingReachesCellList (0x489e20): tests whether any player
   building blocks the candidate cell list. */
struct Person {
    int BlocksFootprintCells(void *cells);
    int BlocksFootprintPath(void *cells);
};

struct IDMap {
    char pad[0x14];
    int count;
};

struct MapOwner {
    char pad[0x78];
    IDMap map;

    Person *MapRecordToGlobal(int index);
};

struct Player {
    char pad[0x16f0];
    MapOwner *owner;
};

struct Game {
    char pad[0x9c];
    Player *player;

    int AnyBuildingReachesCellList(void *cells);
};

int Game::AnyBuildingReachesCellList(void *cells)
{
    MapOwner *owner;
    int i;

    if (player == 0)
        return 1;
    owner = player->owner;
    if (owner == 0)
        return 1;
    i = 0;
    if (0 < owner->map.count) {
        do {
            Person *person = owner->MapRecordToGlobal(i);

            if (person != 0) {
                if (person->BlocksFootprintCells(cells))
                    return 1;
                if (person->BlocksFootprintPath(cells))
                    return 1;
            }
            i++;
        } while (i < owner->map.count);
    }
    return 0;
}
