/* AI_SumPlanSteps: sums the plan steps of every plan record (0x4e2ca0). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct PlanHelper {
    int CountPlanSteps(int value, int a, int b);
};

struct AI {
    char pad[0x110];
    char map[0x14];
    int count;

    int SumPlanSteps(int value);
};

int AI::SumPlanSteps(int value)
{
    int total = 0;
    int index;

    for (index = 0; index < count; index++) {
        void *record = (void *)((IDMapHelper *)map)->Lookup(index, 0);

        total += ((PlanHelper *)record)->CountPlanSteps(value, 0, -1);
    }
    return total;
}
