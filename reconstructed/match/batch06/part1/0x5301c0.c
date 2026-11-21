/* UI_QueueControlCommand: queues a control command on the command object (0x5301c0). */
struct UI {
    char pad0[0x48];
    int command;
    char pad1[0x134 - 0x4c];
    UI *queue;
    void QueueCommand(int command, void *owner, int first, int second, int third);
    void QueueControlCommand(int first, int second, int third);
};

void UI::QueueControlCommand(int first, int second, int third)
{
    if (command != 0) {
        queue->QueueCommand(command, this, first, second, third);
    }
}
