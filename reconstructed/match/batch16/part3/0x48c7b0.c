/* Game_GetRatingPercent: returns how far a rating value is above its
   threshold, clamped to zero through one hundred (0x48c7b0). */
extern float DAT_0055c470;

struct IDMap {
    void *Lookup(int index, int *out);
};

class Game {
public:
    int GetRatingPercent(int index, int value);
};

int Game::GetRatingPercent(int param_1, int param_2)
{
    int local_20[8];
    int iVar1;
    void *record;

    local_20[0] = 0x14;
    local_20[1] = 0x1e;
    local_20[2] = 0x28;
    local_20[3] = 0x32;
    local_20[4] = 0x5a;
    local_20[5] = 0x5f;
    local_20[6] = 0x50;
    local_20[7] = 0x46;
    if (param_2 >= local_20[param_1]) {
        return 100;
    }
    record = ((IDMap *)((char *)this + 4))->Lookup(
        *(int *)((char *)this + 0x2f4), 0);
    iVar1 = 100 - (int)((float)(local_20[param_1] - param_2) *
                        *(float *)((char *)record + 0xa0) * DAT_0055c470);
    if (iVar1 < 0) {
        iVar1 = 0;
    }
    return iVar1;
}
