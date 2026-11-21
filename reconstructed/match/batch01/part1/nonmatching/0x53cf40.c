/* Sprite_Destruct (0x53cf40). */
struct Palette {
    void Free();
};

struct SpriteBase {
    virtual ~SpriteBase();
};

struct Sprite : SpriteBase {
    char pad0[0x1c];
    int *field20;
    int **field24;
    int pad28;
    int *field2c;
    int *field30;
    unsigned char count;
    char pad35[7];
    int *field3c;
    virtual ~Sprite();
};

void Mem_Free(void *block);

Sprite::~Sprite()
{
    int *p;
    int i;
    if (count == 1) {
        p = field20;
        if (p != 0 && *(short *)((char *)p + 0x206) == (short)-1 && p != 0) {
            ((Palette *)p)->Free();
            Mem_Free(p);
        }
    } else {
        i = 0;
        while (i < count) {
            p = field24[i];
            if (p != 0 && *(short *)((char *)p + 0x206) == (short)-1 && p != 0) {
                ((Palette *)p)->Free();
                Mem_Free(p);
            }
            i++;
        }
    }
    if (field2c != 0)
        Mem_Free(field2c);
    if (field30 != 0)
        Mem_Free(field30);
    if (field3c != 0)
        Mem_Free(field3c);
    if (field24 != 0)
        Mem_Free(field24);
}
