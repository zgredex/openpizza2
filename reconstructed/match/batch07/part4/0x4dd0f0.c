/* Economy_ApplyTablePercent: applies a percentage table entry to one economy
   value (0x4dd0f0). */
extern int DAT_0056ca2c[];

struct Economy {
    char pad[0x6c];
    int values[1];
    char pad2[0x10bc - 0x70];
    int tableRow;
    int ApplyTablePercent(int index);
};

int Economy::ApplyTablePercent(int index)
{
    return DAT_0056ca2c[index + tableRow * 9] * values[index] / 100;
}
