/* UI_EnsureChildInitialized: looks up a child record and initializes the
   object it points at (0x531670). */
struct BinarySearch8_t {
    int search(int key, int flag);
};

void __fastcall Object_EnsureInit(void *object);

struct UI {
    char pad[0xe8];
    void **children;
    int EnsureChildInitialized(int key);
};

int UI::EnsureChildInitialized(int key)
{
    int index = ((BinarySearch8_t *)this)->search(key, 0);

    if (index == -1)
        return 0;
    Object_EnsureInit(*(void **)((char *)children + index * 8));
    return 1;
}
