/* Stats_GetMaxObjectMatrixValue: returns the maximum value of an object's
   float matrix (0x4de300). */
struct Grid {
    float GetMaxValue();
};

struct Stats {
    float SumRecordFloatMatrix(int row, int column, int flag);

    float GetMaxObjectMatrixValue(int grid);
};

float Stats::GetMaxObjectMatrixValue(int grid)
{
    float maximum = 0.0f;
    int row;
    int column;

    if (grid != 0) {
        return ((struct Grid *)this)->GetMaxValue();
    }
    for (row = 0; row < 8; row++) {
        for (column = 0; column < 9; column++) {
            float value = SumRecordFloatMatrix(row, column, 0);
            if (value > maximum) {
                maximum = value;
            }
        }
    }
    return maximum;
}
