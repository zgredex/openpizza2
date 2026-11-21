/* Game_RemoveIDMapEntry - 0x4eacb0, 19 bytes */
struct Map
{
    void LookupLinear(int key);
};

struct Game
{
    char pad[0x2c3f8];
    Map map;

    void RemoveIDMapEntry(int key);
};

void Game::RemoveIDMapEntry(int key)
{
    map.LookupLinear(key);
}
