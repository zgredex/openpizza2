/* Font::WrapText (0x535c10) - closest genuine C/C++ attempt.
   The shipped body keeps `text` in ECX / reloads it from the argument slot
   after each GetCharWidth call and defers the EBX/EBP pushes until after the
   newline loop. This build caches `text` in EBP, shrink-wraps the pushes
   before the first loop and therefore shifts the body; the local allocation
   i=EBX, width=ESI, lastSpace=EDI is otherwise the same. */
class Font {
public:
    int GetCharWidth(char c);
    void WrapText(char *text, int maxWidth);
};

void Font::WrapText(char *text, int maxWidth)
{
    int i;
    int width;
    int lastSpace;
    int savedWidth;
    char *p;
    int charWidth;

    for (p = text; *p != 0; p++) {
        if (*p == '\n')
            *p = ' ';
    }
    i = 0;
    width = 0;
    lastSpace = -1;
    if (*text != 0) {
        do {
            if (text[i] == ' ') {
                lastSpace = i;
                savedWidth = width;
            }
            if (text[i] == '\r') {
                width = 0;
                lastSpace = -1;
                i++;
                continue;
            }
            charWidth = GetCharWidth(text[i]);
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
