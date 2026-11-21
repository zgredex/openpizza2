/* DebugConsole_Construct: initializes the in-game debug console (0x54a5f0). */
struct DebugConsole {
    void **vtable;
    int field4;
    int field8;
    int fieldc;
    char pad[0x10];
    int field20;
    int field24;
    DebugConsole *Construct(int param);
};

DebugConsole *DebugConsole::Construct(int param)
{
    vtable = (void **)0x55cb3c;
    field4 = 0;
    field8 = param;
    fieldc = 0;
    field20 = 0;
    field24 = 0;
    return this;
}
