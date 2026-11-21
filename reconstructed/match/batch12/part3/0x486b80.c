/* Game_CountUnassignedObjectsByClass (0x486b80). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int CountUnassignedObjectsByClass(int type, char unassignedOnly);
};

int __fastcall State_Is2DOr2E(void *object);

int Game::CountUnassignedObjectsByClass(int type, char unassignedOnly)
{
    int count = 0;
    int i;
    int n = *(int *)((char *)this + 0x50);

    for (i = 0; i < n; i++) {
        void *object = ((struct IDMap *)((char *)this + 0x3c))->Lookup(i, 0);
        if (State_Is2DOr2E(object) == 0
            && type == *(int *)((char *)object + 0x30)
            && (!unassignedOnly || *(int *)((char *)object + 0x110) == -1)) {
            count++;
        }
    }
    return count;
}
