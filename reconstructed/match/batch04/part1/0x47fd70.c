/* Game_IsCurrentPlayer: compares the current player's company with a player
   (0x47fd70). */
int __fastcall Game_GetCurrentPlayerCompanyName(int game);

unsigned char __fastcall Game_IsCurrentPlayer(int player)
{
    return Game_GetCurrentPlayerCompanyName(*(int *)0x57c670)
           == *(int *)(player + 0x30);
}
