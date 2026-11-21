/* Renderer_FlushTarget (0x52e850, 46 bytes).  Build: /O2 /TP.
   Draws the pending sprite surface and clears the flush counter. */
struct Sprite {
    void Draw(int target, void *surface, int value);
};

struct Renderer {
    void FlushTarget(int target);
};

void Renderer::FlushTarget(int target)
{
    if (*(int *)((char *)this + 0x14) != 0 && *(void **)((char *)this + 0x20) != 0) {
        ((Sprite *)*(void **)((char *)this + 0x20))->Draw(
            target, *(void **)((char *)this + 0xc), *(int *)((char *)this + 0x10));
        *(int *)((char *)this + 0x3c) = 0;
    }
}
