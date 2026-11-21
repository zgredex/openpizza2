/* Game_RegisterObject: appends an object to the game's registration list
   (0x482810). */
struct List {
    void Add(void *object);
};

struct Game {
    void RegisterObject(void *object);
};

void Game::RegisterObject(void *object)
{
    ((List *)((char *)this + 0x58))->Add(object);
}
