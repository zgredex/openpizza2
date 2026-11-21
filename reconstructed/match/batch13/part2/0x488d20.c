/* Game_ResumeSimulation (0x488d20). */
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
struct Thread {
    char pad0[0x10];
    unsigned long id;       /* 0x10 */

    void Init();
};
struct ThreadSync {
    void Signal();
};
struct Linked {
    void HideAll();
};
extern Linked *DAT_0057c5cc;
struct Game {
    char pad0[0x90];
    Thread *thread;         /* 0x90 */
    ThreadSync *sync;       /* 0x94 */
    char pad1[0x1508 - 0x98];
    int running;            /* 0x1508 */
    int field150c;          /* 0x150c */

    void ResumeSimulation();
    void UpdateDateLabels(void *arg);
};

void Game::ResumeSimulation()
{
    if (running != 0) {
        unsigned long id = thread->id;

        if (GetCurrentThreadId() != id && thread != 0)
            thread->Init();
        if (sync != 0)
            sync->Signal();
        DAT_0057c5cc->HideAll();
        running = 0;
        field150c = 1;
        UpdateDateLabels(0);
    }
}
