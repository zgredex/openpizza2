/* UI_SetChildPosition: stores the child's screen position (0x5237e0). */
struct UIChild {
    char pad[0x5c];
    int x;
    int y;
};

struct UI {
    char pad[0x240];
    UIChild *child;
    void SetChildPosition(int x, int y);
};

void UI::SetChildPosition(int x, int y)
{
    UIChild *selected = child;

    if (selected != 0) {
        selected->x = x;
        selected->y = y;
    }
}
