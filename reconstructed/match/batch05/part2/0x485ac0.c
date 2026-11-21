/* Game_GetSpeedSetting: returns 2 only for a fast clock and a high speed
   index (0x485ac0). */
struct Game {
    char pad[0x2e1c];
    int clock;
    int speedIndex;
    int GetSpeedSetting();
};

int Game::GetSpeedSetting()
{
    if (clock > 0x40 && speedIndex > 7)
        return 2;
    return 1;
}
