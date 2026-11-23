struct POINT {
    int x;
    int y;
};

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void *hwnd, POINT *point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

struct Window {
    char pad0[0x248];
    int cursorX;
    int cursorY;
    char pad1[0x2b4 - 0x250];
    int events[0x400][3];
    unsigned eventHead;
    unsigned eventTail;
    char pad2[0x8320 - 0x32bc];
    void *hwnd;
    void DispatchMouseEvent(int type, int x, int y, int flags);
    void SetCursorPosition(int x, int y, int clear, int dispatch);
};

void Window::SetCursorPosition(int x, int y, int clear, int dispatch)
{
    POINT point;
    unsigned index;

    point.x = x;
    point.y = y;
    cursorX = x;
    cursorY = y;
    ClientToScreen(hwnd, &point);
    SetCursorPos(point.x, point.y);
    if (clear != 0 && (index = eventHead) != eventTail) {
        do {
            if (events[index][0] == 0x200)
                events[index][0] = 0;
            index = (index + 1) & 0x3ff;
        } while (index != eventTail);
    }
    if (dispatch != 0)
        DispatchMouseEvent(0x200, cursorX, cursorY, 0);
}
