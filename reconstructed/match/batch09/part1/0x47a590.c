/* Matrix_MaxByRow9x8: maximum over a 9x8 matrix column (or the whole matrix
   for row -1) (0x47a590). */
struct Matrix {
    int MaxByRow9x8(int row);
};

int Matrix::MaxByRow9x8(int row)
{
    int max = 0;
    int column = 0;
    int *cell = (int *)((char *)this + 0x188);

    do {
        if (row == column || row == -1) {
            int *value = cell;
            int remaining = 8;

            do {
                if (*value > max)
                    max = *value;
                value += 9;
                remaining--;
            } while (remaining != 0);
        }
        column++;
        cell++;
    } while (column < 9);
    return max;
}
