/* Rect_Union: expands a rectangle to include another rectangle (0x526d30). */
struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct UI {
    char pad[0x1a4];
    Rect rect;

    void Union(int left, int top, int right, int bottom);
};

extern "C" __declspec(dllimport) int __stdcall SetRect(Rect *rect, int left,
                                                        int top, int right,
                                                        int bottom);

void UI::Union(int newLeft, int newTop, int newRight, int newBottom)
{
    if (rect.left == -999) {
        SetRect(&rect, newLeft, newTop, newRight, newBottom);
        return;
    }
    if (newLeft <= rect.left) {
        rect.left = newLeft;
    }
    if (newRight >= rect.right) {
        rect.right = newRight;
    }
    if (newTop <= rect.top) {
        rect.top = newTop;
    }
    if (newBottom >= rect.bottom) {
        rect.bottom = newBottom;
    }
}
