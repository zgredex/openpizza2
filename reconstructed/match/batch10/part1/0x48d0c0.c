/* Game_RemoveScreenTimers: removes the two screen timers and clears their
   ids (0x48d0c0). */
struct Timer {
    void RemoveById(int id);
};

struct Game {
    char pad[0x2d1c];
    char timer[0x2d8c - 0x2d1c];
    int firstId;
    char pad2[0x2da4 - 0x2d90];
    int secondId;

    void RemoveScreenTimers();
};

void Game::RemoveScreenTimers()
{
    if (firstId != -1) {
        ((struct Timer *)timer)->RemoveById(firstId);
    }
    firstId = -1;
    if (secondId != -1) {
        ((struct Timer *)timer)->RemoveById(secondId);
    }
    secondId = -1;
}
