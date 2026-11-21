/* Game_GetCurrentPlayerCompanyName: returns the current player's name id
   (0x482820). */
int __fastcall Game_GetCurrentPlayerCompanyName(int game)
{
    int index = *(int *)(game + 0x2f0);
    int player = *(int *)(game + index * 4 + 0x224);

    if (player == 0)
        return -1;
    return *(int *)(player + 8);
}
