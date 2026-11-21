/* Game_RemoveTrackedRecord: removes the record's key from the tracked map (0x47ec00). */
struct IDMap {
    int RemoveByKey(int key);
};

struct Game {
    void *FindRecordByField10(int key);
    char pad[0x19c4];
    int map[8];
    void RemoveTrackedRecord(char *record);
};

void Game::RemoveTrackedRecord(char *record)
{
    int key = *(int *)(record + 0x164);
    void *found = FindRecordByField10(key);

    if (found != 0) {
        ((IDMap *)map)->RemoveByKey((int)found);
    }
}
