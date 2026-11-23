extern int DAT_005844fc;
extern float DAT_0055c08c;

/* Surface_GetDescription: locks a DirectDraw surface and copies its
   description (0x5390b0). */
struct Surface {
    int Lock(int flags, void *desc, int a, int b);
};

struct Description {
    int size;
    char pad[0x68];
};

struct Image {
    char pad[0x1a];
    unsigned short width;
    unsigned short height;
    int center;
    char rest[0x28 - 0x24];
    int field28;
    char rest2[0x64 - 0x2c];
    int rect[4];
    void Reset();
    void GetDescription(int *out, int *width_out);
};

extern "C" void __cdecl Sleep(unsigned int milliseconds);
extern "C" void __cdecl WaitForExit(int object);
extern "C" int __cdecl SetRect(void *rect, int left, int top, int right, int bottom);

void Image::GetDescription(int *out, int *width_out)
{
    Description desc;
    int i;
    int tries = 0;

    for (i = 0; i < 0x1b; i++) {
        ((int *)&desc)[i] = 0;
    }
    desc.size = 0x6c;
    while (1) {
        int result;

        if (DAT_005844fc != 0) {
            return;
        }
        result = ((Surface *)out)->Lock(0, &desc, 1, 0);
        if (result == 0) {
            break;
        }
        if (result == -0x7789fe3e) {
            WaitForExit((int)this);
        }
        Sleep(1);
        tries = tries + 1;
        if (200 < tries) {
            return;
        }
    }
    *width_out = *(int *)&desc.pad[0];
    *(unsigned short *)((char *)this + 0x1a) = *(unsigned short *)((char *)&desc + 0x1c);
    *(int *)((char *)this + 0x28) = *(int *)((char *)&desc + 0x34);
    *(unsigned short *)((char *)this + 0x1c) = *(unsigned short *)((char *)&desc + 0x18);
    *(int *)((char *)this + 0x20) = *(int *)&desc.pad[0] >> 1;
    Reset();
    SetRect((char *)this + 0x64, 0, 0, *(unsigned short *)((char *)this + 0x1a),
            *(unsigned short *)((char *)this + 0x1c));
}
