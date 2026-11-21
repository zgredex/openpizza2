/* Game_HasBuildingForPlayer: reports whether a building slot is free for the
   current player (0x502eb0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct World {
    char pad[0x3c];
    char map[0x14];
    int count;

    int GetCurrentPlayerCompanyName();
};

extern int DAT_0057c670;

struct Game {
    char pad[0x48];
    int state;

    bool HasBuildingForPlayer();
};

bool Game::HasBuildingForPlayer()
{
    int i;

    if (state == 0x16) {
        for (i = 0; i < ((struct World *)DAT_0057c670)->count; i++) {
            struct World *world = (struct World *)DAT_0057c670;
            int record = (int)((struct IDMap *)((char *)world + 0x3c))->Lookup(i, 0);

            if (*(int *)(record + 0x30) <= 7) {
                int company = ((struct World *)DAT_0057c670)->GetCurrentPlayerCompanyName();

                if (*(int *)(record + 0x14c + company * 4) == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}
