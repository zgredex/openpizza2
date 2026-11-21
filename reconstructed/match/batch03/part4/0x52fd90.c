/* PC2 byte-match candidate: Window_GadgetNotify_Slider_GetValue
   (0x52fd90, 24 bytes).  Build: /O2 /TP.  Forwards (param, 5, 0x26, 0, value)
   to Window_GadgetNotify using the incoming window object in ecx. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void Slider_GetValue(int param, int value);
};

void Window::Slider_GetValue(int param, int value)
{
    GadgetNotify(param, 5, 0x26, 0, value);
}
