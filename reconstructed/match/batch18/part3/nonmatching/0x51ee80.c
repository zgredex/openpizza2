/* Renderer_ApplySpriteTint: rotates and optionally fills a sprite while
   keeping its union rect up to date (0x51ee80). */
struct Sprite {
    void GetSize(int *width, int *height);
    void Rotate(int angle);
    int FillColor8();
};

struct CS {
    void Enter();
    void Leave();
};

struct Rect {
    char pad[0x1c8];
    CS *lock;
    void Union(int left, int top, int right, int bottom);
};

struct Renderer {
    Sprite *sprite;
    int pad4;
    Rect *scene;
    int left;
    int top;
    int pad14;
    int enabled;
    char pad1[8];
    int filled;
    void ApplySpriteTint(int angle, int filled);
};

void Renderer::ApplySpriteTint(int angle, int filled)
{
    int width;
    int height;

    if (sprite != 0) {
        scene->lock->Enter();
        sprite->GetSize(&width, &height);
        if (enabled != 0) {
            scene->Union(left, top, width + left, height + top);
        }
        sprite->Rotate((this->filled != 0 && filled == 0) ? angle + 8 : angle);
        this->filled = filled;
        if (filled != 0) {
            sprite->FillColor8();
        }
        sprite->GetSize(&width, &height);
        if (enabled != 0) {
            scene->Union(left, top, width + left, height + top);
        }
        scene->lock->Leave();
    }
}
