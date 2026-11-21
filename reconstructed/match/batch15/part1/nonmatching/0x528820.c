/* UI_UpdateHoveredRow: maps a mouse position to a list row and reports whether
   the hovered row changed (0x528820). */
struct UI {
    char pad0[0x28];
    int boundsRight;
    int pad1;
    int originX;
    int originY;
    int left;
    int top;
    int rowCount;
    int pad2;
    int hoveredRow;
    void *layout;

    int UpdateHoveredRow(int *point);
};

int UI::UpdateHoveredRow(int *point)
{
    int y = point[1];
    int topEdge = originY + top;
    int row;

    if (y >= topEdge) {
        int rowHeight = *(int *)((char *)layout + 0x9b0);

        if (y <= rowCount * rowHeight + topEdge) {
            int leftEdge = left + originX;

            if (point[0] >= leftEdge && point[0] <= boundsRight + leftEdge) {
                row = (y - originY - top) / rowHeight;
                goto check;
            }
        }
    }
    row = -1;
check:
    if (row >= rowCount) {
        row = -1;
    }
    if (row == hoveredRow) {
        return 0;
    }
    hoveredRow = row;
    return 1;
}
