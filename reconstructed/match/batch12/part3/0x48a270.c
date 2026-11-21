/* Game_FindFreeObjectByType (0x48a270). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    void *FindFreeObjectByType(int type);
};

int __fastcall State_Is2DOr2E(void *object);

void *Game::FindFreeObjectByType(int type)
{
    int i;
    void *object;

    for (i = 0; i < *(int *)((char *)this + 0x50); i++) {
        object = ((struct IDMap *)((char *)this + 0x3c))->Lookup(i, 0);
        if (State_Is2DOr2E(object) == 0
            && *(int *)((char *)object + 0x30) == type
            && *(int *)((char *)object + 0x74) == 0
            && *(int *)((char *)object + 0x110) == -1) {
            return object;
        }
    }
    return 0;
}
