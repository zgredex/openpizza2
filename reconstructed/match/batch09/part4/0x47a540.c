/* Game_SumStatGrid2: sums an 8x8 slice of the statistics grid, with -1 as a
   wildcard for either index (0x47a540). */
struct StatGrid {
    char pad[0x44];
    int grid[64];

    int SumStatGrid2(int column, int row);
};

int StatGrid::SumStatGrid2(int column, int row)
{
    int sum = 0;
    int i;
    int j;
    int *value;

    for (i = 0; i < 8; i++) {
        if (i == row || row == -1) {
            j = 0;
            value = grid + i;
            do {
                if (j == column || column == -1)
                    sum += *value;
                j++;
                value += 9;
            } while (j < 8);
        }
    }
    return sum;
}
