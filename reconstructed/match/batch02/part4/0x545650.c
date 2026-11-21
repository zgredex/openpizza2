/* PC2 byte-match candidate: Rect_Zero (0x545650, 16 bytes).
   Build: /O2 /TP; entry ??0Rect@@QAE@XZ. */
struct Rect {
    int left;
    int top;
    int right;
    int bottom;

    Rect(void);
};

Rect::Rect(void)
{
    left = 0;
    top = 0;
    right = 0;
    bottom = 0;
}
