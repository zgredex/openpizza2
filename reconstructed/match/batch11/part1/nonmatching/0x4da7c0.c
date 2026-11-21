extern "C" int *DAT_0057c670;
struct PlayerHelper { void GetTopActionIndices(int *first, int *second); };
struct Game {
    void *GetPlayerBySlot(int slot);
    void RecordPlayerStat(int slot);
};
void Game::RecordPlayerStat(int slot)
{
    int local;
    PlayerHelper *player = (PlayerHelper *)((Game *)DAT_0057c670)->GetPlayerBySlot(slot);
    int *record;
    int i = 8;
    player->GetTopActionIndices(&local, &slot);
    record = (int *)((char *)this + 0xfec);
    do {
        record[-2] = *record;
        record[-1] = local;
        *record = slot;
        record += 6;
        i--;
    } while (i != 0);
}
