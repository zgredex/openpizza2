/* Game_GetDateFields: reads the day and month fields out of the game clock
   and scales the month by five (0x48b3c0).  Build: /O2 /TP. */
struct GameClock {
    char pad[6];
    unsigned char month;
    unsigned char day;
};

struct Game {
    char pad[0x94];
    GameClock *clock;
    void GetDateFields(unsigned *day, int *month);
};

void Game::GetDateFields(unsigned *day, int *month)
{
    *day = clock->day;
    *month = clock->month * 5;
}
