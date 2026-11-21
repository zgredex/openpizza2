/* Game_RegisterWorldObject (0x4eac80, 48 bytes).  Build: /O2 /TP.
   Appends the object to the world list, or inserts it into the keyed map
   when a key is given. */
struct List {
    void Add(int value);
};

struct IDMap {
    void InsertGrow(int value, int key);
};

struct Game {
    void RegisterWorldObject(int object, int key);
};

void Game::RegisterWorldObject(int object, int key)
{
    if (key == -1)
        ((List *)((char *)this + 0x2c3f8))->Add(object);
    else
        ((IDMap *)((char *)this + 0x2c3f8))->InsertGrow(object, key);
}
