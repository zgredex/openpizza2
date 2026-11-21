/* Stats_GetMaxCityMatrixValue (0x4de120): finds the maximum cell sum over the
   city matrix, limited to the city's available rows. */
struct Matrix {
    int Max100x8();
};

struct StatsGlobal {
    char pad[0x94];
    char *cityMatrix;
};

extern StatsGlobal *DAT_0057c670;

struct Stats {
    int SumMatrixCells(int row, int column, void *result);
    int GetMaxCityMatrixValue(int matrix);
};

int Stats::GetMaxCityMatrixValue(int matrix)
{
    int maximum = 0;
    unsigned short count;
    int column;
    int row;

    if (matrix != 0)
        return ((Matrix *)matrix)->Max100x8();
    count = *(unsigned short *)(DAT_0057c670->cityMatrix + 10);
    matrix = count;
    if (100 < count)
        matrix = 100;
    column = 0;
    if (matrix <= 0)
        return maximum;
    do {
        row = 0;
        do {
            int value = SumMatrixCells(row, column, 0);

            if (maximum < value)
                maximum = value;
            row++;
        } while (row < 8);
        column++;
    } while (column < matrix);
    return maximum;
}
