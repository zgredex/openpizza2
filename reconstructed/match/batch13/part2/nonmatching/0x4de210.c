/* Stats_SumMatrixCells (0x4de210). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Stats {
    char pad0[0x148];
    IDMap map;              /* 0x148 */
    int count;              /* 0x15c */

    int SumPlayerGrid(int column, int row);
    int SumMatrixCells(int column, int row, Stats *target);
};

int Stats::SumMatrixCells(int column, int row, Stats *target)
{
    int total = 0;
    int count;

    if (target != 0)
        return target->SumPlayerGrid(column, row);
    count = this->count;
    if (count <= 0)
        return total;
    {
        int index = 0;

        for (; index < count; index++) {
            Stats *record = (Stats *)map.Lookup(index, 0);

            total += record->SumPlayerGrid(column, row);
        }
    }
    return total;
}
