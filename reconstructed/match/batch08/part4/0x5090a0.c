/* MapObject_SetRecordFrame: applies a variant frame to the child record
   (0x5090a0). */
struct Record {
    void ApplyVariantState(void *sprite, int frame, int flag);
};

struct MapObject {
    void SetRecordFrame(int frame);
};

void MapObject::SetRecordFrame(int frame)
{
    int *child = *(int **)((char *)this + 0xc8);

    if (child != 0 && (void *)child[0x16] != 0 && frame != -1) {
        ((Record *)child[0x16])->ApplyVariantState((void *)child[0], frame, 1);
        if (*(int *)((char *)this + 0xc8) != 0)
            *(int *)(*(int *)((char *)this + 0xc8) + 0xc) = frame;
    }
}
