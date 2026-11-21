/* Game_DecayProductValues (0x513f50). */
struct IDMap {
    char pad00[0x14];
    void *Lookup(int key, int *out);
};
struct Game {
    char pad00[0x2c];
    int field2c;
    char pad30[0x14];
    struct IDMap map44;
    int count58;

    int DecayProductValues(int tick);
};
extern "C" int DAT_00573b08[];

int Game::DecayProductValues(int tick)
{
    int value = tick / 3;
    int index = 0;

    if (tick % 3 == 0) {
        value = count58;
        if (value > 0) {
            do {
                int record = (int)map44.Lookup(index, 0);
                value = (*(int *)(record + 0xc) / 10 -
                         DAT_00573b08[field2c]) + -10 + *(int *)(record + 4);
                if (value < 0) {
                    value = 0;
                }
                *(int *)(record + 4) = value;
                value = count58;
                index = index + 1;
            } while (index < value);
        }
    }
    return value;
}
