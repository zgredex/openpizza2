/* Stats_SumFloatMatrix: sums a rectangular part of the floating-point
   statistics matrix (0x47a5d0). */
extern float DAT_0055c2e4;

struct Stats {
    char pad[0x410];
    float grid[9][9];

    float SumFloatMatrix(int column, int row);
};

float Stats::SumFloatMatrix(int column, int row)
{
    float total = DAT_0055c2e4;
    int r;
    int c;

    for (r = 0; r < 9; r++) {
        if (r == row || row == -1) {
            for (c = 0; c < 8; c++) {
                if (c == column || column == -1) {
                    total += grid[c][r];
                }
            }
        }
    }
    return total;
}
