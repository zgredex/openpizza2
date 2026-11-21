/* UI_SetTextFit (0x522d40): copies text into the widget buffer and trims
   trailing characters until the measured width fits. */
extern "C" {
char *_strncpy(char *dest, const char *src, unsigned int count);
unsigned int strlen(const char *text);
}

struct Font {
    int MeasureText(char *text);
    int GetCharWidth(char character);
};

struct Device {
    void ClipRect(int *rect, int flag);
};

struct UI {
    char pad[8];
    Device *device;
    char pad2[0x28 - 0xc];
    int rect[0x54 / 4 - 0x28 / 4];
    Font *font;
    char pad3[0x6c - 0x58];
    char *buffer;
    char pad5[0x78 - 0x70];
    unsigned int bufferSize;
    char pad4[0x84 - 0x7c];
    int maxWidth;

    void SetTextFit(char *text);
};

void UI::SetTextFit(char *text)
{
    int width;
    int length;
    int i;

    _strncpy(buffer, text, bufferSize);
    buffer[bufferSize] = 0;
    width = font->MeasureText(buffer);
    length = strlen(buffer);
    for (i = length - 1; i >= 0 && width >= maxWidth; i--) {
        width -= font->GetCharWidth(buffer[i]);
        buffer[i] = 0;
    }
    device->ClipRect(rect, 1);
}
