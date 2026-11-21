/* PC2 byte-match candidate: Window_GadgetNotify_Input_GetText (0x52fbe0, 21 bytes).
   Build: /O2 /TP.  This is a thiscall wrapper that forwards the window object
   (already in ecx) plus a gadget category/code to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void Input_GetText(int param);
};

void Window::Input_GetText(int param)
{
    GadgetNotify(param, 4, 0xf, 0, 0);
}
