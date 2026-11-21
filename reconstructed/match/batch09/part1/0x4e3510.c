/* Game_FindPlanByTarget: finds the plan record of the given target
   (0x4e3510). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Game {
    int *FindPlanByTarget(int target);
};

int *Game::FindPlanByTarget(int target)
{
    int count = *(int *)((char *)this + 0x140);
    int index = 0;

    if (count > 0) {
        do {
            int *plan = ((struct IDMap *)((char *)this + 300))->Lookup(index, 0);

            if (*(int *)((char *)plan + 8) == 3
                && *(int *)((char *)plan + 0x2c) == *(int *)((char *)target + 0x24))
                return plan;
            index++;
        } while (index < count);
    }
    return 0;
}
