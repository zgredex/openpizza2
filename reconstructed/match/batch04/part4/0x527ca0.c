/* PC2 byte-match candidate: UI_ClearField230 (0x527ca0, 27 bytes).
   Build: /O2 /TP.  Clears the cached id when it still matches. */
struct UI {
    unsigned char pad_000[0x230];
    int field_230;
    void ClearField230(int value);
};

void UI::ClearField230(int value)
{
    if (field_230 == value)
        field_230 = 0;
}
