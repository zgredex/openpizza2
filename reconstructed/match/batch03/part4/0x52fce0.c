/* PC2 byte-match candidate: Window_GadgetNotify_Slider_SetChangeNotify
   (0x52fce0, 24 bytes).  Build: /O2 /TP.  Forwards (param, 5, 0x1c, value, 0)
   to Window_GadgetNotify using the incoming window object in ecx. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void Slider_SetChangeNotify(int param, int value);
};

void Window::Slider_SetChangeNotify(int param, int value)
{
    GadgetNotify(param, 5, 0x1c, value, 0);
}
