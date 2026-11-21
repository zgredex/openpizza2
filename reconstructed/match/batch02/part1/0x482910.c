/* Game_GetActiveScreenOrFallback: returns the active screen, falling back to
   the root window (0x482910). */
int __fastcall Game_GetActiveScreenOrFallback(char *this_)
{
    int screen = *(int *)(this_ + 0x270);

    if (screen == 0)
        screen = *(int *)(this_ + 0x264);
    return screen;
}
