/* Palette_Expand (0x48ce70). */
extern "C" void __stdcall Palette_Expand(unsigned short *out, int mode, int format)
{
    unsigned char *src = (unsigned char *)*(int *)out;
    unsigned int b0;
    unsigned int b1;
    unsigned int b2;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int m;
    unsigned int value;
    int i;

    out += 2;
    src += 1;
    i = 0x100;
    do {
        b0 = src[-1];
        b1 = src[0];
        b2 = src[1];
        src += 3;
        switch (format) {
        case 0:
            r = b2; g = b0; b = b0;
            break;
        case 1:
            r = b2; g = b2; b = b0;
            break;
        case 2:
            r = b1; g = b1; b = b2;
            break;
        case 3:
            r = b0; g = b2; b = b1;
            break;
        case 4:
            m = (b1 + b2) >> 1;
            r = m; g = b1; b = m;
            break;
        case 5:
            r = b0; g = b2; b = b2;
            break;
        case 6:
            r = b2; g = b1; b = b0;
            break;
        case 7:
            m = (b1 + b2) / 2;
            r = b0; g = m; b = m;
            break;
        }
        if (mode != 0) {
            value = ((r & 0xfff8) << 5 | (g & 0xf8)) << 3;
        } else {
            value = ((r & 0xf8) << 5 | (g & 0xf8)) << 2;
        }
        *out = (unsigned short)(value | (b >> 3));
        out++;
        i--;
    } while (i != 0);
}
