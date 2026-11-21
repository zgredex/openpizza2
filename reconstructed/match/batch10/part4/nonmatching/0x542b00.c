/* List_Remove (0x542b00): unlinks a node from the doubly linked list and
   decrements the element count. */
struct ListNode {
    int value;
    ListNode *next;
    ListNode *prev;
};

struct List {
    ListNode *head;
    ListNode *tail;
    ListNode *link;
    int count;

    void Remove(ListNode *node);
};

void List::Remove(ListNode *node)
{
    if (link == node)
        link = node->next;
    if (node->prev != 0)
        node->prev->next = node->next;
    else
        head = node->next;
    if (node == tail)
        tail = node->prev;
    if (node->next != 0)
        node->next->prev = node->prev;
    count = count - 1;
}
