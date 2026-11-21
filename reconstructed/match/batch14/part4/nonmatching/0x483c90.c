/* Game_FindFreeObjectByOwner (0x483c90): finds the first object owned by the
   given player that is free for use. */
struct IDMap {
    char pad[0x14];
    int count;
    void *Lookup(int key, int *result);
};

struct Object {
    char pad[0x30];
    int owner;
    char pad2[0x74 - 0x34];
    int field74;
    char pad3[0x110 - 0x78];
    int field110;

    int Is2DOr2E();
};

struct Game {
    char pad[0x3c];
    IDMap objectMap;

    int FindFreeObjectByOwner(int owner, char any);
};

int Game::FindFreeObjectByOwner(int owner, char any)
{
    int count = objectMap.count;
    int i = 0;

    if (0 < count) {
        do {
            Object *object = (Object *)objectMap.Lookup(i, 0);

            if (object->owner == owner) {
                if (any == 0)
                    return (int)object;
                if (object->field110 == -1 &&
                    object->Is2DOr2E() != 1 && object->field74 == 0)
                    return (int)object;
            }
            i++;
        } while (i < count);
    }
    return 0;
}
