/* Map_GetObjectNeighborCell (0x4ee640): computes a neighbouring grid cell
   based on the object direction. */
struct GridEntry {
    char pad[8];
    int *cell;
};

struct Map {
    char pad[0x1c];
    int width;
    char pad2[0x4c - 0x20];
    GridEntry *entries;

    void GetCell(int x, int y);
    void GetObjectNeighborCell(int record, int index);
};

void Map::GetObjectNeighborCell(int record, int index)
{
    int value = **(int **)(*(int *)((char *)this + 0x4c) + index * 0xc + 8);
    int x = value % width;
    int y = value / width;

    switch (*(int *)(record + 0xc)) {
    case 0x14:
        GetCell(x + 1, y + 4);
        return;
    case 0x15:
        GetCell(x + 4, y + 1);
        return;
    case 0x16:
        GetCell(x + 1, y - 2);
        return;
    case 0x17:
        x = x - 2;
        y = y + 1;
    }
    GetCell(x, y);
}
