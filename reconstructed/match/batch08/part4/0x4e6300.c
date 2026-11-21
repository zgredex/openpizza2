/* Game_SetModeByte: stores the mode byte and updates the control panel
   (0x4e6300). */
extern void *DAT_0057c670;

struct UI {
    void QueueControlCommand(int command, int a, int b);
};

struct Game {
    void SetModeByte(unsigned int mode);
};

void Game::SetModeByte(unsigned int mode)
{
    *(unsigned int *)((char *)this + 0xc) = mode & 0xff;
    if (*(void **)((char *)DAT_0057c670 + 0x220) == this &&
        *(int *)((char *)DAT_0057c670 + 0x2d8) == 0xb &&
        *(void **)((char *)DAT_0057c670 + 0x264) != 0) {
        ((UI *)*(void **)((char *)DAT_0057c670 + 0x264))
            ->QueueControlCommand((int)0xfffe79e5, 0x23, 0);
    }
}
