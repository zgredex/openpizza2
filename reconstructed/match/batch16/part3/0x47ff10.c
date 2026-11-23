/* Game_GetConstructionPriority: returns the construction priority for the
   current building state (0x47ff10). */
struct Game {
    int CountFreeBuildingsByType(int type);
    int GetConstructionPriority();
};

struct Rating {
    int GetInverse100();
};

struct IDMap {
    void *Lookup(int index, int *out);
};

int Game::GetConstructionPriority()
{
    Game *manager = *(Game **)((char *)this + 0x16f0);
    int value;
    int i;

    value = manager->CountFreeBuildingsByType(0x1a);
    if (value > 0)
        return 2;
    value = manager->CountFreeBuildingsByType(0x1b);
    if (value > 0)
        return 2;
    value = manager->CountFreeBuildingsByType(0x1c);
    if (value > 0)
        return 2;

    value = ((Rating *)this)->GetInverse100();
    if (value < 0x28)
        return 3;

    for (i = 0; i < *(int *)((char *)this + 0x19ac); i++) {
        int *record = (int *)((IDMap *)((char *)this + 0x1998))->Lookup(i, 0);

        if (record[1] < 10)
            return 1;
    }
    return 0;
}
