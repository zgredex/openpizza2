/* List_RemoveByValue (0x539e20): unlinks and frees the first node whose value
   matches. */
extern "C" {
void Mem_Free(void *block);
}

struct ListNode {
    int value;
    ListNode *next;
};

struct List {
    char pad[0x50];
    ListNode *head;

    void RemoveByValue(int value);
};

void List::RemoveByValue(int value)
{
    ListNode *previous = 0;
    ListNode *node = head;

    while (node != 0) {
        if (node->value == value)
            break;
        previous = node;
        node = node->next;
    }
    if (node != 0) {
        if (previous == 0) {
            head = node->next;
            Mem_Free(node);
            return;
        }
        previous->next = node->next;
        Mem_Free(node);
    }
}
