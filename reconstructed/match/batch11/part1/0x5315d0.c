/* UI_CenterChildVertically: centers a child gadget vertically within its
   parent (0x5315d0). */
struct Child {
    char pad[0x28];
    int field28;
    int unused2c;
    int field30;
};

struct UIHelper {
    int BinarySearch8(int key, char flag);
    void MoveChildToPosition(int y, int extra);
};

struct UI {
    char pad[0x18];
    int field18;
    int unused1c;
    int field20;
    char pad2[0xc4];
    void *children;

    int CenterChildVertically(int key, int extra);
};

int UI::CenterChildVertically(int key, int extra)
{
    int index = ((UIHelper *)this)->BinarySearch8(key, 0);

    if (index == -1)
        return 0;
    Child *child = *(Child **)((char *)children + index * 8);
    ((UIHelper *)child)
        ->MoveChildToPosition((child->field28 - child->field30 - field18 +
                               field20) / 2, extra);
    return 1;
}
