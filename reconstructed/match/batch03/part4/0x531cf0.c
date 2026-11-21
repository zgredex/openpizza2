/* PC2 byte-match candidate: UI_GetWindowObject (0x531cf0, 21 bytes).
   Build: /O2 /TP.  Forwards (param, 7, 0x36, 0, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void GetWindowObject(int param);
};

void Window::GetWindowObject(int param)
{
    GadgetNotify(param, 7, 0x36, 0, 0);
}
