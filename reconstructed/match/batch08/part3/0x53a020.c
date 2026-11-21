/* Window_SetRectAndUpdateChildren: sets the window rectangle from its size
   and republishes it to the children (0x53a020). */
struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct Window {
    char pad[0x1a];
    unsigned short width;      /* 0x1a */
    unsigned short height;     /* 0x1c */
    char pad2[0x84 - 0x1e];
    Rect rect;                 /* 0x84 */
    void SetRectAndUpdateChildren(int x, int y);
};

struct Renderer {
    void CopyStateToChildren();
};

extern void (__stdcall *DAT_0055c280)(Rect *, int, int, int, int);

void Window::SetRectAndUpdateChildren(int x, int y)
{
    DAT_0055c280(&rect, x, y, width + x, height + y);
    ((Renderer *)this)->CopyStateToChildren();
}
