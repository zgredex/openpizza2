/* Person_SetSkill - 0x4d4130, 15 bytes */
extern void __fastcall Game_ResetPlayerStatsByCity(void *this_);

void __fastcall Person_SetSkill(void *this_, int unused, int value)
{
    *(int *)((char *)this_ + 0x4) = value;
    Game_ResetPlayerStatsByCity(this_);
}
