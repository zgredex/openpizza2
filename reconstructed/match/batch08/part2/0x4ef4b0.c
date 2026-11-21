/* Grid_GetCell: returns the cell record at a row/column, or null when out of
   range (0x4ef4b0). */
struct Grid {
    char pad[0x1c];
    int columns;
    int rows;
    char pad2[0x28];
    void *cells;
    void *GetCell(int column, int row);
};

void *Grid::GetCell(int column, int row)
{
    if (row < rows && row >= 0) {
        if (column < columns && column >= 0)
            return (char *)cells + (columns * row + column) * 0xc;
    }
    return 0;
}
