/* UI_GetWindowRect (0x5322a0). */
struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};
extern "C" __declspec(dllimport) int __stdcall
    SetRect(RECT *rect, int left, int top, int right, int bottom);
struct UI {
    char pad0[8];
    RECT windowRect;        /* 0x08 */
    char pad1[0x38 - 0x18];
    int left;               /* 0x38 */
    int top;                /* 0x3c */
    int right;              /* 0x40 */
    int bottom;             /* 0x44 */
    char pad2[0xe0 - 0x48];
    int hasWindowRect;      /* 0xe0 */

    void GetWindowRect(RECT *rect);
};

void UI::GetWindowRect(RECT *rect)
{
    RECT *source;

    if (hasWindowRect != 0) {
        *rect = windowRect;
        return;
    }
    source = (RECT *)((char *)this + 0x38);
    if (source->left != -999) {
        *rect = *source;
        return;
    }
    SetRect(rect, 0, 0, 0, 0);
}
