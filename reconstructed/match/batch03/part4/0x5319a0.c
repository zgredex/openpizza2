/* PC2 byte-match candidate: UI_GetButtonSpriteRecord (0x5319a0, 21 bytes).
   Build: /O2 /TP.  Forwards (param, 6, 0x38, 0, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void GetButtonSpriteRecord(int param);
};

void Window::GetButtonSpriteRecord(int param)
{
    GadgetNotify(param, 6, 0x38, 0, 0);
}
