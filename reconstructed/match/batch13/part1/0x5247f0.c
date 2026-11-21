/* Window_HandleKeyInput (0x5247f0). */
struct Child {
    virtual int Dummy0();
    virtual int Dummy1();
    virtual int Dummy2();
    virtual int Notify(int message, int key, int extra);
};
struct UI {
    int NotifyObjectsByKey(int key);
    void QueueCommand(int command, int arg1, void *object, int arg2, int arg3);
};
struct Window {
    char pad0[0x14];
    void *objects[0x87];    /* 0x14 .. 0x230 */
    Child *child;           /* 0x230 */
    char pad1[8];           /* to 0x23c */
    int objectCount;        /* 0x23c */
    char pad2[0x80c4];      /* to 0x8304 */
    int dispatcher;         /* 0x8304 */

    void HandleKeyInput(int key);
};

void Window::HandleKeyInput(int key)
{
    int index;

    if (child != 0 && child->Notify(0x20, key, 0) != 0)
        return;
    index = objectCount - 1;
    if (index >= 0) {
        do {
            void *object = objects[index];

            if (object != 0 &&
                ((UI *)object)->NotifyObjectsByKey(key) != 0)
                return;
            index--;
        } while (index >= 0);
    }
    if (dispatcher != 0) {
        ((UI *)this)->QueueCommand(dispatcher, 0, this, 0xe, key);
    }
}
