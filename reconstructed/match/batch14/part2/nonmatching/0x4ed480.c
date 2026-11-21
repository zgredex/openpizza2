/* Map_ComputeObjectDistance (0x4ed480): weighted Manhattan distance from an
   object cell to a point, or 1000000 when the index is invalid. */
extern "C" int __cdecl abs(int value);
#pragma intrinsic(abs)

struct Cell {
    int field0;                /* 0x00 */
    int field4;                /* 0x04 */
};

struct Map {
    char pad[0xc];
    int fieldc;                /* 0x0c */
    int field10;               /* 0x10 */
    char pad2[0x1c - 0x14];
    int field1c;               /* 0x1c */
    int field20;               /* 0x20 */
    char pad3[0x4c - 0x24];
    Cell *cells;               /* 0x4c */
    int ComputeObjectDistance(int arg1, int arg2, int arg3, int arg4,
                              int index);
};

int Map::ComputeObjectDistance(int arg1, int arg2, int arg3, int arg4,
                               int index)
{
    Cell *cell;
    int a;
    int b;

    if (index < 0) {
        return 1000000;
    }
    if (field20 * field1c < index) {
        return 1000000;
    }
    cell = (Cell *)((char *)cells + index * 0xc);
    a = (field10 / 2 + cell->field4 - arg2 - arg4) + field10;
    b = (fieldc / 2 - arg1 - arg3) + cell->field0;
    return abs(b) * 3 + abs(a) * 4;
}
