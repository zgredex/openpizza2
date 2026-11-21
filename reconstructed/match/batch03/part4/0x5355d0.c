/* PC2 byte-match candidate: Text_SetCursor (0x5355d0, 23 bytes).
   Build: /O2 /TP.  Stores the two cursor values into the text object. */
struct Text {
    unsigned char pad[0x9a0];
    int cursor_x;
    int cursor_y;
    void SetCursor(int x, int y);
};

void Text::SetCursor(int x, int y)
{
    cursor_x = x;
    cursor_y = y;
}
