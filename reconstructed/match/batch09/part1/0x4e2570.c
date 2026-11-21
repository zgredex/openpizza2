/* Game_CollectObjectsByOwner: appends every owned record to a list
   (0x4e2570). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct List {
    void Add(void *item);
};

struct Game {
    void CollectObjectsByOwner(struct List *list, int owner);
};

void Game::CollectObjectsByOwner(struct List *list, int owner)
{
    int count = *(int *)((char *)this + 0x194);
    int index = 0;

    if (count > 0) {
        do {
            int *record = ((struct IDMap *)((char *)this + 0x180))->Lookup(index, 0);

            if (*(int *)((char *)record + 0x30) == owner)
                list->Add(record);
            index++;
        } while (index < count);
    }
}
