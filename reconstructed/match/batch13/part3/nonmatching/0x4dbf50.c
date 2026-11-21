/* Game_GetPlayerSupplyScore (0x4dbf50). */
struct Game {
    struct Game *GetPlayerBySlot(int slot);
    int CountActiveObjectsByType(int type);
    int GetPlayerCity();
    int GetPlayerSupplyScore(int slot);
};
extern "C" char *DAT_0057c670;

int Game::GetPlayerSupplyScore(int slot)
{
    int score = *(int *)((char *)this + slot * 4 + 0xc98);
    struct Game *player = ((struct Game *)DAT_0057c670)->GetPlayerBySlot(slot);
    int count = player->CountActiveObjectsByType(0x1e);
    int city;

    count = count + player->CountActiveObjectsByType(0x1d);
    city = player->GetPlayerCity();
    score = score + ((*(int *)(city + 0x60) + *(int *)(city + 0x48)) * 3 -
                     count);
    if (score > 100) {
        return 100;
    }
    if (score < 0) {
        return 0;
    }
    return score;
}
