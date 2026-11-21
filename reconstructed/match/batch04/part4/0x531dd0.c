/* PC2 byte-match candidate: UI_OffsetPoint (0x531dd0, 27 bytes).
   Build: /O2 /TP.  Adds the stored origin to a caller point. */
struct UI {
    unsigned char pad_000[0x18];
    int origin_x;
    int origin_y;
    void OffsetPoint(int *px, int *py);
};

void UI::OffsetPoint(int *px, int *py)
{
    *px += origin_x;
    *py += origin_y;
}
