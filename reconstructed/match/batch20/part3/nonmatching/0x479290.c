extern int DAT_0057c670;
extern float DAT_0055c320;

struct IDMap {
    void *Lookup(int key, int *out);
};

extern "C" int Math_RoundFloat(float value);
extern "C" void __stdcall Clamp_0_100(int *value);

struct Game {
    char pad[0x16f8];
    IDMap *objects;
    char pad2[0x170c - 0x16f8 - 4];
    int count;
    char pad3[0x1854 - 0x170c - 4];
    int dominance;
    void ComputeCategoryDominance();
};

void Game::ComputeCategoryDominance()
{
    int counts[5] = {0, 0, 0, 0, 0};
    int bestIndex = -1;
    int bestCount = 0;
    float score = 100.0f;
    int i;

    for (i = 0; i < count; i++) {
        int *record = (int *)objects->Lookup(i, 0);
        if (record != 0) {
            int *other = (int *)((IDMap *)(DAT_0057c670 + 0x74))->Lookup(record[1], 0);
            int type = other[4];
            if (type != 4)
                counts[type] = counts[type] + 1;
        }
    }
    bestIndex = -1;
    bestCount = 0;
    for (i = 0; i < 5; i++) {
        if (bestCount < counts[i]) {
            bestIndex = i;
            bestCount = counts[i];
        }
    }
    if (bestIndex == -1) {
        dominance = 0;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (i != bestIndex && counts[i] != 0 && 0 < bestCount)
            score = score - ((float)counts[i] / (float)bestCount) * DAT_0055c320;
    }
    if (bestCount == 0)
        score = 0;
    dominance = Math_RoundFloat(score);
    Clamp_0_100(&dominance);
}
