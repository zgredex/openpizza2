/* Stats_Increment2D: increments a two-dimensional statistics counter (0x47db10). */
struct Stats {
    void Increment2D(int column, int row);
};

void Stats::Increment2D(int column, int row)
{
    int *counter = (int *)((char *)this + (row + 0x626 + column * 2) * 4);

    ++*counter;
}
