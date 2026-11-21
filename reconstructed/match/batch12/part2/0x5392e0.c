/* Surface_InitFromBuffer: initialises a surface from a pixel buffer
   (0x5392e0). */
struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};

extern "C" __declspec(dllimport) int __stdcall SetRect(
    struct RECT *rect, int left, int top, int right, int bottom);

struct Surface {
    void Release();

    void InitFromBuffer(int buffer, unsigned short width,
                        unsigned short height, int pitch);
};

void Surface::InitFromBuffer(int buffer, unsigned short width,
                             unsigned short height, int pitch)
{
    Release();
    *(int *)((char *)this + 0x28) = buffer;
    *(unsigned short *)((char *)this + 0x1c) = height;
    *(unsigned short *)((char *)this + 0x1a) = width;
    *(int *)((char *)this + 0xc) = 0;
    *(int *)((char *)this + 4) = 0;
    *(unsigned int *)((char *)this + 8) = width;
    *(unsigned int *)((char *)this + 0x10) = height;
    *(int *)((char *)this + 0x20) = pitch >> 1;
    *(int *)((char *)this + 0x14) = 1;
    SetRect((struct RECT *)((char *)this + 100), 0, 0, width, height);
}
