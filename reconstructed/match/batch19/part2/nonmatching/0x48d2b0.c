// Game_CountNearbyTypesAroundRect: counts nearby objects by type.

struct IDMap {
    char *Lookup(int key, int *index);
};

struct State {
    int Is2DOr2E();
};

struct UI {
    void GetRecordCenteredRect(int record, int *x, int *y);
};

struct MapObject {
    void GetScreenPosition(int flags, int *x, int *y);
};

struct Game {
    void CountNearbyTypesAroundRect(void *rect, int radius, int *counts);
};

void Game::CountNearbyTypesAroundRect(void *rect, int radius, int *counts)
{
    int index;
    int limit;
    int sx;
    int sy;
    int rx;
    int ry;
    char *record;

    for (index = 0; index < 8; index++)
        counts[index] = 0;
    record = ((IDMap *)((char *)this + 4))->Lookup(
        *(int *)((char *)this + 0x2f4), 0);
    limit = radius * radius * 4;
    ((UI *)*(void **)(record + 0xfa8))->GetRecordCenteredRect(
        *(int *)((char *)rect + 0x24), &rx, &ry);
    if (*(int *)((char *)this + 0x50) > 0) {
        index = 0;
        do {
            char *object = ((IDMap *)((char *)this + 0x3c))->Lookup(index, 0);
            if (*(int *)(object + 0x30) <= 7 &&
                *(int *)(object + 0x74) == 0 &&
                ((State *)object)->Is2DOr2E() == 0) {
                int dx;
                int dy;
                ((MapObject *)object)->GetScreenPosition(0, &sx, &sy);
                dx = rx - sx;
                dy = ry - sy;
                if (dx * dx + dy * dy * 4 < limit)
                    counts[*(int *)(object + 0x30)]++;
            }
            index++;
        } while (index < *(int *)((char *)this + 0x50));
    }
}
