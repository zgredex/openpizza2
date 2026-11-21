/* Game_CountRecordsWithoutFlag: counts map records whose flag byte at +0x11
   is clear (0x510580). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountRecordsWithoutFlag();
};

int Game::CountRecordsWithoutFlag()
{
    int count = 0;
    int i = 0;

    if (*(int *)((char *)this + 0x5c) > 0) {
        do {
            char *record =
                (char *)((IDMap *)((char *)this + 0x48))->Lookup(i, 0);
            if (*(char *)(record + 0x11) == 0)
                count++;
            i++;
        } while (i < *(int *)((char *)this + 0x5c));
    }
    return count;
}
