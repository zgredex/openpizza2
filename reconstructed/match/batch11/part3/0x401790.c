/* IDMap_RemoveByKey: removes the first entry with the given key under the
   global critical section (0x401790). */
struct CS {
    void Enter();
    void Leave();
};

struct IDMap {
    char pad[4];
    int *values;
    char pad2[4];
    int count;

    int RemoveByKey(int key);
    void RemoveRecursive(int index);
};

extern char DAT_00579af0[];

int IDMap::RemoveByKey(int key)
{
    int i;

    ((struct CS *)DAT_00579af0)->Enter();
    for (i = 0; i < count; i++) {
        if (values[i] == key) {
            RemoveRecursive(i);
            ((struct CS *)DAT_00579af0)->Leave();
            return 1;
        }
    }
    ((struct CS *)DAT_00579af0)->Leave();
    return 0;
}
