/* Game_SetChildField94: stores a value in the child record at offset 0x94 (0x4808a0). */
struct Child {
    char pad[0x94];
    int field94;
};

struct Game {
    char pad[0x16f0];
    Child *child;
    void SetChildField94(int value);
};

void Game::SetChildField94(int value)
{
    child->field94 = value;
}
