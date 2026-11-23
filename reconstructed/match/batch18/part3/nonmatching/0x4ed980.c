/* Map_ComputeVisibleTileRange: clamps the visible tile rectangle to the grid
   (0x4ed980). */
struct Map {
    char pad[0x10];
    int cellHeight;
    void ComputeVisibleTileRange(int *point, int *left, int *top, int *right, int *bottom, int *flag);
    void ScreenToTileCoords(int *point, int *a, int *b);
    void RecordPointToGridCell(int point, int *cell, int *row);
    int *Grid_GetCell(int x, int y);
};

void Map::ComputeVisibleTileRange(int *point, int *left, int *top, int *right,
                                  int *bottom, int *flag)
{
    int *cell;

    *flag = 0;
    ScreenToTileCoords(point, left, top);
    RecordPointToGridCell((int)point, right, bottom);
    cell = Grid_GetCell(*left + 1, *top);
    if (cell != 0 && *point < *cell) {
        *left = *left - 1;
    }
    cell = Grid_GetCell(*left + 1, *top);
    if (cell != 0 && *(int *)(point + 1) <= *(int *)(cell + 4) + cellHeight) {
        *left = *left - 1;
        *bottom = *bottom - 1;
        *flag = 1;
    }
    while (1) {
        int *a = Grid_GetCell(*left, *top);
        int *b = Grid_GetCell(*right, *bottom);

        if (a == 0 || b == 0 || *(int *)(b + 4) <= *(int *)(a + 4)) {
            break;
        }
        *bottom = *bottom - 1;
    }
}
