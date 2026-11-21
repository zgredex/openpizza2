/* Game_GetGlobalTableValue: indexes a global integer table (0x482710). */
extern int DAT_00567d4c[];

int __stdcall Game_GetGlobalTableValue(int index)
{
    return DAT_00567d4c[index];
}
