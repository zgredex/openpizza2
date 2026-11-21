/* Timer_Destroy - 0x403a60, 88 bytes */
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void *handle);

struct NamedLockable
{
    void Destroy();
};

struct Timer
{
    void Destroy();
    void *vtable;
    int state;
    int stopped;
    char pad[4];
    NamedLockable lock;
};

extern char DAT_0055c308[];

void Timer::Destroy()
{
    unsigned long deadline;
    int stopped;

    *(void **)this = DAT_0055c308;
    state = 1;
    deadline = timeGetTime() + 5000;
    stopped = this->stopped;
    while (stopped == 0 && timeGetTime() < deadline)
    {
        Sleep(2);
        stopped = this->stopped;
    }
    CloseHandle(*(void **)((char *)this + 0x6c));
    lock.Destroy();
}
