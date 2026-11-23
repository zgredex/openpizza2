/* Game_CountGoalTargets: counts mission goal records of the requested kind
   (0x480130). */
struct Game {
    int MapRecordToGlobal(int index);
    int CountGoalTargets(int kind);
};

int Game::CountGoalTargets(int kind)
{
    Game *map = *(Game **)((char *)this + 0x16f0);
    int count = 0;
    int i = 0;
    int record;

    if (*(int *)((char *)map + 0x8c) < 1) {
        return 0;
    }
    do {
        record = map->MapRecordToGlobal(i);
        switch (kind) {
        case 0x16:
            if ((*(int *)(record + 0x30) == 0x1d ||
                 *(int *)(record + 0x30) == 0x1e) &&
                *(int *)(record + 0x38) != 0x38 &&
                *(int *)(record + 0x38) != 0x39 &&
                *(int *)(record + 0x108) != 6) {
                record = *(int *)(record + 0xa4);
                if (record != 0x19 && record != 0x1a) {
                    count++;
                }
            }
            break;
        case 0x17:
        case 0x1b:
            if ((*(int *)(record + 0x30) == 0x1d ||
                 *(int *)(record + 0x30) == 0x1e ||
                 *(int *)(record + 0x30) == 0x1f ||
                 *(int *)(record + 0x30) == 0x16) &&
                *(int *)(record + 0x38) != 0x38 &&
                *(int *)(record + 0x38) != 0x39 &&
                *(int *)(record + 0x108) != 6) {
                record = *(int *)(record + 0xa4);
                if (record != 0x19 && record != 0x1a) {
                    count++;
                }
            }
            break;
        }
        map = *(Game **)((char *)this + 0x16f0);
        i++;
    } while (i < *(int *)((char *)map + 0x8c));
    return count;
}
