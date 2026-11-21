/* UI_ContextMenu_Destroy: destroys the context menu's owned objects and
   entries (0x528700). */
struct Object {
    virtual void Destroy(int flag);
};

void Mem_Free(void *block);

struct ContextMenu {
    void *vtable;
    struct Object *entries[9];
    char pad[0x50 - 0x28];
    struct Object *owner;
    struct Object *target;
    char pad2[0x68 - 0x58];
    void *data;

    void Destroy();
};

void ContextMenu::Destroy()
{
    int i;

    vtable = (void *)0x55c788;
    if (owner != 0) {
        owner->Destroy(1);
    }
    if (target != 0) {
        target->Destroy(1);
    }
    if (data != 0) {
        Mem_Free(data);
    }
    for (i = 0; i < 9; i++) {
        if (entries[i] != 0) {
            entries[i]->Destroy(1);
        }
        entries[i] = 0;
    }
}
