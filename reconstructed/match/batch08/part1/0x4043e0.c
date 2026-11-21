/* GameMain: runs the screen loop and tears down the sound thread and its
   allocation (0x4043e0). */
void ResetScreenRegistry(void);
void GameLoop_DispatchScreens(void);
void ShutdownScreens(void);
void __fastcall Sound_StopThread(void *thread);
void Mem_Free(void *block);
extern volatile int DAT_0057c480;
extern void *DAT_0057c5b0;
void __cdecl GameMain(void)
{
    void *thread;
    ResetScreenRegistry();
    GameLoop_DispatchScreens();
    ShutdownScreens();
    DAT_0057c480 = 1;
    thread = DAT_0057c5b0;
    if (thread != 0) {
        Sound_StopThread(thread);
        Mem_Free(thread);
    }
}
