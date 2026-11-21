/* UI_SetModalHandler (0x527cc0, 48 bytes).  Build: /O2 /TP.
   Installs the modal handler and resizes the modal window. */
struct ModalWindow {
    virtual void slot_0();
    virtual void slot_1();
    virtual void slot_2();
    virtual void SetLayout(int width, int height, int flags);
};

struct UI {
    void SetModalHandler(int handler, ModalWindow *window);
};

void UI::SetModalHandler(int handler, ModalWindow *window)
{
    *(int *)((char *)this + 0x8338) = handler;
    *(int *)((char *)this + 0x8348) = *(int *)((char *)this + 0x8340);
    *(ModalWindow **)((char *)this + 0x833c) = window;
    window->SetLayout(0x3c, 0, 0);
}
