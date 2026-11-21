/* PC2 byte-match candidate: Window_GadgetNotify_Slider_SetValue
   (0x52fd70, 27 bytes).  Build: /O2 /TP.  Forwards to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void Slider_SetValue(int param, int value, int extra);
};

void Window::Slider_SetValue(int param, int value, int extra)
{
    GadgetNotify(param, 5, 0x25, value, extra);
}
