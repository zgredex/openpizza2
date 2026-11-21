/* List_Construct (0x4013a0): constructs a list with the given capacity,
   allocating and clearing the two entry arrays. */
extern "C" {
void *operator_new(unsigned int size);
void *memset(void *dest, int value, unsigned int count);
}

extern int DAT_0055c2ec;

struct List {
    void *vtable;
    void *entries;
    void *flags;
    int count;
    unsigned int capacity;
    int field14;
    int limit;

    List *Construct(unsigned int capacity);
};

List *List::Construct(unsigned int capacity)
{
    vtable = (void *)&DAT_0055c2ec;
    if (capacity == 0) {
        entries = 0;
        flags = 0;
        this->capacity = 0;
        count = 0;
        field14 = 0;
        limit = 100000;
        return this;
    }
    entries = operator_new(capacity * 4);
    flags = operator_new(capacity * 4);
    memset(flags, 0, capacity * 4);
    count = 0;
    field14 = 0;
    this->capacity = capacity;
    limit = 100000;
    return this;
}
