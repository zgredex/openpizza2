/* Game_GetPlayerMapValue: looks up a player by slot and returns an entry from
   the player's map ID map at 0x180 (0x489850).  Build: /O2 /TP. */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Player {
    char pad[0x180];
    IDMap map;
};

struct Game {
    char pad[0x200];
    Player *GetPlayerBySlot(int slot);
    int GetPlayerMapValue(int slot, int key);
};

int Game::GetPlayerMapValue(int slot, int key)
{
    Player *player = GetPlayerBySlot(slot);

    if (player != 0)
        return player->map.Lookup(key, 0);
    return 0;
}
