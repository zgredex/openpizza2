extern char *DAT_0057c670;

/* Game_ReassignDestroyedObjectReferences: retargets references to a destroyed
   map object (0x48b420). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct Game {
    void ReassignDestroyedObjectReferences(void *destroyed);
};

extern "C" void *__cdecl Map_GetRandomBuildingOfType(void *map, int type, void *object, char flag);

void Game::ReassignDestroyedObjectReferences(void *destroyed)
{
    int count = *(int *)((char *)this + 0x50);
    void *map = ((IDMap *)((char *)this + 4))->Lookup(*(int *)((char *)this + 0x2f4), 0);
    int i = 0;

    if (0 < count) {
        do {
            int record = (int)((IDMap *)((char *)this + 0x3c))->Lookup(i, 0);

            if (*(int *)(record + 0x30) != 0x2e) {
                if (*(int *)(record + 0xcc) == (int)destroyed) {
                    int replacement = (int)Map_GetRandomBuildingOfType(map,
                        *(int *)((char *)destroyed + 4), destroyed, 0);

                    if (replacement == 0) {
                        replacement = (int)Map_GetRandomBuildingOfType(map, 0, 0, 0);
                    }
                    *(int *)(record + 0xcc) = replacement;
                    {
                        int *reference = (int *)(record + 0xd4);
                        int n = 8;

                        do {
                            if (*reference == (int)destroyed) {
                                *reference = replacement;
                            }
                            reference = reference + 1;
                            n = n - 1;
                        } while (n != 0);
                    }
                } else {
                    int *reference = (int *)(record + 0xd4);
                    int n = 8;

                    do {
                        int replacement;

                        if (*reference == (int)destroyed) {
                            replacement = (int)Map_GetRandomBuildingOfType(map,
                                *(int *)((char *)destroyed + 4), destroyed, 0);
                            if (replacement != 0) {
                                *reference = replacement;
                            }
                        }
                        reference = reference + 1;
                        n = n - 1;
                    } while (n != 0);
                }
            }
            i = i + 1;
        } while (i < count);
    }
}
