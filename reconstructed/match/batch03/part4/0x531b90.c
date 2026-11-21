/* PC2 byte-match candidate: UI_GetButtonContext (0x531b90, 24 bytes).
   Build: /O2 /TP.  Forwards (param, 6, 0x36, 0, value) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void GetButtonContext(int param, int value);
};

void Window::GetButtonContext(int param, int value)
{
    GadgetNotify(param, 6, 0x36, 0, value);
}
