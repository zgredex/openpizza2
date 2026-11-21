/* Game_SetDifficulty (0x50fb40, 46 bytes).  Build: /O2 /TP.
   Stores the difficulty and selects the starting capital for it. */
struct Game {
    void SetDifficulty(int difficulty);
};

void Game::SetDifficulty(int difficulty)
{
    *(int *)((char *)this + 8) = difficulty;
    switch (difficulty) {
    case 1:
        *(int *)((char *)this + 0x20) = 10000;
        break;
    case 2:
        *(int *)((char *)this + 0x20) = 5000;
        break;
    case 3:
        *(int *)((char *)this + 0x20) = 0xdac;
        break;
    }
}
