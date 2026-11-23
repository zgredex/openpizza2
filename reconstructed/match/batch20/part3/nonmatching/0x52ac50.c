extern "C" char *strcpy(char *, const char *);
extern "C" char *strrchr(const char *, int);
#pragma intrinsic(strcpy)
extern "C" int String_Format(char *buffer, const char *format, ...);

struct UI;

struct Window {
    char pad[0x134];
    UI *owner;
    void LoadSpriteCached(char *name, int flag, void *record);
};

struct UI {
    char pad[8];
    Window *window;
    void DecrementRowCounter(char *name);
    void RefreshButtonSprites(int mode);
};

void UI::RefreshButtonSprites(int mode)
{
    char name[260];
    char buffer[260];
    char *dot;
    int i;
    int *entry;

    if (mode < 1 || mode > 2)
        return;
    UI *win = window->owner;
    if (mode == 1) {
        entry = (int *)((char *)this + 0x454);
        i = 3;
        do {
            if (*entry != 0)
                win->DecrementRowCounter((char *)entry - 0x40);
            *entry = 0;
            entry += 0x11;
            i--;
        } while (i != 0);
        return;
    }
    strcpy(name, (char *)this + 0x348);
    dot = strrchr(name, '_');
    if (dot != 0)
        *dot = 0;
    if (mode == 2) {
        i = 0;
        entry = (int *)((char *)this + 0x414);
        do {
            if (entry[0x10] == 0) {
                String_Format(buffer, "%s_%02d.spr", name, i + 9);
                ((Window *)win)->LoadSpriteCached(buffer, i < 2, entry);
            }
            i++;
            entry += 0x11;
        } while (i < 3);
    }
}
