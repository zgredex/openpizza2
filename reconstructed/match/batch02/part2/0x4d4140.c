/* Person_SetSpeed - 0x4d4140, 15 bytes */
extern void __fastcall Game_ResetPlayerStatsByCity(void *this_);

void __fastcall Person_SetSpeed(void *this_, int unused, int value)
{
    *(int *)((char *)this_ + 0x8) = value;
    Game_ResetPlayerStatsByCity(this_);
}
