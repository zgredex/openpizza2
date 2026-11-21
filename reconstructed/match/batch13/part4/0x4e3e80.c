/* Game_FindBestRatedBuilding (0x4e3e80). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Index {
    int Map8To5(int value);
};
struct Game {
    char pad00[0x110];
    struct IDMap map110;
    int count124;

    void *FindBestRatedBuilding(int value);
};

void *Game::FindBestRatedBuilding(int value)
{
    int count = count124;
    int bestRating = 0;
    void *best = 0;
    int index = 0;

    if (count > 0) {
        do {
            void *record = map110.Lookup(index, 0);
            if (*(char *)((char *)record + 0x1dc) == 0) {
                int rating = ((struct Index *)record)->Map8To5(value);
                if (rating > bestRating) {
                    bestRating = rating;
                    best = record;
                }
            }
            index = index + 1;
        } while (index < count);
    }
    return best;
}
