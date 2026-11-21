/* Game_MapInputIndex - 0x5104d0, 23 bytes */
struct Index
{
    void Map8To5(int index);
};

struct Game
{
    void MapInputIndex(int index);
};

void Game::MapInputIndex(int index)
{
    if (index == 8)
        index = 5;
    ((Index *)this)->Map8To5(index);
}
