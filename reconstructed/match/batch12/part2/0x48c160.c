/* Game_SelectPlayer: switches the active player (0x48c160). */
struct Player { char pad[0x4c]; int field4C; };
struct Game {
    char pad[0x288]; int requestedPlayer;
    char pad2[0x29c - 0x28c]; int savedView;
    char pad3[0x2bc - 0x2a0]; int previousView;
    char pad4[0x2ec - 0x2c0]; int currentPlayer;
    int playerField2F0;
    struct Player *GetPlayerBySlot(int slot);
    void SetViewMode(int mode, int flag);
    void SelectPlayer(int player);
};
void Game::SelectPlayer(int player)
{
    struct Player *entry;
    if (player == -1) player = requestedPlayer;
    entry = GetPlayerBySlot(player);
    if (entry != 0 && player != currentPlayer) {
        currentPlayer = player;
        playerField2F0 = entry->field4C;
        previousView = *(volatile int *)&savedView;
        savedView = 1;
        SetViewMode(1, 0);
    }
}
