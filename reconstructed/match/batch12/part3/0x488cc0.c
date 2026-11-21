/* Game_SuspendSimulation (0x488cc0). */

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);

struct Thread {
    void IsOwner();
};

void __fastcall Thread_IsOwner(void *thread);
void __fastcall ThreadSync_Clear(void *sync);

struct Game {
    void SuspendSimulation();
    void UpdateDateLabels(void *arg);
};

void Game::SuspendSimulation()
{
    unsigned long owner;

    *(int *)((char *)this + 0x1508) = 1;
    owner = *(unsigned long *)(*(int *)((char *)this + 0x90) + 0x10);
    if (GetCurrentThreadId() != owner) {
        *(volatile int *)((char *)this + 0x2d14) = 1;
        if (*(struct Thread **)((char *)this + 0x90) != 0) {
            Thread_IsOwner(*(void **)((char *)this + 0x90));
        }
        *(volatile int *)((char *)this + 0x2d14) = 0;
    }
    if (*(int *)((char *)this + 0x94) != 0) {
        ThreadSync_Clear(*(void **)((char *)this + 0x94));
    }
    UpdateDateLabels(0);
}
