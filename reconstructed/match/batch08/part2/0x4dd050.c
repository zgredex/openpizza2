/* Game_RemoveRecordFromAllLocalMaps: removes a record from every local map
   (0x4dd050). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0xfac];
    int count;
    void RemoveRecordFromLocalMap(void *record);
    void RemoveRecordFromAllLocalMaps(void *record);
};

void Game::RemoveRecordFromAllLocalMaps(void *record)
{
    int count = *(int *)((char *)this + 0xfc0);
    int index = 0;

    while (index < count) {
        struct Game *map =
            (struct Game *)((struct IDMap *)((char *)this + 0xfac))
                ->Lookup(index, 0);

        map->RemoveRecordFromLocalMap(record);
        index++;
    }
}
