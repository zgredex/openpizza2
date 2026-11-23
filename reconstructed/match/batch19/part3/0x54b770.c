/* UI_DrawOverlaySprites (0x54b770). */

struct IDMapHelper {
    char pad[0x1c];

    void *Lookup(int key, int *out);
};

struct Sprite {
    void Draw(int frame, unsigned *palette, int flags);
};

struct OverlaySprites {
    char pad0[4];
    IDMapHelper maps[8];

    void DrawOverlaySprites(int frame, int set, void *a, int b, int c, int d);
};

void OverlaySprites::DrawOverlaySprites(int frame, int set, void *a, int b,
                                        int c, int d)
{
    void *first;
    void *second;
    void *fourth;

    if (set == 0) {
        first = maps[0].Lookup((int)a, 0);
        second = maps[2].Lookup(b, 0);
        a = maps[4].Lookup(c, 0);
        fourth = maps[6].Lookup(d, 0);
    } else {
        first = maps[1].Lookup((int)a, 0);
        second = maps[3].Lookup(b, 0);
        a = maps[5].Lookup(c, 0);
        fourth = maps[7].Lookup(d, 0);
    }
    if (first != 0)
        ((Sprite *)first)->Draw(frame, 0, 0);
    if (fourth != 0)
        ((Sprite *)fourth)->Draw(frame, 0, 0);
    if (second != 0)
        ((Sprite *)second)->Draw(frame, 0, 0);
    if (a != 0)
        ((Sprite *)a)->Draw(frame, 0, 0);
}
