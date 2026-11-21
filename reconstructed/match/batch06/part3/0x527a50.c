/* UI_ReleasePendingSprite: clears the child extent and releases the pending
   sprite through its virtual destructor (0x527a50).  Build: /O2 /TP. */
struct UI {
    void ClearChildExtent();
};

struct Sprite {
    virtual void Destroy(int mode);
};

struct Panel {
    char pad[0x8310];
    UI *extent;
    Sprite *pending;
    void ReleasePendingSprite();
};

void Panel::ReleasePendingSprite()
{
    extent->ClearChildExtent();
    if (pending != 0)
        pending->Destroy(1);
    pending = 0;
}
