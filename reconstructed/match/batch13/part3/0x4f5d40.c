/* CityView_ReserveCarCell (0x4f5d40). */
struct CityView {
    char pad00[0x4c];
    char *cells4c;

    int IsCarSpawnCellFree(void *cell);
    void ReserveCarCell(void *cell, void *vehicle);
};
struct Map {
    void *GetFirstLinkedCell(void *cell);
};
struct Grid {
    int GetDirectionBetweenNodes(void *from, void *to);
    void *GetNeighborCell(void *cell, int direction);
};

void CityView::ReserveCarCell(void *cell, void *vehicle)
{
    if (IsCarSpawnCellFree(cell)) {
        char *first = cells4c + *(int *)((char *)cell + 8) * 0xc;
        void *linked = ((struct Map *)this)->GetFirstLinkedCell(cell);
        int direction = ((struct Grid *)this)->GetDirectionBetweenNodes(cell, linked);
        int neighbor = (int)((struct Grid *)this)->GetNeighborCell(
            first, direction);

        *(int *)(*(int *)(first + 8) + 0x38) = 1;
        *(int *)(*(int *)(neighbor + 8) + 0x38) = 1;
        *(int *)((char *)vehicle + 0x44) = **(int **)(first + 8);
        *(int *)((char *)vehicle + 0x48) = **(int **)(neighbor + 8);
        *(int *)((char *)vehicle + 0x4c) = -1;
        *(int *)((char *)vehicle + 0x50) = -1;
    }
}
