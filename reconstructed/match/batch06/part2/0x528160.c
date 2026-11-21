/* UI_ResetScrollPosition: restores the saved scroll position under the lock (0x528160). */
struct CS {
    void Enter();
    void Leave();
};

struct UI {
    char pad0[0x1cc];
    CS lock;
    char pad1[0x82bc - 0x1d0];
    int scrollPosition;
    int savedScrollPosition;
    void ResetScrollPosition();
};

void UI::ResetScrollPosition()
{
    lock.Enter();
    scrollPosition = savedScrollPosition;
    lock.Leave();
}
