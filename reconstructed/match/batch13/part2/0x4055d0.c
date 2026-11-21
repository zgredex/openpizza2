/* Game_ShutdownSubsystems (0x4055d0). */
struct Subsystem {
    virtual void Destroy(int flag);
};
struct SoundSystem {
    void Destruct();
};
extern Subsystem *DAT_0057c5e0;
extern Subsystem *DAT_0057c5ec;
extern Subsystem *DAT_0057c5c8;
extern SoundSystem *DAT_0057ba0c;
extern void Mem_Free(void *block);

void Game_ShutdownSubsystems(void)
{
    SoundSystem *sound;

    if (DAT_0057c5e0 != 0) {
        DAT_0057c5e0->Destroy(1);
        DAT_0057c5e0 = 0;
    }
    if (DAT_0057c5ec != 0) {
        DAT_0057c5ec->Destroy(1);
        DAT_0057c5ec = 0;
    }
    if (DAT_0057c5c8 != 0) {
        DAT_0057c5c8->Destroy(1);
        DAT_0057c5c8 = 0;
    }
    sound = DAT_0057ba0c;
    if (sound != 0) {
        sound->Destruct();
        Mem_Free(sound);
        DAT_0057ba0c = 0;
    }
}
