/* Window_DefaultProc (0x525270). */
struct Window {
    void HandleMessage(void *hwnd, unsigned message, unsigned wParam,
                       long lParam);
};
extern "C" void *DAT_0057c0d8;
extern "C" unsigned DAT_00584504;
extern "C" {
__declspec(dllimport) int __stdcall SetEvent(void *event);
__declspec(dllimport) void __stdcall PostQuitMessage(int code);
__declspec(dllimport) long __stdcall GetWindowLongA(void *hwnd, int index);
__declspec(dllimport) long __stdcall DefWindowProcA(void *hwnd, unsigned message,
                                                   unsigned wParam, long lParam);
}

extern "C" void __stdcall Window_DefaultProc(void *hwnd, unsigned message,
                                             unsigned wParam, long lParam)
{
    void *window;

    switch (message) {
    case 2:
        SetEvent(DAT_0057c0d8);
        PostQuitMessage(0);
        break;
    case 0x1c:
        DAT_00584504 = wParam;
        break;
    }
    window = (void *)GetWindowLongA(hwnd, -0x15);
    if (window == 0) {
        DefWindowProcA(hwnd, message, wParam, lParam);
        return;
    }
    ((struct Window *)window)->HandleMessage(hwnd, message, wParam, lParam);
}
