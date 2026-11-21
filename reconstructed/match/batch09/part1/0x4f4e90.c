/* Map_ScreenToGridCell: converts a screen point into grid cell coordinates
   (0x4f4e90). */
struct Map {
    int ComputeBlitRect(int x, int y, int *param, int flags);
    void ScreenToGridCell(int x, int y, int *cellX, int *cellY, int *param);
};

void Map::ScreenToGridCell(int x, int y, int *cellX, int *cellY, int *param)
{
    int rect = ComputeBlitRect(x, y, param, 0);

    *cellX = **(int **)(rect + 8) % *(int *)((char *)this + 0x1c);
    *cellY = **(int **)(rect + 8) / *(int *)((char *)this + 0x1c);
}
