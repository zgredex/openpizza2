extern int DAT_0058072c;

struct SparseMap {
    void *Lookup48(int key);
};

struct Sprite {
    void GetHotspot(int *x, int *y);
    void GetSize(int *width, int *height);
};

struct Gfx {
    void BlitRectList(unsigned int *rect);
};

struct UI {
    char pad[4];
    SparseMap *map;
    void AlignSpriteToRect(int *position, void *sprite, int *outX, int *outY);
    void ComputeCenteredRect(int *rect, int *outX, int *outY);
    void DrawObjectWithBounds(int *rect, int *bounds);
};

void UI::DrawObjectWithBounds(int *rect, int *bounds)
{
    int x, y, hotspotX, hotspotY, width, height;
    struct Rect { int left, top, right, bottom; } r;

    if (rect == 0 || rect[2] == 0)
        return;
    void *sprite = ((SparseMap *)map)->Lookup48(*(int *)(rect[2] + 0x10));
    if (sprite != 0) {
        AlignSpriteToRect(rect, sprite, &x, &y);
        ((Sprite *)sprite)->GetHotspot(&hotspotX, &hotspotY);
        ((Sprite *)sprite)->GetSize(&width, &height);
        r.left = hotspotX + x;
        r.top = hotspotY + y;
        r.right = width + r.left;
        r.bottom = height + r.top;
    } else {
        ComputeCenteredRect(rect, &x, &y);
        r.left = x - 0x40;
        r.top = y - 0x40;
        r.right = r.left + 0x80;
        r.bottom = r.top + 0x80;
    }
    if (bounds != 0) {
        r.left -= 0x32;
        bounds[0] = r.left;
        r.top -= 0x32;
        r.right += 0x32;
        bounds[1] = r.top;
        r.bottom += 0x32;
        bounds[2] = r.right;
        bounds[3] = r.bottom;
        return;
    }
    ((Gfx *)DAT_0058072c)->BlitRectList((unsigned int *)&r);
}
