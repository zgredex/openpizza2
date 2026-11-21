/* Stats_GetOrSumSeries: returns one statistics series value, or the sum of the
   whole row when the index is -1 (0x4d3940). */
struct StatsGrid {
    int GetOrSumSeries(int column, int index);
};

int StatsGrid::GetOrSumSeries(int column, int index)
{
    char *self = (char *)this;
    int *value;
    int sum = 0;
    int count;

    if (index != -1)
        return *(int *)(self + (index + column * 100) * 4 + 0x44);
    value = (int *)(self + column * 400 + 0x44);
    count = 100;
    do {
        sum += *value;
        value++;
        count--;
    } while (count != 0);
    return sum;
}
