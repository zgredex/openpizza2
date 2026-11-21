/* Surface_Clear: zeroes the surface's pixel buffer (0x5374b0).
   Build: /O2 /TP. */
struct Surface {
    char pad[4];
    int width;
    int height;
    char pad2[4];
    unsigned char bitsPerPixel;
    char pad3[7];
    void *pixels;
    void Clear();
};

extern "C" void *__cdecl memset(void *dest, int value, unsigned count);

void Surface::Clear()
{
    unsigned bytes = (unsigned)(bitsPerPixel >> 3) * height * width;

    memset(pixels, 0, bytes);
}
