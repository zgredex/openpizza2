/* UI_ReplaceActiveObject: swaps the active movie object (0x523900). */
struct Movie {
    void ReleasePlayer();
};

struct UI {
    void MarkFullRectDirty();
    void ReplaceActiveObject(int object);
};

void UI::ReplaceActiveObject(int object)
{
    ((Movie *)this)->ReleasePlayer();
    *(int *)((char *)this + 0x1c4) = object;
    *(int *)((char *)this + 0x83b8) = 1;
    MarkFullRectDirty();
}
