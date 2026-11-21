/* List_DestroyObjects: destroys and frees every object in a linked list
   (0x540f60). */
typedef void (__stdcall *DestroyMethod)(void *object);

struct ListNode {
    void *object;
    ListNode *next;
    ListNode *prev;
};

struct List {
    char pad[0x38];
    ListNode *head;
    ListNode *tail;
    ListNode *current;
    int count;

    void DestroyObjects();
};

extern "C" void Mem_Free(void *pointer);

void List::DestroyObjects()
{
    ListNode *node = head;
    DestroyMethod method;

    current = node;
    if (node != 0) {
        current = node->next;
        for (;;) {
            void *object = node->object;

            method = (DestroyMethod)(*(void ***)object)[0x48 / 4];
            method(object);
            method = (DestroyMethod)(*(void ***)object)[8 / 4];
            method(object);
            if (current == node) {
                current = current->next;
            }
            if (node->prev == 0) {
                head = node->next;
            } else {
                node->prev->next = node->next;
            }
            if (node == tail) {
                tail = node->prev;
            }
            if (node->next != 0) {
                node->next->prev = node->prev;
            }
            count--;
            Mem_Free(node);
            node = current;
            if (node == 0) {
                break;
            }
            current = node->next;
        }
    }
}
