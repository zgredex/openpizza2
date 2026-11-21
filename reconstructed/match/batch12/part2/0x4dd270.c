/* GameClock_Construct: initialises the game clock and starts its thread
   (0x4dd270). */
extern char DAT_0055c564;
extern char DAT_004dd2d0;
extern int DAT_0057dfbc;
extern "C" unsigned long CRT_BeginThread(void (__cdecl *start)(void *),
                                         unsigned stack, void *argument);

struct GameClock {
    char pad[0x14];
    int field14;
    char pad2[8];
    int field20;
    int field24;
    int field1C;

    void Reset();
    void Load(void *data);

    GameClock *Construct(void *data);
};

GameClock *GameClock::Construct(void *data)
{
    *(void **)this = &DAT_0055c564;
    DAT_0057dfbc = 2000;
    if (data != 0) {
        Load(data);
    } else {
        Reset();
    }
    *(int *)((char *)this + 0x1c) = 0;
    *(int *)((char *)this + 0x24) = 0;
    *(int *)((char *)this + 0x20) = 0;
    *(int *)((char *)this + 0x14) = 0xc35;
    CRT_BeginThread((void (__cdecl *)(void *))&DAT_004dd2d0, 0, this);
    return this;
}
