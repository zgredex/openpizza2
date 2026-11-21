/* Game_SetStageIfHigher: raises the game stage, reporting whether the new
   stage was accepted (0x4810a0). */
struct Game {
    char pad[0x2c];
    int stage;
    void SetChildField94(int value);
    int SetStageIfHigher(int value);
};

int Game::SetStageIfHigher(int value)
{
    if (value == 0) {
        stage = 0;
        return 1;
    }
    if (stage != value) {
        if (stage > value)
            return 0;
        stage = value;
        SetChildField94(1);
    }
    return 1;
}
