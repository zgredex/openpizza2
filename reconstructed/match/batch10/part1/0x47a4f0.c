/* Game_SumStatGrid: sums a rectangular part of the integer statistics grid
   (0x47a4f0). */
struct Game {
    char pad[0x188];
    int grid[9][9];

    int SumStatGrid(int column, int row);
};

int Game::SumStatGrid(int column, int row)
{
    int total = 0;
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
