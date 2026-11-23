/* UI_SetWaitCursor: sets or clears the wait cursor, synchronising with the
   UI thread when called from another thread (0x527d10). */
extern "C" __declspec(dllimport) void *__stdcall LoadCursorA(void *instance,
                                                            const char *name);
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall SetClassLongA(void *window,
                                                             int index,
                                                             long value);
extern "C" __declspec(dllimport) void *__stdcall SetCursor(void *cursor);
extern "C" __declspec(dllimport) int __stdcall ResetEvent(void *event);
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void *window,
                                                           unsigned int msg,
                                                           unsigned long wparam,
                                                           long lparam);
extern "C" __declspec(dllimport) unsigned long __stdcall
WaitForSingleObject(void *handle, unsigned long milliseconds);

extern int DAT_0057ba14;
extern int DAT_0057c480;

class UI {
public:
    void SetWaitCursor(int wait);
};

void UI::SetWaitCursor(int param_1)
{
    void *hCursor;
    unsigned long DVar1;

    if (param_1 != 0) {
        hCursor = LoadCursorA(0, (const char *)0x7f00);
    } else {
        hCursor = 0;
    }
    DVar1 = GetCurrentThreadId();
    if (DVar1 == DAT_0057ba14) {
        SetClassLongA(*(void **)((char *)this + 0x8320), -0xc, (long)hCursor);
        SetCursor(hCursor);
        return;
    }
    ResetEvent(*(void **)((char *)this + 0x8354));
    do {
        if (DAT_0057c480 != 0) {
            return;
        }
        PostMessageA(*(void **)((char *)this + 0x8320), 0x400, 0,
                     (long)hCursor);
        DVar1 = WaitForSingleObject(*(void **)((char *)this + 0x8354), 500);
    } while (DVar1 == 0x102);
}
