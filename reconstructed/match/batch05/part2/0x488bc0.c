/* Game_FindPlayerSlot: linear search of the six player slots (0x488bc0). */
struct Game {
    char pad[0x200];
    int player[6];
    int FindPlayerSlot(int value);
};

int Game::FindPlayerSlot(int value)
{
    int index = 0;
    int *slot = player;
    while (index < 6) {
        if (*slot == value)
            return index;
        index++;
        slot++;
    }
    return -1;
}
