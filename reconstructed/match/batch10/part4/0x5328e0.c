/* UI_TickChildRepeatTimer (0x5328e0): decrements a child's repeat timer and
   queues the repeat command when it expires. */
struct UI {
    char pad[0x29c];
    int repeatEnabled;
    int repeatInterval;
    int repeatTimer;

    void QueueControlCommand(int command, int code, int value);
    void TickChildRepeatTimer(int delta);
};

void UI::TickChildRepeatTimer(int delta)
{
    if (repeatEnabled != 0) {
        repeatTimer -= delta;
        if (repeatTimer < 0) {
            QueueControlCommand(-1, 0x1d, 0);
            repeatTimer += repeatInterval;
        }
    }
}
