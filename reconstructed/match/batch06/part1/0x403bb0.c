/* Timer_RemoveById: unlinks and releases the entry with the given id (0x403bb0). */
struct TimerNode {
    int pad0[4];
    int key;
    TimerNode *next;
};

struct Timer {
    int pad0[3];
    TimerNode *head;
    int RemoveEntry(TimerNode *node);
    int RemoveById(int id);
};

int Timer::RemoveById(int id)
{
    TimerNode *node = head;

    while (node != 0) {
        if (node->key == id) {
            return RemoveEntry(node);
        }
        node = node->next;
    }
    return 0;
}
