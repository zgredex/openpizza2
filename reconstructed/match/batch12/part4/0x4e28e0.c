/* Game_ResetBuildingUtilization (0x4e28e0). */

extern char *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Object {
    void GetPlayerValue(int index);
};

struct Game {
    void ResetBuildingUtilization();
};

void Game::ResetBuildingUtilization()
{
    int i = 0;

    *(volatile int *)((char *)this + 0x6c) = *(int *)((char *)this + 0x6c) + 1;
    if (0 < *(int *)((char *)this + 0x1cc)) {
        do {
            int *record = (int *)((struct IDMap *)((char *)this + 0x1b8))
                              ->Lookup(i, 0);
            if (record[1] == 0x1d) {
                void *object = ((struct IDMap *)(DAT_0057c670 + 0x3c))
                                   ->Lookup(*record, 0);
                *(int *)((char *)object + 0xa8) = 100;
                ((struct Object *)object)->GetPlayerValue(-1);
            }
            i++;
        } while (i < *(int *)((char *)this + 0x1cc));
    }
}
