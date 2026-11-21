/* Game_IsPlayerBestInStat (0x48e000). */

struct Game {
    void *GetPlayerBySlot(int slot);
    int IsPlayerBestInStat(int **table, int column, int row);
};

int Game::IsPlayerBestInStat(int **table, int column, int row)
{
    int value = table[row][column];
    int i;

    if (value == 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        void *player = GetPlayerBySlot(i);
        if (player != 0
            && *(int *)((char *)player + 0x48) != row
            && table[i][column] > value) {
            return 0;
        }
    }
    return 1;
}
