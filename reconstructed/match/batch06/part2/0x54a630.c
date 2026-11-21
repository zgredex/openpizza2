/* DebugConsole_Destructor: releases the console window and edit DLL (0x54a630). */
extern void (__stdcall *DAT_0055c1f8)(void *window);
extern void (__stdcall *DAT_0055c068)(void *module);

struct DebugConsole {
    int vtable;
    void *window;
    char pad[0x24 - 8];
    void *module;
    void Destructor();
};

void DebugConsole::Destructor()
{
    vtable = 0x55cb3c;
    if (window != 0) {
        DAT_0055c1f8(window);
    }
    if (module != 0) {
        DAT_0055c068(module);
    }
}
