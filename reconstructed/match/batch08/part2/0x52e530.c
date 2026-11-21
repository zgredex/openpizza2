/* UI_Tooltip_Destroy: releases the tooltip resources and restores the vtable
   (0x52e530). */
void Mem_Free(void *block);

struct UI {
    void ReleaseRefCount(int index);
};

struct VObject {
    virtual void Destroy(int flag);
};

struct UI_Tooltip {
    void *vtable;
    char pad[0x14];
    int refIndex;
    int object;
    char pad2[0x10];
    void *block;
    void *owner;
    void Destroy();
};

void UI_Tooltip::Destroy()
{
    vtable = (void *)0x55c804;
    if (refIndex != 0)
        (*(struct UI **)((char *)this + 0x38))->ReleaseRefCount(refIndex);
    if (block != 0)
        Mem_Free(block);
    if (object != 0)
        ((struct VObject *)object)->Destroy(1);
}
