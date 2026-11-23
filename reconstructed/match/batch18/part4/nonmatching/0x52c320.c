/* UI_DrawTextControl: wraps and positions a UI text control (0x52c320). */
struct Font {
    void WrapText(char *text, int width);
};

struct UI {
    int ProcessDialogInput(int unused, void *text);
    int MeasureTextMaxWidth();
    void SetAbsolutePosition(int x, int y);
    void DrawTextControl();
};

void UI::DrawTextControl()
{
    int width;
    int x;
    int mode;

    if (*(int *)((char *)this + 0x7c) != 0) {
        *(int *)((char *)this + 0x5c) =
            ProcessDialogInput(0, *(void **)((char *)this + 0x74));
        return;
    }
    if (*(short *)((char *)this + 100) != 0 && *(short *)((char *)this + 0x66) != 0) {
        ((Font *)*(void **)((char *)this + 0x54))->WrapText(
            *(char **)((char *)this + 0x74), *(short *)((char *)this + 100));
        *(int *)((char *)this + 0x5c) = -1;
    }
    if (*(int *)((char *)this + 0x5c) == -1) {
        char *p = *(char **)((char *)this + 0x74);
        char c;

        *(int *)((char *)this + 0x5c) = 1;
        c = *p;
        while (c != '\0') {
            if (c == '\n' || c == '\r') {
                *(int *)((char *)this + 0x5c) = *(int *)((char *)this + 0x5c) + 1;
            }
            p = p + 1;
            c = *p;
        }
    }
    if (*(short *)((char *)this + 100) < 1) {
        width = MeasureTextMaxWidth();
        x = *(int *)((char *)this + 0x38);
        mode = *(int *)((char *)this + 0x6c);
        *(int *)((char *)this + 0x28) = x;
        if (mode == 2) {
            x = x - width / 2;
            *(int *)((char *)this + 0x28) = x;
        } else if (mode == 1) {
            x = x - width;
            *(int *)((char *)this + 0x28) = x;
        } else if (mode == 0) {
            *(int *)((char *)this + 0x28) = x;
        }
    } else {
        width = *(short *)((char *)this + 100);
    }
    if (*(short *)((char *)this + 0x66) < 1) {
        SetAbsolutePosition(width, *(int *)(*(int *)((char *)this + 0x54) + 0x9b0));
        return;
    }
    SetAbsolutePosition(width, *(short *)((char *)this + 0x66));
}
