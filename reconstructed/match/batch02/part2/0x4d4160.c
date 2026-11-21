/* Person_SetPerformance - 0x4d4160, 15 bytes */
extern void __fastcall Game_ResetPlayerStatsByCity(void *this_);

void __fastcall Person_SetPerformance(void *this_, int unused, int value)
{
    *(int *)((char *)this_ + 0x3c) = value;
    Game_ResetPlayerStatsByCity(this_);
}
