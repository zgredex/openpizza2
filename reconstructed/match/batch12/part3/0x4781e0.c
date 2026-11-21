/* Game_ComputeRecordMapPercent (0x4781e0). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int ComputeRecordMapPercent();
};

int Game::ComputeRecordMapPercent()
{
    int count = *(int *)((char *)this + 0x19ac);
    int sum = 0;
    int i;

    for (i = 0; i < count; i++) {
        int *record = (int *)((struct IDMap *)((char *)this + 0x1998))
                          ->Lookup(i, 0);
        if (record[7] != 0) {
            sum += *record;
        }
    }
    if (count == 0) {
        return 0;
    }
    return (sum * 100 + 199999) / (count * 200000);
}
