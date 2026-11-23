struct Font {
    char pad0[0x9a0];
    int x;
    int y;
    int lineStartX;
    int lineHeight;
    int advance;
    int field9B0;
    int field9B4;
    int field9B8;
    int lineTop;
    int lineBottom;
    int alignment;
    int MeasureRange(char *text, int start, int end);
    void DrawTextLine(void *surface, char *text);
};

struct Text {
    void DrawCharAdvance(void *surface, char c);
};

void Font::DrawTextLine(void *surface, char *text)
{
    int i = 0;
    while (1) {
        unsigned char c = *(unsigned char *)(i + text);
        int end = i;
        while (0x1f < c) {
            end = end + 1;
            c = *(unsigned char *)(end + text);
        }
        if (*(int *)((char *)this + 0x9c4) != 0) {
            int width;
            if (*(int *)((char *)this + 0x9c4) == 2)
                width = MeasureRange(text, i, end) >> 1;
            else
                width = MeasureRange(text, i, end);
            *(int *)((char *)this + 0x9a0) =
                *(int *)((char *)this + 0x9a0) - width;
        }
        *(int *)((char *)this + 0x9bc) = *(int *)((char *)this + 0x9a0);
        *(int *)((char *)this + 0x9c0) = *(int *)((char *)this + 0x9a4);
        int k;
        for (k = i; k < end; k = k + 1)
            ((Text *)this)->DrawCharAdvance(surface, *(char *)(k + text));
        if (*(char *)(k + text) == '\0')
            break;
        int nextY = *(int *)((char *)this + 0x9ac) +
                    *(int *)((char *)this + 0x9b0);
        *(int *)((char *)this + 0x9a0) = *(int *)((char *)this + 0x9a8);
        i = k + 1;
        *(int *)((char *)this + 0x9ac) = nextY;
        *(int *)((char *)this + 0x9a4) = nextY;
        if (*(char *)(i + text) == '\n')
            i = k + 2;
        if (*(char *)(i + text) == '\0')
            break;
    }
}
