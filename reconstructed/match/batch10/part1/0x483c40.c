/* Game_DestroyCachedScreens: destroys the four cached screen windows unless
   the requested screen is the current one (0x483c40). */
struct UI {
    void DestroyWindowAt(void *slot);
};

struct Game {
    char pad[0x25c];
    int screens[4];
    char pad2[0x290 - 0x26c];
    int currentScreen;

    void DestroyCachedScreens(int screen);
};

void Game::DestroyCachedScreens(int screen)
{
    if (screen == currentScreen) {
        return;
    }
    ((struct UI *)this)->DestroyWindowAt((char *)this + 0x25c);
    ((struct UI *)this)->DestroyWindowAt((char *)this + 0x260);
    ((struct UI *)this)->DestroyWindowAt((char *)this + 0x264);
    ((struct UI *)this)->DestroyWindowAt((char *)this + 0x268);
}
