/* Game_CountObjectsByType2: counts the objects whose byte type matches
   (0x4d6ba0). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct Game {
    char pad[0xfc8];
    char objects[0x14];
    int count;

    int CountObjectsByType2(unsigned int type);
};

int Game::CountObjectsByType2(unsigned int type)
{
    int total = 0;
    int count = *(int *)((char *)this + 0xfdc);
    int index;

    for (index = 0; index < count; index++) {
        int *record = (int *)((IDMapHelper *)objects)->Lookup(index, 0);

        if (type == *(unsigned char *)(*record + 0x824) || type == 0xffffffff)
            total++;
    }
    return total;
}
