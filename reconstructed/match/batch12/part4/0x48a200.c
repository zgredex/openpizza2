/* Game_CountFreeSlots (0x48a200). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    int CountFreeSlots(int type);
};

int __fastcall State_Is2DOr2E(void *object);

int Game::CountFreeSlots(int type)
{
    int count = 0;
    int i = 0;

    if (0 < *(int *)((char *)this + 0x50)) {
        for (; i < *(int *)((char *)this + 0x50); i++) {
            void *object = ((struct IDMap *)((char *)this + 0x3c))->Lookup(i, 0);
            if (State_Is2DOr2E(object) == 0
                && *(int *)((char *)object + 0x30) == type
                && *(int *)((char *)object + 0x74) == 0
                && *(int *)((char *)object + 0x110) == -1) {
                count++;
            }
        }
    }
    return count;
}
