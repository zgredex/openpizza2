/* Game_GetLevelReward: reward table lookup for a level reward kind
   (0x4e3730). */
struct Game {
    int GetPlayerFieldC20(void);
    int GetLevelReward(int kind);
};

int Game::GetLevelReward(int kind)
{
    int level = GetPlayerFieldC20();

    if (level < 3)
        return 0;
    switch (kind) {
    case 0x1d:
        return *(int *)(0x56d104 + level * 4);
    case 0x1e:
        return *(int *)(0x56d114 + level * 4);
    case 0x1f:
        return *(int *)(0x56d124 + level * 4);
    }
    return 0;
}
