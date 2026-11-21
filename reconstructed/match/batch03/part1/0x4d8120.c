/* Game_GetOwnedObjectByIndex: looks up an owned object by index (0x4d8120). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0xfc8];
    IDMap objects;
    void GetOwnedObjectByIndex(int index, int *out);
};

void Game::GetOwnedObjectByIndex(int index, int *out)
{
    objects.Lookup(index, out);
}
