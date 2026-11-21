/* UI_RefreshChildRect: refreshes the cached rectangle of the child window
   (0x527380). */
struct RectData {
    int left;
    int top;
    int right;
    int bottom;
};

struct Rect {
    void Set1A4(RectData *value);
};

struct Window {
    void GetRect(RectData *value);
};

struct Renderer {
    void ReleaseTarget();
};

void __fastcall UI_RefreshChildRect(void *self)
{
    if (*(int *)((char *)*(void **)((char *)self + 0x244) + 0x14) != 0) {
        RectData rect;
        (*(Window **)((char *)self + 0x244))->GetRect(&rect);
        (*(Renderer **)((char *)self + 0x244))->ReleaseTarget();
        ((Rect *)self)->Set1A4(&rect);
    }
}
