/* Game_CountObjectsByType: counts registered objects of a given type
   (0x47aac0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    char pad[0x1500];
    struct IDMap map;
    int count;

    int CountObjectsByType(unsigned type);
};

int Game::CountObjectsByType(unsigned type)
{
    int total = 0;
    int i;

    for (i = 0; i < *(int *)((char *)this + 0x1514); i++) {
        int *record = (int *)map.Lookup(i, 0);

        if (type == *(unsigned char *)(*record + 0x824) || type == 0xffffffff) {
            total++;
        }
    }
    return total;
}
