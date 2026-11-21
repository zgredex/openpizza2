/* Game_GetBuildingConditionCode (0x47ffb0). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int CountObjectsByType(int type);
    int GetBuildingConditionCode();
};

int __fastcall Rating_AdjustB(int object);

int Game::GetBuildingConditionCode()
{
    int i;

    for (i = 0; i < CountObjectsByType(-1); i++) {
        int *record = (int *)((struct IDMap *)((char *)this + 0x1500))
                           ->Lookup(i, 0);
        int object = *record;
        if (Rating_AdjustB(object) < 0x14) {
            return 5;
        }
        if (*(int *)(object + 0xc) < 0x14) {
            return 4;
        }
    }
    return 0;
}
