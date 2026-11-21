/* Window_MoveToSidePanel: moves the window beside the desktop edge
   (0x54a820). */
struct RECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" __declspec(dllimport) int __stdcall GetWindowRect(
    void *window, struct RECT *rect);
extern "C" __declspec(dllimport) void *__stdcall GetDesktopWindow(void);
extern "C" __declspec(dllimport) int __stdcall MoveWindow(
    void *window, int x, int y, int width, int height, int repaint);

struct Window {
    char pad[4];
    void *handle;
    void *parent;

    void MoveToSidePanel();
};

void Window::MoveToSidePanel()
{
    struct RECT screen;
    struct RECT desktop;

    if (handle != 0) {
        GetWindowRect(parent, &screen);
        GetWindowRect(GetDesktopWindow(), &desktop);
        {
            int right = desktop.right;
            int left = desktop.left;
            int width = (right - screen.right) - left;
            int height = screen.bottom - screen.top;

            MoveWindow(handle, screen.right, screen.top, width, height, 1);
        }
    }
}
