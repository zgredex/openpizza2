// UI_BringWindowToFront @ 0x527ee0 (157 bytes)
// Rotates the window list so the requested window becomes the frontmost
// entry, then stops the sound buffers that belonged to the shifted windows.

extern "C" void *__cdecl memmove(void *dst, const void *src, unsigned int size);

struct CS {
    void Enter();
    void Leave();
};

struct Sound {
    void StopBuffer();
};

class UI {
public:
    char pad00[0x14];
    Sound *windows[109];    // 0x14
    CS *cs;                 // 0x1c8
    char pad1cc[0x70];
    int count;              // 0x23c
    char pad240[0x8178];
    int frontChanged;       // 0x83b8

    int FindWindowByID(int id, int *index);
    void BringWindowToFront(int id);
};

void UI::BringWindowToFront(int id)
{
    int index;

    cs->Enter();
    if (FindWindowByID(id, &index) == 0 || index == 0) {
        cs->Leave();
        return;
    }

    Sound *saved = windows[index];
    memmove(&windows[1], &windows[0], index * 4);
    windows[0] = saved;

    int i = 0;
    if (count > 0) {
        do {
            if (windows[i] != 0)
                windows[i]->StopBuffer();
            i++;
        } while (i < count);
    }
    frontChanged = 1;
    cs->Leave();
}
