/* PC2 byte-match candidate: UI_SetButtonRecordVariant (0x531b70, 27 bytes).
   Build: /O2 /TP.  Forwards to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void SetButtonRecordVariant(int param, int value);
};

void Window::SetButtonRecordVariant(int param, int value)
{
    GadgetNotify(param, 6, 300, value, 0);
}
