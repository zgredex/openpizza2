/* List_PushFront: prepends a value node to a list (0x539e00). */
void *operator new(unsigned int size);

struct ListNode {
    void *value;
    ListNode *next;
};

struct List {
    char pad[0x50];
    ListNode *head;
    void PushFront(void *value);
};

void List::PushFront(void *value)
{
    ListNode *node = (ListNode *)operator new(8);

    node->value = value;
    node->next = head;
    head = node;
}
