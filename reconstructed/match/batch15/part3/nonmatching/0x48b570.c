/* Non-matching candidate.
   First difference: offset 0x5c, 6 bytes differ.
   original selects the slot in eax (mov ecx,eax; inc eax) while candidate moves it to ecx before the branch.
   Kept for evidence; not part of the strict match set. */
extern int DAT_0057b9f0;
extern int DAT_0057b9f4;
extern int DAT_0057b9f8;
extern int DAT_0057b9fc;

struct Game {
    char pad0[0x290];
    int state;
    char pad1[0x1508 - 0x294];
    int suspended;
    void AutoSaveTick();
    void SuspendSimulation();
    void ResumeSimulation();
    void SaveGame_Write(char *name, int slot);
};

void Game::AutoSaveTick()
{
    int didSuspend = 0;
    if (suspended == 0 && state != 7 && DAT_0057b9f0 != -1) {
        DAT_0057b9f4 = DAT_0057b9f4 + 1;
        if (DAT_0057b9f4 >= DAT_0057b9f0) {
            DAT_0057b9f4 = 0;
            if (suspended == 0) {
                SuspendSimulation();
                didSuspend = 1;
            }
            int slot = DAT_0057b9fc;
            if (DAT_0057b9fc >= DAT_0057b9f8)
                slot = 0;
            DAT_0057b9fc++;
            if (DAT_0057b9fc >= DAT_0057b9f8)
                DAT_0057b9fc = 0;
            SaveGame_Write(0, slot);
            if (didSuspend)
                ResumeSimulation();
        }
    }
}
