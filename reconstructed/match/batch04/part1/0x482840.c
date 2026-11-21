/* Game_GetPlayerField8: returns field 8 of a player slot (0x482840). */
struct Player {
    char pad[8];
    int field8;
};

struct Game {
    char pad[0x224];
    Player *players[6];
    int GetPlayerField8(int index);
};

int Game::GetPlayerField8(int index)
{
    Player *player = players[index];

    if (player == 0)
        return -1;
    return player->field8;
}
