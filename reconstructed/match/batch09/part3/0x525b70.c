/* EventQueue_SetEntryState22: marks matching queued events with state 0x22
   (0x525b70). */
struct EventQueue {
    void SetEntryState22(int id);
};

void EventQueue::SetEntryState22(int id)
{
    char *self = (char *)this;
    unsigned int index = *(unsigned int *)(self + 0x82bc);

    if (index != *(unsigned int *)(self + 0x82c0)) {
        do {
            if (*(int *)(self + index * 0x14 + 0x32c0) == id)
                *(int *)(self + (index * 5 + 0xcb2) * 4) = 0x22;
            index = (index + 1) & 0x3ff;
        } while (index != *(unsigned int *)(self + 0x82c0));
    }
}
