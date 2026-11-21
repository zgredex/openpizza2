/* Window_MoveToRect (0x54a7f0, 46 bytes).  Build: /O2 /TP.
   Moves the window to the rectangle and repaints it. */
extern int (__stdcall *DAT_0055c284)(void *window, int x, int y,
                                     int width, int height, int repaint);

struct Window {
    void MoveToRect(int *rect);
};

void Window::MoveToRect(int *rect)
{
    void *window = *(void **)((char *)this + 4);

    if (window != 0)
        DAT_0055c284(window, rect[0], rect[1], rect[2] - rect[0],
                     rect[3] - rect[1], 1);
}
