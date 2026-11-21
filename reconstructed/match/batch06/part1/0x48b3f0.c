/* Game_GetYearAndWeekday: reports the current year and weekday (0x48b3f0). */
struct Game {
    char pad[0x94];
    char *date;
    void GetYearAndWeekday(unsigned int *year, unsigned int *weekday);
};

void Game::GetYearAndWeekday(unsigned int *year, unsigned int *weekday)
{
    *year = *(unsigned char *)(date + 8);
    *weekday = *(unsigned short *)(date + 4);
}
