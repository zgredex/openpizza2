/* Game_GetMostCommonTypeIndex (0x4e2a20). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    char pad00[0x180];
    struct IDMap map180;
    int count194;

    int GetMostCommonTypeIndex();
};

int Game::GetMostCommonTypeIndex()
{
    int count = count194;
    int best = -1;
    int index;
    int counts[5];

    if (count == 0) {
        return -1;
    }
    index = 0;
    if (count > 0) {
        do {
            int record = (int)map180.Lookup(index, 0);
            int type = *(int *)(record + 0x30);
            if (type >= 0) {
                counts[type] = counts[type] + 1;
            }
            index = index + 1;
        } while (index < count);
    }
    {
        int bestIndex = -1;
        int *entry;
        index = 0;
        entry = counts;
        do {
            if (*entry > best) {
                best = *entry;
                bestIndex = index;
            }
            index = index + 1;
            entry = entry + 1;
        } while (index < 5);
        return bestIndex;
    }
}
