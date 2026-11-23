/* Dialog::InitBase (0x52ee10). */
extern "C" __declspec(dllimport) int SetRect(void *rect, int left, int top, int right, int bottom);

struct Renderer {
    void *CreateChild(void *parent);
};

struct Dialog {
    char pad[0x300];
    void InitBase(void *renderer, int param2, int param3);
};

void Dialog::InitBase(void *renderer, int param2, int param3)
{
    int *p = (int *)this;

    p[0x4 / 4] = 0;
    p[0x2c0 / 4] = 0;
    p[0x29c / 4] = 0;
    p[0xd8 / 4] = 0;
    p[0x2bc / 4] = 0;
    p[0x13c / 4] = 0;
    p[0xf8 / 4] = 0;
    p[0x16c / 4] = 0;
    p[0x48 / 4] = param3;
    p[0xe4 / 4] = 1;
    p[0x4c / 4] = 0;
    p[0x15c / 4] = 0;
    p[0x10c / 4] = 0;
    p[0x164 / 4] = 1;
    ((char *)this)[0x178] = 0;
    p[0x50 / 4] = 0;
    p[0x94 / 4] = 0;
    ((char *)this)[0x54] = 0;
    p[0x160 / 4] = 0;
    p[0xe0 / 4] = 1;
    p[0xec / 4] = 0;
    p[0x170 / 4] = 0;
    p[0x134 / 4] = param2;
    p[0x114 / 4] = 0;
    p[0xf0 / 4] = 0;
    p[0xf4 / 4] = 0;
    p[0xe8 / 4] = 0;
    p[0x27c / 4] = 0;
    p[0x284 / 4] = 0;
    p[0x28c / 4] = 0;
    p[0x168 / 4] = 0;
    p[0x174 / 4] = 0;
    p[0xdc / 4] = (int)((Renderer *)renderer)->CreateChild(renderer);
    p[0x138 / 4] = 0;
    p[0x298 / 4] = 0;
    SetRect((char *)this + 0x38, -999, 0, 0, 0);
    p[0xfc / 4] = 0xff000000;
    p[0x100 / 4] = 0xff000000;
    p[0x104 / 4] = 0xff000000;
    p[0x108 / 4] = 0xff000000;
}
