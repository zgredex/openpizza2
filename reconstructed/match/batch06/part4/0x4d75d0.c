/* Game_UpdateAndFetchMapEntryFAC: updates the map entry at 0xfac and returns
   its value (0x4d75d0).  Build: /O2 /TP. */
struct IDMap {
    void Update(int *value);
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0xfac];
    IDMap map;
    void UpdateAndFetchMapEntryFAC(int key);
};

void Game::UpdateAndFetchMapEntryFAC(int key)
{
    int value = key;

    map.Update(&value);
    map.Lookup(value, 0);
}
