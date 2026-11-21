/* Win32_PumpMessages (0x539700). */
struct MSG {
    int hwnd;
    unsigned message;
    unsigned wParam;
    long lParam;
    unsigned time;
    int x;
    int y;
};
extern "C" {
__declspec(dllimport) int __stdcall PeekMessageA(struct MSG *msg, void *hwnd,
                                                unsigned first,
                                                unsigned last,
                                                unsigned remove);
__declspec(dllimport) int __stdcall GetMessageA(struct MSG *msg, void *hwnd,
                                               unsigned first,
                                               unsigned last);
__declspec(dllimport) int __stdcall TranslateMessage(const struct MSG *msg);
__declspec(dllimport) long __stdcall DispatchMessageA(const struct MSG *msg);
}

extern "C" void Win32_PumpMessages()
{
    struct MSG msg;
    int haveMessage = PeekMessageA(&msg, 0, 0, 0, 0);

    while (haveMessage != 0 && GetMessageA(&msg, 0, 0, 0) != 0) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
        haveMessage = PeekMessageA(&msg, 0, 0, 0, 0);
    }
}
