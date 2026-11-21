/* List_RemoveObject (0x4f13d0): unlinks the given object from the linked
   object list, updating its state first. */
struct List {
    char pad[0xbc];
    int head;

    void UpdateState(int object);
    int RemoveObject(int object);
};

int List::RemoveObject(int object)
{
    int found = 0;
    int result = 1;
    int node;
    int next;

    if (head == 0)
        return 0;
    UpdateState(object);
    node = head;
    if (node == object) {
        head = *(int *)(node + 0x70);
        return result;
    }
    for (;;) {
        next = *(int *)(node + 0x70);
        for (;;) {
            if (next == 0)
                return 0;
            if (found) {
                if (next == 0)
                    return 0;
                *(int *)(node + 0x70) = *(int *)(next + 0x70);
                return result;
            }
            if (next != object)
                break;
            found = 1;
        }
        node = next;
    }
}
