/* Renderer_DrawPendingSprite: flushes the pending sprite into the target
   rectangle and releases it if requested (0x51eb50). */
extern "C" __declspec(dllimport) int __stdcall SetRect(int *rect, int left,
                                                        int top, int right,
                                                        int bottom);

class Sprite {
public:
    virtual void Destroy(int flag);
    void GetSize(int *width, int *height);
    void Draw(int param, int x, int y);
};

class Renderer {
public:
    int DrawPendingSprite(int param_1, int *param_2);
};

int Renderer::DrawPendingSprite(int param_1, int *param_2)
{
    int width;
    int height;
    int xLeft;

    if (*(void **)((char *)this + 4) == 0) {
        return 0;
    }
    if (*(int *)((char *)this + 0x18) != 0) {
        ((Sprite *)*(void **)((char *)this + 4))->GetSize(&width, &height);
        xLeft = *(int *)((char *)this + 0xc);
        if (xLeft == -9999) {
            return 0;
        }
        SetRect(param_2, xLeft, *(int *)((char *)this + 0x10), width + xLeft,
                height + *(int *)((char *)this + 0x10));
        ((Sprite *)*(void **)((char *)this + 4))
            ->Draw(param_1, *(int *)((char *)this + 0xc),
                   *(int *)((char *)this + 0x10));
        *(int *)((char *)this + 0x18) = 0;
    }
    if ((*(int *)this == 0) && (*(Sprite **)((char *)this + 4) != 0)) {
        ((Sprite *)*(void **)((char *)this + 4))->Destroy(1);
        *(int *)((char *)this + 4) = 0;
    }
    return 1;
}
