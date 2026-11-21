/* UI_SetWindowVisible: toggles the window visibility and queues the matching
   control command (0x532890). */
struct Window {
    void NotifyMouseMove(void);
};

struct UI {
    void QueueControlCommand(int a, int command, int value);
    void SetWindowVisible(int visible);
};

void UI::SetWindowVisible(int visible)
{
    if (*(int *)((char *)this + 0x4c) != visible) {
        *(int *)((char *)this + 0x4c) = visible;
        ((struct Window *)*(void **)((char *)this + 0x134))->NotifyMouseMove();
        if (*(int *)((char *)this + 0x4c) != 0)
            QueueControlCommand(-1, 0x1f, 0);
        else
            QueueControlCommand(-1, 0x1e, 0);
    }
}
