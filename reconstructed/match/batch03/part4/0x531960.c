/* PC2 byte-match candidate: UI_SetButtonColorVariant (0x531960, 24 bytes).
   Build: /O2 /TP.  Forwards (param, 6, 0x39, value, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void SetButtonColorVariant(int param, int value);
};

void Window::SetButtonColorVariant(int param, int value)
{
    GadgetNotify(param, 6, 0x39, value, 0);
}
