/* Game_HandleQueryEndSession: save the running game or switch to the
   end-session view (0x4a21a0). */
extern "C" int DAT_00568d00;
extern "C" int DAT_0057c670;
extern "C" char DAT_0057cfd0;

struct Game {
    void SetViewMode(int mode, int flag);
};

struct SaveGame {
    void Write(char *data, int size);
};

struct GameState {
    char pad0[0x2b4];
    volatile int mode;
    char pad1[0x2d4 - 0x2b8];
    int previousMode;
};

extern "C" void Game_HandleQueryEndSession(void)
{
    struct GameState *game;

    if (DAT_00568d00 != -1) {
        ((struct SaveGame *)DAT_0057c670)->Write(&DAT_0057cfd0, DAT_00568d00);
        return;
    }
    ((struct Game *)DAT_0057c670)->SetViewMode(7, 0);
    game = (struct GameState *)DAT_0057c670;
    game->previousMode = game->mode;
    game->mode = 2;
}
