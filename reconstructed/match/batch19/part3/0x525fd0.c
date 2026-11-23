/* Window_DispatchWindowMessage (0x525fd0). */

extern void *DAT_0057c0d8;
extern "C" __declspec(dllimport) int __stdcall SetEvent(void *event);

struct UI {
    void RemoveObject(unsigned param);
    void QueueCommand(int command, int a, void *self, int b, int c);
    void UpdateChildLayout();
    void DispatchMouseEvent(unsigned msg, int param, unsigned lparam);
};

struct Window {
    char pad0[0x8304];
    int command;                /* 0x8304 */

    void HandleKeyInput(int key);
    void DispatchMouseEvent(unsigned msg, int x, int y, unsigned param);
    void DispatchWindowMessage(unsigned msg, void *wparam, unsigned lparam);
};

void Window::DispatchWindowMessage(unsigned msg, void *wparam, unsigned lparam)
{
    switch (msg) {
    case 500:
        ((UI *)wparam)->RemoveObject(lparam);
        return;
    case 0x100:
        HandleKeyInput((int)wparam);
        return;
    case 0x102:
        HandleKeyInput((int)wparam);
        return;
    case 0x104:
        if (wparam == (void *)0x58 || wparam == (void *)0x73) {
            if (command != 0) {
                ((UI *)this)
                    ->QueueCommand(command, 0, this, 0x17, (int)wparam);
                return;
            }
            SetEvent(DAT_0057c0d8);
            return;
        }
        if (wparam == (void *)0x79) {
            ((UI *)this)->UpdateChildLayout();
            return;
        }
        return;
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x204:
    case 0x205:
        DispatchMouseEvent(msg, lparam & 0xffff, lparam >> 16, (unsigned)wparam);
        return;
    case 0x20a:
        ((UI *)this)->DispatchMouseEvent(msg, (int)wparam, lparam);
        return;
    }
}
