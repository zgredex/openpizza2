/* Stats_SumPlayerGrid (0x47a430). */
extern char *DAT_0057c670;
struct Stats {
    char pad0[0x554];
    int grid[8][100];       /* 0x554 */

    int SumPlayerGrid(int column, int row);
};

int Stats::SumPlayerGrid(int column, int row)
{
    int total = 0;
    int limit = *(unsigned short *)(*(int *)(DAT_0057c670 + 0x94) + 0x0a);
    int r;
    int c;

    if (limit > 100)
        limit = 100;
    for (r = 0; r < limit; r++) {
        if (r == row || row == -1) {
            for (c = 0; c < 8; c++) {
                if (column == c || column == -1)
                    total += grid[c][r];
            }
        }
    }
    return total;
}
