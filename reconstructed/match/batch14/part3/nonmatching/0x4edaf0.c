/* Map_RecordPointToGridCell (0x4edaf0): converts a record point to grid cell
   coordinates, retrying with the map offset when needed. */
struct Rect {
    char pad[8];
    int *value;
};

struct Record {
    char pad[4];
    int field4;
    int field8;
};

extern "C" {
void NoOp_Stub(char *message);
}
extern char DAT_00571b44;

struct Map {
    char pad[0x1c];
    int cellSize;
    char pad2[0xdc - 0x20];
    int offsetX;
    int offsetY;

    Rect *ComputeBlitRect(int x, int y, int *flag, int value);
    int RecordPointToGridCell(Record *record, int *remainder, int *quotient);
};

int Map::RecordPointToGridCell(Record *record, int *remainder, int *quotient)
{
    Rect *rect = ComputeBlitRect(record->field8, record->field4,
                                 (int *)1, 0);
    int value;

    if (rect == 0) {
        rect = ComputeBlitRect(record->field8 - offsetX,
                               offsetY + record->field4, (int *)1, 0);
        if (rect == 0)
            NoOp_Stub(&DAT_00571b44);
    }
    *quotient = *rect->value / cellSize;
    value = *rect->value;
    *remainder = value % cellSize;
    return value / cellSize;
}
