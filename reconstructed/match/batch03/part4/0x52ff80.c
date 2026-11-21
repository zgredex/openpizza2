/* PC2 byte-match candidate: UI_DisableButton (0x52ff80, 21 bytes).
   Build: /O2 /TP.  Forwards (param, 1, 3, 3, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void DisableButton(int param);
};

void Window::DisableButton(int param)
{
    GadgetNotify(param, 1, 3, 3, 0);
}
