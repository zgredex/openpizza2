/* Game_GetTimeSegment: divides the clock byte by three (0x488d90). */
int __fastcall Game_GetTimeSegment(int game)
{
    return *(unsigned char *)(*(int *)(game + 0x94) + 7) / 3;
}
