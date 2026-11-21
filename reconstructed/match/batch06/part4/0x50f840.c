/* GamePlan_ComputeAverageEffect: averages the eight category effects
   (0x50f840).  Build: /O2 /TP. */
struct GamePlan {
    int ComputeCategoryEffect(int param, int category);
    int ComputeAverageEffect(int param);
};

int GamePlan::ComputeAverageEffect(int param)
{
    int total = 0;
    int index = 0;

    do {
        total += ComputeCategoryEffect(param, index);
        index++;
    } while (index < 8);
    return total >> 3;
}
