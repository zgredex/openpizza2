struct Sprite {
    Sprite(int width, void *arg2, const char *name, int *error,
           int arg5, int arg6, int arg7);
    virtual ~Sprite();
    char pad[0x4c];
};

struct UI {
    char pad0[0x10];
    void *field10;
    char pad1[0x8300 - 0x4];
    void *extent;
    Sprite *sprite;
    void ClearChildExtent();
    Sprite *LoadChildSprite(const char *name);
};

extern int DAT_0057c5c8;

Sprite *UI::LoadChildSprite(const char *name)
{
    ((UI *)extent)->ClearChildExtent();
    if (sprite != 0)
        delete sprite;
    int error;
    Sprite *result = new Sprite(DAT_0057c5c8, field10, name, &error, 0, 0, 0);
    sprite = result;
    if (error != 0) {
        if (result != 0)
            delete result;
        sprite = 0;
        result = 0;
    }
    return result;
}
