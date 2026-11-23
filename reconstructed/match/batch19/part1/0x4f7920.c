// Map_PickObject: selects a player subrecord with a low plan score.

struct Game {
    void *GetPlayerSubrecord(int slot, int index, int flag);
};

struct AI {
    int ComputePlanScores(void *object, int *scoreA, int *scoreB, int limit);
};

struct UI {
    void ShiftRowData(void *object, int direction);
};

struct Map {
    int PickObject(int slot);
};

int Map::PickObject(int slot)
{
    int count;
    int index = 0;
    int sum = 0;
    void *best = 0;
    int bestScore = 0;
    int result = 0;
    void *object = 0;
    int score;
    int scoreB[3];

    count = *(int *)(*(int *)((char *)this + slot * 0x168 + 0x70) + 0x15c);
    if (count > 0) {
        do {
            object = ((Game *)this)->GetPlayerSubrecord(slot, index, 1);
            if (object != 0) {
                result = ((AI *)this)->ComputePlanScores(object, &score,
                                                         &scoreB[0], 2);
                if (result == 2) {
                    if (best == 0 || score < bestScore) {
                        bestScore = score;
                        best = object;
                    }
                    result = 3;
                    sum += score;
                }
            }
            index++;
        } while (index < count);
        if (result >= 10 && best != 0 && bestScore < sum / (result * 2)) {
            ((UI *)this)->ShiftRowData(object, 1);
            return 1;
        }
    }
    return 0;
}
