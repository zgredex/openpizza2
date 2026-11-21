/* Game_SetLockedField2FC: stores the field under the game lock (0x4858a0). */
struct CS {
    void Enter();
    void Leave();
};

struct Game {
    char pad0[0x240];
    CS *lock;
    char pad1[0x2fc - 0x244];
    int field2FC;
    void SetLockedField2FC(int value);
};

void Game::SetLockedField2FC(int value)
{
    lock->Enter();
    field2FC = value;
    lock->Leave();
}
