// Map_GetRandomBuildingOfType: random building of a type, with a fallback log.

extern char DAT_0057c1e0[];
extern char DAT_0056cd74[];
extern char DAT_005840d4[];

int Random_RangeFast(int low, int high);
void DebugConsole_Printf(void *console, int level, char *format, int value);

struct Game {
    int CanShowObject();
};

struct IDMap {
    void *Lookup(int key, int *index);
};

struct Map {
    int GetRandomBuildingOfType(int type, int exclude, char visibleOnly);
};

int Map::GetRandomBuildingOfType(int type, int exclude, char visibleOnly)
{
    void *list[256];
    int count = 0;
    int index;

    if (type == 7)
        type = 0;
    if (*(int *)((char *)this + 0xfc0) > 0) {
        index = 0;
        do {
            void *object = ((IDMap *)((char *)this + 0xfac))->Lookup(index, 0);
            if (*(int *)((char *)object + 4) == type &&
                *(int *)((char *)object + 0x48) != -1 &&
                (visibleOnly == 0 ||
                 ((Game *)object)->CanShowObject() != 0) &&
                object != (void *)exclude) {
                list[count] = object;
                count++;
            }
            index++;
        } while (index < *(int *)((char *)this + 0xfc0));
        if (count != 0) {
            unsigned int choice = Random_RangeFast(0, count - 1);
            return (int)list[choice];
        }
    }
    DebugConsole_Printf(*(void **)DAT_0057c1e0, 0xff, DAT_0056cd74,
                        ((int *)DAT_005840d4)[type]);
    return 0;
}
