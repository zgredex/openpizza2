/* Game_CountRecordsByField34: count records whose field 0x34 equals a
   value (0x4de6c0). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountRecordsByField34(int value);
};

int Game::CountRecordsByField34(int value)
{
    int count = 0;
    int index = 0;

    if (*(int *)((char *)this + 0x15c) > 0) {
        do {
            char *record = (char *)((struct IDMap *)((char *)this + 0x148))
                               ->Lookup(index, 0);

            if (*(int *)(record + 0x34) == value)
                count++;
            index++;
        } while (index < *(int *)((char *)this + 0x15c));
    }
    return count;
}
