/* MapBadgeAnim_SetWindow: binds the badge animation to a window (0x54bcc0). */
struct UI {
    void *GetWindowObject(int key);
    void UpdateAnimatedSprites(void *object);
};

struct MapBadgeAnim {
    int pad0;
    void *object;
    char pad[0x1a8 - 8];
    UI *window;
    void SetWindow(UI *owner, int key);
};

void MapBadgeAnim::SetWindow(UI *owner, int key)
{
    void *object;

    window = owner;
    object = owner->GetWindowObject(key);
    this->object = object;
    ((UI *)this)->UpdateAnimatedSprites(object);
}
