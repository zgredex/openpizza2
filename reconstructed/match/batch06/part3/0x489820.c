/* Game_GetPlayerSubmapValue: looks up a player by slot and returns an entry
   from the player's submap ID map at 0x148 (0x489820).  Build: /O2 /TP. */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Player {
    char pad[0x148];
    IDMap submap;
};

struct Game {
    char pad[0x200];
    Player *GetPlayerBySlot(int slot);
    int GetPlayerSubmapValue(int slot, int key);
};

int Game::GetPlayerSubmapValue(int slot, int key)
{
    Player *player = GetPlayerBySlot(slot);

    if (player != 0)
        return player->submap.Lookup(key, 0);
    return 0;
}
