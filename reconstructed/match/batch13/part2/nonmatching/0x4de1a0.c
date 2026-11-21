/* Game_SumStatGridAll (0x4de1a0). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    char pad0[0x148];
    IDMap map;              /* 0x148 */
    int count;              /* 0x15c */

    int SumStatGrid(int a, int b);
    int SumStatGridAll(int a, int b, Game *target);
};

int Game::SumStatGridAll(int a, int b, Game *target)
{
    int total = 0;
    int index = 0;
    int count;
    if (target != 0)
        return target->SumStatGrid(a, b);
    count = this->count;
    if (count <= 0)
        return total;
    for (; index < count; index++) {
        Game *record = (Game *)map.Lookup(index, 0);

        total += record->SumStatGrid(a, b);
    }
    return total;
}
