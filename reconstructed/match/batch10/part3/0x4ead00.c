/* Game_TickWorldObjects: tick all city ad campaigns when not paused. */
extern int DAT_0057c670;
extern "C" void __fastcall CityAds_UpdateCampaign(void *campaign);

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    void TickWorldObjects();
};

void Game::TickWorldObjects()
{
    int i;

    if (*(int *)(DAT_0057c670 + 0x1508) == 0) {
        for (i = 0; i < *(int *)((char *)this + 0x2c40c); i++)
            CityAds_UpdateCampaign(((IDMap *)((char *)this + 0x2c3f8))
                                       ->Lookup(i, 0));
    }
}
