/* RecordList_BlitRecordSprite: blits one record sprite at a screen position
   (0x534880). */
struct Sprite {
    int BlitClipped(unsigned short *frame, int x, int y, unsigned int *flags);
};

struct RecordList {
    void EnsureLoaded();
    bool BlitRecordSprite(int index, int x, int y);
};

bool RecordList::BlitRecordSprite(int index, int x, int y)
{
    int record;
    int sprite;
    int dx;
    int dy;
    unsigned short *frames;

    if (index < 0 || index >= *(int *)((char *)this + 0x48)) {
        return false;
    }
    if (*(int *)(*(int *)((char *)this + 0x4c) + index * 0x48) == -1) {
        return false;
    }
    if (*(char *)((char *)this + 0x35) == '\0') {
        EnsureLoaded();
    }
    record = index * 0x48 + *(int *)((char *)this + 0x4c);
    sprite = *(int *)record;
    dx = (int)(*(double *)(*(int *)((char *)this + 0x50) + sprite * 0x98 + 0x70) +
               *(double *)(record + 8));
    dy = (int)(*(double *)(*(int *)((char *)this + 0x50) + sprite * 0x98 + 0x78) +
               *(double *)(record + 0x10));
    *(unsigned short *)((char *)this + 6) =
        *(unsigned short *)(*(int *)((char *)this + 0x20) + *(short *)(record + 0x32) * 2);
    *(unsigned short *)((char *)this + 8) =
        *(unsigned short *)(*(int *)((char *)this + 0x24) + *(short *)(record + 0x32) * 2);
    *(unsigned short *)((char *)this + 10) =
        *(unsigned short *)(*(int *)((char *)this + 0x28) + *(short *)(record + 0x32) * 2);
    *(unsigned short *)((char *)this + 0xc) =
        *(unsigned short *)(*(int *)((char *)this + 0x2c) + *(short *)(record + 0x32) * 2);
    frames = *(unsigned short **)(*(int *)((char *)this + 0x80) + *(short *)(record + 0x32) * 4);
    return ((Sprite *)this)->BlitClipped(frames, x - dx, y - dy, 0) != 0;
}
