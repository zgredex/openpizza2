/* UI_HitTestChild: tests a point against the child rectangle and forwards the
   local coordinates to the virtual hit test (0x520bc0). */
struct UI {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int HitTest(int x, int y);

    char pad[0x14];
    int captured;
    char pad2[4];
    int enabled;
    char pad3[4];
    int left;
    int top;
    int right;
    int bottom;
    int offsetX;
    int offsetY;

    int HitTestChild(int x, int y);
};

int UI::HitTestChild(int x, int y)
{
    if (captured != 0) {
        return 1;
    }
    if (enabled == 0 || x < left || x >= right ||
        y < top || y >= bottom) {
        return 0;
    }
    return HitTest(x - offsetX, y - offsetY);
}
