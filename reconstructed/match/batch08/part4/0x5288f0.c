/* UI_FinishDragAndExpandDirtyRect: finishes a drag and expands the dirty
   rectangle (0x5288f0). */
struct RectData {
    int left;
    int top;
    int right;
    int bottom;
};

struct Rect {
    void Set1A4(RectData *value);
};

struct UI {
    void QueueControlCommand(int command, int a, int b);
    void GetOuterRect(RectData *value);
};

struct UIDrag {
    void FinishDragAndExpandDirtyRect(void *target);
};

void UIDrag::FinishDragAndExpandDirtyRect(void *target)
{
    if (*(int *)((char *)this + 0x48) != -1)
        ((UI *)*(void **)((char *)this + 0x58))
            ->QueueControlCommand(*(int *)((char *)this + 0x48), 4, 0);
    RectData rect;
    ((UI *)this)->GetOuterRect(&rect);
    ((Rect *)target)->Set1A4(&rect);
}
