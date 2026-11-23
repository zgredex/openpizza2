extern "C" int __cdecl Random_RangeFast(int min, int max);

/* Game_RedirectPersonDestination: redirects building references to another
   destination object (0x48c6d0). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

struct City {
    void *CollectBuildingsByType(int type, void *object, char flag);
};

struct Game {
    void RedirectPersonDestination(void *destination);
};

void Game::RedirectPersonDestination(void *destination)
{
    int type = *(int *)((char *)destination + 0x30);
    void *city = ((IDMap *)((char *)this + 4))->Lookup(*(int *)((char *)this + 0x2f4), 0);
    void *buildings = ((City *)city)->CollectBuildingsByType(type, destination, 0);
    int count = *(int *)((char *)buildings + 0x14);
    unsigned int pick = Random_RangeFast(1, count + 1);
    int i = 0;

    if (0 < *(int *)((char *)this + 0x50)) {
        do {
            int record = (int)((IDMap *)((char *)this + 0x3c))->Lookup(i, 0);
            int j;

            if (0 < count) {
                for (j = 0; j < count; j++) {
                    int building = (int)((IDMap *)buildings)->Lookup(j, 0);
                    int k;
                    int *reference = (int *)(record + 0xd4);

                    for (k = 0; k < 8; k++) {
                        if (*reference == building) {
                            pick = pick - 1;
                            if (pick == 0) {
                                pick = count + 1;
                                *reference = (int)destination;
                            }
                        }
                        reference = reference + 1;
                    }
                }
            }
            i = i + 1;
        } while (i < *(int *)((char *)this + 0x50));
    }
    if (buildings != 0) {
        (*(void (__stdcall **)(int))**(void ***)buildings)(1);
    }
}
