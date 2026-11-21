/* Game_DestroyRootWindow: destroys the root window slot at offset 0x264
   (0x482880). */
struct Game {
    char pad[0x264];
    int *rootWindow;
    void DestroyWindowAt(void **slot);
};

void __fastcall Game_DestroyRootWindow(Game *this_)
{
    this_->DestroyWindowAt((void **)&this_->rootWindow);
}
