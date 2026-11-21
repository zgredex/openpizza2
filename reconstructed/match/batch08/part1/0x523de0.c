/* UI_RefreshAndCenter: renders the scene and centers the surface copy
   (0x523de0). */
void __fastcall CS_Enter(void *section);
void __fastcall CS_Leave(void *section);

struct Surface {
    void CopyRect16(int source, int x, int y);
};

struct UI {
    char pad0[0xc];
    int surface;
    char pad1[0x1b8];
    void *lock;
    void RenderScene();
    void RefreshAndCenter(struct Surface *target);
};

void UI::RefreshAndCenter(struct Surface *target)
{
    CS_Enter(lock);
    RenderScene();
    target->CopyRect16(*(int *)((char *)this + 0xc), 0, 0);
    CS_Leave(lock);
}
