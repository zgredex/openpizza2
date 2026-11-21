/* Game_ResetPlayerStatsByCity: resets stats for the player at the city (0x4d40f0). */
struct Game {
    void *GetPlayerSubmapValue(int city, int submap);
};

struct Stats {
    void ResetAverages();
};

extern char *DAT_0057c670;

void __fastcall Game_ResetPlayerStatsByCity(char *city)
{
    void *player = ((Game *)DAT_0057c670)->GetPlayerSubmapValue(
        *(int *)(city + 0x81c), *(int *)(city + 0x820));

    if (player != 0) {
        ((Stats *)player)->ResetAverages();
    }
}
