/* Array_GetRectByKey: returns the width and height of the child with the
   requested key (0x531570). */
struct ArrayHelper {
    int BinarySearch8(int key, char flag);
};

struct Array {
    char pad[0xe8];
    void *items;

    int GetRectByKey(int key, int *width, int *height);
};

int Array::GetRectByKey(int key, int *width, int *height)
{
    int index = ((ArrayHelper *)this)->BinarySearch8(key, 0);
    char *object;

    if (index == -1)
        return 0;
    object = (char *)*(void **)((char *)items + index * 8);
    *width = *(int *)(object + 0x30) - *(int *)(object + 0x28);
    object = (char *)*(void **)((char *)items + index * 8);
    *height = *(int *)(object + 0x34) - *(int *)(object + 0x2c);
    return 1;
}
