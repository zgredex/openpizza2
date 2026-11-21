/* Game_RemoveRecordFromLocalMap: removes the record and clears its field (0x4d29d0). */
struct IDMap {
    int RemoveByKey(int key);
};

struct Set {
    void Field168(int value);
};

struct Game {
    char pad[0x78];
    int map[8];
    int RemoveRecordFromLocalMap(char *record);
};

int Game::RemoveRecordFromLocalMap(char *record)
{
    int result = ((IDMap *)map)->RemoveByKey(*(int *)(record + 0x164));

    ((Set *)record)->Field168(0);
    return result;
}
