/* Stats_GetMatrixVariantValue (0x47a850): reads one cell of a variant
   statistic matrix; unknown variants return the row index. */
struct Stats {
    char pad[0x1388];
    int variant0[2][9];
    int variant1[2][9];
    int variant2[2][9];
    int variant3[2][9];
    int GetMatrixVariantValue(int variant, int column, int row);
};

int Stats::GetMatrixVariantValue(int variant, int column, int row)
{
    switch (variant) {
    case 0:
        return variant0[row][column];
    case 1:
        return variant1[row][column];
    case 2:
        return variant2[row][column];
    case 3:
        return variant3[row][column];
    default:
        return row;
    }
}
