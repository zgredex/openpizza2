// UI_HitTestChildAtPoint: finds a visible child under a point.

struct Sprite {
    void RealizeLazy();
    int BlitClipped(unsigned short *palette, int x, int y, unsigned int *out);
};

struct UI {
    int IsValidSize(int x, int y);
    void *HitTestChildAtPoint(int *point, int *flags);
};

void *UI::HitTestChildAtPoint(int *point, int *flags)
{
    int index;

    *flags = 1;
    index = *(int *)((char *)this + 0xf0);
    while (--index >= 0) {
        void *child = *(void **)(*(int *)((char *)this + 0xec) + index * 8);
        if (child != 0 &&
            ((UI *)child)->IsValidSize(
                point[0] - *(int *)((char *)this + 0x18),
                point[1] - *(int *)((char *)this + 0x1c)) != 0)
            return child;
    }
    {
        void *sprite = *(void **)((char *)this + 0x50);
        if (sprite != 0) {
            int y = point[1] - *(int *)((char *)this + 0x1c);
            int x = point[0] - *(int *)((char *)this + 0x18);
            int blitted;
            if (*(char *)((int)sprite + 0x39) == 0)
                ((Sprite *)sprite)->RealizeLazy();
            blitted = ((Sprite *)sprite)->BlitClipped(
                *(unsigned short **)((int)sprite + 0x2c), x, y,
                (unsigned int *)0);
            if (blitted == 0) {
                *flags = 0;
                return 0;
            }
        } else {
            sprite = *(void **)((char *)this + 0x94);
            if (sprite != 0) {
                int y = point[1] - *(int *)((char *)this + 0x1c);
                int x = point[0] - *(int *)((char *)this + 0x18);
                int blitted;
                if (*(char *)((int)sprite + 0x39) == 0)
                    ((Sprite *)sprite)->RealizeLazy();
                blitted = ((Sprite *)sprite)->BlitClipped(
                    *(unsigned short **)((int)sprite + 0x2c), x, y,
                    (unsigned int *)0);
                if (blitted == 0)
                    *flags = 0;
            }
        }
    }
    return 0;
}
