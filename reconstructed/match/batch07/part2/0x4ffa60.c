/* Game_GetDateStage (0x4ffa60, 48 bytes).  Build: /O2 /TP.
   Returns stage 1 once the current date reaches the threshold, else stage 4. */
extern int DAT_0057c670;

struct Game {
    int GetDateField0C(void);
    int GetDateStage(int index);
};

int Game::GetDateStage(int index)
{
    int date = ((Game *)DAT_0057c670)->GetDateField0C();

    return ((date >= *(int *)((char *)this + index * 0x168 + 0x54)) - 1U & 3) + 1;
}
