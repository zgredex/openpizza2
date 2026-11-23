void *operator new(unsigned int);
void operator delete(void *);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct CriticalSection {
    char storage[0x58];
    void Enter();
    void Leave();
};

extern CriticalSection g_listLock;

struct List {
    char pad[4];
    int *arrayA;
    int *arrayB;
    int count;
    int capacity;
    int field14;
    int field18;

    int Add(int value);
};

int List::Add(int value)
{
    g_listLock.Enter();
    if (count >= capacity) {
        if (arrayA == 0) {
            arrayA = (int *)operator new(0x50);
            arrayB = (int *)operator new(0x50);
        } else {
            int *newA = (int *)operator new(capacity * 4 + 0x50);
            memcpy(newA, arrayA, capacity * 4);
            int *newB = (int *)operator new(capacity * 4 + 0x50);
            memcpy(newB, arrayB, capacity * 4);
            operator delete(arrayA);
            arrayA = newA;
            operator delete(arrayB);
            arrayB = newB;
        }
        capacity += 0x14;
    }
    arrayA[count] = value;
    arrayB[count] = field18;
    ++field18;
    ++count;
    ++field14;
    g_listLock.Leave();
    return field18 - 1;
}
