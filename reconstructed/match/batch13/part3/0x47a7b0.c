/* Stats_GetMaxGroupScore (0x47a7b0). */
struct Stats {
    float GetGroupScore(int column, int row);
    float GetMaxGroupScore();
};
extern "C" char *DAT_0057c670;
extern "C" float DAT_0055c2e4;

float Stats::GetMaxGroupScore()
{
    float maximum = 0.0f;
    int count = *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 10);
    int limit = count;
    int row;

    if (count > 100) {
        limit = 100;
    }
    row = 0;
    if (limit <= 0) {
        goto finished;
    }
    do {
        int column = 0;
        do {
            float value = GetGroupScore(column, row);
            if (value > maximum) {
                maximum = value;
            }
            column = column + 1;
        } while (column < 7);
        row = row + 1;
    } while (row < limit);
finished:
    return maximum;
}
