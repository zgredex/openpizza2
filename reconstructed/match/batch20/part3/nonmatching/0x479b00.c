struct Grid {
    int ScoreRuns(short *cells);
};

int Grid::ScoreRuns(short *cells)
{
    int rowOne[80];
    int colTwo[80];
    int colOne[80];
    int rowTwo[80];
    int score = 0;
    int row;
    int col;
    short *cell;

    for (row = 0; row < 80; row++)
        rowOne[row] = 0;
    for (row = 0; row < 80; row++)
        colOne[row] = 0;
    for (row = 0; row < 80; row++)
        rowTwo[row] = 0;
    for (row = 0; row < 80; row++)
        colTwo[row] = 0;
    cell = cells + 2;
    for (row = 0; row < 80; row++) {
        for (col = 0; col < 80; col++) {
            int value = *cell;
            cell += 4;
            if (value == 1) {
                if (++rowOne[row] > 2)
                    score += 4;
                if (++colOne[col] > 2)
                    score += 4;
                rowTwo[row] = 0;
                colTwo[col] = 0;
            } else if (value == 2) {
                if (++rowTwo[row] > 4)
                    score += 2;
                if (++colTwo[col] > 4)
                    score += 2;
                rowOne[row] = 0;
                colOne[col] = 0;
            } else {
                rowOne[row] = 0;
                colOne[col] = 0;
                rowTwo[row] = 0;
                colTwo[col] = 0;
            }
        }
    }
    return score;
}
