/* Game_SetMapRenderParams: stores the four render parameters and marks the
   map objects dirty (0x4808c0). */
struct Game {
    char pad[0x1a2c];
    int paramA;
    int paramD;
    int paramB;
    int paramC;
    void MarkAllObjectsDirty(int mask);
    void SetMapRenderParams(int a, int b, int c, int d);
};

void Game::SetMapRenderParams(int a, int b, int c, int d)
{
    paramA = a;
    paramD = d;
    paramB = b;
    paramC = c;
    MarkAllObjectsDirty(4);
}
