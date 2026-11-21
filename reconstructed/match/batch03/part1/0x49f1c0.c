/* UI_RemoveObjectByOffsetKey: removes a UI object whose id has a +100000 bias (0x49f1c0). */
struct UI {
    void RemoveObjectByKey(int key);
};

void __cdecl UI_RemoveObjectByOffsetKey(void *ui, int key)
{
    ((UI *)ui)->RemoveObjectByKey(key + 0x186a0);
}
