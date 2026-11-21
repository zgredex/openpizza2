/* Array_Grow (0x54b3d0). */
extern "C" void *operator_new(unsigned size);
extern "C" void Mem_Free(void *pointer);
extern "C" void *memcpy(void *dest, const void *source, unsigned count);

struct Array {
    void **items;
    int count;
    int capacity;

    int Grow(void *value);
};

int Array::Grow(void *value)
{
    if (count >= capacity) {
        void **grown = (void **)operator_new(capacity * 4 + 0x50);

        memcpy(grown, items, count * 4);
        Mem_Free(items);
        items = grown;
        capacity = capacity + 0x14;
    }
    items[count] = value;
    count = count + 1;
    return count - 1;
}
