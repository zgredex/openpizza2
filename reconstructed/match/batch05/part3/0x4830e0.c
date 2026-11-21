/* Game_DestroyEventWindow: removes the active event window (0x4830e0). */
struct Window {
    void DestroyChild(void *child);
};

extern Window *DAT_0057c5e0;

struct Game {
    char pad[0x26c];
    void *eventWindow;
    void DestroyEventWindow();
};

void Game::DestroyEventWindow()
{
    void *window = eventWindow;

    if (window != 0) {
        eventWindow = 0;
        DAT_0057c5e0->DestroyChild(window);
    }
}
