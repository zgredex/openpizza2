/* PC2 byte-match candidate: UI_SetPosition (0x532310, 23 bytes).
   Build: /O2 /TP.  Stores the two position values into the window object. */
struct UI {
    unsigned char pad[0x28c];
    int position_x;
    int position_y;
    void SetPosition(int x, int y);
};

void UI::SetPosition(int x, int y)
{
    position_x = x;
    position_y = y;
}
