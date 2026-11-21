/* UI_SetLabelIdText (0x520d90). */
extern "C" void *operator_new(unsigned size);
extern "C" void Mem_Free(void *pointer);
extern "C" unsigned strlen(const char *text);
extern "C" char *strcpy(char *dest, const char *source);

struct UI {
    char pad00[0x10];
    char *text10;
    char pad14[0x10];
    int id24;

    void SetLabelIdText(int id, char *text);
};

void UI::SetLabelIdText(int id, char *text)
{
    id24 = id;
    if (text10 != 0) {
        Mem_Free(text10);
    }
    if (text != 0) {
        text10 = (char *)operator_new(strlen(text) + 1);
        strcpy(text10, text);
    } else {
        text10 = 0;
    }
}
