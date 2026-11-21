/* Game_ContainsObjectPointer: tests whether the object map holds a pointer
   (0x480bf0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    char pad[0x16f8];
    char map[0x14];
    int count;

    char ContainsObjectPointer(void *pointer);
};

char Game::ContainsObjectPointer(void *pointer)
{
    int i;

    for (i = 0; i < count; i++) {
        if (pointer == ((struct IDMap *)map)->Lookup(i, 0)) {
            return 1;
        }
    }
    return 0;
}
