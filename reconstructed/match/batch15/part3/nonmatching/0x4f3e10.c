/* Non-matching candidate.
   First difference: offset 0x0, 112 bytes differ.
   original uses no frame pointer for the cell parameter; candidate keeps it in ebp and grows the frame.
   Kept for evidence; not part of the strict match set. */
struct Grid {
    char pad0[0x1c];
    int width;
    int GetCell(int x, int y);
    int GetNeighborCell(int *cell, int direction);
};

int Grid::GetNeighborCell(int *cell, int direction)
{
    int value = **(int **)((char *)cell + 8);
    int x = value % width;
    int y = value / width;

    switch (direction) {
    case 0:
        return GetCell(x, y + 1);
    case 2:
        return GetCell(x, y - 1);
    case 4:
        return GetCell(x + 1, y + 1);
    case 5:
        y--;
    case 1:
        return GetCell(x + 1, y);
    case 6:
        return GetCell(x - 1, y - 1);
    case 7:
        y++;
    case 3:
        return GetCell(x - 1, y);
    default:
        return (int)cell;
    }
}
