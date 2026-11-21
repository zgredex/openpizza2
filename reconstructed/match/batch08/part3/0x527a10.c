/* UI_RefreshChildSprite: sets or clears the child element sprite
   (0x527a10). */
struct UI {
    void SetElementSprite(void *sprite, int param_2, int param_3);
    void ClearChildExtent();
};

struct Sprite;

struct Container {
    char pad[0x8310];
    UI *element;               /* 0x8310 */
    Sprite *sprite;            /* 0x8314 */
    void RefreshChildSprite(int param_1, int param_2, int param_3);
};

void Container::RefreshChildSprite(int param_1, int param_2, int param_3)
{
    if (param_1 == 0 || *(Sprite **)((char *)this + 0x8314) == 0) {
        ((UI *)*(void **)((char *)this + 0x8310))->ClearChildExtent();
        return;
    }
    ((UI *)*(void **)((char *)this + 0x8310))
        ->SetElementSprite(*(Sprite **)((char *)this + 0x8314), param_2, param_3);
}
