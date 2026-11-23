/* Grid_GetDirectionBetweenNodes (0x4f57f0). */

struct GridNode {
    char pad0[0x0c];
    int x;                      /* 0x0c */
    int y;                      /* 0x10 */
};

extern "C" void Debug_WarningMessageBox(int message);

int __stdcall Grid_GetDirectionBetweenNodes(GridNode *a, GridNode *b)
{
    if (a->x == b->x && a->y > b->y)
        return 6;
    if (a->x < b->x && a->y > b->y)
        return 2;
    if (a->x < b->x && a->y == b->y)
        return 5;
    if (a->x < b->x && a->y < b->y)
        return 1;
    if (a->x == b->x && a->y < b->y)
        return 4;
    if (a->x > b->x && a->y < b->y)
        return 0;
    if (a->x > b->x && a->y == b->y)
        return 7;
    if (a->x > b->x && a->y > b->y)
        return 3;
    Debug_WarningMessageBox(0x571d8c);
    return -1;
}
