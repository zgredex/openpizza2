/* UI_PurgeChildFromLists: removes a value from every child list (0x532850). */
struct Array {
    void *GetPtr(int index);
    void RemoveValueLocked(int value);
};

struct UI {
    char pad[0x148];
    int count;
    void PurgeChildFromLists(int value);
};

void UI::PurgeChildFromLists(int value)
{
    int count = *(int *)((char *)this + 0x158);
    int index = 0;

    while (index < count) {
        int record =
            (int)((struct Array *)((char *)this + 0x148))->GetPtr(index);

        ((struct Array *)(record + 4))->RemoveValueLocked(value);
        index++;
    }
}
