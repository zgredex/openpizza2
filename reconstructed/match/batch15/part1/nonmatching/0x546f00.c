/* List_Insert: inserts a node at the head or tail of a doubly linked list
   (0x546f00). */
struct ListNode {
    void *object;
    ListNode *next;
    ListNode *prev;
};

struct List {
    ListNode *head;
    ListNode *tail;
    ListNode *last;
    int count;

    void Insert(ListNode *node, char atTail);
};

void List::Insert(ListNode *node, char atTail)
{
    if (atTail != 0) {
        node->prev = tail;
        node->next = 0;
        if (tail != 0) {
            tail->next = node;
        }
        if (last == tail) {
            last = node;
        }
        tail = node;
        if (head == 0) {
            count++;
            head = node;
            return;
        }
    } else {
        node->prev = 0;
        node->next = head;
        if (head != 0) {
            head->prev = node;
        }
        if (last == head) {
            last = node;
        }
        head = node;
        if (tail == 0) {
            tail = node;
        }
    }
    count++;
}
