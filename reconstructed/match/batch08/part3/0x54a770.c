/* Window_SetVisible: shows or hides the window (0x54a770). */
extern int (__stdcall *DAT_0055c1ec)(void *window, int command);

struct Window {
    char pad[4];
    void *handle;              /* 0x4 */
    char pad2[0x20 - 8];
    int visible;               /* 0x20 */
    void SetVisible(int visible);
};

void Window::SetVisible(int visible)
{
    void *handle = *(void **)((char *)this + 4);

    if (handle != 0) {
        if (visible != 0) {
            DAT_0055c1ec(handle, 1);
            *(int *)((char *)this + 0x20) = 1;
            return;
        }
        DAT_0055c1ec(handle, 0);
        *(int *)((char *)this + 0x20) = 0;
    }
}
