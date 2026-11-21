/* PC2 byte-match candidate: Window_NotifyMouseMove (0x524970, 27 bytes).
   Build: /O2 /TP.  Forwards the cached mouse position as WM_MOUSEMOVE. */
struct Window {
    unsigned char pad_000[0x248];
    int mouse_x;
    int mouse_y;
    void DispatchMouseEvent(int message, int x, int y, int extra);
    void NotifyMouseMove();
};

void Window::NotifyMouseMove()
{
    DispatchMouseEvent(0x200, mouse_x, mouse_y, 0);
}
