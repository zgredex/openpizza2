/* Game_CountActiveObjectsByType (0x4e1d40). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Record {
    int key;                /* 0x00 */
};
struct State {
    char pad0[0x30];
    int type;               /* 0x30 */

    int Is2DOr2E();
};
struct Game {
    char pad0[0x1b8];
    IDMap map;              /* 0x1b8 */
    int count;              /* 0x1cc */

    int CountActiveObjectsByType(int type);
};
struct GlobalGame {
    char pad0[0x3c];
    IDMap map;              /* 0x3c */
};
extern GlobalGame *DAT_0057c670;

int Game::CountActiveObjectsByType(int type)
{
    int total = 0;
    int index = 0;
    int count = this->count;

    if (count > 0) {
        do {
            Record *record = (Record *)map.Lookup(index, 0);
            State *state = (State *)DAT_0057c670->map.Lookup(record->key, 0);

            if (state->Is2DOr2E() == 0 &&
                (type == -1 || state->type == type))
                total++;
            index++;
        } while (index < count);
    }
    return total;
}
