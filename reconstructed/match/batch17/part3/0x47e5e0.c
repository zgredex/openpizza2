struct Sprite {
    void LoadIntoSlot78(char *name);
};

struct SpriteManager {
    char pad0[0x38];
    int sizeIndex;
    char pad1[0x14e0 - 0x3c];
    void *sprite;
    void GetSizeName(int variant, int number);
};

extern char DAT_00567cd4[];
extern char DAT_00567ccc[];
extern char DAT_00567cc4[];
extern char DAT_00567cbc[];
extern char DAT_00567cb4[];
extern char DAT_00567cac[];
extern char DAT_00567ca4[];
extern char DAT_00567ca0[];
extern char DAT_00567c68[];
extern char DAT_00567c84[];

extern "C" void String_Format(char *buffer, const char *format, ...);

void SpriteManager::GetSizeName(int variant, int number)
{
    char *names[8];
    char buffer[128];

    names[0] = DAT_00567cd4;
    names[1] = DAT_00567ccc;
    names[2] = DAT_00567cc4;
    names[3] = DAT_00567cbc;
    names[4] = DAT_00567cb4;
    names[5] = DAT_00567cac;
    names[6] = DAT_00567ca4;
    names[7] = DAT_00567ca0;
    if (variant != 4) {
        String_Format(buffer, DAT_00567c84, names[*(int *)((char *)this + 0x38)],
                      names[variant + 3], number + 1);
    } else {
        String_Format(buffer, DAT_00567c68,
                      names[*(int *)((char *)this + 0x38)], DAT_00567ca0);
    }
    ((Sprite *)*(void **)((char *)this + 0x14e0))->LoadIntoSlot78(buffer);
}
