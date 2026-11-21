/* Game_RemoveLocalEntryRecursive - 0x4d2a90, 16 bytes */
struct IDMap
{
    int RemoveRecursive(int key);
};

struct Game
{
    char padding[0x78];
    void RemoveLocalEntryRecursive(int key);
};

void Game::RemoveLocalEntryRecursive(int key)
{
    ((IDMap *)((char *)this + 0x78))->RemoveRecursive(key);
}
