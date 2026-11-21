/* Game_AdvanceProductionCounter (0x4e29b0). */

extern char *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Object {
    void GetPlayerValue(int index);
};

struct Game {
    void AdvanceProductionCounter();
};

void Game::AdvanceProductionCounter()
{
    int i = 0;

    *(volatile int *)((char *)this + 0x64) = *(int *)((char *)this + 0x64) + 1;
    if (0 < *(int *)((char *)this + 0x1cc)) {
        do {
            int *record = (int *)((struct IDMap *)((char *)this + 0x1b8))
                              ->Lookup(i, 0);
            if (record[1] == 0x17) {
                void *object = ((struct IDMap *)(DAT_0057c670 + 0x3c))
                                   ->Lookup(*record, 0);
                *(int *)((char *)object + 0xa8) = 100;
                ((struct Object *)object)->GetPlayerValue(-1);
            }
            i++;
        } while (i < *(int *)((char *)this + 0x1cc));
    }
}
