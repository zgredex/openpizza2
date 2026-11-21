/* AI_StepToNeighborCell (0x47e860). */

struct IDMap {
    int LookupLinear(int value);
};

struct Grid {
    void *GetCell(int x, int y);
    void *GetRecord28(int type, int index);
};

struct AI {
    void StepToNeighborCell(void *cell);
};

void AI::StepToNeighborCell(void *cell)
{
    void *record;

    if (((struct IDMap *)((char *)this + 0x1998))->LookupLinear((int)cell) % 2 == 0) {
        record = (*(struct Grid **)((char *)this + 0x14e0))->GetCell(*(int *)((char *)cell + 0x14) + 3,
                               *(int *)((char *)cell + 0x18));
    } else {
        record = (*(struct Grid **)((char *)this + 0x14e0))->GetCell(*(int *)((char *)cell + 0x14) - 3,
                               *(int *)((char *)cell + 0x18));
    }
    (*(struct Grid **)((char *)this + 0x14e0))->GetRecord28(1, *(short *)(*(int *)((char *)record + 8) + 0x24));
}
