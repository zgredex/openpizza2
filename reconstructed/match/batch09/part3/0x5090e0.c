/* UI_DetachChildRecord: detaches a child record from its owning UI object
   (0x5090e0). */
struct Record {
    void ClearFlags48(int value);
};

struct Object {
    void SetShort28(int value);
};

struct UIChild {
    void DetachChildRecord();
};

void UIChild::DetachChildRecord()
{
    char *self = (char *)this;
    int *child = *(int **)(self + 200);

    if (child != 0 && (void *)child[0x16] != 0) {
        ((Record *)child[0x16])->ClearFlags48(*child);
        if (*(int *)(self + 200) != 0)
            *(int *)(*(int *)(self + 200) + 0xc) = -1;
        if (*(int *)((int)*(void **)(self + 200) + 0x18) == 0)
            ((Object *)*(void **)(self + 200))->SetShort28(-1);
    }
}
