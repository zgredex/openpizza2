/* Game_ComputeAverageSkill: average skill value over every company
   (0x4e3f00). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Index {
    int Map8To5(int skill);
};

struct Game {
    int ComputeAverageSkill(int skill);
};

int Game::ComputeAverageSkill(int skill)
{
    int count = *(int *)((char *)this + 0x124);
    int sum = 0;
    int index = 0;

    if (count > 0) {
        do {
            struct Index *record = (struct Index *)
                ((struct IDMap *)((char *)this + 0x110))->Lookup(index, 0);

            sum += record->Map8To5(skill);
            index++;
        } while (index < count);
    }
    if (count == 0)
        return 0;
    return sum / count;
}
