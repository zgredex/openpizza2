/* UI_ScrollChildByVelocity (0x528510). */

struct UIChild {
    void MoveChildToPosition(int x, int y);
    void ClipChildRect();
};

struct UI {
    bool ScrollChildByVelocity(int unused, int delta);
};

bool UI::ScrollChildByVelocity(int unused, int delta)
{
    if (*(int *)((char *)this + 0x1c) >= 0) {
        *(float *)((char *)this + 0x2c) = (float)delta
            * *(float *)((char *)this + 0x24)
            + *(float *)((char *)this + 0x2c);
        *(float *)((char *)this + 0x30) = (float)delta
            * *(float *)((char *)this + 0x28)
            + *(float *)((char *)this + 0x30);
    } else {
        *(int *)((char *)this + 0x2c) = *(int *)((char *)this + 0x34);
        *(int *)((char *)this + 0x30) = *(int *)((char *)this + 0x38);
    }
    ((struct UIChild *)*(void **)((char *)this + 0x20))->MoveChildToPosition(
        (int)*(float *)((char *)this + 0x2c),
        (int)*(float *)((char *)this + 0x30));
    ((struct UIChild *)*(void **)((char *)this + 0x20))->ClipChildRect();
    return *(int *)((char *)this + 0x1c) >= 0;
}
