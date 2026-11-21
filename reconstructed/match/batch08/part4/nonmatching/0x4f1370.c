/* List_AppendNode: appends a node to the singly linked list (0x4f1370). */
struct Node {
    char pad[0x70];
    Node *next;                /* 0x70 */
};

struct List2 {
    char pad[0xbc];
    Node *head;                /* 0xbc */
    void AppendNode(Node *node);
};

void List2::AppendNode(Node *node)
{
    Node *head = *(Node **)((char *)this + 0xbc);

    if (head == 0) {
        *(Node **)((char *)this + 0xbc) = node;
        node->next = 0;
        return;
    }
    Node *current = head;
    while (current->next != 0)
        current = current->next;
    current->next = node;
    node->next = 0;
}
