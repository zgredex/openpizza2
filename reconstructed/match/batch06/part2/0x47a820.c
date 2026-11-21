/* Game_SumStatRow8: sums one statistics row or all rows (0x47a820). */
struct Game {
    char pad[0x1364];
    int values[8];
    int SumStatRow8(int row);
};

int Game::SumStatRow8(int row)
{
    int sum = 0;
    int index = 0;
    int *value = values;

    do {
        if (index == row || row == -1) {
            sum += *value;
        }
        index++;
        value++;
    } while (index < 8);
    return sum;
}
