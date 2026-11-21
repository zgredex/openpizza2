/* GameClock_Destroy: stops the clock worker and restores the vtable
   (0x4dd670). */
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned int milliseconds);

struct GameClock {
    void *vtable;
    char pad[0x1c];
    int stopping;
    int workerDone;
    void Destroy();
};

void GameClock::Destroy()
{
    int done = *(int *)((char *)this + 0x24);
    int retries;

    vtable = (void *)0x55c564;
    *(int *)((char *)this + 0x20) = 1;
    for (retries = 400; done == 0 && retries > 0; retries--) {
        Sleep(10);
        done = *(int *)((char *)this + 0x24);
    }
}
