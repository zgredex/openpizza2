/* Surface_BlitRLEEnsureFormat: realizes a lazy sprite and blits it with the
   surface's pixel format (0x53d650). */
struct Sprite {
    void RealizeLazy();
};

struct Surface {
    char pad[0x2c];
    unsigned char *format;
    char pad2[9];
    unsigned char realized;
    void BlitRLESkipToRGB(int a, void *b, unsigned char *format, int c, int d);
    void BlitRLEEnsureFormat(int a, void *b, int c, int d);
};

void Surface::BlitRLEEnsureFormat(int a, void *b, int c, int d)
{
    if (realized == 0)
        ((Sprite *)this)->RealizeLazy();
    BlitRLESkipToRGB(a, b, format, c, d);
}
