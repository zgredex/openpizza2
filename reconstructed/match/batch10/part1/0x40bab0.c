/* Game_UpdateIdleCars: gives idle cars random road destinations (0x40bab0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    char pad[0x58];
    char map[0x14];
    int count;

    void UpdateIdleCars();
};

__fastcall int Record_GetFlag3E48(void *record);
__fastcall void Car_PickRandomRoadStep(void *car);

void Game::UpdateIdleCars()
{
    int i;

    for (i = 0; i < count; i++) {
        void *record = ((struct IDMap *)map)->Lookup(i, 0);

        if (Record_GetFlag3E48(record) == 0 &&
            *(short *)(*(int *)((char *)record + 8) + 0x28) == -1) {
            Car_PickRandomRoadStep(record);
        }
    }
}
