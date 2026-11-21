/* Game_IncrementVisitCounter: bumps the total and one slot counter
   (0x47fd50). */
struct Game {
    char pad[0x16c0];
    unsigned short total;
    unsigned short slot[8];
    void IncrementVisitCounter(int index);
};

void Game::IncrementVisitCounter(int index)
{
    total++;
    if (index >= 0 && index < 8)
        slot[index]++;
}
