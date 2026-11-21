/* List_FreeAll: frees every node and resets the list counters (0x541250). */
struct Node {
    char pad[4];
    Node *next;
};

void __cdecl Mem_Free(void *block);

struct List {
    Node *head;
    char pad[4];
    int count;
    int capacity;
    void FreeAll();
};

void List::FreeAll()
{
    Node *node = head;

    while (node != 0) {
        Node *next = node->next;

        Mem_Free(node);
        node = next;
    }
    head = 0;
    count = 0;
    capacity = 0;
}
