/* AI_GetMaxPlanSteps: returns the largest plan-step count of a player's
   objects (0x4e2c40). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct PlanObject {
    int CountPlanSteps(int first, int second, int third);
};

struct AI {
    char pad[0x110];
    char map[0x14];
    int count;

    int GetMaxPlanSteps(int param);
};

int AI::GetMaxPlanSteps(int param)
{
    int maximum = 0;
    int i;

    for (i = 0; i < *(int *)((char *)this + 0x124); i++) {
        struct PlanObject *object = (struct PlanObject *)
            ((struct IDMap *)map)->Lookup(i, 0);
        int steps = object->CountPlanSteps(param, 0, -1);

        if (steps > maximum) {
            maximum = steps;
        }
    }
    return maximum;
}
