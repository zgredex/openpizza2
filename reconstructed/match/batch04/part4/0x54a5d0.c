/* PC2 byte-match candidate: Window_GetChildAndNotify (0x54a5d0, 27 bytes).
   Build: /O2 /TP.  Queries the child through its operation table. */
struct Window;
struct Child;

struct ChildOps {
    unsigned char pad_000[8];
    void (__stdcall *query)(Child *self, Child **out);
};

struct Child {
    ChildOps *ops;
};

struct Window {
    unsigned char pad_000[8];
    Child *child;
};

Child *__fastcall Window_GetChildAndNotify(Window *window)
{
    Child *child = window->child;
    if (child == 0)
        return 0;
    Child *result;
    child->ops->query(child, &result);
    return result;
}
