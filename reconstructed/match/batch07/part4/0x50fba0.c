/* GamePlan_ComputeEffectValue: converts the average plan effect into the
   game's 0..100 effect scale (0x50fba0). */
extern double DAT_0055c690;

struct GamePlan {
    int ComputeAverageEffect(int index);
    int ComputeEffectValue(int index);
};

int GamePlan::ComputeEffectValue(int index)
{
    int average = ComputeAverageEffect(index);

    if (average >= 0x28)
        return (int)((average - 0x28) * DAT_0055c690);
    return 0x28 - average;
}
