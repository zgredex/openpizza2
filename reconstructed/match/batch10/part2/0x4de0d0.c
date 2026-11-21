/* Stats_GetMaxMatrixValue: maximum value of the whole statistics grid
   (0x4de0d0). */
struct Matrix {
    int MaxByRow9x8(int limit);
};

struct Game {
    int SumStatGridAll(int row, int column, void *unused);
    int GetMaxMatrixValue(void *matrix);
};

int Game::GetMaxMatrixValue(void *matrix)
{
    int max = 0;

    if (matrix == 0) {
        int row;
        int column;

        for (row = 0; row < 8; row++) {
            for (column = 0; column < 9; column++) {
                int value = SumStatGridAll(row, column, 0);

                if (value > max)
                    max = value;
            }
        }
        return max;
    }
    return ((struct Matrix *)matrix)->MaxByRow9x8(-1);
}
