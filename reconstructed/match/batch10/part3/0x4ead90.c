/* Map_Get2DTableValue: read one of two 48-column integer tables. */
struct Map {
    int Get2DTableValue(int table, int row, int col);
};

int Map::Get2DTableValue(int table, int row, int col)
{
    switch (table) {
    case 1:
        return *(int *)((char *)this + (row * 0x30 + col) * 4 + 0x2c234);
    case 0:
        return *(int *)((char *)this + (row * 0x30 + col) * 4 + 0x2bf4c);
    }
    return 0;
}
