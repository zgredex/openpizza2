/* PC2 byte-match candidate: Text_GetPosition (0x5355b0, 27 bytes).
   Build: /O2 /TP.  Returns the stored text cursor position. */
struct Text {
    unsigned char pad_000[0x9a0];
    int x;
    int y;
    void GetPosition(int *px, int *py);
};

void Text::GetPosition(int *px, int *py)
{
    *px = x;
    *py = y;
}
