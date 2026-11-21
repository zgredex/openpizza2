/* Person_SetHealth - 0x4d4150, 15 bytes */
extern void __fastcall Game_ResetPlayerStatsByCity(void *this_);

void __fastcall Person_SetHealth(void *this_, int unused, int value)
{
    *(int *)((char *)this_ + 0x10) = value;
    Game_ResetPlayerStatsByCity(this_);
}
