/* Map_SetObjectFlags (0x4d2d10). */
struct CS {
    void Enter();
    void Leave();
};
struct Map {
    char pad00[0x24];
    int field24;

    void RenderObject(void *cell, int flag);
    void SetObjectFlags(void *object, unsigned flags);
};
extern "C" char *DAT_0057c670;

void Map::SetObjectFlags(void *object, unsigned flags)
{
    unsigned *cell;

    ((struct CS *)*(int *)(DAT_0057c670 + 0x240))->Enter();
    cell = (unsigned *)(*(int *)((char *)object + 0x4c) + field24 * 0xc);
    if (cell != 0) {
        if (*(int *)(cell[2] + 0x1c) == -1) {
            *(int *)(cell[2] + 0x1c) = 0;
        }
        *(unsigned *)(cell[2] + 0x1c) = *(unsigned *)(cell[2] + 0x1c) | flags;
        if (flags == 1) {
            *(char *)(cell[2] + 0x2c) = 0;
        }
        ((struct Map *)object)->RenderObject(cell, 1);
    }
    ((struct CS *)*(int *)(DAT_0057c670 + 0x240))->Leave();
}
