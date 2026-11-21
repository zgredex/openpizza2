/* Game_LookupObjectByIndex: looks up an object in the map at offset 0xfc8 (0x4d6ad0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0xfc8];
    IDMap objects;
    void LookupObjectByIndex(int index);
};

void Game::LookupObjectByIndex(int index)
{
    objects.Lookup(index, 0);
}
