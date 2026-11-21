/* List_FindByKey: linear search of the node list by key (0x403b90). */
struct Node {
    char pad0[0x10];
    int key;
    Node *next;
};

struct List {
    char pad[0xc];
    Node *head;
    Node *FindByKey(int key);
};

Node *List::FindByKey(int key)
{
    Node *node = head;

    while (node != 0) {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
