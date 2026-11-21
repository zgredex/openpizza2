/* UI_SetTextString: replaces the window's text with a copy of the given
   string (0x520d10). */
extern "C" unsigned int strlen(const char *text);
extern "C" char *strcpy(char *dest, const char *src);

void Mem_Free(void *block);
extern "C" void *operator_new(unsigned int size);

struct UI {
    char pad[0xc];
    char *text;

    void SetTextString(char *value);
};

void UI::SetTextString(char *value)
{
    if (text != 0) {
        Mem_Free(text);
    }
    text = (char *)operator_new(strlen(value) + 1);
    strcpy(text, value);
}
