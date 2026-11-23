/* UI_RenderScene (0x523e20). */

extern "C" void NoOp_Stub(int message);

struct Surface {
    int LockAndMark();
    int GetDescription(int description, int *out);
    void InitFromBuffer(int buffer, int width, int height, int param);
    void IsReady(int description);
    void ConfigureFromOwner(void *owner);
};

struct UI {
    void EnsureBackBufferWindow(void *surface);
};

struct Renderer {
    char pad0[0x0c];
    Surface *surface;           /* 0x0c */
    char pad1[0x1a4];
    int mode1b4;                /* 0x1b4 */
    char pad1b8[4];
    void *owner1bc;             /* 0x1bc */
    int description;            /* 0x1c0 */
    char pad2[0xac];
    int width;                  /* 0x270 */
    int height;                 /* 0x274 */
    char pad3[0x8134];
    void *window83ac;           /* 0x83ac */
    char pad4[8];
    int flag83b8;               /* 0x83b8 */
};

extern "C" int __fastcall UI_RenderScene(Renderer *self)
{
    int local;

    if (self->window83ac != 0 && self->flag83b8 != 0) {
        ((UI *)self->window83ac)
            ->EnsureBackBufferWindow(self->surface);
        return 1;
    }
    if (self->mode1b4 != 0) {
        if (self->surface->LockAndMark() == 0)
            return 0;
        int nested = *(int *)((char *)self->surface + 0x40);

        if (nested != 0)
            self->surface->IsReady(*(int *)(nested + 8));
        else
            self->surface->IsReady(nested);
        return 1;
    }
    if (self->owner1bc != 0) {
        ((Surface *)self->owner1bc)->ConfigureFromOwner(self->surface);
        return 1;
    }
    if (self->description == 0)
        NoOp_Stub(0x574204);
    int desc = self->surface->GetDescription(self->description, &local);

    if (desc == 0)
        return 0;
    self->surface->InitFromBuffer(desc, self->width, self->height, local);
    self->surface->IsReady(self->description);
    return 1;
}
