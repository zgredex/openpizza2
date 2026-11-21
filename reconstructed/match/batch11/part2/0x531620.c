/* Array_ToggleObjectActive: toggles the pending state of an array element
   (0x531620). */
struct ArrayHelper {
    int BinarySearch8(int key, char flag);
};

struct ObjectHelper {
    void EnsureInit();
    void ClearPendingCommand();
};

struct Array {
    char pad[0xe8];
    void *items;

    int ToggleObjectActive(int key, int active);
};

int Array::ToggleObjectActive(int key, int active)
{
    int index = ((ArrayHelper *)this)->BinarySearch8(key, 0);

    if (index == -1)
        return 0;
    if (active != 0) {
        ((ObjectHelper *)*(void **)((char *)items + index * 8))->EnsureInit();
        return 1;
    }
    ((ObjectHelper *)*(void **)((char *)items + index * 8))
        ->ClearPendingCommand();
    return 1;
}
