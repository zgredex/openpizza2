/* PC2 byte-match candidate: Window_GadgetNotify_Slider_SetGradientColors
   (0x52fcc0, 24 bytes).  Build: /O2 /TP.  Forwards (param, 5, 0x1b, 0, value)
   to Window_GadgetNotify using the incoming window object in ecx. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void Slider_SetGradientColors(int param, int value);
};

void Window::Slider_SetGradientColors(int param, int value)
{
    GadgetNotify(param, 5, 0x1b, 0, value);
}
