/* Game_CountRecordsWithFlag16F4: count records whose flag byte at +0x16f4
   is set (0x4de710). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountRecordsWithFlag16F4(void);
};

int Game::CountRecordsWithFlag16F4(void)
{
    int count = 0;
    int index = 0;

    if (*(int *)((char *)this + 0x15c) > 0) {
        do {
            char *record = (char *)((struct IDMap *)((char *)this + 0x148))
                               ->Lookup(index, 0);

            if (*(char *)(record + 0x16f4) != 0)
                count++;
            index++;
        } while (index < *(int *)((char *)this + 0x15c));
    }
    return count;
}
