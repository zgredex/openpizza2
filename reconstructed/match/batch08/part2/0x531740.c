/* UI_RemoveObjectByKey: removes an object from the child array and marks the
   UI dirty (0x531740). */
void __fastcall UI_ClearPendingClipFlag(int object);

struct UI {
    char pad[0xe0];
    int dirty;
    char pad2[4];
    int *children;
    int BinarySearch8(int key, char zero);
    int RemoveObjectByKey(int key);
};

int UI::RemoveObjectByKey(int key)
{
    int index = BinarySearch8(key, 0);

    if (index == -1)
        return 0;
    UI_ClearPendingClipFlag(*(int *)(*(int *)((char *)this + 0xe8) + index * 8));
    *(int *)((char *)this + 0xe0) = 1;
    return 1;
}
