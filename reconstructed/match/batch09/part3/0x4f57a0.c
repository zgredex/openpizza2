/* Map_SetCellObjectFrame: updates a cell object's frame byte and redraws it
   when it changes (0x4f57a0). */
extern "C" int DAT_0058072c;

struct UI {
    void DrawObjectWithBounds(int *object, int *unused);
};

struct Map {
    void SetCellObjectFrame(int index, char frame);
};

void Map::SetCellObjectFrame(int index, char frame)
{
    char *self = (char *)this;
    int *cell = (int *)(*(int *)(self + 0x4c) + index * 0xc);

    if (cell != 0) {
        int object = cell[2];

        if (object != 0 && frame != *(char *)(object + 0x2e)) {
            *(char *)(object + 0x2e) = frame;
            if (DAT_0058072c != 0)
                ((UI *)this)->DrawObjectWithBounds(cell, 0);
        }
    }
}
