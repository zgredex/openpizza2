/* Game_FindIdleObjectByClass: finds the first idle map object of a class
   (0x48b960). */
struct IDMapHelper {
    void *Lookup(int index, int *result);
};

struct Game {
    char pad[0x50];
    int objectCount;

    int FindIdleObjectByClass(int classId);
};

int Game::FindIdleObjectByClass(int classId)
{
    int index = 0;

    while (index < objectCount) {
        char *object =
            (char *)((IDMapHelper *)((char *)this + 0x3c))->Lookup(index, 0);

        if (*(int *)(object + 0x30) == 10 &&
            *(int *)(object + 0x10c) == classId &&
            *(int *)(object + 0xa4) == -1 &&
            *(int *)(object + 0x74) == 0)
            return (int)object;
        index++;
    }
    return 0;
}
