/* UI_ComputeCenteredRect (0x4f34c0, 46 bytes).  Build: /O2 /TP.
   Horizontal inset is half the width; vertical inset is 1.5x the height. */
struct UI {
    void ComputeCenteredRect(int *rect, int *left, int *top);
};

void UI::ComputeCenteredRect(int *rect, int *left, int *top)
{
    int height = *(int *)((char *)this + 0x10);
    int y = rect[1];
    int topEdge = (height >> 1) + y + height;
    int width = *(int *)((char *)this + 0xc);

    *left = (width >> 1) + rect[0];
    *top = topEdge;
}
