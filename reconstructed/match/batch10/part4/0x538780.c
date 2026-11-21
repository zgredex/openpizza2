/* Renderer_ToggleRenderTarget (0x538780): switches the renderer between the
   back buffer and the primary surface and reinitializes the pixel format. */
struct Surface {
    void InitPixelFormat(void *format, int mode);
};

struct Renderer {
    char pad[0x30];
    char dirty;
    char pad2[0x4c - 0x31];
    int targetState;

    void ReleaseTargets();
    void CopyStateToChildren();
    void ToggleRenderTarget();
};

void Renderer::ToggleRenderTarget()
{
    int local;

    if (targetState == 3)
        return;
    if (targetState == 0) {
        ReleaseTargets();
        targetState = 1;
        ((Surface *)this)->InitPixelFormat(&local, 1);
    } else {
        ReleaseTargets();
        targetState = 0;
        ((Surface *)this)->InitPixelFormat(&local, 1);
    }
    dirty = 1;
    CopyStateToChildren();
}
