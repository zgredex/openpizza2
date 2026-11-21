/* Game_GetMaxMatrixValue: returns the largest player-matrix value, or the
   maximum of a supplied 4x9 matrix (0x4de670). */
struct Matrix4x9 {
    int Max4x9();
};

struct GameMatrix {
    int SumPlayerMatrixValues(int row, int column, void *unused);
    int GetMaxMatrixValue(int matrix);
};

int GameMatrix::GetMaxMatrixValue(int matrix)
{
    int maximum = 0;
    int i;
    int j;
    int value;

    if (matrix == 0) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 9; j++) {
                value = SumPlayerMatrixValues(i, j, 0);
                if (value > maximum)
                    maximum = value;
            }
        }
        return maximum;
    }
    return ((Matrix4x9 *)matrix)->Max4x9();
}
