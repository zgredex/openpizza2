extern char *DAT_0057c670;

int __fastcall Game_GetPlayerCity(char *this_)
{
    return *(int *)(DAT_0057c670 + 0x224 + *(int *)(this_ + 0x4c) * 4);
}
