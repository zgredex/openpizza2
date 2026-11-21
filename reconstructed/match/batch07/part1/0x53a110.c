/* Renderer_RestoreDisplay (0x53a110, 46 bytes).  Build: /O2 /TP.
   Restores the display surface through the graphics interface and waits for
   the worker thread. */
extern int DAT_00574734;
extern int DAT_00574738;

struct GraphicsVtbl {
    void (__stdcall *slot_00)();
    void (__stdcall *slot_01)();
    void (__stdcall *slot_02)();
    void (__stdcall *slot_03)();
    void (__stdcall *slot_04)();
    void (__stdcall *slot_05)();
    void (__stdcall *slot_06)();
    void (__stdcall *slot_07)();
    void (__stdcall *slot_08)();
    void (__stdcall *slot_09)();
    void (__stdcall *slot_10)();
    void (__stdcall *slot_11)();
    void (__stdcall *slot_12)();
    void (__stdcall *slot_13)();
    void (__stdcall *slot_14)();
    void (__stdcall *slot_15)();
    void (__stdcall *slot_16)();
    void (__stdcall *slot_17)();
    void (__stdcall *slot_18)();
    void (__stdcall *slot_19)();
    void (__stdcall *slot_20)();
    void (__stdcall *Restore)(void *self, int a, int b, int c);
};

struct Graphics {
    GraphicsVtbl *vtbl;
};

struct Thread {
    void WaitForExit(void);
};

struct Renderer {
    void RestoreDisplay(void);
};

void Renderer::RestoreDisplay(void)
{
    if (*(int *)((char *)this + 0x4c) == 0) {
        Graphics *graphics = *(Graphics **)*(void ***)((char *)this + 0x40);

        graphics->vtbl->Restore(graphics, DAT_00574734, DAT_00574738, 0x10);
    }
    ((Thread *)this)->WaitForExit();
}
