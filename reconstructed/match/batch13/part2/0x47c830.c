/* City_ComputeServiceLevel (0x47c830). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct City {
    char pad0[0x34];
    int mapKey;             /* 0x34 */
    int levelIndex;         /* 0x38 */

    int ComputeServiceLevel();
};
struct Game {
    char pad0[4];
    IDMap map;              /* 0x04 */
};
extern Game *DAT_0057c670;
extern int DAT_005675ac[];

int City::ComputeServiceLevel()
{
    char *record = (char *)DAT_0057c670->map.Lookup(mapKey, 0);
    int minimum = 0x18;
    int index;

    for (index = 0; index < 4; index++) {
        char value;

        if (index < 0 || index > 3)
            value = 0;
        else
            value = record[0xa4 + index * 4];
        int adjusted = value - 6;

        if (minimum > adjusted)
            minimum = adjusted;
    }
    if (minimum > 0x18)
        return 0;
    return (0x18 - minimum) / DAT_005675ac[levelIndex] + 1;
}
