/* Game_GetCostForType: returns the construction cost for a type
   (0x4d4330). */
struct Game {
    char pad[4];
    int size4;
    int size8;

    int GetCostForType(int type);
};

int Game::GetCostForType(int type)
{
    switch (type) {
    case 0:
        return (size4 * size4) / 10;
    case 3:
        return (size8 * size8) / 10;
    case 1:
        return 0x32;
    case 2:
        return 500;
    }
    return 0;
}
