/* PC2 byte-match candidate: UI_StartButtonMovie (0x531c40, 24 bytes).
   Build: /O2 /TP.  Forwards (param, 6, 0x3e, value, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void StartButtonMovie(int param, int value);
};

void Window::StartButtonMovie(int param, int value)
{
    GadgetNotify(param, 6, 0x3e, value, 0);
}
