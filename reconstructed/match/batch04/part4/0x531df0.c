/* PC2 byte-match candidate: UI_SubtractOrigin (0x531df0, 27 bytes).
   Build: /O2 /TP.  Subtracts the stored origin from a caller point. */
struct UI {
    unsigned char pad_000[0x18];
    int origin_x;
    int origin_y;
    void SubtractOrigin(int *px, int *py);
};

void UI::SubtractOrigin(int *px, int *py)
{
    *px -= origin_x;
    *py -= origin_y;
}
