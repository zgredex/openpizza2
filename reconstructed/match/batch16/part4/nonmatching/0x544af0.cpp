extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);

void __cdecl operator delete(void *object);

class LockGuard {
    void *section;
public:
    LockGuard(void *value) : section(value) { EnterCriticalSection(value); }
    ~LockGuard() { LeaveCriticalSection(section); }
};

struct ListPayload {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
};

struct LockedListNode {
    ListPayload *payload;
    LockedListNode *next;
    LockedListNode *previous;
};

struct LockedList {
    char pad[0x08];
    LockedListNode *head;
    LockedListNode *tail;
    LockedListNode *current;
    int count;
    char lock[0x18];

    void RemoveNodeLocked(LockedListNode *node);
};

void LockedList::RemoveNodeLocked(LockedListNode *node)
{
    LockGuard guard(&lock);
    if (node != 0) {
        node->payload->slot1();
        current = (current == node) ? current->next : current;

        LockedListNode *previous = node->previous;
        if (previous != 0)
            previous->next = node->next;
        else
            head = node->next;

        if (node == tail)
            tail = node->previous;

        LockedListNode *next = node->next;
        if (next != 0)
            next->previous = node->previous;

        --count;
        ::operator delete(node);
    }
}
