/* Person_SetMotivation - 0x4d4120, 15 bytes */
extern void __fastcall Game_ResetPlayerStatsByCity(void *this_);

void __fastcall Person_SetMotivation(void *this_, int unused, int value)
{
    *(int *)((char *)this_ + 0xc) = value;
    Game_ResetPlayerStatsByCity(this_);
}
