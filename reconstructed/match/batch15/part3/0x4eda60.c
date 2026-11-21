struct Map {
    char pad0[0x1c];
    int width;
    char pad1[0xd8 - 0x20];
    int scroll_x;
    char pad2[0xe0 - 0xdc];
    int scroll_y;
    int ComputeBlitRect(int x, int y, int *mode, int flags);
    void ScreenToTileCoords(int *pos, int *tile_x, int *tile_y);
};

void Map::ScreenToTileCoords(int *pos, int *tile_x, int *tile_y)
{
    int cell = ComputeBlitRect(*pos, pos[1], (int *)1, 0);
    if (cell == 0) {
        cell = ComputeBlitRect(scroll_x + *pos, scroll_y + pos[1], (int *)1, 0);
        while (cell == 0) {
            (*pos)++;
            pos[1]++;
            cell = ComputeBlitRect(*pos, pos[1], (int *)1, 0);
        }
    }
    *tile_x = **(int **)(cell + 8) % width;
    *tile_y = **(int **)(cell + 8) / width;
}
