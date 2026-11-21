/* CityView_IsCarSpawnCellFree (0x4f5cd0). */

struct CityView {
    char pad[0x4c];
    int *array;
    int CountValid8(void *cell);
    void *GetFirstLinkedCell(void *cell);
    int GetDirectionBetweenNodes(void *from, void *to);
    void *GetNeighborCell(void *cell, int direction);
    int IsCarSpawnCellFree(void *cell);
};

int CityView::IsCarSpawnCellFree(void *cell)
{
    int index;
    int *entry;
    void *first;
    int direction;
    void *neighbor;

    if (CountValid8(cell) == 1) {
        index = *(int *)((char *)cell + 8);
        entry = array + index * 3;
        if (*(int *)(*(int *)((char *)entry + 8) + 0x38) == 0) {
            first = GetFirstLinkedCell(cell);
            direction = GetDirectionBetweenNodes(cell, first);
            neighbor = GetNeighborCell(entry, direction);
            if (*(int *)(*(int *)((char *)neighbor + 8) + 0x38) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
