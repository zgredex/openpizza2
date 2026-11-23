/* Font::WrapText (0x535c10). */
class Font {
public:
    int GetCharWidth(char c);
    void WrapText(char *text, int maxWidth);
};

void Font::WrapText(char *text, int maxWidth)
{
    char *p;
    int i;
    int width;
    int lastSpace;
    int savedWidth;

    for (p = text; *p != 0; p++) {
        if (*p == '\n')
            *p = ' ';
    }
    i = 0;
    width = 0;
    lastSpace = -1;
    if (*text != 0) {
        do {
            char c = text[i];
            if (c == ' ') {
                lastSpace = i;
                savedWidth = width;
            }
            if (c == '\r') {
                width = 0;
                lastSpace = -1;
                i++;
                continue;
            }
            int charWidth = GetCharWidth(c);
            if (width + charWidth > maxWidth && lastSpace != -1) {
                text[lastSpace] = '\n';
                width -= savedWidth + GetCharWidth(' ');
                lastSpace = -1;
            }
            width += charWidth;
            i++;
        } while (text[i] != 0);
    }
}
