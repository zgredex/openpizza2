// Player_ComputeNetStatTotal @ 0x4e3780 (154 bytes)
// Sums the per-record statistics over four rounds.

extern char *DAT_0057c670;

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class Stats {
public:
    float SumFilteredFloats(int first, int second, int round);
    float SumFilteredFloats2(int first, int second, int round);
};

class Player {
public:
    char pad0[0x148];
    IDMap map;
    int count;

    float ComputeNetStatTotal();
};

float Player::ComputeNetStatTotal()
{
    int count = *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 0xa);
    float total = 0.0f;
    int round;

    for (round = 0; round < 4; round++) {
        count--;
        if (count < 0)
            break;
        int n = this->count;
        for (int index = 0; index < n; index++) {
            Stats *record = (Stats *)this->map.Lookup(index, 0);
            total += record->SumFilteredFloats(-1, -1, count);
            total -= record->SumFilteredFloats2(-1, -1, count);
        }
    }
    return total;
}
