/* Game_UpdateIDMapEntry: updates the ID map entry at 0x2c3f8 and returns its
   value (0x4eacd0).  Build: /O2 /TP. */
struct IDMap {
    void Update(int *value);
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x2c3f8];
    IDMap map;
    void UpdateIDMapEntry(int key);
};

void Game::UpdateIDMapEntry(int key)
{
    int value = key;

    map.Update(&value);
    map.Lookup(value, 0);
}
