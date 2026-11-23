// Game_GetCategoryShare: percentage share of one category across objects.

struct IDMap {
    char *Lookup(int key, int *index);
};

struct Game {
    int GetCategoryShare(int type, int category);
};

int Game::GetCategoryShare(int type, int category)
{
    int totals[6];
    int index;
    int k;
    int total;

    for (k = 0; k < 6; k++)
        totals[k] = 0;

    if (type == -1) {
        if (*(int *)((char *)this + 0x50) > 0) {
            index = 0;
            do {
                char *object = ((IDMap *)((char *)this + 0x3c))->Lookup(index, 0);
                if (*(int *)(object + 0x30) <= 7) {
                    for (k = 0; k < 6; k++)
                        totals[k] += *(int *)(object + 0x14c + k * 4);
                }
                index++;
            } while (index < *(int *)((char *)this + 0x50));
        }
    } else {
        if (*(int *)((char *)this + 0x50) > 0) {
            index = 0;
            do {
                char *object = ((IDMap *)((char *)this + 0x3c))->Lookup(index, 0);
                if (*(int *)(object + 0x30) == type) {
                    for (k = 0; k < 6; k++)
                        totals[k] += *(int *)(object + 0x14c + k * 4);
                }
                index++;
            } while (index < *(int *)((char *)this + 0x50));
        }
    }
    total = 0;
    for (k = 0; k < 6; k++)
        total += totals[k];
    if (total == 0 || totals[category] == 0)
        return 0;
    return totals[category] * 100 / total;
}
