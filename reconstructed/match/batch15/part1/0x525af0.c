/* UI_ProcessCommandQueue: dispatches every queued UI command (0x525af0). */
struct Command {
    void (__cdecl *handler)(int, int, int, int);
    int arg1;
    int arg2;
    int type;
    int arg4;
};

struct UI {
    char pad[0x32bc];
    int queue[0x400 * 5];
    int head;
    int tail;

    void ProcessCommandQueue();
};

void UI::ProcessCommandQueue()
{
    int index = head;

    while (index != tail) {
        int *base = (int *)this;
        int type = base[index * 5 + 0xcb2];

        if (type != 0x22) {
            Command *command = (Command *)(base + index * 5 + 0xcaf);
            void (__cdecl *handler)(int, int, int, int) = command->handler;
            int arg1 = command->arg1;
            int arg2 = command->arg2;
            int arg4 = base[index * 5 + 0xcb3];

            head = (index + 1) & 0x3ff;
            handler(arg1, arg2, type, arg4);
        } else {
            head = (index + 1) & 0x3ff;
        }
        index = head;
    }
}
