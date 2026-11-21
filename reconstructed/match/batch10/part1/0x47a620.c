/* Grid_GetMaxValue: returns the largest value in the 9x8 statistics grid
   (0x47a620). */
struct Grid {
    char pad[0x410];
    float grid[9][9];

    float GetMaxValue();
};

float Grid::GetMaxValue()
{
    float maximum = 0.0f;
    int r;
    int c;

    for (r = 0; r < 9; r++) {
        for (c = 0; c < 8; c++) {
            float value = grid[c][r];

            if (value > maximum) {
                maximum = value;
            }
        }
    }
    return maximum;
}
