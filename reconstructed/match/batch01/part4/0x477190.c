/* PC2 byte-match candidate. Build with CL /O2 /GX /TP; see worklog.md and
   verify.py for the exact matcher command. */
struct IDMap {
    int Lookup(int key, int *out);
};
struct Map {
    int GetHourlyValue(int index);
    void *AI_ComputePath(int a, int b, int c);
    void *Grid_GetCell(int x, int y);
    void SetTileFieldWithDefault(void *cell, int value, int flag);
    void ScreenToGridCell(int x, int y, int *out1, int *out2, int flag);
    void ComputeCenteredRect(void *cell, int *out1, int *out2);
};
struct Game {
    int FindRecordByTripleKey(int a, int b, int c, int *out);
    char pad00[0x240];
    void *lock;                 /* +0x240 */
};
struct ConstructionOrder {
    unsigned char data[0x24];
    ConstructionOrder(int a, int b);
};
struct List {
    void Add(void *object);
};
struct Gfx {
    void BlitRectList(void *rect);
};
struct Branch {
    void SpawnWalkInCustomer(void);
};
extern Game *g_game;            /* 0x57c670 */
extern Gfx *g_gfx;              /* 0x58072c */
extern "C" int __cdecl Random_RangeFast(int min, int max);
struct Lock {
    void Enter(void);
    void Leave(void);
};

void Branch::SpawnWalkInCustomer(void)
{
    int rec;
    int record;
    int path;
    int obj;
    int gx;
    int gy;
    int rx;
    int ry;
    int rect[4];
    void *cell;
    short value;

    if (((Map *)this)->GetHourlyValue(0) != 0) {
        record = g_game->FindRecordByTripleKey(0xb, 4, 3, &rec);
        path = (int)((Map *)*(void **)((char *)this + 0x14e0))->AI_ComputePath(1, 0, 0);
        if (path != 0) {
            obj = (int)new ConstructionOrder(rec, Random_RangeFast(0, 7));
            ((Map *)*(void **)((char *)this + 0x14e0))->ScreenToGridCell(
                *(int *)(path + 0xc), *(int *)(path + 0x10), &gx, &gy, 1);
            *(int *)((char *)this + 0x1718) = 0;
            ((List *)((char *)this + 0x19e0))->Add((void *)obj);
            *(int *)(obj + 0x18) = gx;
            *(int *)(obj + 0x1c) = gy;
            *(int *)(obj + 0x20) =
                *(int *)((char *)*(void **)((char *)this + 0x14e0) + 0x1c) * gy + gx;
            cell = ((Map *)*(void **)((char *)this + 0x14e0))->Grid_GetCell(gx, gy);
            value = *(short *)(record + (*(int *)(obj + 8) + 10) * 0xc);
            ((Lock *)g_game->lock)->Enter();
            ((Map *)*(void **)((char *)this + 0x14e0))->SetTileFieldWithDefault(
                cell, value, 1);
            ((Map *)*(void **)((char *)this + 0x14e0))->ComputeCenteredRect(
                cell, &rx, &ry);
            rx = rx - *(int *)((char *)*(void **)((char *)this + 0x14e0) + 0x24);
            ry = ry - *(int *)((char *)*(void **)((char *)this + 0x14e0) + 0x28);
            rect[0] = rx - 0x10;
            rect[1] = ry - 8;
            rect[2] = rect[0] + 0x20;
            rect[3] = rect[1] + 0x10;
            g_gfx->BlitRectList(rect);
            ((Lock *)g_game->lock)->Leave();
        }
    }
}
