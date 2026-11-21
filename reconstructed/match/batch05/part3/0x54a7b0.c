/* Window_ToggleVisibility: flips a window's visibility (0x54a7b0). */
typedef void *HWND;

__declspec(dllimport) int __stdcall IsWindowVisible(HWND hwnd);

struct Window {
    char pad[4];
    HWND hwnd;
    void SetVisible(int visible);
    void ToggleVisibility();
};

void Window::ToggleVisibility()
{
    if (hwnd != 0)
        SetVisible(IsWindowVisible(hwnd) == 0);
}
