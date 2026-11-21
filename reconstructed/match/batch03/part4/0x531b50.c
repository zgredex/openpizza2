/* PC2 byte-match candidate: UI_ClearButtonRecordAnimation (0x531b50, 24 bytes).
   Build: /O2 /TP.  Forwards (param, 6, 0x12d, 0, 0) to Window_GadgetNotify. */
struct Window {
    void GadgetNotify(int param, int type, int code, int value, int extra);
    void ClearButtonRecordAnimation(int param);
};

void Window::ClearButtonRecordAnimation(int param)
{
    GadgetNotify(param, 6, 0x12d, 0, 0);
}
