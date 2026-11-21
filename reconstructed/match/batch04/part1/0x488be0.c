/* Game_GetPlayerBySlot: bounds-checks a slot and returns its player
   (0x488be0). */
struct Player;

struct Game {
    char pad[0x200];
    Player *players[6];
    Player *GetPlayerBySlot(int slot);
};

Player *Game::GetPlayerBySlot(int slot)
{
    if (slot < 0 || slot >= 6)
        return 0;
    return players[slot];
}
