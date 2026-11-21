/* Grid_CollectType351 (0x4f55e0): collects up to 0x51 cells whose object
   type is 0x351 into an array of (column, row) pairs. */
struct GridCell {
    char pad[4];
    int type;                  /* 0x04 */
};

struct Position {
    int column;
    int row;
};

struct Grid {
    char pad[0x1c];
    int columns;               /* 0x1c */
    int rows;                  /* 0x20 */
    char pad2[0x4c - 0x24];
    GridCell **cells;          /* 0x4c */
    void CollectType351(Position *output);
};

void Grid::CollectType351(Position *output)
{
    int count;
    int cellIndex;
    int column;
    int row;
    GridCell *cell;
    Position *current;

    count = 0;
    cellIndex = 0;
    row = 0;
    if (0 < rows) {
        do {
            column = 0;
            if (0 < columns) {
                current = output + count;
                do {
                    cell = *(GridCell **)((char *)cells + cellIndex * 0xc + 8);
                    if (cell != 0 && cell->type == 0x351) {
                        current->column = column;
                        current->row = row;
                        count = count + 1;
                        current = current + 1;
                        if (0x50 < count) {
                            return;
                        }
                    }
                    cellIndex = cellIndex + 1;
                    column = column + 1;
                } while (column < columns);
            }
            row = row + 1;
        } while (row < rows);
    }
}
