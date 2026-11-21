/* UI_SetObjectRangeByKey (0x531400). */
struct CS {
    void Enter();
    void Leave();
};
struct UI {
    char pad00[0xe8];
    int arrayE8;
    char padEc[0x48];
    int field134;

    int BinarySearch8(int key, int unused);
    void MoveChildToPosition(int x, int y);
    int SetObjectRangeByKey(int key, int x, int y);
};

int UI::SetObjectRangeByKey(int key, int x, int y)
{
    int index;

    ((struct CS *)*(int *)(*(int *)((char *)this + 0x134) + 0x1c8))->Enter();
    index = BinarySearch8(key, 0);
    if (index == -1) {
        ((struct CS *)*(int *)(*(int *)((char *)this + 0x134) + 0x1c8))->Leave();
        return 0;
    }
    ((struct UI *)*(int *)(*(int *)((char *)this + 0xe8) + index * 8))
        ->MoveChildToPosition(x, y);
    ((struct CS *)*(int *)(*(int *)((char *)this + 0x134) + 0x1c8))->Leave();
    return 1;
}
