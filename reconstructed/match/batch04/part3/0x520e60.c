/* UI_ClearPendingClipFlag: clears the clip flag and applies the clip rectangle (0x520e60). */
struct UI {
    void ClipRect(int *rect, int enable);
};

struct ClipOwner {
    char pad[8];
    UI *renderer;
    char pad2[0x14];
    int clipPending;
    int pad3;
    int clipRect[1];
};

void __fastcall UI_ClearPendingClipFlag(ClipOwner *owner)
{
    if (owner->clipPending != 0) {
        owner->clipPending = 0;
        owner->renderer->ClipRect(owner->clipRect, 1);
    }
}
