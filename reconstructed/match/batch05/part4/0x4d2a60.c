/* Game_MapRecordToGlobal: maps a local record id into the global map (0x4d2a60). */
struct IDMap {
    void *Lookup(int key, int *out);
};

extern int DAT_0057c670;

struct Game {
    char pad[0x78];
    void MapRecordToGlobal(int record);
};

void Game::MapRecordToGlobal(int record)
{
    void *local = ((IDMap *)((char *)this + 0x78))->Lookup(record, 0);

    ((IDMap *)((char *)DAT_0057c670 + 0x3c))->Lookup((int)local, 0);
}
