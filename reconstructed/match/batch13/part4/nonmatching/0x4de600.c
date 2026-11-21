/* Game_SumPlayerMatrixValues (0x4de600). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Stats {
    int GetMatrixVariantValue(int first, int second, int flag);
};
struct Game {
    char pad00[0x148];
    struct IDMap map148;
    int count15c;

    int SumPlayerMatrixValues(int first, int second, void *matrix);
};

int Game::SumPlayerMatrixValues(int first, int second, void *matrix)
{
    int sum = 0;
    int count;
    int index;
    struct IDMap *map;

    if (matrix != 0) {
        return ((struct Stats *)matrix)->GetMatrixVariantValue(first, second, 1);
    }
    count = count15c;
    index = 0;
    map = (struct IDMap *)((char *)this + 0x148);
    if (count < 1) {
        return sum;
    }
    do {
        void *entry = map->Lookup(index, 0);
        sum = sum + ((struct Stats *)entry)
                        ->GetMatrixVariantValue(first, second, 1);
        index = index + 1;
    } while (index < count);
    return sum;
}
