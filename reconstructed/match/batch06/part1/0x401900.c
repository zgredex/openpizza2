/* Map_FindIndex: linear search of a map key array (0x401900). */
struct Map {
    int pad0;
    int *items;
    int pad8;
    int count;
    int FindIndex(int value);
};

int Map::FindIndex(int value)
{
    int index = 0;

    if (count > 0) {
        int *item = items;
        while (index < count) {
            if (*item == value) {
                return index;
            }
            index++;
            item++;
        }
    }
    return -1;
}
