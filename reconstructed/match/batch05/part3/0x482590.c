/* Game_AddScreenTimer: registers the periodic screen timer (0x482590). */
struct Timer {
    int AddEntry(void *callback, int interval, int flags);
};

struct Game {
    char pad[0x2d1c];
    char timerArea[0x70];
    void AddScreenTimer();
};

void Game::AddScreenTimer()
{
    Timer *timer = (Timer *)((char *)this + 0x2d1c);

    *(int *)((char *)this + 0x2d8c) = timer->AddEntry((void *)0x481190, 200, 0);
}
