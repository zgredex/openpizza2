extern char *DAT_0057c1e0;
extern char STR_00574184[];

/* UI_CreateWindow: allocates a window slot and constructs a dialog window
   (0x523bb0). */
struct CS {
    void Enter();
    void Leave();
};

struct Dialog {
    void *Construct(void *owner, void *sprite, int type, int field10, int a, int b, int c);
};

struct UI {
    char pad[0x14];
    void *windows[1];
    int CreateWindow(int type, int a, int b, int c);
};

extern "C" void __cdecl DebugConsole_Printf(void *console, int color, char *format, int id);

extern "C" int __cdecl UI_CreateWindow(UI *ui, int type, int a, int b, int c)
{
    int slot;
    void *memory;
    void *window;
    CS *lock = *(CS **)((char *)ui + 0x1c8);

    lock->Enter();
    slot = ui->CreateWindow(type, a, b, c);
    memory = operator new(0x2c8);
    if (memory == 0) {
        window = 0;
    } else {
        window = ((Dialog *)memory)->Construct(ui, *(void **)((char *)ui + 0xc), c,
            *(int *)((char *)ui + 0x10), type, a, b);
    }
    *(void **)((char *)ui + slot * 4 + 0x14) = window;
    *(int *)((char *)window + 4) = slot;
    DebugConsole_Printf(DAT_0057c1e0, 0xff0000, STR_00574184, slot);
    lock->Leave();
    return slot;
}
