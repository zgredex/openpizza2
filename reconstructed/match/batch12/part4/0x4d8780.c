/* Game_CountRecordsByOwner (0x4d8780). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int CountRecordsByOwner(void *owner);
};

int Game::CountRecordsByOwner(void *owner)
{
    int count = 0;
    int i = 0;

    if (0 < *(int *)((char *)this + 0xfc0)) {
        for (; i < *(int *)((char *)this + 0xfc0); i++) {
            int *record = (int *)((struct IDMap *)((char *)this + 0xfac))
                              ->Lookup(i, 0);
            if (record[0x12] != -1) {
                if (record[0xe] > 0 && record[0xc] == (int)owner) {
                    count++;
                }
                if (record[1] == (int)owner) {
                    count++;
                }
            }
        }
    }
    return count;
}
