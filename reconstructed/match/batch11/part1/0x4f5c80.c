/* Map_GetFirstLinkedCell: resolves the first non-empty linked cell of a tile
   (0x4f5c80). */
struct Cell {
    char pad[0x14];
    short cells[8];
};

struct ArrayHelper {
    int CountValid8(Cell *cell);
    void *GetRecord28(int index, int value);
};

extern "C" void __cdecl NoOp_Stub(char *message);

struct Map {
    void *GetFirstLinkedCell(Cell *cell);
};

void *Map::GetFirstLinkedCell(Cell *cell)
{
    int i;

    if (((ArrayHelper *)this)->CountValid8(cell) > 1)
        NoOp_Stub((char *)0x571dc0);
    for (i = 0; i < 8; i++) {
        if (cell->cells[i] != -1)
            return ((ArrayHelper *)this)->GetRecord28(0, cell->cells[i]);
    }
    return 0;
}
