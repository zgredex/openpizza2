/* UI_QueueChildCommand: forwards a two-argument command to the active child
   through the UI command queue (0x528190).  Build: /O2 /TP. */
struct Child;

struct UI {
    char pad[0x8304];
    Child *activeChild;
    int QueueCommand(Child *child, int a, int b, int c, int d);
    int QueueChildCommand(int first, int second);
};

int UI::QueueChildCommand(int first, int second)
{
    if (activeChild == 0)
        return 0;
    QueueCommand(activeChild, 0, 0, first, second);
    return 1;
}
