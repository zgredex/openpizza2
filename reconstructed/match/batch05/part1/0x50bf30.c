/* Game_GetPlayerEconomyModifier: looks up the active player and queries the
   economy modifier (0x50bf30). */
struct Player;

struct Game {
    char pad[0x110];
    int activePlayer;
    Player *GetPlayerBySlot(int slot);
    void GetPlayerEconomyModifier();
};

struct Economy {
    void GetModifier(int a, int b);
};

extern Game *DAT_0057c670;

void Game::GetPlayerEconomyModifier()
{
    int slot = activePlayer;
    Player *player = DAT_0057c670->GetPlayerBySlot(slot);
    ((Economy *)player)->GetModifier(0x1e, 0);
}
