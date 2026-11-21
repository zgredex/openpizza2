/* Game_CountObjectsByState: counts records whose state field matches, with -1
   matching every record (0x486910). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

struct GameObjectList {
    int CountObjectsByState(int state);
};

int GameObjectList::CountObjectsByState(int state)
{
    char *self = (char *)this;
    int total = *(int *)(self + 0x50);
    int found = 0;
    int i = 0;
    int *record;

    if (0 < total) {
        do {
            record = ((IDMap *)(self + 0x3c))->Lookup(i, 0);
            if (state == -1 || state == *(int *)((char *)record + 0x30))
                found++;
            i++;
        } while (i < total);
    }
    return found;
}
