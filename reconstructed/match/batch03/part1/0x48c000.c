/* Game_HasQueuedEventType: finds an entry by its field 0x34 key (0x48c000). */
struct IDMap {
    void *Lookup(int key, int *out);
    int FindByField34(int key);
};

struct Game {
    char pad[0x304];
    IDMap records;
    void HasQueuedEventType(int type);
};

void Game::HasQueuedEventType(int type)
{
    records.FindByField34(type);
}
